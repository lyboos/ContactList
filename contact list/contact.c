#define  _CRT_SECURE_NO_WARNINGS 
#include"contact.h"
static void checkcapa(struct CONTACT* ps)
{
	if (ps->size == ps->capacity)
	{
		struct peoinfo* ptr=(struct peoinfo*)realloc(ps->data, (ps->capacity + 2) * sizeof(struct peoinfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("add room done\n");
		}
		else
		{
			printf("add room fail\n");
		}
	}
}

static int cmp_name(const void* a, const void* b)
{
	struct peoinfo* l = (struct peoinfo*)a;
	struct peoinfo* r = (struct peoinfo*)b;
	return strcmp(l->name,r->name);
}

static int cmp_tel(const void* a, const void* b)
{
	struct peoinfo* l = (struct peoinfo*)a;
	struct peoinfo* r = (struct peoinfo*)b;
	return strcmp(l->tel, r->tel);
}

static int cmp_age(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

static int cmp_sex(const void* a, const void* b)
{
	struct peoinfo* l = (struct peoinfo*)a;
	struct peoinfo* r = (struct peoinfo*)b;
	return strcmp(l->sex, r->sex);
}

void load(struct CONTACT* ps) 
{
	struct peoinfo tem = { 0 };
	FILE* pfr = fopen("contact list.dat","rb");
	if (pfr==NULL)
	{
		printf("load:%s", strerror(errno));
		return 0;
	}
	else
	{
		while (fread(&tem, sizeof(struct peoinfo), 1, pfr))
		{
			checkcapa(ps);
			ps->data[ps->size] = tem;
			ps->size++;

		}
		fclose(pfr);
		pfr = NULL;
	}
}

void init(struct CONTACT* ps)
{
	ps->data = (struct peoinfo*)malloc(3 * sizeof(struct peoinfo));
	if (ps->data == NULL)
	{
		return;
	}
	else
	{
		ps->size = 0;
		ps->capacity = CAPA;
	}
	load(ps);
}

static int cmp_add(const void* a, const void* b)
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
	checkcapa(ps);
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
	//if (ps->size == MAX)
	//{
	//	printf("ͨѶ¼�������޷����ӣ�\n");
	//}
	//else
	//{
	//	printf("����������:>");
	//	scanf("%s", ps->data[ps->size].name);
	//	printf("����������:>");
	//	scanf("%d", &(ps->data[ps->size].age));
	//	printf("�������Ա�:>");
	//	scanf("%s", ps->data[ps->size].sex);
	//	printf("������绰����:>");
	//	scanf("%s", ps->data[ps->size].tel);
	//	printf("�������ַ:>");
	//	scanf("%s", ps->data[ps->size].add);
	//	ps->size++;
	//	printf("���ӳɹ�\n");
	//}
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
//		FILE* pf = fopen("contact list","wb");
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
//		fclose(pf);
//		pf = NULL;
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

void contactsort(struct CONTACT* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
	}
	else 
	{
		int cate = 0;
		printf("1.name\t2.age\n3.sex\t4.tel\n5.add\n");
		printf("����������:>");
		scanf("%d", &cate);
		switch (cate)
		{
		case cancel:
			printf("ȡ���ɹ�\n");
			break;
		case mingzi:
			qsort(ps->data, ps->size, 72, cmp_name);
			printf("��������ɹ���\n");
			break;
		case nianling:
			qsort(ps->data, ps->size, 72, cmp_age);
			printf("��������ɹ���\n");
			break;
		case xingbie:
			qsort(ps->data, ps->size, 72, cmp_sex);
			printf("��������ɹ���\n");
			break;
		case dianhua:
			qsort(ps->data, ps->size, 72, cmp_tel);
			printf("��������ɹ���\n");
			break;
		case zhuzhi:
			qsort(ps->data, ps->size, 72, cmp_add);
			printf("��������ɹ���\n");
			break;
		default:
			printf("input error!");
			break;
		}
	}
}

void destory(struct CONTACT* ps)
{
	free(ps->data);
	ps->data = NULL;
}

void save(struct CONTACT* ps)
{
	FILE* pfw = fopen("contact list.dat", "wb");
	if (pfw== NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	else
	{
		int i = 0;
		for ( i = 0; i < ps->size; i++)
		{
			fwrite(&(ps->data[i]),sizeof(struct peoinfo),1,pfw);
		}
		printf("save successfully!\n");
	}
}