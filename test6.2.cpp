#include<iostream>
using namespace std;
//定义一个链式队列
typedef int DataType;
struct Node//节点结构体定义
{
	DataType data;
	Node* next;
};
struct LinkQueue//链式队列结构体定义
{
	Node* front;//队头指针
	Node* rear;//队尾指针
};
//1.初始化一个空链队列
LinkQueue* InitQueue()
{
	LinkQueue* Q = new LinkQueue;//创建一个链队列
	if (Q == NULL) {
		cout << "内存分配失败" << endl;
		return NULL;
	}
	Q->front = Q->rear = new Node;//创建一个头结点
	if (Q->front == NULL) {
		cout << "内存分配失败" << endl;
		return NULL;
	}
	Q->front->next = NULL;//头节点的next指针置为空
	return Q;
}
//2.判断链队列是否为空
bool IsEmpty(LinkQueue* Q) {
	if (Q->front == Q->rear) {
		return true;
	}
	return false;
}
//3.入队
bool EnQueue(LinkQueue* Q,DataType data) {
	if (Q == NULL) {
		return false;
	}
	Node* node = new Node;//创建一个新结点
	if (node == NULL) {
		cout << "内存分配失败" << endl;
		return false;
	}
	node->data = data;
	node->next = NULL;
	Q->rear->next = node;//将新节点插入到队尾
	Q->rear = node;//更新队尾指针
	return true;
}
//4.出队
bool DeQueue(LinkQueue* Q, DataType& data) {
	if (Q == NULL || IsEmpty(Q)) {
		return false;//队列为空或不存在，无法出队
	}
	Node* node = Q->front->next;//node指向队头元素节点
	data = node->data;//队头元素赋给data
	Q->front->next = node->next;//将头结点指向下一个节点
	if (Q->rear == node) {
		Q->rear = Q->front;
	}
	delete node;//释放出对结点的内存
	return true;
}
//5.获取队头元素
bool GetFront(LinkQueue* Q, DataType& data) {
	if (Q == NULL || IsEmpty(Q)) {
		return false;
	}
	Node* node = Q->front->next;//node指向队头元素节点
	data = node->data;//队头元素赋给data
	return true;
}
//测试主函数
int main() {
	//1.初始化
	LinkQueue* myQueue = InitQueue();
	if (myQueue == NULL) return -1;
	//2.判空
	cout << "当前队列是否为空：" << IsEmpty(myQueue) << endl;
	//3.入队
	cout<<"入队10："<<(EnQueue(myQueue, 10) ? "成功":"失败") << endl;
	cout<<"入队20："<<(EnQueue(myQueue, 20) ? "成功":"失败") << endl;
	cout<<"入队30："<<(EnQueue(myQueue, 30) ? "成功":"失败") << endl;
	cout << "入队后，队列是否为空：" << IsEmpty(myQueue) << endl;
	//5.获取队首元素
	DataType frontVal;
	if (GetFront(myQueue, frontVal)) {
		cout << "当前队首元素是：" << frontVal << endl;
	}
	//4.出队
	DataType popVal;
	if (DeQueue(myQueue, popVal)) {
		cout << "出队元素是：" << popVal << endl;
	}
	if (GetFront(myQueue, frontVal)) {
		cout << "出队一次后，队首元素为：" << frontVal << endl;
	}
	return 0;
}

