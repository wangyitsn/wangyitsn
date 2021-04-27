#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct Book {
	char Id[20]; //���
	char Name[40];//����
	char Author[10]; //����
	float Price;  //����
	int Number;  //���
	char PublicTime[20];  //����ʱ��
	char PublicPlace[20]; //����ص�
	float Prices;  //�۸�
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
}  //չʾ���е���Ϣ
void Modify(NODE& head) {
	char Code[20];
	printf("���������Ա���룺");
	scanf("%s", Code);
	if (strcmp(Code, "TongSaiNan") == 0) {
		NODE p = head;
		Display(head);
		int i, j = 1;
		printf("��ѡ����Ҫ�޸ĵı�ţ�");
		scanf("%d", &i);
		for (p, j; p != NULL, j < i; p = p->next, j++) {

		}
		printf("��������Ҫ�޸ĵ����ݣ�");
		scanf("%s %s %s %f %d %s %s %f", p->Books.Id, p->Books.Name, p->Books.Author, &p->Books.Price, &p->Books.Number, p->Books.PublicTime, p->Books.PublicPlace, &p->Books.Prices);
		//system("pause");
	}
	else {
		printf("������󣡣�");
	}
}  //�޸ĺ���
void Find(NODE head) {
	int i, j, t = 1;
	char name[40];
	NODE p;
	printf("\t�q�q----------------------------------------------�r�r\n");
	printf("\t��             1. ����Ų���                      ��\n");
	printf("\t��             2. ����������                      ��\n");
	printf("\t��             3. �����߲���                      ��\n");
	printf("\t��             4. �����۲���                      ��\n");
	printf("\t��             5. ������ʱ�����                  ��\n");
	printf("\t��             6. ������ص����                  ��\n");
	printf("\t��             7. ���۸����                      ��\n");
	printf("\t�t�t----------------------------------------------�s\n");
	printf("��ѡ����Ҫ�����ַ�ʽ���в���:");
	scanf("%d", &i);
	printf("��ѡ����Ҫ���ҵ�����:");
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
	printf("���ҳɹ���������");
	system("pause");
}//���Һ���
void Add(NODE& head) {
	char Code[20];
	printf("���������Ա���룺");
	scanf("%s", Code);
	if (strcmp(Code, "TongSaiNan") == 0) {
		NODE p = head;
		int i;
		Book add[20];
		for (i = 0; i < 20; i++) {
			printf("��������Ҫ��ӵ���Ϣ��");
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
		printf("��ӳɹ���������");
	}
	else {
		printf("������󣡣���");
	}
	system("pause");
}//��Ӻ���
void Del(NODE& head) {
	char Code[20];
	printf("���������Ա���룺");
	scanf("%s", Code);
	if (strcmp(Code, "TongSaiNan") == 0) {
		Display(head);
		printf("��ѡ��Ҫɾ�������ݱ�ţ�");
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
		printf("������󣡣�");
	}
}
void Menue() {
	printf("\t�q�q----------------------------------------------�r�r\n");
	printf("\t��           ͼ ��  ��  ��  ϵ  ͳ                ��\n");
	printf("\t��             a. ���ͼ����Ϣ                    ��\n");
	printf("\t��                                                ��\n");
	printf("\t��             b. �޸�ͼ����Ϣ                    ��\n");
	printf("\t��                                                ��\n");
	printf("\t��             c. ɾ��ͼ����Ϣ                    ��\n");
	printf("\t��                                                ��\n");
	printf("\t��             d. ����ͼ��                        ��\n");
	printf("\t��                                                ��\n");
	printf("\t��             e. ͼ����Ϣ                        ��\n");
	printf("\t��                                                ��\n");
	printf("\t��             f. �˳�ϵͳ                        ��\n");
	printf("\t�t�t----------------------------------------------�s�s\n");
}
int main() {
	NODE head;
	Creat(head);
	for (;;) {
		char i, Code[20];
		Menue();
		printf("��������Ҫ������ѡ�\n");
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