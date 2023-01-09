#pragma once

#include "User.h"
#include "LinkList.h"
#include "LinkQueue.h"

template <typename T>
struct AVLNode {
	int depth; //��ȣ��������ÿ��������ȣ�ͨ����ȵıȽϿɵó��Ƿ�ƽ��
	T value; //���ֵ
	AVLNode<T>* lchild;
	AVLNode<T>* rchild;
	AVLNode<T>():lchild(NULL),rchild(NULL),depth(1) {}
};

template <typename T>
class AVLTree {
public:
	//������
	void Insert(AVLNode<T>*& t, T &x);
	//ɾ�����
	bool Delete(AVLNode<T>*& t, T x);
	//�����Ƿ���ڸ���ֵ�Ľ��
	bool Contains(AVLNode<T>* t,  T &x);
	bool changeT(AVLNode<T>* t, T& x);
	//�������
	void InorderTraversal(AVLNode<T>* t);
	//ǰ�����
	void PreorderTraversal(AVLNode<T>* t);
	//��α���
	LNode<T>* LevelTraversal(AVLNode<T>* t);
	//��Сֵ���
	AVLNode<T>* FindMin(AVLNode<T>* t) const;
	//���ֵ���
	AVLNode<T>* FindMax(AVLNode<T>* t) const;
private:
	int getDepth(AVLNode<T>* t);
	//����ת ��
	AVLNode<T>* LL(AVLNode<T>* t);
	//����ת ��
	AVLNode<T>* RR(AVLNode<T>* t);
	//˫��ת ����
	AVLNode<T>* LR(AVLNode<T>* t);
	//˫��ת ����
	AVLNode<T>* RL(AVLNode<T>* t);
};

template <typename T>
bool changeT(AVLNode<T>* t, T& x) {


}
template <typename T>

int AVLTree<T>::getDepth(AVLNode<T>* t) {
	if (!t) return -1;
	return t->depth;
}

template <typename T>
AVLNode<T>* AVLTree<T>::LL(AVLNode<T>* t) {
	AVLNode<T>* p = t->lchild;
	t->lchild = p->rchild;
	p->rchild = t;
	//	t = p;
	t->depth = max(getDepth(t->lchild), getDepth(t->rchild)) + 1;
	p->depth = max(getDepth(p->lchild), getDepth(p->rchild)) + 1;
	return p;
}

template <typename T>
AVLNode<T>* AVLTree<T>::RR(AVLNode<T>* t) {
	AVLNode<T>* p = t->rchild;
	t->rchild = p->lchild;
	p->lchild = t;
	//	t = p;
	t->depth = max(getDepth(t->lchild), getDepth(t->rchild)) + 1;
	p->depth = max(getDepth(p->lchild), getDepth(p->rchild)) + 1;
	return p;
}

template <typename T>
AVLNode<T>* AVLTree<T>::LR(AVLNode<T>* t) {
	RR(t->lchild);
	return LL(t);
}

template <typename T>
AVLNode<T>* AVLTree<T>::RL(AVLNode<T>* t) {
	LL(t->rchild);
	return RR(t);
}
//������ 
template <typename T>
void AVLTree<T>::Insert(AVLNode<T>*& t, T& x) {
	if (t == NULL) {
		t = new AVLNode<T>;
		t->value = x;
	}
	else if (x < t->value) {
		AVLTree<T>::Insert(t->lchild, x);
		if (getDepth(t->lchild) - getDepth(t->rchild) > 1) {
			if (x < t->lchild->value) t = LL(t);
			else t = LR(t);
		}
	}
	else if (x > t->value) {
		AVLTree<T>::Insert(t->rchild, x);
		if (getDepth(t->rchild) - getDepth(t->lchild) > 1) {
			if (x > t->rchild->value) t = RR(t);
			else t = RL(t);
		}
	}
	else {
		t->value = x;
	}
	t->depth = max(getDepth(t->lchild), getDepth(t->rchild)) + 1;
	//cout << "-------" << "  " << t->depth<<"----" << endl;
}
//ɾ�� 
template <typename T>
bool AVLTree<T>::Delete(AVLNode<T>* &t, T x) {
	if (!t) return false;
	else if (t->value == x) {
		if (t->lchild && t->rchild) {	
			if(getDepth(t->lchild) > getDepth(t->rchild) ){
				//cout << FindMax(t->lchild)->value << endl;
				t->value = FindMax(t->lchild)->value;		
				Delete(t->lchild, t->value);
			}
			else {
				t->value = FindMax(t->rchild)->value;
				Delete(t->rchild, t->value);
			}
		}
		else {
			AVLNode<T>* p = t;
			t = t->lchild ? t->lchild : t->rchild;
			delete p;
		}
	}
	else if (x < t->value) {
		Delete(t->lchild, x);
		if (getDepth(t->rchild) - getDepth(t->lchild) > 1) {
			if (getDepth(t->rchild->rchild) > getDepth(t->rchild->lchild)) {
				t = RR(t);
			}
			else {
				t = RL(t);
			}
		}
		else {
			t->depth = max(getDepth(t->lchild), getDepth(t->rchild));
		}
	}
	else if(x > t->value) {
		Delete(t->rchild, x);
		if (getDepth(t->lchild) - getDepth(t->rchild) > 1) {
			if (getDepth(t->lchild->lchild) > getDepth(t->lchild->rchild)) {
				t = LL(t);
			}
			else {
				t = LR(t);
			}
		}
		else {
			t->depth = max(getDepth(t->lchild), getDepth(t->rchild)) + 1;
		}
	}else {
		
	}

	return true;
}
//���ҽ�� 
template <typename T>
bool AVLTree<T>::Contains(AVLNode<T>* t, T &x) {
	if (!t) return false;
	if (x < t->value) return Contains(t->lchild, x);
	else if (x > t->value) return Contains(t->rchild, x);
	else if (x == t->value) {
		x = t->value;
		return true;		
	}
	return false;
}

//�������
template <typename T>
void AVLTree<T>::InorderTraversal(AVLNode<T>* t) {
	if (t) {
		InorderTraversal(t->lchild);
		cout << t->value << endl;
		InorderTraversal(t->rchild);
	}
}
//ǰ�����
template <typename T>
void AVLTree<T>::PreorderTraversal(AVLNode<T>* t) {
	if (t) {
		cout << t->value << endl;
		InorderTraversal(t->lchild);
		InorderTraversal(t->rchild);
	}
}
//��α���
template <typename T>
LNode<T>* AVLTree<T>::LevelTraversal(AVLNode<T>* t) {
	LNode<T>* L = NULL;
	LinkList<T> linklist;
	linklist.InitList(L);
	LinkQueue<AVLNode<T> > linkqueue;
	LinkQueueNode<AVLNode<T> > Q;
	//linkqueue.InitQueue(Q);
	//AVLTree<T> t;
	linkqueue.EnQueue(Q, *t);//
	int i = 1;
	while (linkqueue.is_emp(Q)) {
		AVLNode<T> e;
		linkqueue.DeQueue(Q, e);
		linklist.ListInsert(L, i, e.value);
		i++;
		if (e.lchild) linkqueue.EnQueue(Q, *e.lchild);
		if (e.rchild) linkqueue.EnQueue(Q, *e.rchild);
	}
	return L;
}
//���ֵ���
template <typename T>
AVLNode<T>* AVLTree<T>::FindMax(AVLNode<T>* t)const {
	if (!t) return NULL;
	if (!t->rchild) return t;
	return FindMax(t->rchild);
}

//��Сֵ���
template <typename T>
AVLNode<T>* AVLTree<T>::FindMin(AVLNode<T>* t)const {
	if (!t) return NULL;
	if (!t->lchild) return t;
	return FindMin(t->lchild);
}
