#pragma once
#include<iostream>
using namespace std;
#include <fstream>
#include "Country.h"

typedef struct SqList{
	Player r[12];
	int length;
	SqList(Player* t) :length(11) {
		for (int i = 1; i < 12; i++) {
			r[i] = t[i - 1];
		}
	}
}SqList;
class userManager
{
public:
	AVLNode<User>* U ;
	AVLTree<User> T;
	userManager(){
		U = new AVLNode<User>;
		init();
		//T.InorderTraversal(U);	
	}
	~userManager() {
		LNode<User>* t = T.LevelTraversal(U);
		fstream file("user.txt", fstream::out | ios_base::trunc);//���ļ�
		if (!file) {
			cout << "����δ�ҵ��ļ���" << endl;
			exit(ERROR);
		}
		while (t->next != NULL) {
			file << t->next->data.username << "\t" << t->next->data.password << "\t" << t->next->data.money;
			t = t->next;
			if (t->next) file << endl;
		}
		cout << " user.txt ������" << endl;
	}
	void init();
	bool regist();
	bool login(User &user);
	bool changePwd(User& user);
	void showMoney(User& user);
	void showTeam(User& user, AMGraph& G);
	void showAll();
	void deleteByName();
};

void userManager::showAll() {
	T.InorderTraversal(U);
}
void userManager::deleteByName() {
	showAll();
	cout << "��������Ҫɾ���� �û�����" << endl;
	string name, pwd;
	double money;
	cin >> name;
	cout << "��������Ҫɾ���� �û��������룺" << endl;
	cin >> pwd;
	User x(name, pwd, 10);
	T.Delete(U, x);
}
bool userManager::changePwd(User& user) {
	cout << "��Ҫ���ĵ�����Ϊ:" << endl;
	string password;
	cin >> password;
	bool t = user.changePassword(password);
	if (!t) {
		cout << "�����벻ͬ������" << endl;
		return false;
	}
	else {
		T.Insert(U,user);
		cout << "�޸ĳɹ���" << endl;
	}
	return true;
}

void userManager::showMoney(User& user) {
	//cout << "�û�  " << user.username << "  ӵ�� : " << user.money << "Ǯ" << endl;
	cout << "�û�" << "\t"<< "����" << "\t" << "�ʽ�"<< endl;
	cout << user << endl;
}
int Partition(SqList& L, int low, int high) {
	L.r[0] = L.r[low];
	int pivotkey = L.r[low].pId;
	while (low < high) {
		while (low < high && L.r[high].pId >= pivotkey) --high;
		L.r[low] = L.r[high];
		while (low < high && L.r[low].pId <= pivotkey) ++low;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}
void QSort(SqList& L, int low, int high) {
	if (low < high) {
		int pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivotloc + 1, high);

	}
}
void QuickSort(SqList& L) {
	QSort(L, 1, L.length);
}
void userManager::showTeam(User& user,AMGraph & G) {
	cout << "��������Ҫ���Ĺ���" << endl;
	string country;
	cin >> country;
	Country c(country);
	VNode v(c);
	VNode t;
	G.GetVex(c, t);
	SqList L(t.data.player);
	QuickSort(L);
	for (int i = 0; i < 11; i++) {
		//cout <<	"λ�ã�" << t.data.player[i].pSite << "\t" << "����:"<<	t.data.player[i].pName << "\t" << "����:" << t.data.player[i].pNumber << endl;
		cout <<	"λ�ã�" << L.r[i + 1].pSite << "\t" << "����:" << L.r[i + 1].pName << "\t" << "����:" << L.r[i + 1].pNumber << endl;
	}	
}

bool userManager::regist() {
	string username, password;
	cout << "��������û���: " << endl;
	cin >> username;
	cout << "�����������: " << endl;
	cin >> password;
	User u(username, password, 1000);
	bool t = T.Contains(U, u);
	if (t) {
		cout << "�û����Ѿ�������" << endl;
		return false;
	}
	else {
		T.Insert(U, u);
		cout << "�û�ע��ɹ�" << endl;
	}
}

bool userManager::login(User& user) {
	string username, password;
	cout << "��������û���: " << endl;
	cin >> username;
	cout << "�����������: " << endl;
	cin >> password;
	User u(username, password, 1);
	bool t = T.Contains(U, u);
	if (t) {
		user = u;
		cout << "OK�� ��֤�ɹ�" << endl;
		return true;
	}
	else {
		cout << "��������û������� ��⣡��" << endl;
		return false;
	}
}
void userManager::init(){
	fstream file{};
	file.open("user.txt");//���ļ�
	if (!file) {
		cout << "����δ�ҵ��ļ���" << endl;
		exit(ERROR);
	}
	std::string username, password;
	double money;
	file >> username >> password >> money;
	User a(username, password, money);
	U->value = a;
	while (!file.eof()) {
		file >> username >> password >> money;
		User b(username, password, money);
		T.Insert(U, b);
	}
	cout << "���� user.txt ��Ϣ���\n\n";
	file.close();

}
