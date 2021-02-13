#define  _CRT_SECURE_NO_WARNINGS 
#include"contact.h"

int cmp_name(const void* a, const void* b)
{
	struct peoinfo* l = (struct peoinfo*)a;
	struct peoinfo* r = (struct peoinfo*)b;
	return -strcmp(l->name,r->name);
}

int cmp_tel(const void* a, const void* b)
{
	struct peoinfo* l = (struct peoinfo*)a;
	struct peoinfo* r = (struct peoinfo*)b;
	return -strcmp(l->tel, r->tel);
}

int cmp_age(const void* a, const void* b) 
{
	return *(int*)b - *(int*)a;
}

int cmp_sex(const void* a, const void* b)
{
	struct peoinfo* l = (struct peoinfo*)a;
	struct peoinfo* r = (struct peoinfo*)b;
	return -strcmp(l->sex, r->sex);
}

void init(struct CONTACT* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

int cmp_add(const void* a, const void* b)
{
	struct peoinfo* l = (struct peoinfo*)a;
	struct peoinfo* r = (struct peoinfo*)b;
	return -strcmp(l->add, r->add);
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
		printf("通讯录已满，无法增加！\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话号码:>");
		scanf("%s", ps->data[ps->size].tel);
		printf("请输入地址:>");
		scanf("%s", ps->data[ps->size].add);
		ps->size++;
		printf("增加成功\n");
	}
}

void delete(struct CONTACT* ps)
{
	char name[MAX_NAME];
	printf("请输入需删除人的姓名:>");
	scanf("%s", name);
	int pos = findbyname(ps,name);
	if (pos==ps->size)
	{
		printf("通讯录未发现此人！\n");
	}
	else
	{
		int j = 0;
		for ( j = pos; j <ps->size ; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功！\n");
	}
}

void search(const struct CONTACT* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找的姓名:>");
	scanf("%s", name);
	int pos = findbyname(ps,name);
	if (pos == -1)
	{
		printf("通讯录无此人\n");
	}
	else
	{
		printf("%-12s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "住址");
		printf("%-12s\t%-4d\t%-5s\t%-12s\t%-20s\n", ps->data[pos].name, ps->data[pos].age, ps->data[pos].sex,ps->data[pos].tel, ps->data[pos].add);
	}
}

void modify(struct CONTACT* ps)
{
	char name[MAX_NAME];
	printf("请输入被修改人名字:>");
	scanf("%s", name);
	int pos = findbyname(ps,name);
	if (pos==-1)
	{
		printf("被修改人的信息不存在！\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话号码:>");
		scanf("%s", ps->data[ps->size].tel);
		printf("请输入地址:>");
		scanf("%s", ps->data[ps->size].add);
		printf("修改成功\n");
	}
}

void show(const struct CONTACT* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空！\n");
	}
	else
	{
		int i = 0;
		printf("%-12s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "住址");
		for ( i = 0; i < ps->size; i++)
		{
			printf("%-12s\t%-4d\t%-5s\t%-12s\t%-20s\n", ps->data[i].name, ps->data[i].age, ps->data[i].sex, ps->data[i].tel, ps->data[i].add);
		}
	}
}

void contactsort(struct CONTACT* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空！\n");
	}
	else 
	{
		int cate = 0;
		printf("1.name\t2.age\n3.sex\t4.tel\n5.add\n");
		printf("按……排序:>");
		scanf("%d", &cate);
		switch (cate)
		{
		case cancel:
			printf("取消成功\n");
			break;
		case mingzi:
			qsort(ps->data, MAX, 72, cmp_name);
			printf("重新排序成功！\n");
			break;
		case nianling:
			qsort(ps->data, MAX, 72, cmp_age);
			printf("重新排序成功！\n");
			break;
		case xingbie:
			qsort(ps->data, MAX, 72, cmp_sex);
			printf("重新排序成功！\n");
			break;
		case dianhua:
			qsort(ps->data, MAX, 72, cmp_tel);
			printf("重新排序成功！\n");
			break;
		case zhuzhi:
			qsort(ps->data, MAX, 72, cmp_add);
			printf("重新排序成功！\n");
			break;
		default:
			printf("input error!");
			break;
		}
	}
}