#pragma once
#include<stdio.h>
#include<string.h>
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TEL 12
#define MAX_ADD 30

enum option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT,//6
};
struct peoinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char add[MAX_ADD];
};

struct CONTACT
{
	struct peoinfo data[MAX];
	int size;
};

void init(struct CONTACT* ps);
void add(struct CONTACT* ps);
void delete(struct CONTACT* ps);
void search(const struct CONTACT* ps);
void modify(struct CONTACT* ps);
void show(const struct CONTACT* ps);
