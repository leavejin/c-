#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	//system("color 3E");
	List list;
	create(&list);
	readfile_book(&list);
	readfile_user(&list);
	int input=1,if_login=0,inadmin=0; //用户输入 用于循环
	while(input) {
		system("cls"); 
		printf1();
		scanf("%d",&input);	
		switch(input) {
			case 0 :
				break;
			case 1 :
				scanf_user_data(&list);
				break;
			case 2 :
				login(&list);
				break;
			case 3 :
				if(!if_admin(&list)) {
					printf(">>>请使用管理员账号登录<<<\n");
					system("pause");
					system("cls");				 
					break;
				}
					admin_menu(&list);
					break; 
			default :printf(">>>输入错误，请重新输入<<<\n");
					system("pause");break;
		}
		if(input==0) break;	//用户输入0退出
	}
	savefile_book(&list);
	savefile_user(&list);
	printf_end();
	system("pause"); 
	return 0;	
}


