#include <iostream>
#include "subjA.h"

//������� �����))
//��� ��� ��� ����� ������
bool debag = false;

using namespace std;

int GetNum(bool s = false) {
	if (s)
		std::cout << ">> Enter num\n<< ";
	int a;
	while (true) {
		std::cin >> a;
		if (std::cin.fail()) // ���� ���������� ���������� ��������� ���������,
		{
			std::cout << "ERROR" << std::endl << ">> Is not num" << std::endl << std::endl << ">> Num pls)\n<< ";
			std::cin.clear(); // �� ���������� cin � '�������' ����� ������
			std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
		}
		else // ���� �� ������, �� ���������� a
			return a;
	}
}

void Menu() {
	std::cout
		<< "Choose num actions" << std::endl
		<< "1-add" << std::endl
		<< "2-del" << std::endl
		<< "3-get item" << std::endl
		<< "4-remove" << std::endl
		<< "5-insert" << std::endl
		<< "6-count" << std::endl
		<< "7-clear" << std::endl
		<< "8-get index" << std::endl
		<< "9-found" << std::endl
		<< "10-sort" << std::endl
		<< "0-exit" << std::endl
		<< "<< ";
}

int main() {
	int key = 0;
	Item* buf = NULL;
	List L;
	std::cout << "Hello User" << std::endl << std::endl;
	do {
		Menu();
		key = GetNum();
		switch (key)
		{
		case(-1)://����� ������
			Print(&L);
			std::system("pause");
			break;
		case(1)://���������� ��������
			if (!buf)
				buf = L.Create();
			L.Add(buf);
			buf = NULL;
			break;
		case(2)://�������� ��������
			L.Del(GetNum(true));
			break;
		case(3)://��������� ������ �������� �� ��������� �� ����
			if (buf)
				delete buf;
			buf = L.GetItem(GetNum(true));
			std::cout << ">> " << buf << std::endl;
			std::system("pause");
			buf = NULL;
			break;
		case(4)://��������� �������� �� ������
			if (buf)
				delete buf;
			buf = L.Remove(GetNum(true));
			break;
		case(5)://������� ��������
			L.Insert(buf, GetNum(true));
			break;
		case(6)://������� ��������� ������
			std::cout << ">> " << L.Count() << std::endl;
			std::system("pause");
			break;
		case(7)://�������� ������
			if (buf)
				delete buf;
			L.Clear();
			break;
		case(8)://��������� ������ �� ������
			L.GetIndedx(buf);
			break;
		case(9)://�����
			L.Found();
			std::system("pause");
			break;
		case(10)://����������
			L.Sort();
			break;
		case(0)://���������� ���������
			break;
		case(255)://:D
			std::system("cls");
			debag = !debag;
			std::cout << "MODE TRANSFORM" << std::endl << "Debag " << debag << "\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n-\n";
			std::system("pause");
			break;
		default:
			cout << "Sor, I not understand u" << std::endl;
			std::system("pause");
			break;
		}
		std::system("cls");
		std::cout << buf << std::endl;
		if (debag)
			std::cout << "BAAAAAAAAAAAAAAAAAAAAAG mode :D" << std::endl;
		std::cout << std::endl;
	} while (key);
	if (buf)
		delete buf;
	std::system("cls");
	std::cout << ">> Good bye " << std::endl;
	std::system("pause");
	return 0;
}