#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;
bool isValid(string s) {
	stack<char> st;//初始化一个空栈
	bool flag = true;//设置标记变量flag,初值为true
	//扫描表达式，依次读入字符ch
	for (char ch : s) {
		if (!flag) break;
		if (ch == '(' || ch == '[' || ch == '{') {
			//若是左括号，压入栈中
			st.push(ch);
		}
		else if (ch == ')') {
			//若是右括号‘)’
			if (!st.empty() && st.top() == '(') {
				st.pop();//正确匹配，出栈
			}
			else {
				flag = false;//错误匹配
			}
		}
		else if (ch == ']') {
			//若是右括号"]"
			if (!st.empty() && st.top() == ']') {
				st.pop();
			}
			else {
				flag = false;
			}
		}
		else if (ch == '}') {
			//若是右括号"}"
			if (!st.empty() && st.top() == '{') {
				st.pop();
			}
			else {
				flag = false;
			}
		}
	}
	return flag && st.empty();
}
int main() {
	cout << "输入：{()[{}]} 输出：" << (isValid("{()[{}]}") ? "匹配" : "不匹配") << endl;
	cout << "输入：(){[}]() 输出：" << (isValid("(){[}]()") ? "匹配" : "不匹配")<< endl;
	return 0;
}