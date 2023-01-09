#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "AVLTree.h"
#include "AMGraph.h"
#include "userManager.h"


class menuManager
{
public:
	int v;
	userManager um;
	User user;
	AMGraph G;
	menuManager() {
		createGroup(G);
		load_arc(G);
		v = 0 ;
	}
	
	void StartMenu();//��ʼ�˵� 
	void userMenu();//�û��˵� 
	void adminMenu();//����Ա�˵�
	void one_level();//��ʼ
	void two_level();//�û�
	void admin_level();//����Ա
	void createGroup(AMGraph & G);
	void load_arc(AMGraph& G);
	
};

void menuManager::createGroup(AMGraph& G) {
	fstream file;
	file.open("Group_01.txt");//���ļ�
	if (!file) {
		cout << "����δ�ҵ��ļ���" << endl;
		exit(ERROR);
	}
	for (int k = 0; k < 8; k++) {
		string group;
		file >> group; 
		for (int i = 0; i < 4 ; i++) {
			string name;
			file >> name;
			Country c(name);
			for (int j = 0; j < 11; j++) {
				file >> c.player[j].pId
					>> c.player[j].pNumber
					>> c.player[j].pSite
					>> c.player[j].pSalary
					>> c.player[j].pName;
			}
			G.InsertVex(c);
		}
	}
	cout << "���� Group_01.txt ��Ϣ���\n\n";
	file.close();
	//G.DFSTraverse(0);
}
void menuManager::load_arc(AMGraph& G) {
	fstream file;
	file.open("game_group.txt");//���ļ�
	if (!file) {
		cout << "����δ�ҵ��ļ���" << endl;
		exit(ERROR);
	}
	for (int k = 0; k < 48; k++) {
		for (int i = 0; i < 3; i++) {
			string c1, c2;
			int s;
			file >> c1 >> s >> c2;
			G.InsertArc(c1, c2, s);
		}
	}
	cout << "���� game_group.txt ��Ϣ���\n\n";
	file.close();

}
void menuManager::adminMenu() {
	cout << "1.�û�ɾ��" << endl;
	cout << "2.�û���Ϣ��ѯ" << endl;
	cout << "4.�˳�" << endl;
} 
void menuManager::StartMenu() {
	cout << "1.ע��" << endl;
	cout << "2.��¼" << endl;
	cout << "3.i am ����Ա" << endl;
	cout << "4.�˳�" << endl;
	cout << "���������ѡ��" << endl;
}
void menuManager::userMenu() {
	cout << "1.�޸�����" << endl;		//yes
	cout << "2.��Ϣ��ѯ" << endl;		//yes
	//cout << "3.�鿴��ʷѺע" << endl;
	cout << "4.��ѯ�����������������" << endl;  //yes
	//cout << "5.��ʷ��ս���" << endl;
	cout << "6.������Ϸ" << endl;				//yes
	cout << "7.�ǳ�" << endl;
	cout << "���������ѡ��" << endl;
}

void menuManager::one_level() {
	while (1) {
		StartMenu();
		cout << "����������ѡ�� " << endl;
		int switch_on;
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			um.regist();
			break;
		case 2:
			if(um.login(user)) two_level();
			break;
		case 3:
			admin_level();
			break;
		case 4:
			return ;
		default:
			cout << "����������" << endl;
			break;
		}
	}
}
void menuManager::two_level() {
	while (1) {
		userMenu();
		cout << "����������ѡ�� " << endl;
		int switch_on;
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			um.changePwd(user);		//�޸�����
			break;
		case 2:
			um.showMoney(user);		//��ʾ�ʲ�
			break;
		case 4:
			um.showTeam(user, G);	// �鿴��������
			break;
		case 6:
			if (v > 32) {
				//��̭��
				cout << "С����������" << endl;
				cout << "��̭����ûд" << endl;
				break;
			}
			G.game(v,user);
			v += 4;
			break;
		case 7:
			return;
		default:
			cout << "����������" << endl;
			break;
		}
	}
}
void menuManager::admin_level() {
	while (1) {
		adminMenu();
		int switch_on;
		cout << "�������ѡ�� " << endl;
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			//�û�ɾ��
			um.deleteByName();
			break;
		case 2:
			//�û���ѯ
			um.showAll();
			break;
		case 4:
			//�Ƴ�
			return;
		default:
			cout << "����������" << endl;
			break;
		}
	}

}
#endif