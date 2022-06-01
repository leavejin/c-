#include "main.h"

void menu1() {//开始菜单 
	printf("{------------------------------------------}\n");
	color(9);
	printf("|           欢迎来到玛卡巴卡乐园           |\n");
	printf("|                                          |\n");
	color(10);
	printf("|            *1.注册                       |\n");
	color(12);
	printf("|            *2.用户界面                   |\n");
	color(13);
	printf("|            *3.管理界面                   |\n");
	color(14);
	printf("|            *0.退出系统                   |\n");
	printf("|                                          |\n");
	printf("{------------------------------------------}\n");
}

void menu2() {//管理员菜单 
	printf("{------------------------------------------}\n");
	color(9);
	printf("|           欢迎来到管理员菜单             |\n");
	printf("|                                          |\n");
	color(10);
	printf("|            *1.加书                       |\n");
	color(12);
	printf("|            *2.删书                       |\n");
	color(11);
	printf("|            *0.退出管理员页面             |\n");
	printf("|                                          |\n");
	printf("{------------------------------------------}\n");
}

void menu3() {//用户菜单 
	printf("{------------------------------------------}\n");
	color(9);
	printf("|           欢迎来到用户菜单               |\n");
	printf("|                                          |\n");
	color(12);
	printf("|            *1.查看书籍                   |\n");
	color(10);
	printf("|            *2.俺要借书                   |\n");
	color(12);
	printf("|            *3.俺要还书                   |\n");
	color(13);
	printf("|            *4.更改账号名                 |\n");
	color(9);
	printf("|            *5.更改密码                   |\n");
	color(12);
	printf("|            *0.退出登录                   |\n");
	printf("|                                          |\n");
	printf("{------------------------------------------}\n");
}
void menu4(){
	printf("{------------------------------------------}\n");
	color(9);
	printf("|           请输入你的查找方式             |\n");
	printf("|                                          |\n");
	color(12);
	printf("|            *1.按书名查找                 |\n");
	color(10);
	printf("|            *2.按作者查找                 |\n");
	color(12);
	printf("|            *3.查看所有                   |\n");
	color(12);
	printf("|            *0.返回上一级                 |\n");
	printf("|                                          |\n");
	printf("{------------------------------------------}\n");
} 
void menu() {//开始菜单
	int input=1;
		while(input) {
			system("cls");
			menu1();
			scanf("%d",&input);
			switch(input) {
				case 0 :
					break;
				case 1 :
					reg(); 
					//注册 
					break;
				case 2 :
					//用户界面 
					user_login() ;
					break;
				case 3 :
					//管理员界面 
					admin_login();
					break;
			}
		}
} 
void reg(){//注册 
	char sql[1024]={0};
	char reg_user[30],reg_pwd[30];
	printf("{---------------请输入用户名---------------}\n");
	scanf("%s",reg_user) ;
	printf("{---------------请输入密码  ---------------}\n");
	scanf("%s",reg_pwd) ;	
	sprintf(sql,"insert into user(username,password) values('%s','%s')",reg_user,reg_pwd);
	if(executeNonQuery(sql)){
		color(10); 
		printf("{------------恭喜你！！注册成功！！ ---------------}\n") ; 
	}else{
		color(12);
		printf("{------------注册失败，请重新注册 ---------------}\n") ; 
	}
	system("pause");
	system("cls");
}

char* is_login(){
	//写一个验证账号密码是否正确的函数 
	//正确放回1 错误放回0 
	char s_user[30],s_pwd[30];
	printf("{---------------请输入用户名---------------}\n");
	scanf("%s",s_user) ;
	printf("{---------------请输入密码  ---------------}\n");
	scanf("%s",s_pwd) ;	
	//带入数据库查询 正确放回1 错误放回0 
	char sql[1024]={0};
	sprintf(sql,"select username from user where username='%s' and `password`='%s' ",s_user,s_pwd);
	char flag[30]={0};
	MYSQL_RES *res = executeQuery(sql);
	MYSQL_ROW row;
	while(row=mysql_fetch_row(res)){
		strcpy(flag,row[0]);
	}
	return flag;
}
void user_login() {
	//普通用户登录
	strcpy(log_un,is_login());
	if(strcmp(log_un,"")!=0) {
		printf("{-------------登录成功！！-------------}\n");
		system("pause");
		//登录成功 进入普通用户界面
		int input=1;
		while(input) {
			system("cls");
			menu3();
			scanf("%d",&input);
			switch(input) {
				case 0 :
					strcpy(log_un,"");
					break;
				case 1 ://查看书籍
					//print_books();
					check();					 
					break;
				case 2 ://借书
					bor_book();					 
					break;
				case 3 ://还书
					ret_book();					 
					break;
				case 4 ://更改账号名 
					ud_username();				
					break;
				case 5 ://更改密码 
					ud_pwd() ;
					break;
			}
			system("pause");
		}
	} else {
		color(12);
		printf("{----------账号密码错误或者未注册----------}\n");
		system("pause");
	}
	system("cls");
}
void check(){
		int input=1;
		while(input) {
			system("cls");
			menu4();
			scanf("%d",&input);
			switch(input) {
				case 1 :
				//按照书名查找	
				check_name();						 
					break;
				case 2 :
				//按照作者查找	
				check_author();			 
					break;
				case 3 ://查看所有 
					print_books();					 
					break;
				case 0 :
					return ;
			}
			system("pause");
		}
	system("cls");
}
void check_name(){
	char name[30],author[30],status[30],id[30],s_name[30];	
	printf("{--------------请输入你要查找的书籍名字-------------}\n");
	scanf("%s",s_name);
	char sql[1024]={0};
	sprintf(sql,"select id,`name`,author,`status`from book where `name`='%s' ",s_name);
	MYSQL_RES *res = executeQuery(sql);
	MYSQL_ROW row;
	printf("%-100s\n","{-------------------------------------------------------------------------------------------------------------}");
	printf("|");printf("%-10s\t%-30s\t%-30s\t%-30s","书籍id","书籍名称","作者","书籍是否被借阅");printf("|\n");
	int i=2;
	while(row=mysql_fetch_row(res)){
		strcpy(name,row[1]);
		strcpy(author,row[2]);
		strcpy(status,(strcmp(row[3],"0")==0)?"已被借阅":"可借阅");	
		strcpy(id,row[0]);
		color(i++);
		printf("|");printf("%-10s\t%-30s\t%-30s\t%-30s",id,name,author,status);printf("|\n");
	}
	printf("%-100s\n","{-------------------------------------------------------------------------------------------------------------}");printf("\n");
} 
void check_author(){
	char name[30],author[30],status[30],id[30],s_name[30];	
	printf("{--------------请输入书籍的作者名字-------------}\n");
	scanf("%s",s_name);
	char sql[1024]={0};
	sprintf(sql,"select id,`name`,author,`status`from book where `author`='%s' ",s_name);
	MYSQL_RES *res = executeQuery(sql);
	MYSQL_ROW row;
	printf("%-100s\n","{-------------------------------------------------------------------------------------------------------------}");
	printf("|");printf("%-10s\t%-30s\t%-30s\t%-30s","书籍id","书籍名称","作者","书籍是否被借阅");printf("|\n");
	int i=2;
	while(row=mysql_fetch_row(res)){
		strcpy(name,row[1]);
		strcpy(author,row[2]);
		strcpy(status,(strcmp(row[3],"0")==0)?"已被借阅":"可借阅");	
		strcpy(id,row[0]);
		color(i++);
		printf("|");printf("%-10s\t%-30s\t%-30s\t%-30s",id,name,author,status);printf("|\n");
	}
	printf("%-100s\n","{-------------------------------------------------------------------------------------------------------------}");printf("\n");
} 
void print_books() {
	//打印书籍 	
	char name[30],author[30],status[30],id[30];	
	MYSQL_RES *res = executeQuery("select id,`name`,author,`status`from book");
	MYSQL_ROW row;
	printf("%-100s\n","{-------------------------------------------------------------------------------------------------------------}");
	printf("|");printf("%-10s\t%-30s\t%-30s\t%-30s","书籍id","书籍名称","作者","书籍是否被借阅");printf("|\n");
	int i=2;
	while(row=mysql_fetch_row(res)){
		strcpy(name,row[1]);
		strcpy(author,row[2]);
		strcpy(status,(strcmp(row[3],"0")==0)?"已被借阅":"可借阅");	
		strcpy(id,row[0]);
		color(i++);
		printf("|");printf("%-10s\t%-30s\t%-30s\t%-30s",id,name,author,status);printf("|\n");
	}
	printf("%-100s\n","{-------------------------------------------------------------------------------------------------------------}");printf("\n");
}
void bor_book() {
	{	
	MYSQL_RES *res = executeQuery("select id,`name`,author,`status`from book");
	MYSQL_ROW row;
	int f=0;
	while(row=mysql_fetch_row(res)){
		f=1;
	}
	if(!f){
		printf("{-----------书籍为空-----------}\n");
		system("pause");
		return ;
	}
	}
	char name[30],author[30],status[30],id[30];
	MYSQL_RES *res = executeQuery("select id,`name`,author from book where `status`=1");
	MYSQL_ROW row;
	printf("%-70s\n","{-----------------------------------------------------------------------------}");
	printf("|");printf("%-10s\t%-30s\t%-30s","书籍id","书籍名称","作者");printf("|\n");
	int i=2;
	while(row=mysql_fetch_row(res)){
		strcpy(name,row[1]);
		strcpy(author,row[2]);
		strcpy(id,row[0]);
		color(i++);
		printf("|");printf("%-10s\t%-30s\t%-30s",id,name,author);printf("|\n");
	}                
	printf("%-70s\n","{-----------------------------------------------------------------------------}");
	//printf("\n");
	char s_book[30];
	char sql[1024]={0};	
	printf("{-----------请输入要借阅的书籍id-----------}\n");
	scanf("%s",s_book) ;
	
	{
	sprintf(sql,"select *from book where id=%s and `status`=1",s_book);
	MYSQL_RES *res = executeQuery(sql);
	MYSQL_ROW row;
	int f=0;
	while(row=mysql_fetch_row(res)){
		f=1;
	}
	if(!f){
		printf("{-----------借阅失败，不存在该书本-----------}\n");
		system("pause");
		return ;
	}
	}
	
	sprintf(sql,"UPDATE book SET `status` =0,username='%s',dt=now() WHERE `status` =1 and id=%s",log_un,s_book);
	if(executeNonQuery(sql)){
		color(10); 
		printf("{-----------------借书成功-------------------}\n");
	}else{
		color(12); 
		printf("{-------------借书失败，请重新借阅-------------}\n");
	}
	//system("pause");
	//system("cls");
}
void ret_book(){
	{	
	char sqli[1024]={0};
	sprintf(sqli,"select id,`name`,author,`status`from book where `username`='%s' ",log_un);
	MYSQL_RES *res = executeQuery(sqli);
	MYSQL_ROW row;
	int f=0;
	while(row=mysql_fetch_row(res)){
		f=1;
	}
	if(!f){
		printf("{-----------你未借阅书本-----------}\n");
		system("pause");
		return ;
	}
	}
	char name[30],author[30],dt[50],id[30];
	//char id[30];
    char sql[1024]={0};
	sprintf(sql,"select id,`name`,author,dt from book where `status`=0 and username='%s' ",log_un);
	MYSQL_RES *res = executeQuery(sql);
	MYSQL_ROW row;
	//printf("书籍id\t书籍名称\t作者\t借阅时间\n");
	printf("%-100s\n","{-------------------------------------------------------------------------------------------------------------}");
	printf("|");
	printf("%-10s\t%-30s\t%-30s\t%-30s","书籍id","书籍名称","作者","借阅时间");
	printf("|\n");
	int i=2;
	while(row=mysql_fetch_row(res)){
		strcpy(name,row[1]);
		strcpy(author,row[2]);
		strcpy(id,row[0]);
		strcpy(dt,row[3]);
		//printf("%s\t%s\t%s\t%s\n",id,name,author,dt);
		color(i++);
		printf("|");
		printf("%-10s\t%-30s\t%-30s\t%-30s",id,name,author,dt);
		printf("|\n");
	}
	printf("%-100s\n","{-------------------------------------------------------------------------------------------------------------}");
	printf("\n");
	char s_book[30];	
	printf("{-----------请输入要归还的书籍id-----------}\n");
	scanf("%s",s_book) ;
	
	{
	sprintf(sql,"select *from book where id=%s",s_book);
	MYSQL_RES *res = executeQuery(sql);
	MYSQL_ROW row;
	int f=0;
	while(row=mysql_fetch_row(res)){
		f=1;
	}
	if(!f){
		printf("{-----------还书失败，不存在该书本-----------}\n");
		system("pause");
		return ;
	}
	}
	
	sprintf(sql,"UPDATE book SET `status` =1,username='test',dt=now() WHERE `status` =0 and id=%s",s_book);
	if(executeNonQuery(sql)){
		color(10); 
		printf("{-----------------还书成功-------------------}\n");
	}else{
		color(12); 
		printf("{-------------还书失败，请重新还书-------------}\n");
	}
}
void ud_username() {
	//更改账号
	char s_username[30]; 
	char sql[1024]={0};
	printf("{-----------请输入要更改的账号名-----------}\n");
	scanf("%s",s_username);
	sprintf(sql,"UPDATE user set username='%s' where username='%s'",s_username,log_un);
	if(executeNonQuery(sql)){
		color(10); 
		printf("{-----------------更改成功-------------------}\n");
		strcpy(log_un,s_username); 
	}else{
		color(12); 
		printf("{-------------更改失败，请重新更改-------------}\n");
	}
	system("pause");
}
void ud_pwd() {
	//更改用户名密码 
	char s_pwd[30]; 
	char sql[1024]={0};
	printf("{-----------请输入要更改的密码-----------}\n");
	scanf("%s",s_pwd);
	sprintf(sql,"UPDATE user set password='%s' where username='%s'",s_pwd,log_un);
	if(executeNonQuery(sql)){
		color(10); 
		printf("{-----------------更改成功-------------------}\n");
	}else{
		color(12); 
		printf("{-------------更改失败，请重新更改-------------}\n");
	}
	system("pause");
}
 
void admin_login() {
	//管理员登录 
	strcpy(log_un,is_login());
	if(strcmp(log_un,"")!=0) {
		//判断是否为管理员(admin是否为1) 否则打印不是管理员 然后退出
		 if(!is_admin()){
		 	printf("你不是管理员\n");system("pause");return;
		 }
		printf("{-------------登录成功！！-------------}\n");
		system("pause");
		//system("cls");
		//登录成功 进入普通用户界面
		int input=1;
		while(input) {
			system("cls");
			menu2();
			scanf("%d",&input);
			switch(input) {
				case 0 :
					strcpy(log_un,"");
					break;
				case 1 :
					//加书 
					add_book();
					break;
				case 2 :
					//删书 
					del_book(); 
					break;
			}
		}
	} else {
		color(12);
		printf("{----------账号密码错误或者未注册----------}\n");
		system("pause");
	}
	system("cls");
}
int is_admin(){//判断是否为管理员 是的话返回1 否则0
	char sql[1024]={0};
	int i=0;
	sprintf(sql,"select * from user where username='%s' and admin= 1",log_un);
	MYSQL_RES *res = executeQuery(sql);
	MYSQL_ROW row;
	while(row=mysql_fetch_row(res)){
		i=1;
	}
	return i;
}
void add_book(){
	char s_name[30],s_author[30];
	char sql[1024]={0};
	int i=0;
	printf("{-----------请输入要加入书籍的名称-----------}\n");
	scanf("%s",s_name);
	printf("{-----------请输入要加入书籍的作者-----------}\n");
	scanf("%s",s_author);
	sprintf(sql,"select * from book where name='%s'",s_name);
	MYSQL_RES *res = executeQuery(sql);
	MYSQL_ROW row;
	while(row=mysql_fetch_row(res)){
		i=1;
	}
	if(i){
		color(12);
		printf("{-----------书籍已经存在-----------}\n");
		system("pause"); 
		return ;
	}
	sprintf(sql,"insert into book(`name`,author) values('%s','%s')",s_name,s_author);
	if(executeNonQuery(sql)){
		color(10); 
		printf("{-----------------加书成功-------------------}\n");
	}else{
		color(12); 
		printf("{-------------加书失败，请重新加入-------------}\n");
	}
	system("pause");
} 
void del_book(){
	////
	{	
	MYSQL_RES *res = executeQuery("select id,`name`,author,`status`from book");
	MYSQL_ROW row;
	int f=0;
	while(row=mysql_fetch_row(res)){
		f=1;
	}
	if(!f){
		printf("{-----------书籍为空-----------}\n");
		system("pause");
		return ;
	}
	}
	////
	print_books();
	char s_id[30],s_author[30];
	char sql[1024]={0};
	printf("{-----------请输入要删除的书本id-----------}\n");
	scanf("%s",s_id);
	
	{
	sprintf(sql,"select *from book where id=%s",s_id);
	MYSQL_RES *res = executeQuery(sql);
	MYSQL_ROW row;
	int f=0;
	while(row=mysql_fetch_row(res)){
		f=1;
	}
	if(!f){
		printf("{-----------删除失败，不存在该书本-----------}\n");
		system("pause");
		return ;
	}
	}
	
	sprintf(sql,"delete from book where id=%s ",s_id);
	if(executeNonQuery(sql)){
		color(10); 
		printf("{-----------------删除成功-------------------}\n");
	}else{
		color(12); 
		printf("{-------------删除失败，请重新删除-------------}\n");
	}
	system("pause");
}
void printf_end(){

	color(9);
	printf("             __/\\__         _   _________     _                           \n");
	printf("          __/      \\__     | | |_______  \\___| |                         \n");
	printf("        _/  ________  \\_   | |         | |_____|                          \n");
	printf("        \\_ /        \\ _/   | |_________| |______                         \n");
	printf("         _|__________|_    | |_________   ______|                          \n");
	printf("        |______        |   | |______   | | __                             \n");
	printf("              /       /    | |____  |  \\ \\/ /                           \n");
	printf("             /       /     | |    | |   \\ \\/                            \n ");
	printf("           /_____  /      | |    | |  / \\ \\                             \n");
	printf("         __/_____  /____   | |    | |  | |\\ \\__                         \n");
	printf("        |_______________|  | |    | |  | | \\_  |                         \n");
	printf("         _______________   | |    | |  | |   | |                          \n");
	printf("        |_______________|  |_|    |_|  |_|   |_|                          \n");
	//printf("                                                                           \n");
	//printf("                                                                           \n");
	//system("pause");	
}
void by_leavejinx(){
	color(5);
	color(9);
	printf("    _                                          _   _                   \n");
	printf("   | |                                        | | |_|                      \n");
	printf("   | |    _____   ______   _     _   _____    | |  _    _____          \n");
	printf("   | |   | ____| |  __  |  \\\\   //  | ____|   | | | |  |  _  | \\  /           \n");
	printf("   | |__ ||____| | |__| |_  \\\\_//   ||____|  _| | | |  | | | |  \\/     \n");
	printf("   |____||_____| |________|  \\_/    |_____| |___| |_|  |_| |_|  /\\         \n");
	printf("                              \n");
	printf("  {------------------玛卡巴卡图书管理系统2.0  by leavejinx----------------------------}                                 \n ");
	printf("                          \n");
	color(12);
	printf("  {-----------------------管理员账号 -u test -p 123456--------------------------------}                           \n");
	printf("                               \n");
	color(9);
	printf("  {-------------------------------欢迎你的使用----------------------------------------}                             \n");
		color(5);
	printf("  {------------------------- 祝你  韵中有味 文笔留香----------------------------------}                                                 \n");
	system("pause");
} 
int color(int c) {//改变颜色的函数
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
	return 0;
}

int executeNonQuery(char *sql)//非查询语句 
{
	int i; 
	MYSQL *pConn = mysql_init(0);
	if(!mysql_real_connect(pConn,"localhost","root","leavejinx","dazuoye",0,0,0)){
		goto error;
	}
	if(mysql_query(pConn,"set names gbk")){
		goto error;
	}
	if(mysql_query(pConn,sql)){
		goto error;
	}
	printf("执行成功\n");
	i=1;
	goto exit;
error:
	i=0;
	printf("执行出错 %s\n",mysql_error(pConn));
exit:
mysql_close(pConn); 
return i;
} 

MYSQL_RES *executeQuery(char *sql)//查询语句 
{
		MYSQL *pConn = mysql_init(0);
	if(!mysql_real_connect(pConn,"localhost","root","leavejinx","dazuoye",0,0,0)){
		goto error;
	}
	if(mysql_query(pConn,"set names gbk")){
		goto error;
	}
	if(mysql_query(pConn,sql)){
		goto error;
	}
	{
		MYSQL_RES *result = mysql_store_result(pConn);
		mysql_close(pConn);
		return result;
	}
	goto exit;
error:
	printf("执行出错 %s\n",mysql_error(pConn));
exit:
mysql_close(pConn); 
}

