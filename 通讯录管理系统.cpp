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
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else {
		string name;
		cout << "������������";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		int sex;
		cout << "�������Ա�" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		
		int age = 0;
		cout << "���������䣺";
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		string phone;
		cout << "��������ϵ��ʽ��";
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string address;
		cout << "������סַ��";
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		
		abs->m_Size++;
		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(AddressBook* abs)
{
	if (abs->m_Size == 0) {
		cout << "��ǰ��¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArray[i].m_Name << endl;
			cout << "�Ա�" << (abs->personArray[i].m_Sex==1?"��":"Ů") << endl;
			cout << "���䣺" << abs->personArray[i].m_Age <<endl;
			cout << "�绰��" << abs->personArray[i].m_Phone << endl;
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
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
	cout << "������Ҫɾ������ϵ��������";
	string name;
	cin >> name;

	int ret = isExist(abs,name);

	if (ret == -1) {
		cout << "���޴��ˣ�" << endl;
	}
	else {
		for (int i = ret; i < abs->m_Size-1; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ���" << endl;
		system("pause");
		system("cls");
	}
}

void findPerson(AddressBook* abs)
{
	cout << "������Ҫ���ҵ���ϵ�ˣ�";
	string name;
	cin >> name;
	
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "���޴��ˣ�" << endl;	
	}
	else {
		cout << "������" << abs->personArray[ret].m_Name << endl;
		cout << "�Ա�" << (abs->personArray[ret].m_Sex==1?"��":"Ů") << endl;
		cout << "���䣺" << abs->personArray[ret].m_Age << endl;
		cout << "�绰��" << abs->personArray[ret].m_Phone << endl;
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(AddressBook* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��������";
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret == -1) {
		cout << "���޴���!" << endl;
	}
	else {
		cout << "�������µ���ϵ��������";
		string newName;
		cin >> newName;
		abs->personArray[ret].m_Name = newName;

		cout << "�������µ���ϵ���Ա�";
		int newSex;
		
		while (true) {
			cin >> newSex;
			if (newSex == 1 || newSex == 2) {
				abs->personArray[ret].m_Sex = newSex;
				break;
			}
			cout << "�����������������루1����\t2��Ů��" << endl;
		}

		cout << "�������µ���ϵ�����䣺";
		int newAge;
		cin >> newAge;
		abs->personArray[ret].m_Age = newAge;

		cout << "�������µ���ϵ�˵绰��";
		string newPhone;
		cin >> newPhone;
		abs->personArray[ret].m_Phone = newPhone;

		cout << "�������µ���ϵ��סַ��";
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
	cout << "ͨѶ¼����գ�" << endl;
	system("pause");
	system("cls");
}

void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
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
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
		}
	}

	system("pause");
	return 0;
}