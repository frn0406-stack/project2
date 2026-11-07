#include<iostream>
using namespace std;
//定义联系人结构体
struct Contact
{
	char name[50];//联系人姓名
	char phone[12];//联系人电话
	struct Birthday
	{
		int year;
		int mounth;
		int day;
	}birthday;
	int age;
};
//定义通讯录节点结构体
struct Node
{
	Contact data;//联系人信息
	Node* next;//指向下一个节点的指针
};
/*函数功能：初始化一个空的通讯录链表
*函数形参：无
*返回值类型：返回一个空的通讯录链表的头指针，Node*类型
*/
Node* InitAddressBook()
{
	Node* head=new Node;//创建一个新结点
	if (head == NULL) {
		cout << "内存分配失败！" << endl;
	}
	else {
		head->next = NULL;
	}
	return head;
}
/*函数功能：采用头插法创建一个通讯录链表
*函数形参：通讯录链表头指针Node* head,联系人信息Contact
*返回值类型：创建成功返回true,否则返回false,bool类型
*/
bool CreateAddressBookHead(Node* head, Contact data) {
	Node* node = new Node;//创建一个新的节点
	if (node == NULL) {
		cout << "内存分配失败" << endl;
		return false;
	}
	node->data = data;//将联系人的信息赋值给新节点
	node->next = head->next;//将新节点的next指针指向头节点的下一个节点
	head-> next = node;//将头结点的next指针指向新节点
	return true;//创建成功返回true
}
/*函数功能：采用尾插法创建一个通讯录链表
*函数形参：通讯录链表头指针Node* head,联系人信息Contact
*返回值类型：创建成功返回true,否则返回false,bool类型
*/
bool CreateAddressBookTail(Node* head, Contact data) {
	static Node* tail = head;//定义一个尾指针，初始指向头节点
	Node* node = new Node;//创建一个新的节点
	if (node == NULL) {
		cout << "内存分配失败！" << endl;
		return false;
	}
	node->data = data;//将联系人信息赋值给新节点
	node->next = NULL;//将新节点的next指针置为空
	tail->next = node;//将尾指针next指向新节点
	tail = node;//将为指针指向新节点
	return true;
}
/*函数功能：输入单个联系人信息
*函数形参：无
*返回值类型：返回联系人信息，Contact类型
*/
Contact  InputContact() {
	Contact data;
	cout << "请输入联系人姓名："  << endl;
	cin >> data.name;
	cout << "请输入联系人电话：" << endl;
	cin >> data.phone;
	cout << "请输入联系人生日（年 月 日）：" << endl;
	cin >> data.birthday.year >> data.birthday.mounth >> data.birthday.day;
	data.age = 2026 - data.birthday.year;//计算年龄
	return data;
}
/*函数功能：输出单个联系人信息
*函数形参：联系人信息Contact data
*返回值类型:无，void类型
*/
void OutputContact(Contact data) {
	cout << "姓名：" << data.name << endl;
	cout << "电话：" << data.phone << endl;
	cout << "生日：" << data.birthday.year << "年" << data.birthday.mounth << "月" << data.birthday.day << "日" << endl;
	cout << "年龄：" << data.age << endl;
}
/*函数功能：输出通讯录中所有联系人的信息
*函数形参：通讯录链表头指针Node* head
*返回值类型:无，void类型
*/
void OutputAddressBook(Node* head) {
	Node* node = head->next;
	while (node) {
		OutputContact(node->data);
		node = node->next;
	}
}
/*函数功能：按姓名查找通讯录指定联系人信息
*函数形参：通讯录链表头指针Node*head，联系人姓名char name[]
*返回值类型:查找成功，返回地址，否则返回空，Node*类型
*/
Node* SearchContactByName(Node* head, char name[]) {
	Node* node = head->next;
	while (node) {
		if (strcmp(node->data.name, name) == 0)
			return node;//查找成功，返回结点地址
		node = node->next;
	}
	return NULL;//查找失败，返回空
}
/*函数功能：按电话号码查找通讯录指定联系人
*函数形参：通讯录链表头指针Node*head，联系人电话char phone[]
*返回值类型:查找成功，返回地址，否则返回空，Node*类型
*/
Node* SearchContactByPhone(Node* head, char* phone) {
	Node* node = head->next;
	while (node) {
		if (strcmp(node->data.phone, phone) == 0)
			return node;//查找成功，返回节点地址
		node = node->next;
	}
	return NULL;//查找失败，返回空
}
/*函数功能：查找指定联系人的前驱点
*函数形参：通讯录链表头指针Node*head，指定联系人地址Node* target
*返回值类型:查找成功，返回前驱点，否则返回空，Node*类型
*/
Node* SearchPreNode(Node* head, Node* target) {
	for (Node* pre = head;pre->next != NULL;pre = pre->next) {
		if (pre->next == target) {
			return pre;//查找成功，返回前驱结点地址
		}
	}
	return NULL;//查找失败，返回空
}
/*函数功能：在指定联系人的后面插入一个新的联系人
*函数形参：通讯录链表头指针Node*head，指定联系人地址Node* target联系人的信息(Contact data)
*返回值类型:插入成功，返回true，否则返回false，bool类型
*/
bool InsertContactAfter(Node* head, Node* target,Contact data) {
	Node* node = new Node;
	if (true) {
		node->data = data;//数据域赋值
		node->next = target->next;//指针域赋值
		target->next = node;//将指定结点指向新的节点
		return true;
	}
	return false;
}

/*函数功能：在指定联系人前面插入一个新的联系人
*函数形参：通讯录链表头指针Node*head，指定联系人地址Node* target联系人的信息(Contact data)
*返回值类型:插入成功，返回true，否则返回false，void类型
*/
bool InserContactBefor(Node* head, Node* target, Contact data) {
	Node* pre = SearchPreNode(head, target);//查找指定联系人的前驱节点
	if (pre) {
		Node* node = new Node;//创建一个新结点
		if (node) {
			node->data = data;
			node->next = target;
			pre->next = node;//将前驱结点的next指向新节点
			return true;//插入成功，返回true
		}
	}
	return false;//插入失败，返回false
}
/*函数功能：删除指定联系人
*函数形参：通讯录链表头指针Node*head，指定联系人地址Node* target
*返回值类型:删除成功，返回true，否则返回false,bool类型
*/
bool DeleteContact(Node* head, Node* target) {
	Node* pre = SearchPreNode(head, target);//查找联系人的前驱节点
	if (pre) {
		pre->next = target->next;//将前驱结点的next指针指向指定节点的下一个节点
		delete target;//释放指定节点的内存空间
		return true;//删除成功，返回true
	}
	return false;
}
/*函数功能：删除指定联系人的后继
*函数形参：通讯录链表头指针Node*head，指定联系人地址Node* target
*返回值类型:删除成功，返回true，否则返回false,bool类型
*/
bool DeleteContactNext(Node* head, Node* target) {
	if (target->next)//判断指定节点是否有后继节点
	{
		Node* node = target->next;//保存指定节点的后继节点
		target->next = node->next;//将指定节点指向后继节点的下一个节点
		delete node;//释放后继节点的的内存空间
		return true;//删除成功
	}
	return false;//删除失败，返回false
}
/*函数功能：打印用户选择菜单
*函数形参：无
*返回了类型：返回用户的选择，int类型
*/
int PrintMenu() {
	int choice;
	cout <<"====================通讯录管理程序====================" << endl;
	cout <<"1.添加联系人" << endl;
	cout <<"2.删除联系人" << endl;
	cout << "3.查找联系人" << endl;
	cout << "4.修改联系人" << endl;
	cout << "5.显示所有联系人" << endl;
	cout << "6.退出程序" << endl;
	cout << "=======================================================" << endl;
	cout << "请输入您的选择（1-6）" << endl;
	cin >> choice;
	return choice; 
}
int main() {
	Node* myBook = InitAddressBook();
	if (myBook == NULL) return -1;
	int choice;
	while (true) {
		choice=PrintMenu();
		if (choice == 6) break;
		char nameBuf[50], phoneBuf[20];
		Node* target = NULL;
		Contact newContact;
		switch (choice) {
		case 1: //1.添加联系人
			int addchoice;
			cout << "\n---请选择添加方式---\n" << endl;
			cout << "1.尾插法" << endl;
			cout << "2.头插法" << endl;
			cout << "请输入（1-2）：" << endl;
			cin >> addchoice;
			newContact = InputContact();
			if (addchoice == 1) {
				if (CreateAddressBookTail(myBook, newContact))
					cout << "尾插法添加成功！\n" << endl;
			}
			else if (addchoice == 2) {
				if (CreateAddressBookHead(myBook, newContact)) {
					cout << "头插法添加成功！\n" << endl;
				}
			}
			else {
				cout << "无效选择，添加失败！\n" << endl;
			}
			break;
		case 2: //2.删除联系人
			int delchoice;
			cout << "\n---请选择删除方式---" << endl;
			cout << "1.删除指定联系人本人" << endl;
			cout << "2.删除指定联系人的下一个人" << endl;
			cout << "请输入（1-2）：" << endl;
			cin >> delchoice;
			cout << "请输入目标联系人姓名：" << endl;
			cin >> nameBuf;
			target = SearchContactByName(myBook, nameBuf);//找人
			if (target != NULL) {
				if (delchoice == 1) {
					if (DeleteContact(myBook, target)) {
						cout << "删除成功！\n" << endl;
					}
					else if (delchoice == 2) {
						if (DeleteContactNext(myBook, target)) {
							cout << "已成功删除它后面的那个人！\n" << endl;
						}
						else {
							cout << "删除失败：目标后面没人了！\n" << endl;
						}
					}
				}
			}
			else {
				cout << "查无此人，无法删除！\n" << endl;
			}
			break;
		case 3: //3.查找联系人
			int searchchoice;
			cout << "\n---请选择查找方式---" << endl;
			cout << "1.按姓名查找" << endl;
			cout << "2.按电话查找" << endl;
			cout << "请输入（1-2）：" << endl;
			cin >> searchchoice;
			if (searchchoice == 1) {
				cout << "请输入姓名：" << endl;
				cin >> nameBuf;
				target = SearchContactByName(myBook, nameBuf);
			}
			else if (searchchoice == 2) {
				cout << "请输入电话：" << endl;
				cin >> phoneBuf;
				target = SearchContactByPhone(myBook, phoneBuf);
			}
			if (target != NULL) {
				cout << "找到联系人信息：" << endl;
				OutputContact(target->data);
			}
			else {
				cout << "未找到该联系人！\n" << endl;
			}
			break;
		case 4: //4.修改联系人
			cout << "\n---修改联系人---\n：" << endl;
			cout << "请输入要修改联系人的姓名：" << endl;
			cin >> nameBuf;
			target = SearchContactByName(myBook, nameBuf);
			if (target != NULL) {
				cout << "已找到该联系人，请重新输入他的信息：" << endl;
				target->data = InputContact();//直接调用输入函数，把新数据覆盖掉原来的数据
				cout << "修改成功！\n" << endl;
			}
			else {
				cout << "查无此人，无法修改！\n" << endl;
			}
			break;
		case 5: {//5.显示所有联系人
			cout << "================通讯录列表================\n" << endl;
			OutputAddressBook(myBook);//调用遍历输出函数
			cout << "==========================================\n" << endl;
			break;
		}
		case 6: //6.退出程序
			cout << "感谢使用通讯录管理系统，再见!\n" << endl;
			return 0;
	   }
	}
}