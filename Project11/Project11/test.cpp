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
	printf("��������Ҫ��ӵ�ѧ����Ϣ��\n");
	printf("������");
	scanf("%s", &L->data.name);
	name_judge();
	printf("ѧ�ţ�");
	id_judge();
	printf("�Ա�");
	scanf("%s", &L->data.sex);
	sex_judge();
	printf("���䣺");
	scanf("%d", &L->data.age);
	while (L->data.age > 28 || L->data.age < 18)
	{
		printf("����������������������\n");
		scanf("%d", &L->data.age);
	}
	printf("��ַ��");
	scanf("%s", &L->data.address);
	address_judge();
	printf("������ݣ�");
	scanf("%d", &L->data.birthday.year);
	while (L->data.birthday.year < 1900 || L->data.birthday.year>2000)
	{
		printf("���������������������\n");
		scanf("%d", &L->data.birthday.year);
	}
	printf("�����·ݣ�");
	scanf("%d", &L->data.birthday.month);
	while (L->data.birthday.month < 1 || L->data.birthday.month>12)
	{
		printf("�·�������������������\n");
		scanf("%d", &L->data.birthday.month);
	}
	printf("���룺");
	phone_judge();
	last = L;
	last->next = NULL;
	n = n + 1;
	printf("��ӳɹ�\n");
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
			printf("����\t\tѧ��\t\t�Ա�\t����\t��������\t�绰����\t��ַ\n");
			printf("%s\t\t%d\t\t%s\t%d\t%d/%d\t\t%d\t%s\n", p->data.name, p->data.id, p->data.sex, p->data.age, p->data.birthday.year, p->data.birthday.month, p->data.phone, p->data.address);
			p = p->next;
		} while (p != NULL);
	}
	else
		printf("���������\n");
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
		printf("��ѡ����ҷ�ʽ��\n");
		printf("1.����������\n2.��ѧ�Ų�ѯ\n");
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
		printf("���������\n");
		system("pause");
	}
}


void find1()
{
	char s[20];
	list *p;
	printf("������Ҫ����ѧ����������");
	scanf("%s", &s);
	p = head;
	do
	{
		if (strcmp(s, p->data.name) == 0)
		{
			printf("����\t\tѧ��\t\t�Ա�\t����\t��������\t�绰����\t��ַ\n");
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
	printf("������Ҫ����ѧ����ѧ�ţ�");
	scanf("%d", &s);
	p = head;
	do
	{
		if (p->data.id == s)
		{
			printf("����\t\tѧ��\t\t�Ա�\t����\t��������\t�绰����\t��ַ\n");
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
		printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
		scanf("%d", &s);
		p = head;
		do
		{
			if (p->data.id == s)
			{
				system("cls");
				printf("Ҫ�޸ĵ�ѧ����Ϣ����\n");
				printf("����\t\tѧ��\t\t�Ա�\t����\t��������\t�绰����\t��ַ\n");
				printf("%s\t\t%d\t\t%s\t%d\t%d/%d\t\t%d\t%s\n", p->data.name, p->data.id, p->data.sex, p->data.age, p->data.birthday.year, p->data.birthday.month, p->data.phone, p->data.address);
				break;
			}
			p = p->next;
		} while (p != NULL);
		printf("��ѡ��Ҫ�޸ĵ���\n");
		printf("1.�޸�����\n2.�޸�ѧ��\n3.�޸��Ա�\n4.�޸�����\n5.�޸ĳ�������\n6.�޸ĵ绰����\n7.�޸ĵ�ַ\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1:

			printf("�����޸�Ϊ��");
			scanf("%s", &p->data.name); break;
		case 2:
			printf("ѧ���޸�Ϊ��");
			scanf("%d", &p->data.id);
			id_judge();
			break;
		case 3:
			printf("�Ա��޸�Ϊ��");
			scanf("%s", &p->data.sex); break;
		case 4:
			printf("�����޸�Ϊ��");
			scanf("%d", &p->data.age); break;
		case 5:
			printf("���������޸�Ϊ��");
			scanf("%d%d", &p->data.birthday.year, &p->data.birthday.month); break;
		case 6:
			printf("�绰�����޸�Ϊ��");
			scanf("%d", &p->data.phone); break;
		case 7:
			printf("��ַ�޸�Ϊ��");
			scanf("%s", &p->data.address);  break;
		}
		printf("�޸ĳɹ�\n");
	}
	else
		printf("���������\n");
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
		printf("������Ҫɾ��ѧ����������");
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
	printf("ɾ���ɹ�\n");
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
			printf("����\n");
			fclose(fp);
			break;
		}
		p = p->next;
	}
	fclose(fp);
	printf("�洢�ɹ�\n");
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
	printf("��ȡ�ɹ�!\n\n");
	system("pause");
	system("cls");
}


void choose()
{
	int num;
	//	printf("��ѡ����Ҫ���еĲ�����");
	//	scanf("%d", &num);
	while (1)
	{

		//	system("cls");
		printf("��ѡ����Ҫ���еĲ�����");
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
			printf("ѧ��������������������\n");
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
			printf("����������������������\n");
	}
}


void name_judge()
{
	char *p = NULL;
	int i = 0;
	p = L->data.name;
	while (strlen(L->data.name) < 1 || strlen(L->data.name) > name_length)
	{
		printf("����������������������\n");
		scanf("%s", &L->data.name);
	}
	while (i <= strlen(L->data.name))
	{
		if ((*p >= 'a'&&*p <= 'z') || (*p >= 'A'&&*p <= 'Z'))
		{
			printf("����������������������\n");
			scanf("%s", &L->data.name);
		}
		else if (*p >= '0'&&*p <= '9')
		{
			printf("����������������������\n");
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
		printf("��ַ������������������\n");
		scanf("%s", &L->data.name);
	}
	while (i <= strlen(L->data.address))
	{
		if ((*p >= 'a'&&*p <= 'z') || (*p >= 'A'&&*p <= 'Z'))
		{
			printf("��ַ������������������\n");
			scanf("%s", &L->data.address);
		}
		else if (*p >= '0'&&*p <= '9')
		{
			printf("��ַ������������������\n");
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
			printf("�Ա�������������������\n");
			scanf("%s", &L->data.sex);
		}
		else if (*p >= '0'&&*p <= '9')
		{
			printf("�Ա�������������������\n");
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
	printf("|        ѧ����Ϣ����ϵͳ         |\n");
	printf("|                                 |\n");
	printf("|        1�����ѧ����Ϣ          |\n");
	printf("|        2������ѧ����Ϣ          |\n");
	printf("|        3����ʾѧ����Ϣ          |\n");
	printf("|        4���޸�ѧ����Ϣ          |\n");
	printf("|        5��ɾ��ѧ����Ϣ          |\n");
	printf("|        6������ѧ����Ϣ          |\n");
	printf("|        7����ȡѧ����Ϣ          |\n");
	printf("|        8���ص����˵�            |\n");
	printf("|                                 |\n");
	printf("|---------------------------------|\n");

	system("pause");
}
