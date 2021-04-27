#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct Book {
	char Id[20]; //书号
	char Name[40];//书名
	char Author[10]; //作者
	float Price;  //单价
	int Number;  //库存
	char PublicTime[20];  //出版时间
	char PublicPlace[20]; //出版地点
	float Prices;  //价格
};
typedef struct st {
	Book Books;
	struct st* next;
}Node, * NODE;
void Creat(NODE& Head) {
	Book Passage[40];
	int i = 0, j;
	FILE* fp;
	fp = fopen("E://c.txt", "r");
	while (~fscanf(fp, "%s %s %s %f %d %s %s %f\n", Passage[i].Id, Passage[i].Name, Passage[i].Author, &Passage[i].Price, &Passage[i].Number, Passage[i].PublicTime, Passage[i].PublicPlace, &Passage[i].Prices)) {
		i++;
	}
	j = i;
	i = 0;
	NODE p, q, head;
	head = NULL;
	p = (NODE)malloc(sizeof(struct st));
	strcpy(p->Books.Id, Passage[i].Id);
	strcpy(p->Books.Name, Passage[i].Name);
	strcpy(p->Books.Author, Passage[i].Author);
	strcpy(p->Books.PublicPlace, Passage[i].PublicPlace);
	strcpy(p->Books.PublicTime, Passage[i].PublicTime);
	p->Books.Price = Passage[i].Price;
	p->Books.Prices = Passage[i].Prices;
	p->Books.Number = Passage[i].Number;
	i++;
	while (strcmp(p->Books.Id, "#") != 0) {
		if (head == NULL) head = p;
		else {
			q->next = p;
		}
		q = p;
		p = (NODE)malloc(sizeof(struct st));
		strcpy(p->Books.Id, Passage[i].Id);
		strcpy(p->Books.Name, Passage[i].Name);
		strcpy(p->Books.Author, Passage[i].Author);
		strcpy(p->Books.PublicPlace, Passage[i].PublicPlace);
		strcpy(p->Books.PublicTime, Passage[i].PublicTime);
		p->Books.Price = Passage[i].Price;
		p->Books.Prices = Passage[i].Prices;
		p->Books.Number = Passage[i].Number;
		i++;
	}
	q->next = NULL;
	Head = head;
}
void Display(NODE head) {
	int i = 1;
	NODE p = head;
	for (p; p != NULL; p = p->next, i++) {
		printf("%d.%s %s %s %.1f %d %s %s %.1f\n", i, p->Books.Id, p->Books.Name, p->Books.Author, p->Books.Price, p->Books.Number, p->Books.PublicTime, p->Books.PublicPlace, p->Books.Prices);
	}
	system("pause");
}  //展示所有的信息
void Modify(NODE& head) {
	char Code[20];
	printf("请输入管理员密码：");
	scanf("%s", Code);
	if (strcmp(Code, "TongSaiNan") == 0) {
		NODE p = head;
		Display(head);
		int i, j = 1;
		printf("请选择你要修改的编号：");
		scanf("%d", &i);
		for (p, j; p != NULL, j < i; p = p->next, j++) {

		}
		printf("请输入您要修改的内容：");
		scanf("%s %s %s %f %d %s %s %f", p->Books.Id, p->Books.Name, p->Books.Author, &p->Books.Price, &p->Books.Number, p->Books.PublicTime, p->Books.PublicPlace, &p->Books.Prices);
		//system("pause");
	}
	else {
		printf("密码错误！！");
	}
}  //修改函数
void Find(NODE head) {
	int i, j, t = 1;
	char name[40];
	NODE p;
	printf("\t╭----------------------------------------------╮\n");
	printf("\t｜             1. 按书号查找                      ｜\n");
	printf("\t｜             2. 按书名查找                      ｜\n");
	printf("\t｜             3. 按作者查找                      ｜\n");
	printf("\t｜             4. 按单价查找                      ｜\n");
	printf("\t｜             5. 按出版时间查找                  ｜\n");
	printf("\t｜             6. 按出版地点查找                  ｜\n");
	printf("\t｜             7. 按价格查找                      ｜\n");
	printf("\t╰----------------------------------------------╯\n");
	printf("请选择你要按那种方式进行查找:");
	scanf("%d", &i);
	printf("请选择你要查找的内容:");
	if (i == 4 || i == 7) {
		scanf("%d", &j);
	}
	else {
		scanf("%s", name);
	}
	switch (i) {
	case 1:for (p = head; p != NULL; p = p->next) { if (strcmp(p->Books.Id, name) == 0) printf("%d.%s %s %s %.1f %d %s %s %.1f\n", t++, p->Books.Id, p->Books.Name, p->Books.Author, p->Books.Price, p->Books.Number, p->Books.PublicTime, p->Books.PublicPlace, p->Books.Prices); }break;
	case 2:for (p = head; p != NULL; p = p->next) { if (strcmp(p->Books.Name, name) == 0) printf("%d.%s %s %s %.1f %d %s %s %.1f\n", t++, p->Books.Id, p->Books.Name, p->Books.Author, p->Books.Price, p->Books.Number, p->Books.PublicTime, p->Books.PublicPlace, p->Books.Prices); }break;
	case 3:for (p = head; p != NULL; p = p->next) { if (strcmp(p->Books.Author, name) == 0) printf("%d.%s %s %s %.1f %d %s %s %.1f\n", t++, p->Books.Id, p->Books.Name, p->Books.Author, p->Books.Price, p->Books.Number, p->Books.PublicTime, p->Books.PublicPlace, p->Books.Prices); }break; break;
	case 4:for (p = head; p != NULL; p = p->next) { if (p->Books.Price == j) printf("%d.%s %s %s %.1f %d %s %s %.1f\n", t++, p->Books.Id, p->Books.Name, p->Books.Author, p->Books.Price, p->Books.Number, p->Books.PublicTime, p->Books.PublicPlace, p->Books.Prices); }break;
	case 5:for (p = head; p != NULL; p = p->next) { if (strcmp(p->Books.PublicTime, name) == 0) printf("%d.%s %s %s %.1f %d %s %s %.1f\n", t++, p->Books.Id, p->Books.Name, p->Books.Author, p->Books.Price, p->Books.Number, p->Books.PublicTime, p->Books.PublicPlace, p->Books.Prices); }break;
	case 6:for (p = head; p != NULL; p = p->next) { if (strcmp(p->Books.PublicPlace, name) == 0) printf("%d.%s %s %s %.1f %d %s %s %.1f\n", t++, p->Books.Id, p->Books.Name, p->Books.Author, p->Books.Price, p->Books.Number, p->Books.PublicTime, p->Books.PublicPlace, p->Books.Prices); }break;
	case 7:for (p = head; p != NULL; p = p->next) { if (p->Books.Prices == j) printf("%d.%s %s %s %.1f %d %s %s %.1f\n", t++, p->Books.Id, p->Books.Name, p->Books.Author, p->Books.Price, p->Books.Number, p->Books.PublicTime, p->Books.PublicPlace, p->Books.Prices); }break; break; break;
	};
	printf("查找成功！！！！");
	system("pause");
}//查找函数
void Add(NODE& head) {
	char Code[20];
	printf("请输入管理员密码：");
	scanf("%s", Code);
	if (strcmp(Code, "TongSaiNan") == 0) {
		NODE p = head;
		int i;
		Book add[20];
		for (i = 0; i < 20; i++) {
			printf("请输入您要添加的信息：");
			scanf("%s %s %s %f %d %s %s %f", add[i].Id, add[i].Name, add[i].Author, &add[i].Price, &add[i].Number, add[i].PublicTime, add[i].PublicPlace, &add[i].Prices);
			if (strcmp(add[i].Id, "#") == 0) break;
			for (p; p->next != NULL; p = p->next) {
				if (strcmp(p->Books.Id, add[i].Id) == 0) {
					p->Books.Number++;
					break;
				}
			}
			if (p->next == NULL) {
				NODE q = (NODE)malloc(sizeof(struct st));
				strcpy(q->Books.Id, add[i].Id);
				strcpy(q->Books.Name, add[i].Name);
				strcpy(q->Books.Author, add[i].Author);
				strcpy(q->Books.PublicPlace, add[i].PublicPlace);
				strcpy(q->Books.PublicTime, add[i].PublicTime);
				q->Books.Number = add[i].Number;
				q->Books.Price = add[i].Price;
				q->Books.Prices = add[i].Prices;
				p->next = q;
				q->next = NULL;
			}
		}
		printf("添加成功！！！！");
	}
	else {
		printf("密码错误！！！");
	}
	system("pause");
}//添加函数
void Del(NODE& head) {
	char Code[20];
	printf("请输入管理员密码：");
	scanf("%s", Code);
	if (strcmp(Code, "TongSaiNan") == 0) {
		Display(head);
		printf("请选择要删除的内容编号：");
		int i, j = 1;
		scanf("%d", &i);
		if (i == 1) {
			head = head->next;
		}
		else {
			NODE p = head, q = NULL;
			for (j, p, q; p != NULL, j < i; q = p, p = p->next, j++) {

			}
			q->next = p->next;
		}
	}
	else {
		printf("密码错误！！");
	}
}
void Menue() {
	printf("\t╭----------------------------------------------╮\n");
	printf("\t｜           图 书  管  理  系  统                ｜\n");
	printf("\t｜             a. 添加图书信息                    ｜\n");
	printf("\t｜                                                ｜\n");
	printf("\t｜             b. 修改图书信息                    ｜\n");
	printf("\t｜                                                ｜\n");
	printf("\t｜             c. 删除图书信息                    ｜\n");
	printf("\t｜                                                ｜\n");
	printf("\t｜             d. 查找图书                        ｜\n");
	printf("\t｜                                                ｜\n");
	printf("\t｜             e. 图书信息                        ｜\n");
	printf("\t｜                                                ｜\n");
	printf("\t｜             f. 退出系统                        ｜\n");
	printf("\t╰----------------------------------------------╯\n");
}
int main() {
	NODE head;
	Creat(head);
	for (;;) {
		char i, Code[20];
		Menue();
		printf("请输入你要操作的选项：\n");
		scanf("%c", &i);
		if (i == 'f')break;
		else switch (i) {
		case 'a':Add(head); break;
		case 'b':Modify(head); break;
		case 'c':Del(head); break;
		case 'd':Find(head); break;
		case 'e':Display(head); break;
		}
		system("cls");
	}
	return 0;
}