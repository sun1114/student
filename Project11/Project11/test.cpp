#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define id_length 6
#define phone_length 8
#define name_length 10 
#define address_length 15
#pragma warning(disable:4996)


struct born_time {
	int year;
	int month;
};


typedef struct student
{
	char name[10];
	int id;
	char sex[4];
	int age;
	struct born_time birthday;
	int phone;
	char address[10];
}stu;


typedef struct node {
	stu data;
	struct node *next;
}list;


list *L, *head, *last;
int n = 0;


void add();
void show();
void seek();
void find1();
void find2();
void change();
void del();
void save();
void choose();
void menu();
void id_judge();
void phone_judge();
void name_judge();
void address_judge();
void sex_judge();


int main()
{
	menu();
	choose();
	return 0;
}


void add()
{
	system("cls");
	L = (list*)malloc(sizeof(list));
	if (n == 0)
		last = head = L;
	else
		last->next = L;
	printf("请输入需要添加的学生信息：\n");
	printf("姓名：");
	scanf("%s", &L->data.name);
	name_judge();
	printf("学号：");
	id_judge();
	printf("性别：");
	scanf("%s", &L->data.sex);
	sex_judge();
	printf("年龄：");
	scanf("%d", &L->data.age);
	while (L->data.age > 28 || L->data.age < 18)
	{
		printf("年龄输入有误，请重新输入\n");
		scanf("%d", &L->data.age);
	}
	printf("地址：");
	scanf("%s", &L->data.address);
	address_judge();
	printf("出生年份：");
	scanf("%d", &L->data.birthday.year);
	while (L->data.birthday.year < 1900 || L->data.birthday.year>2000)
	{
		printf("年份输入有误，请重新输入\n");
		scanf("%d", &L->data.birthday.year);
	}
	printf("出生月份：");
	scanf("%d", &L->data.birthday.month);
	while (L->data.birthday.month < 1 || L->data.birthday.month>12)
	{
		printf("月份输入有误，请重新输入\n");
		scanf("%d", &L->data.birthday.month);
	}
	printf("号码：");
	phone_judge();
	last = L;
	last->next = NULL;
	n = n + 1;
	printf("添加成功\n");
	system("pause");
	system("cls");
	//  menu();
}


void show()
{
	list *p;
	if (n != 0)
	{
		p = head;
		do
		{
			printf("姓名\t\t学号\t\t性别\t年龄\t出生年月\t电话号码\t地址\n");
			printf("%s\t\t%d\t\t%s\t%d\t%d/%d\t\t%d\t%s\n", p->data.name, p->data.id, p->data.sex, p->data.age, p->data.birthday.year, p->data.birthday.month, p->data.phone, p->data.address);
			p = p->next;
		} while (p != NULL);
	}
	else
		printf("请添加数据\n");
	system("pause");
	system("cls");
}

void seek()
{
	system("cls");
	void find1();
	void find2();
	if (n != 0)
	{
		int num;
		printf("请选择查找方式：\n");
		printf("1.按姓名查找\n2.按学号查询\n");
		scanf("%d", &num);
		system("cls");
		switch (num)
		{
		case 1:
			find1();
			break;
		case 2:
			find2();
			break;
		}
	}
	else
	{
		printf("请添加数据\n");
		system("pause");
	}
}


void find1()
{
	char s[20];
	list *p;
	printf("请输入要查找学生的姓名：");
	scanf("%s", &s);
	p = head;
	do
	{
		if (strcmp(s, p->data.name) == 0)
		{
			printf("姓名\t\t学号\t\t性别\t年龄\t出生年月\t电话号码\t地址\n");
			printf("%s\t\t%d\t\t%s\t%d\t%d/%d\t\t%d\t%s\n", p->data.name, p->data.id, p->data.sex, p->data.age, p->data.birthday.year, p->data.birthday.month, p->data.phone, p->data.address);
		}
		p = p->next;
	} while (p != NULL);
	system("pause");
	system("cls");

}
void find2()
{
	int s;
	list *p;
	printf("请输入要查找学生的学号：");
	scanf("%d", &s);
	p = head;
	do
	{
		if (p->data.id == s)
		{
			printf("姓名\t\t学号\t\t性别\t年龄\t出生年月\t电话号码\t地址\n");
			printf("%s\t\t%d\t\t%s\t%d\t%d/%d\t\t%d\t%s\n", p->data.name, p->data.id, p->data.sex, p->data.age, p->data.birthday.year, p->data.birthday.month, p->data.phone, p->data.address);
		}
		p = p->next;
	} while (p != NULL);
	system("pause");
	system("cls");
}



void change()
{
	list *p;
	if (n != 0)
	{
		int s, num;
		printf("请输入要修改的学生学号：");
		scanf("%d", &s);
		p = head;
		do
		{
			if (p->data.id == s)
			{
				system("cls");
				printf("要修改的学生信息如下\n");
				printf("姓名\t\t学号\t\t性别\t年龄\t出生年月\t电话号码\t地址\n");
				printf("%s\t\t%d\t\t%s\t%d\t%d/%d\t\t%d\t%s\n", p->data.name, p->data.id, p->data.sex, p->data.age, p->data.birthday.year, p->data.birthday.month, p->data.phone, p->data.address);
				break;
			}
			p = p->next;
		} while (p != NULL);
		printf("请选择要修改的项\n");
		printf("1.修改姓名\n2.修改学号\n3.修改性别\n4.修改年龄\n5.修改出生年月\n6.修改电话号码\n7.修改地址\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1:

			printf("姓名修改为：");
			scanf("%s", &p->data.name); break;
		case 2:
			printf("学号修改为：");
			scanf("%d", &p->data.id);
			id_judge();
			break;
		case 3:
			printf("性别修改为：");
			scanf("%s", &p->data.sex); break;
		case 4:
			printf("年龄修改为：");
			scanf("%d", &p->data.age); break;
		case 5:
			printf("出生年月修改为：");
			scanf("%d%d", &p->data.birthday.year, &p->data.birthday.month); break;
		case 6:
			printf("电话号码修改为：");
			scanf("%d", &p->data.phone); break;
		case 7:
			printf("地址修改为：");
			scanf("%s", &p->data.address);  break;
		}
		printf("修改成功\n");
	}
	else
		printf("请添加数据\n");
	system("pause");
}


void del()
{
	list *p;
	if (n != 0)
	{
		list *f, *l;
		l = NULL;
		char s[20];
		printf("请输入要删除学生的姓名：");
		scanf("%s", &s);
		p = head;
		if (strcmp(p->data.name, s) == 0)
		{
			f = head; head = head->next; free(f);
		}
		else
		{
			do
			{
				if (strcmp(p->data.name, s) == 0)
				{
					f = p;
					l->next = p->next;
					free(f);
					break;
				}
				l = p;
				p = p->next;
			} while (p != NULL);
		}
	}
	printf("删除成功\n");
	system("pause");
	system("cls");
}


void save()
{
	FILE *fp;
	list *p;
	if ((fp = fopen("student.txt", "wb")) == NULL)
		printf("cannot open the file!");
	p = head;
	while (p != NULL)
	{
		if (fwrite(p, sizeof(list), 1, fp) != 1)
		{
			printf("出错\n");
			fclose(fp);
			break;
		}
		p = p->next;
	}
	fclose(fp);
	printf("存储成功\n");
	system("pause");
	system("cls");
}


void read()
{
	FILE *fp;
	if ((fp = fopen("student.txt", "rb+")) == NULL)
	{
		printf("cannot open file!");
		exit(0);
	}
	do
	{
		L = (node*)malloc(sizeof(list));
		if (n == 0)
			head = L;
		else
			last->next = L;
		last = L;
		fread(L, sizeof(list), 1, fp);
		//	last = L;
		n = n + 1;
	} while (last->next != NULL);
	fclose(fp);
	printf("读取成功!\n\n");
	system("pause");
	system("cls");
}


void choose()
{
	int num;
	//	printf("请选择你要进行的操作：");
	//	scanf("%d", &num);
	while (1)
	{

		//	system("cls");
		printf("请选择你要进行的操作：");
		scanf("%d", &num);
		switch (num)
		{
		case 1: add(); break;
		case 2: seek(); break;
		case 3: show(); break;
		case 4: change(); break;
		case 5: del(); break;
		case 6: save(); break;
		case 7: read(); break;
		case 8: menu(); break;
		}
		system("cls");
		menu();
	}
}


void id_judge()
{
	while (1)
	{
		int num, m = 0;
		scanf("%d", &L->data.id);
		num = L->data.id;
		while (num != 0)
		{
			num = num / 10;
			m++;
		}
		if (m == id_length)
			break;
		else
			printf("学号输入有误，请重新输入\n");
	}
}


void phone_judge()
{
	while (1)
	{
		int num, m = 0;
		scanf("%d", &L->data.phone);
		num = L->data.phone;
		while (num != 0)
		{
			num = num / 10;
			m++;
		}
		if (m == phone_length)
			break;
		else
			printf("号码输入有误，请重新输入\n");
	}
}


void name_judge()
{
	char *p = NULL;
	int i = 0;
	p = L->data.name;
	while (strlen(L->data.name) < 1 || strlen(L->data.name) > name_length)
	{
		printf("名字输入有误，请重新输入\n");
		scanf("%s", &L->data.name);
	}
	while (i <= strlen(L->data.name))
	{
		if ((*p >= 'a'&&*p <= 'z') || (*p >= 'A'&&*p <= 'Z'))
		{
			printf("名字输入有误，请重新输入\n");
			scanf("%s", &L->data.name);
		}
		else if (*p >= '0'&&*p <= '9')
		{
			printf("名字输入有误，请重新输入\n");
			scanf("%s", &L->data.name);
		}
		else
			i++;
		p++;
	}
	return;
}

void address_judge()
{
	char *p = NULL;
	int i = 0;
	p = L->data.address;
	while (strlen(L->data.name) < 1 || strlen(L->data.name) > address_length)
	{
		printf("地址输入有误，请重新输入\n");
		scanf("%s", &L->data.name);
	}
	while (i <= strlen(L->data.address))
	{
		if ((*p >= 'a'&&*p <= 'z') || (*p >= 'A'&&*p <= 'Z'))
		{
			printf("地址输入有误，请重新输入\n");
			scanf("%s", &L->data.address);
		}
		else if (*p >= '0'&&*p <= '9')
		{
			printf("地址输入有误，请重新输入\n");
			scanf("%s", &L->data.address);
		}
		else
			i++;
		p++;
	}
	return;
}


void sex_judge()
{
	char *p = NULL;
	int i = 0;
	p = L->data.sex;
	while (i <= strlen(L->data.sex))
	{
		if ((*p >= 'a'&&*p <= 'z') || (*p >= 'A'&&*p <= 'Z'))
		{
			printf("性别输入有误，请重新输入\n");
			scanf("%s", &L->data.sex);
		}
		else if (*p >= '0'&&*p <= '9')
		{
			printf("性别输入有误，请重新输入\n");
			scanf("%s", &L->data.sex);
		}
		else
			i++;
		p++;
	}
	return;
}


void menu()
{
	system("cls");
	printf("|---------------------------------|\n");
	printf("|                                 |\n");
	printf("|        学生信息管理系统         |\n");
	printf("|                                 |\n");
	printf("|        1、添加学生信息          |\n");
	printf("|        2、查找学生信息          |\n");
	printf("|        3、显示学生信息          |\n");
	printf("|        4、修改学生信息          |\n");
	printf("|        5、删除学生信息          |\n");
	printf("|        6、保存学生信息          |\n");
	printf("|        7、读取学生信息          |\n");
	printf("|        8、回到主菜单            |\n");
	printf("|                                 |\n");
	printf("|---------------------------------|\n");

	system("pause");
}
