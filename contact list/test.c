#define  _CRT_SECURE_NO_WARNINGS 
#include"contact.h"

void menu()
{
	printf("***********************************\n");
	printf("******|     CONTACT LIST    |******\n");
	printf("******|*********************|******\n");
	printf("******| 1.add    |   2.del  |******\n"); 
	printf("******| 3.search | 4.modify |******\n");
	printf("******| 5.show   |   6.sort |******\n");
	printf("******| 0.exit              |******\n");
	printf("***********************************\n");
	printf("***********************************\n");
}

int main()
{
	int input = 0;
	int size = 0;
	int flag = 1;
	struct CONTACT con;
	init(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add(&con);
			break;
		case DEL:
			delete(&con);
			break;
		case SEARCH:
			search(&con);
			break;
		case MODIFY:
			modify(&con);
			break;
		case SHOW:
			show(&con);
			break;
		case CONSORT:
			contactsort(&con);
			break;
		case EXIT:
			flag = 0;
			destory(&con);
			printf("退出通讯录!\n");
			break;
		default:
			printf("selection wrong\n");
			break;
		}
	} while (input);
	return 0;
}