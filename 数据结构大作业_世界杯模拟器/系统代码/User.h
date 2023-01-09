#pragma once

#include <iostream>
using namespace std;

class User {
public:
	//int id;
	string username;
	string password;
	double money;

public:
	User(string u, string p, double m) :username(u), password(p), money(m) {};
	User() :username(" "), password(" "), money(0.0) {};
	User(const User& u) {
		username = u.username;
		password = u.password;
		money = u.money;
	}
	bool changePassword(std::string password);
	double getMoney();
	
	bool operator<(User u) {
		if (this->username < u.username) return true;
		else return false;
	}

	bool operator>(User u) {
		if (this->username > u.username) return true;
		else return false;
	}

	bool operator==(User u) {
		if (this->username == u.username && password == u.password)
				return true;
		else return false;
	}

};
ostream& operator<<(ostream& cout, const User& u) {
	cout << u.username << "\t" << u.password << "\t" << u.money;
	return cout;
}

bool User::changePassword(std::string password) {

	if (password == this->password) return false;
	this->password = password;
	return true;

}

double User::getMoney() {

	return this->money;

}

