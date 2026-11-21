#include<iostream>
using namespace std;
typedef int DataType;
struct SeqQueue//顺序队列的数据结构
{
	DataType* data;
	int front;
	int rear;
	int maxSize;
};
//1.初始化队列
SeqQueue* InitQueue(int maxsize)
{
	SeqQueue* Q = new SeqQueue;//创建一个新的顺序队列
	if (Q==NULL) {
		cout << "内存分配失败！" << endl;
		return NULL; 
	}
	Q->data = new DataType[maxsize];//为顺序队列分配存储空间
	Q->front = 0;
	Q->rear = 0;
	Q->maxSize = maxsize;//设置队列的最大容量
	return Q;
}
//2.判断队列是否为空
bool IsEmpty(SeqQueue* Q)
{
	if (Q->front == Q->rear) {
		return true;
	}
	return false;
}
//3.判断顺序队列是否满
bool IsFull(SeqQueue* Q)
{
	if ((Q->rear + 1) % Q->maxSize == Q->front) {
		return true;
	}
	return false;
}
//4.入队操作
bool EnQueue(SeqQueue* Q, DataType e)
{
	if (IsFull(Q)) {
		cout << "队列已满，无法入队！" << endl;
		return false;
	}
	Q->data[Q->rear] = e;//将元素e插入到队尾
	Q->rear = (Q->rear + 1) % Q->maxSize;//更新队尾指针
	return true;
}
//5.出队操作
bool DeQueue(SeqQueue* Q, DataType& e)
{
	if (IsEmpty(Q)) {
		cout << "队列为空，无法出队！" << endl;
		return false;
	}
	e = Q->data[Q->front];//将队头元素赋值给e
	Q->front = (Q->front + 1) % Q->maxSize;//更新队头指针
	return true;
}
//6.获取队头元素
bool FirstQueue(SeqQueue* Q, DataType& e) {
	if (IsEmpty(Q)) {
		cout << "队列为空，无法获取队头元素！" << endl;
		return false;
	}
	e = Q->data[Q->front];//将队头元素赋值给e
	return true;
}
//测试主函数
int main() {
	cout << "---1.测试初始化队列---" << endl;
	SeqQueue* Q = InitQueue(5);
	//验证是否为空
	if (IsEmpty(Q)) {
		cout << "当前列队为空" << endl;
	}
	cout << "\n---测试入队---" << endl;
	//入队操作
	cout << "入队 10" << (EnQueue(Q, 10) ? "成功" : "失败") << endl;
	cout << "入队 20" << (EnQueue(Q, 20) ? "成功" : "失败") << endl;
	cout << "入队 30" << (EnQueue(Q, 30) ? "成功" : "失败") << endl;
	cout << "\n---获取队头元素---" << endl;
	DataType frontVal;
	if (FirstQueue(Q, frontVal)) {
		cout << "队头元素为: " << frontVal << endl;
	}
	cout << "\n---测试出队---" << endl;
	DataType outVal;
	if (DeQueue(Q, outVal)) {
		cout << "出队元素为：" << outVal << endl;
	}
	//出队后看队头
	if (FirstQueue(Q, frontVal)) {
		cout << "出队后，当前队头元素为：" << frontVal << endl;
	}
	cout << "\n---测试队列是否满---" << endl;
	cout << "继续入队40：" << (EnQueue(Q, 40) ? "成功" : "失败") << endl;
	cout << "继续入队50：" << (EnQueue(Q, 50) ? "成功" : "失败") << endl;
	cout << "继续入队60：" << (EnQueue(Q, 60) ? "成功" : "失败") << endl;
}

