#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
	system("cls");
	system("color 3");
	printf("�������û���\n");
	scanf("%s",scanf_data.user);
	if(ret_userpace(list,scanf_data.user)){
		printf("�û����Ѿ�����\n");
		return;
	}
	system("cls");
	printf("����������\n");
	scanf("%s",scanf_data.pwd);
	strcpy(scanf_data.admin,"��ͨ�û�");
	make_user_data(list,scanf_data);
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
	system("cls");
	printf("�������鱾���\n");
	scanf("%s",scanf_data.id);
	system("cls");
	printf("����������\n");
	scanf("%s",scanf_data.name);
	strcpy(scanf_data.isbor,"���Խ���");
	make_book_data(list,scanf_data);

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
	printf_book(list);
	Book *q = list->bhead;
	Book *p = list->bhead->next;
	char scanf_id[100];
	system("cls");
	printf("������Ҫɾ�����鱾id\n");
	scanf("%s",scanf_id);
	while(p) {
		if(strcmp(p->data.id,scanf_id)==0) {
			q->next=p->next;
			free(p);
			break;
		}
		q=p;
		p=p->next;
	}
	if(!p) 
	{
	system("color 5");
	printf("û���ҵ�ָ�����鼮\n");
	}
}//ɾ��ָ��id���鱾
void del_user(List *list) {
	printf_user(list);
	Register *q = list->uhead;
	Register *p = list->uhead->next;
	char scanf_username[100];
	system("cls");
	printf("������Ҫɾ�����û���\n");
	scanf("%s",scanf_username);
	while(p) {
		if(strcmp(p->data.user,scanf_username)==0) {
			q->next=p->next;
			free(p);
			break;
		}
		q=p;
		p=p->next;
	}
	if(!p) 
	{system("color 5");
	printf("�Ҳ���ָ���û�\n");
	}
}//ɾ��ָ�����Ƶ��û�
void bor_book(List *list) {
	char scanf_id[100];
	Book *p;
	Register *w;
	printf_book(list);
	system("color 3");
	printf("������Ҫ���ĵ��鱾id\n");
	scanf("%s",scanf_id);
	p=search_book(list->bhead,scanf_id);
	if(p) {
		if(strcmp(p->data.isbor,"�ѱ�����")==0) {
			system("color 5");
			printf("��Ҫ���ĵ��鼮�ѱ�����\n");
			return;
		}
		strcpy(p->data.isbor,"�ѱ�����");
	} else 
	{
		system("color 5");
		printf("û�ҵ��鼮\n");
	}
}  //���Ķ�Ӧid���鱾
void ret_book(List *list) {
	char scanf_id[100];
	Book *p;
	printf_book(list);
	system("color 3");
	printf("������Ҫ�����鱾id\n");
	scanf("%s",scanf_id);
	p=search_book(list->bhead,scanf_id);
	if(strcmp(p->data.isbor,"���Խ���")==0) {
		system("color 5");
		printf("��û�н��Ĵ���\n");
		return;
	}
	if(p) {
		strcpy(p->data.isbor,"���Խ���");
		system("color 3");
		printf("���ѳɹ�����\n");
	} else
	{
	system("color 5");
	printf("û�ҵ��鼮\n");
	} 

} //����
void printf_user(List *list) {
	Register *p = list->uhead->next;
	printf("%-90s\n","**************************************************************************************************************");
	printf("%-30s\t%-30s\t%-30s\n\n","�û���","�û�������","�Ƿ�Ϊͼ�����Ա");
	while(p) {
		printf("%-30s\t%-30s\t%-30s\n",p->data.user,p->data.pwd,p->data.admin);
		p=p->next;
	}
	printf("%-90s\n","**************************************************************************************************************");
	printf("\n");
}//��ӡ�û���
void printf_book(List *list) {
	Book *p = list->bhead->next;
	printf("%-90s\n","^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	printf("%-30s\t%-30s\t%-30s\n\n","�鼮id","�鼮����","�鼮�Ƿ񱻽���");
	while(p) {
		printf("%-30s\t%-30s\t%-30s\n",p->data.id,p->data.name,p->data.isbor);
		p=p->next;
	}
	printf("%-90s\n","**************************************************************************************************************");
	printf("\n");
}//��ӡͼ���
int if_admin(List *list) {
	struct user scanf_admin;
	int ret=0;
	printf("�û�����\n");
	scanf("%s",scanf_admin.user) ;
	printf("���룺\n");
	scanf("%s",scanf_admin.pwd) ;
	system("pause");
	system("cls");
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
	printf_user(list);
	char adduser[100];
	Register * p;
	system("cls");
	printf("����Ҫ��ӹ���ԱȨ�޵��û���\n");
	scanf("%s",adduser);
	p=ret_userpace(list,adduser);
	if(p) strcpy(p->data.admin,"ͼ�����Ա");
	else 
	{system("color 5");
	printf("�Ҳ���ָ���û�\n");
	}
}//��ӹ���Ա
void login(List *list) {
	struct user scanf_user;
	Register *p;
	int f;
	system("color 3");
	system("cls");
	printf("�û�����\n");
	scanf("%s",scanf_user.user) ;
	system("cls");
	printf("���룺\n");
	scanf("%s",scanf_user.pwd) ;
	p=search_user(list,scanf_user);
	if(p) {
		printf("��¼�ɹ�\n");
		system("pause");
	    system("cls");
		//��¼�ɹ� ������ͨ�û�����
		int input=1;
		while(input) {
			printf("1.����\n2.����\n3.�޸�����\n0.�˳���¼\n");
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
		system("color 5");
		printf("�˺�����������δע��\n");
	}
}//�鿴��¼�˺������Ƿ���ȷ

void change_pwd(List *list,char *p) {
	Register *q;
	char change_input[100];
	q=ret_userpace(list,p);
	system("cls");
	system("color 3");
	printf("��������ĺ������\n");
	scanf("%s",change_input);
	strcpy(q->data.pwd,change_input);
	printf("���ĳɹ�\n");
	system("pause");
	system("cls");
}//��������
void bor_record (List*list,char *p) {

}//��ʷ����
void admin_menu(List *list) {
	int admin_input=1;
	char input_del_id[100];
	while(admin_input) {
		printf("1.����\n2.ɾ��\n3.ɾ���û�\n4.��ӹ���Ա\n0.�˳�����Աҳ��\n");
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
