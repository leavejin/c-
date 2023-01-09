#ifndef AMGRAPH_H
#define AMGRAPH_H

#include "Country.h"

#define MVNum 40
#define OK 1
#define ERROR 0

typedef Country ElemType;

typedef struct ArcNode {
	int adjvex;
	int weight;
	ArcNode* nextarc;
}ArcNode;

typedef struct VNode {
	ElemType  data;
	ArcNode* firstarc;
	VNode() :firstarc(NULL){}
	VNode(ElemType value) :firstarc(NULL),data(value){}
	VNode(const VNode& v) {
		data = v.data;
	}
}VNode, AdjList[MVNum];

class AMGraph {

public:
	AdjList vertices;
	int vexnum;
	int arcnum;
	bool visited[MVNum];
	AMGraph(){ InitGraph();}
	//~AMGraph() {delete vertices;}
	//��ʼ��
	void InitGraph();
	//
	void DestroyGraph();
	//����u��ͼ�е�λ��
	int LocateVex(VNode u);
	//����v��ֵ ����u
	void GetVex(VNode v, VNode& u);
	//��v��ֵvalue
	void PutVex(VNode v, ElemType value);
	//���ص�һ���ڽӵ�
	ArcNode* FirstAdjVex(VNode v);
	//����w���һ���ڽӵ�
	ArcNode* NextAdjVex(VNode v, ArcNode w);
	//��ͼ�����v
	void InsertVex(VNode v);
	//��ͼ��ɾ��v
	void DeleteVex(VNode v);
	//��ӱ�
	void InsertArc(VNode v, VNode w, int weight);
	//ɾ����
	void DeleteArc(VNode v, VNode w);
	//�����������
	void DFSTraverse(int v, User& user);
	//�����������
	void BFSTraverse(int v);

	int LocateVex(string u);
	void InsertArc(string v1, string w1, int weight);
	void game(int v, User & user);
};

void AMGraph::InitGraph() {
	this->arcnum = this->vexnum = 0;
}

void AMGraph::DestroyGraph() {
	//	free(G);
}
int AMGraph::LocateVex(string u) {
	for (int i = 0; i < this->vexnum; i++) {
		if (this->vertices[i].data.name == u) return i;
	}
	return -1;
}
int AMGraph::LocateVex(VNode u) {
	for (int i = 0; i < this->vexnum; i++) {
		if (this->vertices[i].data.name == u.data.name) return i;
	}
	return -1;
}

void AMGraph::GetVex(VNode v, VNode& u) {

	for (int i = 0; i < this->vexnum; i++) {
		if (this->vertices[i].data == v.data) u.data = this->vertices[i].data;
	}

}
void AMGraph::PutVex(VNode v, ElemType value) {

	int i = this->LocateVex(v);
	//string name = value.name;
	this->vertices[i].data = value;
}

ArcNode* AMGraph::FirstAdjVex(VNode v) {

	int i = this->LocateVex(v);
	return this->vertices[i].firstarc;
}
ArcNode* AMGraph::NextAdjVex(VNode v, ArcNode w) {

	int i = this->LocateVex(v);
	ArcNode* p = this->vertices[i].firstarc;
	while (p->adjvex != w.adjvex) {
		p = p->nextarc;
	}
	p = p->nextarc;
	return p;
}

void AMGraph::InsertVex(VNode v) {

	if (this->vexnum == MVNum) return;

	this->vertices[this->vexnum] = v;
	this->vexnum++;
}
void AMGraph::DeleteVex(VNode v) {

	
}
void AMGraph::InsertArc(VNode v, VNode w, int weight) {
	int i = this->LocateVex(v);
	int j = this->LocateVex(w);
	ArcNode* p1 = new ArcNode;
	p1->adjvex = j;
	//weight
	p1->weight = weight;
	p1->nextarc = this->vertices[i].firstarc;
	this->vertices[i].firstarc = p1;
	this->arcnum++;
}
void AMGraph::InsertArc(string v1, string w1, int weight) {
	/*VNode v(v1);
	VNode w(w1);*/
	int i = this->LocateVex(v1);
	int j = this->LocateVex(w1);
	ArcNode* p1 = new ArcNode;
	p1->adjvex = j;
	//weight
	p1->weight = weight;
	p1->nextarc = this->vertices[i].firstarc;
	this->vertices[i].firstarc = p1;
	this->arcnum++;
}
//void DeleteArc(AMGraph &G, VNode v, VNode w);

void AMGraph::DFSTraverse(int v, User& user) {
	//cout << v << ": " << this->vertices[v].data.name << endl;
	visited[v] = true;
	ArcNode* p = this->vertices[v].firstarc;

	while (p) {
		//�˴������ս��Ϣ

		cout << "-------------------------" << endl;
		cout << this->vertices[v].data.name << "\t" << "vs" << "\t"<< this->vertices[p->adjvex].data.name << endl;
 		cout << "��������ʤ����һ��" << endl;
		int choise;
		cin >> choise;
		cout << this->vertices[v].data.name << "\t" << p->weight << "\t" << this->vertices[p->adjvex].data.name << endl;	
		if (choise > 0 && p->weight > 0) {
			cout << "��¶���" << endl;
			user.money += 10;
			cout << "��ǰ����ʽ�Ϊ�� " << user.money << endl;
		}
		else if (choise < 0 && p->weight < 0) {
			cout << "��¶���" << endl;
			user.money += 10;
			cout << "��ǰ����ʽ�Ϊ�� " << user.money << endl;
		}
		else if (choise == 0 && p->weight == 0) {
			cout << "��¶���" << endl;
			user.money += 10;
			cout << "��ǰ����ʽ�Ϊ�� " << user.money << endl;
		}
		else {
			cout << "no��������´�����" << endl;
			user.money -= 10;
			cout << "��ǰ����ʽ�Ϊ�� " << user.money << endl;
		}
		cout << "-------------------------" << endl;

		int w = p->adjvex;
		if (!visited[w]) {
			
			this->DFSTraverse(w,user);
		}
		p = p->nextarc;
	}
	delete p;

}
void AMGraph::game(int v,User& user) {
	DFSTraverse(v,user);//bool visited[MVNum];
	for (int i = 0; i < MVNum; i++) {
		visited[i] = false;
	}
}
//void BFSTraverse(AMGraph G);

#endif