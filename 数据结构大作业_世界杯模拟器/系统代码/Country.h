#pragma once

#include <iostream>
using namespace std;

struct Player {
public:
	int pId;
	int pNumber;
	string pSite;
	int pSalary;
	string pName;

	Player() :pId(0), pNumber(0), pSite(" "), pSalary(0), pName(" ") {}
	Player(int id, int number, string site, int salary, string name):pId(id), pNumber(number), pSite(site), pSalary(salary), pName(name) {}
	Player(const Player& player) {
		pId = player.pId;
		pNumber = player.pNumber;
		pSite = player.pSite;
		pSalary = player.pSalary;
		pName = player.pName;
	}
};

class Country {
public:

	string name;
	Player player[11];

	Country(){}
	Country(string name){
		this->name = name;
	}
	Country(const Country & c){
		for (int i = 0; i < 11; i++) {
			player[i] = c.player[i];
		}
		name = c.name;
	}
	bool operator ==(Country other) {
		if (name == other.name) return true;
		return false;
	}
};
