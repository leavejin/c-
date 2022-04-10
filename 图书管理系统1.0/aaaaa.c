#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include<windows.h>
void create(List *list) {
	list->uhead = (Register*)malloc(sizeof(Register));
	list->bhead = (Book*)malloc(sizeof(Book));
	list->uhead->next =NULL;
	strcpy(list->uhead->data.user  , "cx");
	strcpy(list->uhead->data.pwd   , "cx");
	strcpy(list->uhead->data.admin , "ͼ�����Ա");
	list->bhead->next =NULL;
	list->btail = list->bhead;
	list->utail = list->uhead;
}//����ͷ�ڵ�
void scanf_user_data(List *list) {
	struct user scanf_data;
again: 
	system("cls");
	printf(">>>������Ҫע����û���<<<\n");
	scanf("%s",scanf_data.user);
	getchar();
	if(ret_userpace(list,scanf_data.user)) {
		printf(">>>�û����Ѿ�����<<<\n");
		printf(">>>�Ƿ�Ҫ����ע���û�y/n<<<\n");
	    if(getchar()=='y') goto again;
	    else return;
	}
	//system("cls");
	printf(">>>������ע�������<<<\n");
	scanf("%s",scanf_data.pwd);
	getchar();
	strcpy(scanf_data.admin,"��ͨ�û�");
	make_user_data(list,scanf_data);
	printf(">>>ע��ɹ���ף��������ζ���ı�����<<<\n");
	printf(">>>�Ƿ�Ҫ����ע���û�y/n<<<\n");
	if(getchar()=='y') goto again;
	system("pause");
	system("cls");
}// ע���û�����
void make_user_data(List *list,struct user data) {
	Register *p=(Register *)malloc(sizeof(Register));
	p->data = data;
	p->next = NULL;
	//list->uhead->next = p;
	list->utail->next =p;
	list->utail =p;
}//ĩβ��������û�����

void scanf_book_data(List *list) {
	struct book scanf_data;
	again:
	system("cls");
	printf(">>>������Ҫ��ŵ��鼮���id<<<\n");
	scanf("%s",scanf_data.id);
	getchar();
	if(search_book(list->bhead,scanf_data.id)) {
		printf(">>>�鼮id�Ѵ���<<<\n");
		printf(">>>�Ƿ�Ҫ��������鼮y/n<<<\n");
	    if(getchar()=='y') goto again;
	    else return;
	}
	//system("cls");
	printf("������Ҫ��ŵ�����\n");
	scanf("%s",scanf_data.name);
	getchar();
	strcpy(scanf_data.isbor,"���Խ���");
	make_book_data(list,scanf_data);
	printf(">>>�Ƿ�Ҫ��������鼮y/n<<<\n");
	if(getchar()=='y') goto again;
}// ����ͼ������
void make_book_data(List *list,struct book data) {
	Book *p=(Book *)malloc(sizeof(Book));
	p->data = data;
	p->next = NULL;
	list->btail->next =p;
	list->btail =p;
	//&*list->bhead->next = p;
}//ĩβ�������ͼ������
Book *search_book(Book *p, char *id) {
	p=p->next;
	while(p) {
		if(strcmp(p->data.id,id)==0) {
			break;
		}
		p=p->next;
	}
	return p;
}//�ҵ���Ӧid���鱾 û�ҵ����� NULL
Register *search_user(List * p , struct user data) {
	Register *w= p->uhead;
	while(w) {
		if(strcmp(w->data.user,data.user)==0 &&strcmp(w->data.pwd,data.pwd)==0) {
			break;
		}
		w = w->next;
	}
	return w;
}//�ж��û��������Ƿ���ȷ
Register *ret_userpace(List * p ,char *data) {
	Register *w= p->uhead;
	while(w) {
		if(strcmp(w->data.user,data)==0) {
			break;
		}
		w = w->next;
	}
	return w;
}//�����û�����λ��
void del_book(List *list) {
again:
	system("cls");
	printf_book(list);
	Book *q = list->bhead;
	Book *p = list->bhead->next;
	char scanf_id[100];
	printf(">>>������Ҫɾ�����鱾id<<<\n");
	scanf("%s",scanf_id);
	getchar();
	while(p) {
		if(strcmp(p->data.id,scanf_id)==0) {
			q->next=p->next;
			free(p);
			printf(">>>ɾ���ɹ���<<<\n");
			break;
		}
		q=p;
		p=p->next;
	}
	if(!p) {
		printf(">>>û���ҵ�ָ�����鼮<<<\n");
	}
	printf(">>>�Ƿ�Ҫ����ɾ���û�y/n<<<\n");
	if(getchar()=='y') goto again;
	system("pause");
}//ɾ��ָ��id���鱾
void del_user(List *list) {
again:
	system("cls");
	printf_user(list);
	Register *q = list->uhead;
	Register *p = list->uhead->next;
	char scanf_username[100];
	//system("cls");
	printf(">>>������Ҫɾ�����û���<<<\n");
	scanf("%s",scanf_username);
	getchar();
	while(p) {
		if(strcmp(p->data.user,scanf_username)==0) {
			q->next=p->next;
			free(p);
			printf(">>>ɾ���ɹ�����<<<\n");
			break;
		}
		q=p;
		p=p->next;
	}
	if(!p) {
		printf(">>>�Ҳ���Ҫɾ�����û�<<<\n");
	}
	printf(">>>�Ƿ�Ҫ����ɾ���û�y/n<<<\n");
	if(getchar()=='y') goto again;
	system("pause");
}//ɾ��ָ�����Ƶ��û�
void bor_book(List *list) {
again:
	system("cls");
	char scanf_id[100];
	Book *p;
	Register *w;
	printf_book(list);
	//system("color 3");
	printf(">>>������Ҫ���ĵ��鱾id<<<\n");
	scanf("%s",scanf_id);
	getchar();
	p=search_book(list->bhead,scanf_id);
	if(p) {
		if(strcmp(p->data.isbor,"�ѱ�����")==0) {
			printf(">>>��Ҫ���ĵ��鼮�ѱ�����<<<\n");
		} else {
			strcpy(p->data.isbor,"�ѱ�����");
			printf(">>>����ɹ�<<<\n");
			printf_book(list);
		}
	} else {
		printf(">>>û�ҵ��鼮<<<\n");
	}
	printf(">>>�Ƿ�Ҫ��������y/n<<<\n");
	if(getchar()=='y') goto again;
	system("pause");
	system("cls");
}  //���Ķ�Ӧid���鱾
void ret_book(List *list) {
again:
	system("cls");
	char scanf_id[100];
	Book *p;
	printf_book(list);
	printf(">>>��������Ҫ�����鱾id<<<\n");
	scanf("%s",scanf_id);
	getchar();
	p=search_book(list->bhead,scanf_id);
	if(p) {
		if(strcmp(p->data.isbor,"���Խ���")==0) {
			printf(">>>����δ������<<<\n");
			//system("pause");
			//return;
		} else {
			strcpy(p->data.isbor,"���Խ���");
			printf(">>>���ѳɹ��黹����<<<\n");
		}
	} else {
		printf(">>>û�ҵ��鼮<<<\n");
	}
	printf(">>>�Ƿ�Ҫ�����黹y/n<<<\n");
	if(getchar()=='y') goto again;
	system("pause");
} //����
void printf_user(List *list) {
	int i=2;
	Register *p = list->uhead->next;
	printf("%-90s\n","{---------------------------------------------------------------------------------------------}");
	printf("|");
	printf("%-30s\t%-30s\t%-30s","�û���","�û�������","�û�Ȩ��");
	printf("|\n");
	while(p) {
		color(i++);
		printf("|");
		printf("%-30s\t%-30s\t%-30s",p->data.user,p->data.pwd,p->data.admin);
		printf("|\n");
		p=p->next;
	}
	printf("%-90s\n","{---------------------------------------------------------------------------------------------}");
	printf("\n");
}//��ӡ�û���
void printf_book(List *list) {
	int i=2;
	Book *p = list->bhead->next;
	printf("%-90s\n","{---------------------------------------------------------------------------------------------}");
	printf("|");
	printf("%-30s\t%-30s\t%-30s","�鼮id","�鼮����","�鼮�Ƿ񱻽���");
	printf("|\n");
	while(p) {
		color(i++);
		printf("|");
		printf("%-30s\t%-30s\t%-30s",p->data.id,p->data.name,p->data.isbor);
		printf("|\n");
		p=p->next;
	}
	printf("%-90s\n","{---------------------------------------------------------------------------------------------}");
	printf("\n");
}//��ӡͼ���
int if_admin(List *list) {
	system("cls");
	struct user scanf_admin;
	int ret=0;
	printf(">>>�������û�����<<<\n");
	scanf("%s",scanf_admin.user) ;
	printf(">>>���������룺<<<\n");
	scanf("%s",scanf_admin.pwd) ;
	Register *p = list->uhead;
	if(search_user(list,scanf_admin)) {
		while(p) {
			if(strcmp(p->data.admin,"ͼ�����Ա")==0) {
				ret=1;
				break;
			}
			p=p->next;
		}
	}
	return ret;
}//�ж��Ƿ�Ϊ����Ա
void add_admin(List *list) {
again:
	system("cls");
	printf_user(list);
	char adduser[100];
	Register * p;
	printf(">>>������Ҫ��ӹ���ԱȨ�޵��û���<<<\n");
	scanf("%s",adduser);
	getchar();
	p=ret_userpace(list,adduser);
	if(p) strcpy(p->data.admin,"ͼ�����Ա");
	else {
		system("color 5");
		printf(">>>�Ҳ���ָ���û�\n<<<");
	}
	printf(">>>�Ƿ�Ҫ�������y/n<<<\n");
	if(getchar()=='y') goto again;
	system("pause");
	system("cls");
}//��ӹ���Ա
void login(List *list) {
	struct user scanf_user;
	Register *p;
	int f;
	//system("color 3");
	system("cls");
	printf(">>>�������û�����<<<\n");
	scanf("%s",scanf_user.user) ;
	//system("cls");
	printf(">>>���������룺<<<\n");
	scanf("%s",scanf_user.pwd) ;
	p=search_user(list,scanf_user);
	if(p) {
		printf(">>>��¼�ɹ�<<<\n");
		system("pause");
		//system("cls");
		//��¼�ɹ� ������ͨ�û�����
		int input=1;
		while(input) {
			system("cls");
			printf3();
			scanf("%d",&input);
			switch(input) {
				case 0 :
					break;
				case 1 :
					bor_book(list);
					break;
				case 2 :
					ret_book(list);
					break;
				case 3 :
					change_pwd(list,scanf_user.user);
					break;
			}
			if(input==0) break;	//�û�����0�˳�
		}
	} else {
		color(12);
		printf(">>>�˺�����������δע��<<<\n");
		system("pause");
		system("cls");
	}
}//�鿴��¼�˺������Ƿ���ȷ

void change_pwd(List *list,char *p) {
	Register *q;
	char change_input[100];
	q=ret_userpace(list,p);
	system("cls");
	//system("color 3");
	printf(">>>��������ĺ������<<<\n");
	scanf("%s",change_input);
	strcpy(q->data.pwd,change_input);
	printf(">>>���ĳɹ�<<<\n");
	system("pause");
	system("cls");
}//��������
void bor_record (List*list,char *p) {

}//��ʷ����
void admin_menu(List *list) {
	system("cls");
	int admin_input=1;
	char input_del_id[100];
	while(admin_input) {
		printf2();
		scanf("%d",&admin_input);
		switch(admin_input) {
			case 0:
				system("cls");
				break;
				system("cls");
			case 1:
				system("cls");
				scanf_book_data(list);
				system("cls");
				break;
			case 2:
				system("cls");
				del_book(list);
				system("cls");
				break;
			case 3:
				system("cls");
				del_user(list);
				system("cls");
				break;
			case 4:
				system("cls");
				add_admin(list);
				system("cls");
				break;

		}
	}
}
void printf1() {
	printf("{------------------------------------------}\n");
	color(9);
	printf("|           ��ӭ��������ͼ��֮��           |\n");
	printf("|                                          |\n");
	color(10);
	printf("|            *1.ע��                       |\n");
	color(12);
	printf("|            *2.��¼����                   |\n");
	color(13);
	printf("|            *3.�������                   |\n");
	color(14);
	printf("|            *0.�˳�ϵͳ                   |\n");
	printf("|                                          |\n");
	printf("{------------------------------------------}\n");
}
void printf2() {
	printf("{------------------------------------------}\n");
	color(9);
	printf("|           ��ӭ��������Ա�˵�             |\n");
	printf("|                                          |\n");
	color(10);
	printf("|            *1.����                       |\n");
	color(12);
	printf("|            *2.ɾ��                       |\n");
	color(13);
	printf("|            *3.ɾ���û�                   |\n");
	color(14);
	printf("|            *4.��ӹ���Ա                 |\n");
	color(11);
	printf("|            *0.�˳�����Աҳ��             |\n");
	printf("|                                          |\n");
	printf("{------------------------------------------}\n");
}
void printf3() {
	printf("{------------------------------------------}\n");
	color(9);
	printf("|           ��ӭ�����û��˵�               |\n");
	printf("|                                          |\n");
	color(10);
	printf("|            *1.����                       |\n");
	color(12);
	printf("|            *2.����                       |\n");
	color(13);
	printf("|            *3.�޸�����                   |\n");
	color(14);
	printf("|            *0.�˳���¼                   |\n");
	printf("|                                          |\n");
	printf("{------------------------------------------}\n");
}
void savefile_book( List *list) {
	FILE*fp = fopen("book.txt", "w");
	Book*p = list->bhead->next;
	while (p != NULL) {
		fprintf(fp, "%s\t%s\t%s\n", p->data.id, p->data.name, p->data.isbor);
		p = p->next;
	}

	fclose(fp);
	fp = NULL;
}//����Ԫ��㱣��ͼ������
void readfile_book(List *list) {
	FILE*fp = fopen("book.txt", "r");
	if (fp == NULL) {
		//�������ļ��򴴽�
		fp = fopen("book.txt", "w+");
	}
	struct book p;
	while (fscanf(fp, "%s\t%s\t%s\n", p.id, p.name, p.isbor) != EOF) {
		Book * r= (Book *)malloc(sizeof(Book));
		r->data = p;
		r->next = NULL;
		list->btail->next =r;
		list->btail =r;
	}
	fclose(fp);
	fp = NULL;
}//��ȡͼ������
void savefile_user( List *list) {
	FILE*fp = fopen("user.txt", "w");
	Register *p = list->uhead->next;
	while (p != NULL) {
		fprintf(fp, "%s\t%s\t%s\n", p->data.user, p->data.pwd, p->data.admin);
		p = p->next;
	}
	fclose(fp);
	fp = NULL;
}//�����û�����
void readfile_user(List *list) {
	FILE*fp = fopen("user.txt", "r");
	if (fp == NULL) {
		//�������ļ��򴴽�
		fp = fopen("user.txt", "w+");
	}
	struct user p;
	while (fscanf(fp, "%s\t%s\t%s\n", p.user, p.pwd, p.admin) != EOF) {
		Register * r= (Register *)malloc(sizeof(Register));
		r->data = p;
		r->next = NULL;
		list->utail->next =r;
		list->utail =r;
	}
	fclose(fp);
	fp = NULL;
}//��ȡ�û�����
int color(int c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
	return 0;//�ı���ɫ�ĺ���

}
void printf_end(){
	color(5);
	printf("                ף��  ������ζ �ı�����                                    \n");
	color(9);
	printf("             __/\\__         _   _________     _                           \n");
	printf("          __/      \\__     | | |_______  \\___| |                         \n");
	printf("        _/  ________  \\_   | |         | |_____|                          \n");
	printf("        \\_ /        \\ _/   | |_________| |______                         \n");
	printf("         _|__________|_    | |_________   ______|                          \n");
	printf("        |______        |   | |______   | |  __                             \n");
	printf("              /       /    | |____  |   \\ \\/ /                           \n");
	printf("             /       /     | |    | |    \\ \\/                            \n ");
	printf("           /_____  /      | |    | |   / \\ \\                             \n");
	printf("         __/_____  /____   | |    | |   | |\\ \\__                         \n");
	printf("        |_______________|  | |    | |   | | \\_  |                         \n");
	printf("         _______________   | |    | |   | |   | |                          \n");
	printf("        |_______________|  |_|    |_|   |_|   |_|                          \n");
	printf("                                                                           \n");
	printf("                                                                           \n");	
}
