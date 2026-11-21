#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct Node {
	DataType data;
	struct Node* next;
}Node,*LinkList;
//1.链表初始化
Node* InitLinkList() 
{
    Node* head = (Node*)malloc(sizeof(Node));
	if (!head) return NULL;
	head->next = NULL;
	return head;
}
//2.头插法建立单链表
LinkList CreatHead_LinkList(int n) {
	LinkList L= NULL;
	Node* s;
	int i;
	for (i = 1;i <= n;i++) {
		s = (Node*)malloc(sizeof(Node));
		printf("2.请输入第%d个元素的值:", i);
		scanf("%d", &s->data);
		s->data = L;
	    L = s;
	}
	return L;
} 
//3.尾插法建立单链表
LinkList CreatTail_LinkList(int n) {
	LinkList head = NULL;
	Node* s, * r=NULL;
	int i;
	for (i = 1;i <= n;i++) {
		s = (Node*)malloc(sizeof(Node));
		printf("请输入第%d个元素的值：",i);
		scanf("%d", &s->data);
		s->next = NULL;
		if (head == NULL) {
			head = s;
		}
		else {
			r->next = s;
		}
		r = s; 
	}
	return head;
}
//4.判断链表是否为空
int IsEmpty(Node* head) {
	if (head == NULL) return 1;
	return head->next==NULL;
}
//5.计算链表长度
int GetLength(Node*head) {
	int count = 0;
	Node* p = head->next;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}
//6.输出链表内容
void PrintLinkList(Node*head) {
	Node* p = head;
	if (p == NULL) {
		printf("空链表\n");
		return;
	}
	printf("链表内容为：\n");
	while (p != NULL) {
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}
int main() {
	printf("1、初始化链表\n");
	Node* head = InitLinkList();
	if (head != NULL) {
		printf("链表初始化成功!\n");
	}
	//4.判断列表是否为空测试
	printf("4.判断链表是否为空：");
	if (IsEmpty(head)) {
		printf("当前链表为空\n");
	}
	else {
		printf("当前列表不为空\n");
	}
	//2.测试头插法
	int n;
	printf("头插法建立后：\n");
	printf("请输入要创建的节点个数：");
	scanf("%d", &n);
	head = CreatHead_LinkList(n);
	//6.输出链表测试
	printf("6.尾插法建立后：\n");
	PrintLinkList(head);
	//5.测试计算长度
	printf("5.当前链表长度为：%d\n", GetLength(head));
	//3.尾插法测试
	printf("3.尾插法建立后：\n");
	printf("请输入要创建的节点个数：");
	scanf("%d", &n);
	head = CreatTail_LinkList(n);
	//6.输出链表测试
	printf("6.尾插法建立后：\n");
	PrintLinkList(head);
	//5.测试计算长度
	printf("5.当前链表长度为：%d\n", GetLength(head));
	return 0;
}