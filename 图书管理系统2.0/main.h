#include <winsock.h>
#include <mysql.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
char log_un[30];
MYSQL_RES *executeQuery(char *sql);//查询语句 
int executeNonQuery(char *sql);//非查询语句 
int color(int c);//颜色
void menu1();//开始菜单 
void menu2();//管理员菜单 
void menu3();//用户菜单
void menu();//开始菜单
void user_login();//普通用户登录  
void admin_login();//管理员登录 
void printf_end();//至诚校徽 
void reg();//注册 
char* is_login();//验证是否注册
void print_books();//查看书籍  
void bor_book();//借书 
void ud_pwd();//更改密码
void ud_username();//更改账号名字
void del_book();//删书 
void menu4();//询问查找方式的菜单
void check();//用户输入查找方式 
void check_author();//按照作者查找
void check_name();//按照书名查找 
void by_leavejinx();
