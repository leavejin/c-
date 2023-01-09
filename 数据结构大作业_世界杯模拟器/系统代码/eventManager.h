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
	
	void StartMenu();//开始菜单 
	void userMenu();//用户菜单 
	void adminMenu();//管理员菜单
	void one_level();//初始
	void two_level();//用户
	void admin_level();//管理员
	void createGroup(AMGraph & G);
	void load_arc(AMGraph& G);
	
};

void menuManager::createGroup(AMGraph& G) {
	fstream file;
	file.open("Group_01.txt");//打开文件
	if (!file) {
		cout << "错误！未找到文件！" << endl;
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
	cout << "输入 Group_01.txt 信息完毕\n\n";
	file.close();
	//G.DFSTraverse(0);
}
void menuManager::load_arc(AMGraph& G) {
	fstream file;
	file.open("game_group.txt");//打开文件
	if (!file) {
		cout << "错误！未找到文件！" << endl;
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
	cout << "输入 game_group.txt 信息完毕\n\n";
	file.close();

}
void menuManager::adminMenu() {
	cout << "1.用户删除" << endl;
	cout << "2.用户信息查询" << endl;
	cout << "4.退出" << endl;
} 
void menuManager::StartMenu() {
	cout << "1.注册" << endl;
	cout << "2.登录" << endl;
	cout << "3.i am 管理员" << endl;
	cout << "4.退出" << endl;
	cout << "请输入你的选择：" << endl;
}
void menuManager::userMenu() {
	cout << "1.修改密码" << endl;		//yes
	cout << "2.信息查询" << endl;		//yes
	//cout << "3.查看历史押注" << endl;
	cout << "4.查询各个国家足球队阵容" << endl;  //yes
	//cout << "5.历史对战情况" << endl;
	cout << "6.竞猜游戏" << endl;				//yes
	cout << "7.登出" << endl;
	cout << "请输入你的选择：" << endl;
}

void menuManager::one_level() {
	while (1) {
		StartMenu();
		cout << "快点做出你的选择： " << endl;
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
			cout << "请重新输入" << endl;
			break;
		}
	}
}
void menuManager::two_level() {
	while (1) {
		userMenu();
		cout << "快点做出你的选择： " << endl;
		int switch_on;
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			um.changePwd(user);		//修改密码
			break;
		case 2:
			um.showMoney(user);		//显示资产
			break;
		case 4:
			um.showTeam(user, G);	// 查看队伍阵容
			break;
		case 6:
			if (v > 32) {
				//淘汰赛
				cout << "小组赛比完啦" << endl;
				cout << "淘汰赛还没写" << endl;
				break;
			}
			G.game(v,user);
			v += 4;
			break;
		case 7:
			return;
		default:
			cout << "请重新输入" << endl;
			break;
		}
	}
}
void menuManager::admin_level() {
	while (1) {
		adminMenu();
		int switch_on;
		cout << "快点做出选择： " << endl;
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			//用户删除
			um.deleteByName();
			break;
		case 2:
			//用户查询
			um.showAll();
			break;
		case 4:
			//推出
			return;
		default:
			cout << "请重新输入" << endl;
			break;
		}
	}

}
#endif