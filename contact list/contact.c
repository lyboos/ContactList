#define  _CRT_SECURE_NO_WARNINGS 
#include"contact.h"

void init(struct CONTACT* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

static int findbyname(const struct CONTACT* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(name, ps->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void add(struct CONTACT* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷����ӣ�\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[ps->size].name);
		printf("����������:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰����:>");
		scanf("%s", ps->data[ps->size].tel);
		printf("�������ַ:>");
		scanf("%s", ps->data[ps->size].add);
		ps->size++;
		printf("���ӳɹ�\n");
	}
}

void delete(struct CONTACT* ps)
{
	char name[MAX_NAME];
	printf("��������ɾ���˵�����:>");
	scanf("%s", name);
	int pos = findbyname(ps,name);
	if (pos==ps->size)
	{
		printf("ͨѶ¼δ���ִ��ˣ�\n");
	}
	else
	{
		int j = 0;
		for ( j = pos; j <ps->size ; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ���\n");
	}
}

void search(const struct CONTACT* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ�����:>");
	scanf("%s", name);
	int pos = findbyname(ps,name);
	if (pos == -1)
	{
		printf("ͨѶ¼�޴���\n");
	}
	else
	{
		printf("%-12s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-12s\t%-4d\t%-5s\t%-12s\t%-20s\n", ps->data[pos].name, ps->data[pos].age, ps->data[pos].sex,ps->data[pos].tel, ps->data[pos].add);
	}
}

void modify(struct CONTACT* ps)
{
	char name[MAX_NAME];
	printf("�����뱻�޸�������:>");
	scanf("%s", name);
	int pos = findbyname(ps,name);
	if (pos==-1)
	{
		printf("���޸��˵���Ϣ�����ڣ�\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[ps->size].name);
		printf("����������:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰����:>");
		scanf("%s", ps->data[ps->size].tel);
		printf("�������ַ:>");
		scanf("%s", ps->data[ps->size].add);
		printf("�޸ĳɹ�\n");
	}
}

void show(const struct CONTACT* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
	}
	else
	{
		int i = 0;
		printf("%-12s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		for ( i = 0; i < ps->size; i++)
		{
			printf("%-12s\t%-4d\t%-5s\t%-12s\t%-20s\n", ps->data[i].name, ps->data[i].age, ps->data[i].sex, ps->data[i].tel, ps->data[i].add);
		}
	}
}