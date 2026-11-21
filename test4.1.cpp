#include<iostream>
using namespace std;
//定义顺序栈的结构体
typedef int DataType;
struct Stack
{
	int top;//栈底指针，指向栈顶元素下标
	int maxsize;//顺序栈的最大空间
	DataType* elem;//存放顺序栈的栈元素
};
//1.初始化一个空的顺序栈
Stack* InitStack(int maxsize) {
	Stack* stack = new Stack;//创建一个新的顺序栈
	if (stack == NULL) {
		cout << "内存分配失败！" << endl;
		return NULL;
	}
	stack->elem= new DataType[maxsize];//为顺序栈分配空间
	if (stack->elem == NULL) {
		cout << "内存分配失败！" << endl;
		delete stack;
		return NULL;
	}
	stack->top = -1;//初始化栈顶指针为-1，表示栈为空
	stack->maxsize = maxsize;//设置顺序栈的最大空间
	return stack;//返回顺序栈的指针
}
//2.判断栈是否为空
bool IsEmpty(Stack* s) {
	if (s->top == -1) {
		return true;
	}
	return false;
}
//3.判断顺序栈是否满
bool IsFull(Stack* s) {
	if (s->top == s->maxsize - 1) {
		return true;
	}
	return false;
}
//4.入栈
bool Push(Stack* s, DataType x) {
	if (IsFull(s)) {
		cout << "栈已满，无法入栈！" << endl;
		return false;
	}
	s->top++;//栈顶指针先加1
	s->elem[s->top] = x;
	return true;
}
//5.出栈
//通过引用参数x返回出栈的元素，成功返回true，失败返回false
bool Pop(Stack* s, DataType& x) {
	if(IsEmpty(s)) {
		cout << "栈为空，无法出栈！" << endl;
		return false;
	}
	x = s->elem[s->top];//取出栈顶元素
	s->top--;//栈顶指针减1
	return true;
}
//6.获取栈顶元素值
//通过引用参数x返回栈顶元素，但不改变栈顶指针。成功返回true,失败返回false
bool GetTop(Stack* s, DataType& x) {
	if (IsEmpty(s)) {
		cout << "栈为空，无法获取栈顶元素！" << endl;
		return false;
	}
	x = s->elem[s->top];//取出栈顶元素
	return true;
}
int main() {
	Stack* myStack = InitStack(5);
	cout << "初始化后，栈是否为空：" << (IsEmpty(myStack) ? "是" : "否") << endl;
	//测试入栈
	cout << "\n开始入栈10，20，30：" << endl;
	Push(myStack, 10);
	Push(myStack, 20);
	Push(myStack, 30);
	//获取栈顶元素
	DataType topVal;
	if (GetTop(myStack, topVal)) {
		cout << "当前栈顶元素为：" << topVal << endl;
	}
	//测试出栈
	DataType popVal;
	if (Pop(myStack, popVal)) {
		cout << "出战元素为：" << popVal << endl;
	}
	if (GetTop(myStack, topVal)) {
		cout << "出栈一次后，当前栈顶元素为：" << topVal << endl;
	}
	//测试栈满情况
	cout << "\n继续入栈40，50，60：" << endl;
	Push(myStack, 40);
	Push(myStack, 50);
	Push(myStack, 60);
	cout << "当前栈是否已满：" << (IsFull(myStack) ? "是" : "否") << endl;
	//释放内存
	delete[] myStack->elem;
	delete myStack;
	return 0;
}