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
		fstream file("user.txt", fstream::out | ios_base::trunc);//打开文件
		if (!file) {
			cout << "错误！未找到文件！" << endl;
			exit(ERROR);
		}
		while (t->next != NULL) {
			file << t->next->data.username << "\t" << t->next->data.password << "\t" << t->next->data.money;
			t = t->next;
			if (t->next) file << endl;
		}
		cout << " user.txt 输出完毕" << endl;
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
	cout << "请输入你要删除的 用户名：" << endl;
	string name, pwd;
	double money;
	cin >> name;
	cout << "请输入你要删除的 用户名的密码：" << endl;
	cin >> pwd;
	User x(name, pwd, 10);
	T.Delete(U, x);
}
bool userManager::changePwd(User& user) {
	cout << "你要更改的密码为:" << endl;
	string password;
	cin >> password;
	bool t = user.changePassword(password);
	if (!t) {
		cout << "请输入不同的密码" << endl;
		return false;
	}
	else {
		T.Insert(U,user);
		cout << "修改成功咯" << endl;
	}
	return true;
}

void userManager::showMoney(User& user) {
	//cout << "用户  " << user.username << "  拥有 : " << user.money << "钱" << endl;
	cout << "用户" << "\t"<< "密码" << "\t" << "资金"<< endl;
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
	cout << "请输入你要看的国家" << endl;
	string country;
	cin >> country;
	Country c(country);
	VNode v(c);
	VNode t;
	G.GetVex(c, t);
	SqList L(t.data.player);
	QuickSort(L);
	for (int i = 0; i < 11; i++) {
		//cout <<	"位置：" << t.data.player[i].pSite << "\t" << "姓名:"<<	t.data.player[i].pName << "\t" << "号码:" << t.data.player[i].pNumber << endl;
		cout <<	"位置：" << L.r[i + 1].pSite << "\t" << "姓名:" << L.r[i + 1].pName << "\t" << "号码:" << L.r[i + 1].pNumber << endl;
	}	
}

bool userManager::regist() {
	string username, password;
	cout << "快点输入用户名: " << endl;
	cin >> username;
	cout << "快点输入密码: " << endl;
	cin >> password;
	User u(username, password, 1000);
	bool t = T.Contains(U, u);
	if (t) {
		cout << "用户名已经存在啦" << endl;
		return false;
	}
	else {
		T.Insert(U, u);
		cout << "用户注册成功" << endl;
	}
}

bool userManager::login(User& user) {
	string username, password;
	cout << "快点输入用户名: " << endl;
	cin >> username;
	cout << "快点输入密码: " << endl;
	cin >> password;
	User u(username, password, 1);
	bool t = T.Contains(U, u);
	if (t) {
		user = u;
		cout << "OK啦 验证成功" << endl;
		return true;
	}
	else {
		cout << "密码或者用户名错误 糟糕！！" << endl;
		return false;
	}
}
void userManager::init(){
	fstream file{};
	file.open("user.txt");//打开文件
	if (!file) {
		cout << "错误！未找到文件！" << endl;
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
	cout << "输入 user.txt 信息完毕\n\n";
	file.close();

}
