
struct book {
	char id[100];  
	char name[100];
	char isbor[100];
} ;

struct user {
	char user[100];
	char pwd[100];
	char admin[100];
} ;

typedef struct _register {
	struct user data;
	struct _register *next;
} Register;

typedef struct _book {
	struct book data;
	struct _book *next;
} Book;

typedef struct _list {
	Register* uhead; 
	Register* utail; 
	Book* bhead;
	Book* btail;	
} List;

void create(List *list);     // 建立表头 
void scanf_user_data(List *list); // 读入用户数据 
void make_user_data(List *list,struct user data); //末尾处理加入用户数据 
void scanf_book_data(List *list);// 读入图书数据 
void make_book_data(List *list,struct book data);//末尾处理加入图书数据
Book *search_book(Book *p, char *id); //找到指定id书籍 
void del_book(List *list) ;//删除指定id的书本 
void del_user(List *list);// 删除用户 
void bor_book(List *list); //借阅对应id的书本 
void ret_book(List *list); //还指定id的书本 
void printf_user(List *list);//打印用户表 
void printf_book(List *list);//打印图书表 
int  if_admin(List *list); //判断是否为管理员 
void login(List *list);//查看登录账号密码是否正确
Register *ret_userpace(List * p ,char *data) ;//返回用户名所在位置 
void change_pwd(List *list,char *p);
void admin_menu(List *list);//管理员菜单 
void savefile_book( List *list);//保存图书数据 
void readfile_book(List *list);//读取图书数据 
void savefile_user( List *list);
void readfile_user(List *list);
void printf1();//打印初始菜单
void printf2();//打印管理员菜单
void printf3();//打印普通用户菜单 
int color(int c); 
void printf_end();
