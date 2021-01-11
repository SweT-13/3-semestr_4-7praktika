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
	//Если есть элем перед то у него заменяем след на след текущего
	if (before) {
		before->after = after;
	}
	//Если есть элем след то у него заменяем перед на перед текущего
	if (after) {
		after->before = before;
	}
	//Проверка на пренадлежность к листу
	if (uplist) {
		//Замена адреса головы листа
		if (uplist->head == this) {
			uplist->head = after;
		}
		//Замена адреса хвоста листа
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
	//Проверка на нулевой указатель и остановка программы
	if (!obj) {
		if (debag) {
			std::cout << "Error" << std::endl << "NuLL pointer" << std::endl;
			system("pause");
		}
	}
	else {
		obj->uplist = this;
		//Если список пуст то надо и указатель на начальный элемент изменить
		if (!head) {
			head = obj;
			obj->before = NULL;
		}
		//Если список был НЕ пуст надо позаботиться о связи итемов
		if (tail) {
			tail->after = obj;
			obj->before = tail;
		}
		//Действия выполняемые в любом случае(обновление адреса хвоста и ..)
		tail = obj;
		obj->after = NULL;
	}
}
void List::Del(const int n) {
	Item* current = NULL;
	current = GetItem(n);
	//Если не найдет элемент с нужным номером, вернет 0 адрес который нельзя будет удалить
	if (current) {
		delete current;
	}
}
Item* List::Remove(const int n) {
	Item* current = NULL;
	current = GetItem(n);
	//Если вернет не нул надо вырезать элемент
	if (current) {
		//Если есть элем перед то у него заменяем след на след текущего
		if (current->before) {
			current->before->after = current->after;
		}
		//Если есть элем след то у него заменяем перед на перед текущего
		if (current->after) {
			current->after->before = current->before;
		}
		//Проверка на пренадлежность к листу
		if (current->uplist) {
			//Замена адреса головы листа
			if (current->uplist->head == current) {
				current->uplist->head = current->after;
			}
			//Замена адреса хвоста листа
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
	//Нулегово элемента в списке нету
	if (n == 0)
		return 0;
	Item* current = NULL;
	//Разветвление на счет с головы или с хвоста
	if (n > 0) {
		current = head;
		int i = 1;
		//Поиск элемента, смотря на то что случиться раньше список закончиться или номер найдет
		while (current && i != n) {
			current = current->after;
			i++;
		}
	}
	else
	{
		current = tail;
		int i = -1;
		//Поиск элемента, смотря на то что случиться раньше список закончиться или номер найдет
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
		//Если элем по номеру не найдет,
		//значит его нет в списке и полученный объект мы добовляем в конец списка
		if (current) {
			obj->before = current;
			obj->after = current->after;
			//Если элемент был не крайним, то у след надо заменить перед на адрес текущего
			if (obj->after)
				obj->after->before = obj;
			//Если условие не выполнилось значит элем был крайним и надо заменить адрес хвоста списка
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
	//Проход по элем листа
	while (current)
	{
		//Если адреса совпадают возвращает номер и завершает работу
		if (current == obj)
			return i;
		current = current->after;
		i++;
	}
	//Если элемент не найдет, вернет 0
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

