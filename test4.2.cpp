#include <iostream>
#include<stack>
#include<string>
using namespace std;
//定义转换函数
string decimalToBase(int num, int base) {
	//处理特殊情况：如果输入的是十进制数是0，直接返回“0”
	if (num == 0) {
		return"0";
	}
	//声明一个整型栈，用于存储每次除以base的余数
	stack<int> s;
	while (num > 0) {
		s.push(num % base);//取余数并压栈（push）
		num = num / base;//更新数字为商
	}
	//声明一个空字符串用于拼接最终结果
	string result = "";
	//依次弹出栈顶顺序
	while (!s.empty()) {
		//将栈顶的整数转换为字符串，并拼接到结果字符串的末尾
		result += to_string(s.top());
		s.pop();
	}
	return result;
}
int main() {
	int num, base;
	cout << "请输入一个十进制的整数num:" << endl;
	cin >> num;
	cout << "请输入目标进制base（2<=base<=9）:" << endl;
	cin >> base;
	if (base < 2 || base>9) {
		cout << "错误：base的取值范围必须在2-9之间！" << endl;
		return 1;
	}
	string result = decimalToBase(num, base);
	cout << "十进制数" << num << "转换为" << base << "进制的结果是：" << result << endl;
	return 0;
}