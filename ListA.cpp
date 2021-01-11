#include <iostream>
#include "ListA.h"

List::List()
{
	head = tail = NULL;
}
List::~List()
{
	if (head) {
		Item* current = head;
		while (current) {
			delete current;
			current = head;
		}
	}
	head = tail = NULL;
	if (debag) {
		std::cout << "BB list\n";
		std::system("pause");
	}

}

Item::Item()
{
	before = after = NULL;
	uplist = NULL;
}
Item::~Item()
{
	//���� ���� ���� ����� �� � ���� �������� ���� �� ���� ��������
	if (before) {
		before->after = after;
	}
	//���� ���� ���� ���� �� � ���� �������� ����� �� ����� ��������
	if (after) {
		after->before = before;
	}
	//�������� �� �������������� � �����
	if (uplist) {
		//������ ������ ������ �����
		if (uplist->head == this) {
			uplist->head = after;
		}
		//������ ������ ������ �����
		if (uplist->tail == this) {
			uplist->tail = before;
		}
	}
	if (debag) {
		std::cout << "BB item\n";
		std::system("pause");
	}
}

void List::Add(Item* obj) {
	//�������� �� ������� ��������� � ��������� ���������
	if (!obj) {
		if (debag) {
			std::cout << "Error" << std::endl << "NuLL pointer" << std::endl;
			system("pause");
		}
	}
	else {
		obj->uplist = this;
		//���� ������ ���� �� ���� � ��������� �� ��������� ������� ��������
		if (!head) {
			head = obj;
			obj->before = NULL;
		}
		//���� ������ ��� �� ���� ���� ������������ � ����� ������
		if (tail) {
			tail->after = obj;
			obj->before = tail;
		}
		//�������� ����������� � ����� ������(���������� ������ ������ � ..)
		tail = obj;
		obj->after = NULL;
	}
}
void List::Del(const int n) {
	Item* current = NULL;
	current = GetItem(n);
	//���� �� ������ ������� � ������ �������, ������ 0 ����� ������� ������ ����� �������
	if (current) {
		delete current;
	}
}
Item* List::Remove(const int n) {
	Item* current = NULL;
	current = GetItem(n);
	//���� ������ �� ��� ���� �������� �������
	if (current) {
		//���� ���� ���� ����� �� � ���� �������� ���� �� ���� ��������
		if (current->before) {
			current->before->after = current->after;
		}
		//���� ���� ���� ���� �� � ���� �������� ����� �� ����� ��������
		if (current->after) {
			current->after->before = current->before;
		}
		//�������� �� �������������� � �����
		if (current->uplist) {
			//������ ������ ������ �����
			if (current->uplist->head == current) {
				current->uplist->head = current->after;
			}
			//������ ������ ������ �����
			if (current->uplist->tail == current) {
				current->uplist->tail = current->before;
			}
		}
		current->after = current->after = NULL;
		current->uplist = NULL;
	}
	return current;
}
Item* List::GetItem(const int n) {
	//�������� �������� � ������ ����
	if (n == 0)
		return 0;
	Item* current = NULL;
	//������������ �� ���� � ������ ��� � ������
	if (n > 0) {
		current = head;
		int i = 1;
		//����� ��������, ������ �� �� ��� ��������� ������ ������ ����������� ��� ����� ������
		while (current && i != n) {
			current = current->after;
			i++;
		}
	}
	else
	{
		current = tail;
		int i = -1;
		//����� ��������, ������ �� �� ��� ��������� ������ ������ ����������� ��� ����� ������
		while (current && i != n) {
			current = current->before;
			i--;
		}
	}
	return current;
}
int List::Count() {
	Item* current = head;
	int i = 0;
	while (current) {
		i++;
		current = current->after;
	}
	return i;
}
void List::Clear() {
	if (head) {
		Item* current = head;
		while (current) {
			delete current;
			current = head;
		}
	}
	head = tail = NULL;
}
void List::Insert(Item* obj, const int n) {
	if (!obj) {
		std::cout << "Error" << std::endl << "NuLL pointer" << std::endl;
		system("pause");
	}
	else
	{
		Item* current = NULL;
		current = GetItem(n);
		//���� ���� �� ������ �� ������,
		//������ ��� ��� � ������ � ���������� ������ �� ��������� � ����� ������
		if (current) {
			obj->before = current;
			obj->after = current->after;
			//���� ������� ��� �� �������, �� � ���� ���� �������� ����� �� ����� ��������
			if (obj->after)
				obj->after->before = obj;
			//���� ������� �� ����������� ������ ���� ��� ������� � ���� �������� ����� ������ ������
			else
				tail = obj;
			current->after = obj;
			obj->uplist = this;
		}
		else
			Add(obj);
	}
}
int List::GetIndedx(const Item* obj) {
	Item* current = head;
	int i = 1;
	//������ �� ���� �����
	while (current)
	{
		//���� ������ ��������� ���������� ����� � ��������� ������
		if (current == obj)
			return i;
		current = current->after;
		i++;
	}
	//���� ������� �� ������, ������ 0
	return 0;
}

void Item::Print() {
	std::cout << "Before\t\tCurrent\t\tAfter\t\tuplist" << std::endl;
	std::cout << before << "\t" << this << "\t" << after << "\t" << uplist << std::endl;
}

void Print(const List* l) {
	std::cout << "List\t\tHead\t\tTail" << std::endl;
	std::cout << l << "\t" << l->head << "\t" << l->tail << std::endl;
	if (l->head) {
		Item* current = l->head;
		while (current)
		{
			current->Print();
			current = current->after;
		}
	}
}

