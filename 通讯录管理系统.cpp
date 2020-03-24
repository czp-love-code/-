#include<iostream>
#include<string>

#define MAX 1000

using namespace std;

struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct AddressBook
{
	struct Person personArray[MAX];

	int m_Size;
};

void addPerson(AddressBook* abs)
{
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入姓名：";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		int sex;
		cout << "请输入性别：" << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		
		int age = 0;
		cout << "请输入年龄：";
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		string phone;
		cout << "请输入联系方式：";
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string address;
		cout << "请输入住址：";
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		
		abs->m_Size++;
		cout << "添加成功！" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(AddressBook* abs)
{
	if (abs->m_Size == 0) {
		cout << "当前记录为空！" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name << endl;
			cout << "性别：" << (abs->personArray[i].m_Sex==1?"男":"女") << endl;
			cout << "年龄：" << abs->personArray[i].m_Age <<endl;
			cout << "电话：" << abs->personArray[i].m_Phone << endl;
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(AddressBook* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
			return i;
	}
	return -1;
}

void deletePerson(AddressBook* abs)
{
	cout << "请输入要删除的联系人姓名：";
	string name;
	cin >> name;

	int ret = isExist(abs,name);

	if (ret == -1) {
		cout << "查无此人！" << endl;
	}
	else {
		for (int i = ret; i < abs->m_Size-1; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功！" << endl;
		system("pause");
		system("cls");
	}
}

void findPerson(AddressBook* abs)
{
	cout << "请输入要查找的联系人：";
	string name;
	cin >> name;
	
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "查无此人！" << endl;	
	}
	else {
		cout << "姓名：" << abs->personArray[ret].m_Name << endl;
		cout << "性别：" << (abs->personArray[ret].m_Sex==1?"男":"女") << endl;
		cout << "年龄：" << abs->personArray[ret].m_Age << endl;
		cout << "电话：" << abs->personArray[ret].m_Phone << endl;
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(AddressBook* abs)
{
	cout << "请输入要修改的联系人姓名：";
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret == -1) {
		cout << "查无此人!" << endl;
	}
	else {
		cout << "请输入新的联系人姓名：";
		string newName;
		cin >> newName;
		abs->personArray[ret].m_Name = newName;

		cout << "请输入新的联系人性别：";
		int newSex;
		
		while (true) {
			cin >> newSex;
			if (newSex == 1 || newSex == 2) {
				abs->personArray[ret].m_Sex = newSex;
				break;
			}
			cout << "输入有误，请重新输入（1、男\t2、女）" << endl;
		}

		cout << "请输入新的联系人年龄：";
		int newAge;
		cin >> newAge;
		abs->personArray[ret].m_Age = newAge;

		cout << "请输入新的联系人电话：";
		string newPhone;
		cin >> newPhone;
		abs->personArray[ret].m_Phone = newPhone;

		cout << "请输入新的联系人住址：";
		string newAddress;
		cin >> newAddress;
		abs->personArray[ret].m_Addr = newAddress;
	}
	system("pause");
	system("cls");
}

void cleanPerson(AddressBook* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空！" << endl;
	system("pause");
	system("cls");
}

void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

int main()
{
	AddressBook abs;
	abs.m_Size = 0;

	int select = 0;

	while (true)
	{
		showMenu();

		cin >> select;
		switch (select) {
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
		}
	}

	system("pause");
	return 0;
}