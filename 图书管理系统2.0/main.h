#include <winsock.h>
#include <mysql.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
char log_un[30];
MYSQL_RES *executeQuery(char *sql);//��ѯ��� 
int executeNonQuery(char *sql);//�ǲ�ѯ��� 
int color(int c);//��ɫ
void menu1();//��ʼ�˵� 
void menu2();//����Ա�˵� 
void menu3();//�û��˵�
void menu();//��ʼ�˵�
void user_login();//��ͨ�û���¼  
void admin_login();//����Ա��¼ 
void printf_end();//����У�� 
void reg();//ע�� 
char* is_login();//��֤�Ƿ�ע��
void print_books();//�鿴�鼮  
void bor_book();//���� 
void ud_pwd();//��������
void ud_username();//�����˺�����
void del_book();//ɾ�� 
void menu4();//ѯ�ʲ��ҷ�ʽ�Ĳ˵�
void check();//�û�������ҷ�ʽ 
void check_author();//�������߲���
void check_name();//������������ 
void by_leavejinx();
