
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

void create(List *list);     // ������ͷ 
void scanf_user_data(List *list); // �����û����� 
void make_user_data(List *list,struct user data); //ĩβ��������û����� 
void scanf_book_data(List *list);// ����ͼ������ 
void make_book_data(List *list,struct book data);//ĩβ�������ͼ������
Book *search_book(Book *p, char *id); //�ҵ�ָ��id�鼮 
void del_book(List *list) ;//ɾ��ָ��id���鱾 
void del_user(List *list);// ɾ���û� 
void bor_book(List *list); //���Ķ�Ӧid���鱾 
void ret_book(List *list); //��ָ��id���鱾 
void printf_user(List *list);//��ӡ�û��� 
void printf_book(List *list);//��ӡͼ��� 
int  if_admin(List *list); //�ж��Ƿ�Ϊ����Ա 
void login(List *list);//�鿴��¼�˺������Ƿ���ȷ
Register *ret_userpace(List * p ,char *data) ;//�����û�������λ�� 
void change_pwd(List *list,char *p);
void admin_menu(List *list);//����Ա�˵� 
void savefile_book( List *list);//����ͼ������ 
void readfile_book(List *list);//��ȡͼ������ 
void savefile_user( List *list);
void readfile_user(List *list);
void printf1();//��ӡ��ʼ�˵�
void printf2();//��ӡ����Ա�˵�
void printf3();//��ӡ��ͨ�û��˵� 
int color(int c); 
void printf_end();
