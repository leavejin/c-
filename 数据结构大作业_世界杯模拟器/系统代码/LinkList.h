#pragma once
using namespace std;


template <typename T>
struct LNode {
	T data;
	struct LNode* next;
};

template <typename T>
class LinkList {
public:
	//��ʼ�� 
	bool InitList(LNode<T>*& L);
	//ȡֵ
	bool GetElem(LNode<T>* L, int i, T& e);
	//����
	LNode<T>* LocateElem(LNode<T>* L, T e);
	//���� 
	bool ListInsert(LNode<T>*& L, int i, T e);
	//ɾ��
	bool  ListDelete(LNode<T>*& L, int i);

};


template <typename T>
bool LinkList<T>::InitList(LNode<T>*& L) {
	L = new LNode<T>;
	L->next = NULL;
	return true;
}
//ȡֵ
template <typename T>
bool LinkList<T>::GetElem(LNode<T>* L, int i, T& e) {
	LNode<T>* p = L->next;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) return false;
	e = p->data;
	return true;
}
//����
template <typename T>
LNode<T>* LinkList<T>::LocateElem(LNode<T>* L, T e) {
	LNode<T>* p = L->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p;
}
//���� 
template <typename T>
bool LinkList<T>::ListInsert(LNode<T>*& L, int i, T e) {
	LNode<T>* p = L;
	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return false;
	LNode<T>* s = new LNode<T>;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
//ɾ��
template <typename T>
bool  LinkList<T>::ListDelete(LNode<T>*& L, int i) {
	LNode<T>* p = L;
	int j = 0;
	while (p->next && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1) return false;
	LNode<T>* s = p->next;
	p->next = s->next;
	delete s;
	return true;
}
