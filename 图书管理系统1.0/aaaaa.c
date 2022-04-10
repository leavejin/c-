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
	strcpy(list->uhead->data.admin , "图书管理员");
	list->bhead->next =NULL;
	list->btail = list->bhead;
	list->utail = list->uhead;
}//建立头节点
void scanf_user_data(List *list) {
	struct user scanf_data;
again: 
	system("cls");
	printf(">>>请输入要注册的用户名<<<\n");
	scanf("%s",scanf_data.user);
	getchar();
	if(ret_userpace(list,scanf_data.user)) {
		printf(">>>用户名已经存在<<<\n");
		printf(">>>是否要继续注册用户y/n<<<\n");
	    if(getchar()=='y') goto again;
	    else return;
	}
	//system("cls");
	printf(">>>请输入注册的密码<<<\n");
	scanf("%s",scanf_data.pwd);
	getchar();
	strcpy(scanf_data.admin,"普通用户");
	make_user_data(list,scanf_data);
	printf(">>>注册成功。祝你韵中有味，文笔留香<<<\n");
	printf(">>>是否要继续注册用户y/n<<<\n");
	if(getchar()=='y') goto again;
	system("pause");
	system("cls");
}// 注册用户数据
void make_user_data(List *list,struct user data) {
	Register *p=(Register *)malloc(sizeof(Register));
	p->data = data;
	p->next = NULL;
	//list->uhead->next = p;
	list->utail->next =p;
	list->utail =p;
}//末尾处理加入用户数据

void scanf_book_data(List *list) {
	struct book scanf_data;
	again:
	system("cls");
	printf(">>>请输入要存放的书籍编号id<<<\n");
	scanf("%s",scanf_data.id);
	getchar();
	if(search_book(list->bhead,scanf_data.id)) {
		printf(">>>书籍id已存在<<<\n");
		printf(">>>是否要继续存放书籍y/n<<<\n");
	    if(getchar()=='y') goto again;
	    else return;
	}
	//system("cls");
	printf("请输入要存放的书名\n");
	scanf("%s",scanf_data.name);
	getchar();
	strcpy(scanf_data.isbor,"可以借阅");
	make_book_data(list,scanf_data);
	printf(">>>是否要继续存放书籍y/n<<<\n");
	if(getchar()=='y') goto again;
}// 读入图书数据
void make_book_data(List *list,struct book data) {
	Book *p=(Book *)malloc(sizeof(Book));
	p->data = data;
	p->next = NULL;
	list->btail->next =p;
	list->btail =p;
	//&*list->bhead->next = p;
}//末尾处理加入图书数据
Book *search_book(Book *p, char *id) {
	p=p->next;
	while(p) {
		if(strcmp(p->data.id,id)==0) {
			break;
		}
		p=p->next;
	}
	return p;
}//找到对应id的书本 没找到返回 NULL
Register *search_user(List * p , struct user data) {
	Register *w= p->uhead;
	while(w) {
		if(strcmp(w->data.user,data.user)==0 &&strcmp(w->data.pwd,data.pwd)==0) {
			break;
		}
		w = w->next;
	}
	return w;
}//判断用户名密码是否正确
Register *ret_userpace(List * p ,char *data) {
	Register *w= p->uhead;
	while(w) {
		if(strcmp(w->data.user,data)==0) {
			break;
		}
		w = w->next;
	}
	return w;
}//返回用户所在位置
void del_book(List *list) {
again:
	system("cls");
	printf_book(list);
	Book *q = list->bhead;
	Book *p = list->bhead->next;
	char scanf_id[100];
	printf(">>>请输入要删除的书本id<<<\n");
	scanf("%s",scanf_id);
	getchar();
	while(p) {
		if(strcmp(p->data.id,scanf_id)==0) {
			q->next=p->next;
			free(p);
			printf(">>>删除成功！<<<\n");
			break;
		}
		q=p;
		p=p->next;
	}
	if(!p) {
		printf(">>>没有找到指定的书籍<<<\n");
	}
	printf(">>>是否要继续删除用户y/n<<<\n");
	if(getchar()=='y') goto again;
	system("pause");
}//删除指定id的书本
void del_user(List *list) {
again:
	system("cls");
	printf_user(list);
	Register *q = list->uhead;
	Register *p = list->uhead->next;
	char scanf_username[100];
	//system("cls");
	printf(">>>请输入要删除的用户名<<<\n");
	scanf("%s",scanf_username);
	getchar();
	while(p) {
		if(strcmp(p->data.user,scanf_username)==0) {
			q->next=p->next;
			free(p);
			printf(">>>删除成功！！<<<\n");
			break;
		}
		q=p;
		p=p->next;
	}
	if(!p) {
		printf(">>>找不到要删除的用户<<<\n");
	}
	printf(">>>是否要继续删除用户y/n<<<\n");
	if(getchar()=='y') goto again;
	system("pause");
}//删除指定名称的用户
void bor_book(List *list) {
again:
	system("cls");
	char scanf_id[100];
	Book *p;
	Register *w;
	printf_book(list);
	//system("color 3");
	printf(">>>请输入要借阅的书本id<<<\n");
	scanf("%s",scanf_id);
	getchar();
	p=search_book(list->bhead,scanf_id);
	if(p) {
		if(strcmp(p->data.isbor,"已被借阅")==0) {
			printf(">>>你要借阅的书籍已被借阅<<<\n");
		} else {
			strcpy(p->data.isbor,"已被借阅");
			printf(">>>借书成功<<<\n");
			printf_book(list);
		}
	} else {
		printf(">>>没找到书籍<<<\n");
	}
	printf(">>>是否要继续借阅y/n<<<\n");
	if(getchar()=='y') goto again;
	system("pause");
	system("cls");
}  //借阅对应id的书本
void ret_book(List *list) {
again:
	system("cls");
	char scanf_id[100];
	Book *p;
	printf_book(list);
	printf(">>>请输入你要还的书本id<<<\n");
	scanf("%s",scanf_id);
	getchar();
	p=search_book(list->bhead,scanf_id);
	if(p) {
		if(strcmp(p->data.isbor,"可以借阅")==0) {
			printf(">>>该书未被借阅<<<\n");
			//system("pause");
			//return;
		} else {
			strcpy(p->data.isbor,"可以借阅");
			printf(">>>你已成功归还此书<<<\n");
		}
	} else {
		printf(">>>没找到书籍<<<\n");
	}
	printf(">>>是否要继续归还y/n<<<\n");
	if(getchar()=='y') goto again;
	system("pause");
} //还书
void printf_user(List *list) {
	int i=2;
	Register *p = list->uhead->next;
	printf("%-90s\n","{---------------------------------------------------------------------------------------------}");
	printf("|");
	printf("%-30s\t%-30s\t%-30s","用户名","用户名密码","用户权限");
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
}//打印用户表
void printf_book(List *list) {
	int i=2;
	Book *p = list->bhead->next;
	printf("%-90s\n","{---------------------------------------------------------------------------------------------}");
	printf("|");
	printf("%-30s\t%-30s\t%-30s","书籍id","书籍名称","书籍是否被借阅");
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
}//打印图书表
int if_admin(List *list) {
	system("cls");
	struct user scanf_admin;
	int ret=0;
	printf(">>>请输入用户名：<<<\n");
	scanf("%s",scanf_admin.user) ;
	printf(">>>请输入密码：<<<\n");
	scanf("%s",scanf_admin.pwd) ;
	Register *p = list->uhead;
	if(search_user(list,scanf_admin)) {
		while(p) {
			if(strcmp(p->data.admin,"图书管理员")==0) {
				ret=1;
				break;
			}
			p=p->next;
		}
	}
	return ret;
}//判断是否为管理员
void add_admin(List *list) {
again:
	system("cls");
	printf_user(list);
	char adduser[100];
	Register * p;
	printf(">>>请输入要添加管理员权限的用户名<<<\n");
	scanf("%s",adduser);
	getchar();
	p=ret_userpace(list,adduser);
	if(p) strcpy(p->data.admin,"图书管理员");
	else {
		system("color 5");
		printf(">>>找不到指定用户\n<<<");
	}
	printf(">>>是否要继续添加y/n<<<\n");
	if(getchar()=='y') goto again;
	system("pause");
	system("cls");
}//添加管理员
void login(List *list) {
	struct user scanf_user;
	Register *p;
	int f;
	//system("color 3");
	system("cls");
	printf(">>>请输入用户名：<<<\n");
	scanf("%s",scanf_user.user) ;
	//system("cls");
	printf(">>>请输入密码：<<<\n");
	scanf("%s",scanf_user.pwd) ;
	p=search_user(list,scanf_user);
	if(p) {
		printf(">>>登录成功<<<\n");
		system("pause");
		//system("cls");
		//登录成功 进入普通用户界面
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
			if(input==0) break;	//用户输入0退出
		}
	} else {
		color(12);
		printf(">>>账号密码错误或者未注册<<<\n");
		system("pause");
		system("cls");
	}
}//查看登录账号密码是否正确

void change_pwd(List *list,char *p) {
	Register *q;
	char change_input[100];
	q=ret_userpace(list,p);
	system("cls");
	//system("color 3");
	printf(">>>请输入更改后的密码<<<\n");
	scanf("%s",change_input);
	strcpy(q->data.pwd,change_input);
	printf(">>>更改成功<<<\n");
	system("pause");
	system("cls");
}//更改密码
void bor_record (List*list,char *p) {

}//历史借阅
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
	printf("|           欢迎来到至诚图书之家           |\n");
	printf("|                                          |\n");
	color(10);
	printf("|            *1.注册                       |\n");
	color(12);
	printf("|            *2.登录界面                   |\n");
	color(13);
	printf("|            *3.管理界面                   |\n");
	color(14);
	printf("|            *0.退出系统                   |\n");
	printf("|                                          |\n");
	printf("{------------------------------------------}\n");
}
void printf2() {
	printf("{------------------------------------------}\n");
	color(9);
	printf("|           欢迎来到管理员菜单             |\n");
	printf("|                                          |\n");
	color(10);
	printf("|            *1.加书                       |\n");
	color(12);
	printf("|            *2.删书                       |\n");
	color(13);
	printf("|            *3.删除用户                   |\n");
	color(14);
	printf("|            *4.添加管理员                 |\n");
	color(11);
	printf("|            *0.退出管理员页面             |\n");
	printf("|                                          |\n");
	printf("{------------------------------------------}\n");
}
void printf3() {
	printf("{------------------------------------------}\n");
	color(9);
	printf("|           欢迎来到用户菜单               |\n");
	printf("|                                          |\n");
	color(10);
	printf("|            *1.借书                       |\n");
	color(12);
	printf("|            *2.还书                       |\n");
	color(13);
	printf("|            *3.修改密码                   |\n");
	color(14);
	printf("|            *0.退出登录                   |\n");
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
}//从首元结点保存图书数据
void readfile_book(List *list) {
	FILE*fp = fopen("book.txt", "r");
	if (fp == NULL) {
		//不存在文件则创建
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
}//读取图书数据
void savefile_user( List *list) {
	FILE*fp = fopen("user.txt", "w");
	Register *p = list->uhead->next;
	while (p != NULL) {
		fprintf(fp, "%s\t%s\t%s\n", p->data.user, p->data.pwd, p->data.admin);
		p = p->next;
	}
	fclose(fp);
	fp = NULL;
}//保存用户数据
void readfile_user(List *list) {
	FILE*fp = fopen("user.txt", "r");
	if (fp == NULL) {
		//不存在文件则创建
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
}//读取用户数据
int color(int c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
	return 0;//改变颜色的函数

}
void printf_end(){
	color(5);
	printf("                祝你  韵中有味 文笔留香                                    \n");
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
