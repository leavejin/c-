#include "main.h"

void menu1() {//��ʼ�˵� 
	printf("{------------------------------------------}\n");
	color(9);
	printf("|           ��ӭ�����꿨�Ϳ���԰           |\n");
	printf("|                                          |\n");
	color(10);
	printf("|            *1.ע��                       |\n");
	color(12);
	printf("|            *2.�û�����                   |\n");
	color(13);
	printf("|            *3.�������                   |\n");
	color(14);
	printf("|            *0.�˳�ϵͳ                   |\n");
	printf("|                                          |\n");
	printf("{------------------------------------------}\n");
}

void menu2() {//����Ա�˵� 
	printf("{------------------------------------------}\n");
	color(9);
	printf("|           ��ӭ��������Ա�˵�             |\n");
	printf("|                                          |\n");
	color(10);
	printf("|            *1.����                       |\n");
	color(12);
	printf("|            *2.ɾ��                       |\n");
	color(11);
	printf("|            *0.�˳�����Աҳ��             |\n");
	printf("|                                          |\n");
	printf("{------------------------------------------}\n");
}

void menu3() {//�û��˵� 
	printf("{------------------------------------------}\n");
	color(9);
	printf("|           ��ӭ�����û��˵�               |\n");
	printf("|                                          |\n");
	color(12);
	printf("|            *1.�鿴�鼮                   |\n");
	color(10);
	printf("|            *2.��Ҫ����                   |\n");
	color(12);
	printf("|            *3.��Ҫ����                   |\n");
	color(13);
	printf("|            *4.�����˺���                 |\n");
	color(9);
	printf("|            *5.��������                   |\n");
	color(12);
	printf("|            *0.�˳���¼                   |\n");
	printf("|                                          |\n");
	printf("{------------------------------------------}\n");
}
void menu4(){
	printf("{------------------------------------------}\n");
	color(9);
	printf("|           ��������Ĳ��ҷ�ʽ             |\n");
	printf("|                                          |\n");
	color(12);
	printf("|            *1.����������                 |\n");
	color(10);
	printf("|            *2.�����߲���                 |\n");
	color(12);
	printf("|            *3.�鿴����                   |\n");
	color(12);
	printf("|            *0.������һ��                 |\n");
	printf("|                                          |\n");
	printf("{------------------------------------------}\n");
} 
void menu() {//��ʼ�˵�
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
					//ע�� 
					break;
				case 2 :
					//�û����� 
					user_login() ;
					break;
				case 3 :
					//����Ա���� 
					admin_login();
					break;
			}
		}
} 
void reg(){//ע�� 
	char sql[1024]={0};
	char reg_user[30],reg_pwd[30];
	printf("{---------------�������û���---------------}\n");
	scanf("%s",reg_user) ;
	printf("{---------------����������  ---------------}\n");
	scanf("%s",reg_pwd) ;	
	sprintf(sql,"insert into user(username,password) values('%s','%s')",reg_user,reg_pwd);
	if(executeNonQuery(sql)){
		color(10); 
		printf("{------------��ϲ�㣡��ע��ɹ����� ---------------}\n") ; 
	}else{
		color(12);
		printf("{------------ע��ʧ�ܣ�������ע�� ---------------}\n") ; 
	}
	system("pause");
	system("cls");
}

char* is_login(){
	//дһ����֤�˺������Ƿ���ȷ�ĺ��� 
	//��ȷ�Ż�1 ����Ż�0 
	char s_user[30],s_pwd[30];
	printf("{---------------�������û���---------------}\n");
	scanf("%s",s_user) ;
	printf("{---------------����������  ---------------}\n");
	scanf("%s",s_pwd) ;	
	//�������ݿ��ѯ ��ȷ�Ż�1 ����Ż�0 
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
	//��ͨ�û���¼
	strcpy(log_un,is_login());
	if(strcmp(log_un,"")!=0) {
		printf("{-------------��¼�ɹ�����-------------}\n");
		system("pause");
		//��¼�ɹ� ������ͨ�û�����
		int input=1;
		while(input) {
			system("cls");
			menu3();
			scanf("%d",&input);
			switch(input) {
				case 0 :
					strcpy(log_un,"");
					break;
				case 1 ://�鿴�鼮
					//print_books();
					check();					 
					break;
				case 2 ://����
					bor_book();					 
					break;
				case 3 ://����
					ret_book();					 
					break;
				case 4 ://�����˺��� 
					ud_username();				
					break;
				case 5 ://�������� 
					ud_pwd() ;
					break;
			}
			system("pause");
		}
	} else {
		color(12);
		printf("{----------�˺�����������δע��----------}\n");
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
				//������������	
				check_name();						 
					break;
				case 2 :
				//�������߲���	
				check_author();			 
					break;
				case 3 ://�鿴���� 
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
	printf("{--------------��������Ҫ���ҵ��鼮����-------------}\n");
	scanf("%s",s_name);
	char sql[1024]={0};
	sprintf(sql,"select id,`name`,author,`status`from book where `name`='%s' ",s_name);
	MYSQL_RES *res = executeQuery(sql);
	MYSQL_ROW row;
	printf("%-100s\n","{-------------------------------------------------------------------------------------------------------------}");
	printf("|");printf("%-10s\t%-30s\t%-30s\t%-30s","�鼮id","�鼮����","����","�鼮�Ƿ񱻽���");printf("|\n");
	int i=2;
	while(row=mysql_fetch_row(res)){
		strcpy(name,row[1]);
		strcpy(author,row[2]);
		strcpy(status,(strcmp(row[3],"0")==0)?"�ѱ�����":"�ɽ���");	
		strcpy(id,row[0]);
		color(i++);
		printf("|");printf("%-10s\t%-30s\t%-30s\t%-30s",id,name,author,status);printf("|\n");
	}
	printf("%-100s\n","{-------------------------------------------------------------------------------------------------------------}");printf("\n");
} 
void check_author(){
	char name[30],author[30],status[30],id[30],s_name[30];	
	printf("{--------------�������鼮����������-------------}\n");
	scanf("%s",s_name);
	char sql[1024]={0};
	sprintf(sql,"select id,`name`,author,`status`from book where `author`='%s' ",s_name);
	MYSQL_RES *res = executeQuery(sql);
	MYSQL_ROW row;
	printf("%-100s\n","{-------------------------------------------------------------------------------------------------------------}");
	printf("|");printf("%-10s\t%-30s\t%-30s\t%-30s","�鼮id","�鼮����","����","�鼮�Ƿ񱻽���");printf("|\n");
	int i=2;
	while(row=mysql_fetch_row(res)){
		strcpy(name,row[1]);
		strcpy(author,row[2]);
		strcpy(status,(strcmp(row[3],"0")==0)?"�ѱ�����":"�ɽ���");	
		strcpy(id,row[0]);
		color(i++);
		printf("|");printf("%-10s\t%-30s\t%-30s\t%-30s",id,name,author,status);printf("|\n");
	}
	printf("%-100s\n","{-------------------------------------------------------------------------------------------------------------}");printf("\n");
} 
void print_books() {
	//��ӡ�鼮 	
	char name[30],author[30],status[30],id[30];	
	MYSQL_RES *res = executeQuery("select id,`name`,author,`status`from book");
	MYSQL_ROW row;
	printf("%-100s\n","{-------------------------------------------------------------------------------------------------------------}");
	printf("|");printf("%-10s\t%-30s\t%-30s\t%-30s","�鼮id","�鼮����","����","�鼮�Ƿ񱻽���");printf("|\n");
	int i=2;
	while(row=mysql_fetch_row(res)){
		strcpy(name,row[1]);
		strcpy(author,row[2]);
		strcpy(status,(strcmp(row[3],"0")==0)?"�ѱ�����":"�ɽ���");	
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
		printf("{-----------�鼮Ϊ��-----------}\n");
		system("pause");
		return ;
	}
	}
	char name[30],author[30],status[30],id[30];
	MYSQL_RES *res = executeQuery("select id,`name`,author from book where `status`=1");
	MYSQL_ROW row;
	printf("%-70s\n","{-----------------------------------------------------------------------------}");
	printf("|");printf("%-10s\t%-30s\t%-30s","�鼮id","�鼮����","����");printf("|\n");
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
	printf("{-----------������Ҫ���ĵ��鼮id-----------}\n");
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
		printf("{-----------����ʧ�ܣ������ڸ��鱾-----------}\n");
		system("pause");
		return ;
	}
	}
	
	sprintf(sql,"UPDATE book SET `status` =0,username='%s',dt=now() WHERE `status` =1 and id=%s",log_un,s_book);
	if(executeNonQuery(sql)){
		color(10); 
		printf("{-----------------����ɹ�-------------------}\n");
	}else{
		color(12); 
		printf("{-------------����ʧ�ܣ������½���-------------}\n");
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
		printf("{-----------��δ�����鱾-----------}\n");
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
	//printf("�鼮id\t�鼮����\t����\t����ʱ��\n");
	printf("%-100s\n","{-------------------------------------------------------------------------------------------------------------}");
	printf("|");
	printf("%-10s\t%-30s\t%-30s\t%-30s","�鼮id","�鼮����","����","����ʱ��");
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
	printf("{-----------������Ҫ�黹���鼮id-----------}\n");
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
		printf("{-----------����ʧ�ܣ������ڸ��鱾-----------}\n");
		system("pause");
		return ;
	}
	}
	
	sprintf(sql,"UPDATE book SET `status` =1,username='test',dt=now() WHERE `status` =0 and id=%s",s_book);
	if(executeNonQuery(sql)){
		color(10); 
		printf("{-----------------����ɹ�-------------------}\n");
	}else{
		color(12); 
		printf("{-------------����ʧ�ܣ������»���-------------}\n");
	}
}
void ud_username() {
	//�����˺�
	char s_username[30]; 
	char sql[1024]={0};
	printf("{-----------������Ҫ���ĵ��˺���-----------}\n");
	scanf("%s",s_username);
	sprintf(sql,"UPDATE user set username='%s' where username='%s'",s_username,log_un);
	if(executeNonQuery(sql)){
		color(10); 
		printf("{-----------------���ĳɹ�-------------------}\n");
		strcpy(log_un,s_username); 
	}else{
		color(12); 
		printf("{-------------����ʧ�ܣ������¸���-------------}\n");
	}
	system("pause");
}
void ud_pwd() {
	//�����û������� 
	char s_pwd[30]; 
	char sql[1024]={0};
	printf("{-----------������Ҫ���ĵ�����-----------}\n");
	scanf("%s",s_pwd);
	sprintf(sql,"UPDATE user set password='%s' where username='%s'",s_pwd,log_un);
	if(executeNonQuery(sql)){
		color(10); 
		printf("{-----------------���ĳɹ�-------------------}\n");
	}else{
		color(12); 
		printf("{-------------����ʧ�ܣ������¸���-------------}\n");
	}
	system("pause");
}
 
void admin_login() {
	//����Ա��¼ 
	strcpy(log_un,is_login());
	if(strcmp(log_un,"")!=0) {
		//�ж��Ƿ�Ϊ����Ա(admin�Ƿ�Ϊ1) �����ӡ���ǹ���Ա Ȼ���˳�
		 if(!is_admin()){
		 	printf("�㲻�ǹ���Ա\n");system("pause");return;
		 }
		printf("{-------------��¼�ɹ�����-------------}\n");
		system("pause");
		//system("cls");
		//��¼�ɹ� ������ͨ�û�����
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
					//���� 
					add_book();
					break;
				case 2 :
					//ɾ�� 
					del_book(); 
					break;
			}
		}
	} else {
		color(12);
		printf("{----------�˺�����������δע��----------}\n");
		system("pause");
	}
	system("cls");
}
int is_admin(){//�ж��Ƿ�Ϊ����Ա �ǵĻ�����1 ����0
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
	printf("{-----------������Ҫ�����鼮������-----------}\n");
	scanf("%s",s_name);
	printf("{-----------������Ҫ�����鼮������-----------}\n");
	scanf("%s",s_author);
	sprintf(sql,"select * from book where name='%s'",s_name);
	MYSQL_RES *res = executeQuery(sql);
	MYSQL_ROW row;
	while(row=mysql_fetch_row(res)){
		i=1;
	}
	if(i){
		color(12);
		printf("{-----------�鼮�Ѿ�����-----------}\n");
		system("pause"); 
		return ;
	}
	sprintf(sql,"insert into book(`name`,author) values('%s','%s')",s_name,s_author);
	if(executeNonQuery(sql)){
		color(10); 
		printf("{-----------------����ɹ�-------------------}\n");
	}else{
		color(12); 
		printf("{-------------����ʧ�ܣ������¼���-------------}\n");
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
		printf("{-----------�鼮Ϊ��-----------}\n");
		system("pause");
		return ;
	}
	}
	////
	print_books();
	char s_id[30],s_author[30];
	char sql[1024]={0};
	printf("{-----------������Ҫɾ�����鱾id-----------}\n");
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
		printf("{-----------ɾ��ʧ�ܣ������ڸ��鱾-----------}\n");
		system("pause");
		return ;
	}
	}
	
	sprintf(sql,"delete from book where id=%s ",s_id);
	if(executeNonQuery(sql)){
		color(10); 
		printf("{-----------------ɾ���ɹ�-------------------}\n");
	}else{
		color(12); 
		printf("{-------------ɾ��ʧ�ܣ�������ɾ��-------------}\n");
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
	printf("  {------------------�꿨�Ϳ�ͼ�����ϵͳ2.0  by leavejinx----------------------------}                                 \n ");
	printf("                          \n");
	color(12);
	printf("  {-----------------------����Ա�˺� -u test -p 123456--------------------------------}                           \n");
	printf("                               \n");
	color(9);
	printf("  {-------------------------------��ӭ���ʹ��----------------------------------------}                             \n");
		color(5);
	printf("  {------------------------- ף��  ������ζ �ı�����----------------------------------}                                                 \n");
	system("pause");
} 
int color(int c) {//�ı���ɫ�ĺ���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
	return 0;
}

int executeNonQuery(char *sql)//�ǲ�ѯ��� 
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
	printf("ִ�гɹ�\n");
	i=1;
	goto exit;
error:
	i=0;
	printf("ִ�г��� %s\n",mysql_error(pConn));
exit:
mysql_close(pConn); 
return i;
} 

MYSQL_RES *executeQuery(char *sql)//��ѯ��� 
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
	printf("ִ�г��� %s\n",mysql_error(pConn));
exit:
mysql_close(pConn); 
}

