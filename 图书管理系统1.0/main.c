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
	int input=1,if_login=0,inadmin=0; //�û����� ����ѭ��
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
					printf(">>>��ʹ�ù���Ա�˺ŵ�¼<<<\n");
					system("pause");
					system("cls");				 
					break;
				}
					admin_menu(&list);
					break; 
			default :printf(">>>�����������������<<<\n");
					system("pause");break;
		}
		if(input==0) break;	//�û�����0�˳�
	}
	savefile_book(&list);
	savefile_user(&list);
	printf_end();
	system("pause"); 
	return 0;	
}


