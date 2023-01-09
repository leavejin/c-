#pragma once
using namespace std;
template<typename T>
struct QNode
{
	T data;
	struct QNode<T>* next;
};

template<typename T>
struct LinkQueueNode {
	QNode<T>* front;
	QNode<T>* rear;
	LinkQueueNode() {
		rear = new QNode<T>;
		front = rear;
		front->next = NULL;		
	}
};

template<typename T>
class LinkQueue {

public:
	//void InitQueue();
	//��� 
	bool EnQueue(LinkQueueNode<T>& Q, T e);
	//����
	bool DeQueue(LinkQueueNode<T>& Q, T& e);
	//ȡ��ͷԪ��
	T GetHead(LinkQueueNode<T> Q);

	bool is_emp(LinkQueueNode<T>& Q);

	bool InitQueue(LinkQueueNode<T>& Q) {
		Q.rear = new QNode<T>;
		Q.front = Q.rear;
		Q.front->next = NULL;
		return true;
	}
};

//��� 
template<typename T>
bool LinkQueue<T>::EnQueue(LinkQueueNode<T>& Q, T e) {
	QNode<T>* p = new QNode<T>;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return true;
}
//����
template<typename T>
bool LinkQueue<T>::DeQueue(LinkQueueNode<T>& Q, T& e) {
	if (Q.front == Q.rear) return false;
	QNode<T>* p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	delete p;
	return true;
}
//ȡ��ͷԪ��
template<typename T>
T LinkQueue<T>::GetHead(LinkQueueNode<T> Q) {
	if (Q.front == Q.rear) return NULL;
	return Q.front->next->data;
}
template<typename T>
bool LinkQueue<T>::is_emp(LinkQueueNode<T>& Q) {
	if (Q.front == Q.rear) return false;
	return true;

}
