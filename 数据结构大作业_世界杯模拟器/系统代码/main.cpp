#include "eventManager.h"


menuManager m;

int main() {
	
	m.one_level();

	return 0;
}










































//int main() {
//
//	AMGraph G;
//	Country c1("c1");
//	Country c2("c2");
//	Country c3("c3");
//	Country c4("c4");
//	VNode v1(c1);
//	VNode v2(c2);
//	VNode v3(c3);
//	VNode v4(c4);
//	G.InsertVex(v1);
//	G.InsertVex(v2);
//	G.InsertVex(v3);
//	G.InsertVex(v4);
//	G.InsertArc(v1, v2, 1);
//	G.InsertArc(v1, v3, 2);
//	G.InsertArc(v1, v4, 3);
//	G.InsertArc(v2, v3, 4);
//	G.InsertArc(v2, v4, 5);
//	G.InsertArc(v3, v4, 6);
//
//	G.DFSTraverse(0);
//	return 0;
//}

//int main() {
//	User a("jack", "hah", 1.3);
//	User b("leave", "nan", 18.8);
//	User c("xixi", "nv", 12.8);
//	User d("aaa", "nan", 11.8);
//
//	AVLNode<User>* T = new AVLNode<User>;
//	AVLTree<User> A;
//	T->value = a;
//	A.Insert(T, b);
//	A.Insert(T, c);
//	A.Insert(T, d);
//	User f("leave", "nan", 18.8);
//	int tt = A.Contains(T, f);
//	//LNode<T>* LevelTraversal(AVLNode<T>*t);
//	LNode<User>* list = A.LevelTraversal(T);
//	LNode<User>* p = list->next;
//	while (p) {
//		cout << p->data << endl;
//		p = p->next;
//	}
//	cout << tt;
//	//A.InorderTraversal(T);
//	return 0;
//}

