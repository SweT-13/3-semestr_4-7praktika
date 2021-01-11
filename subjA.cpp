#include <iostream>
#include "subjA.h"
extern bool debag;

int ID = 1;

std::ostream& operator<< (std::ostream& out, const Type& ty) {
	switch (ty)
	{
	case(Type::None):
		out << "None";
		break;
	case(Type::Detail):
		out << "Detail";
		break;
	case(Type::Implement):
		out << "Implement";
		break;
	}
	return out;
}

Base::Base()
{
	name.clear();
	type = Type::None;
}
Base::~Base()
{
	name.clear();
	if (debag) {
		std::cout << "BB Base\n";
		std::system("pause");
	}
}
void Base::Print() {
	std::cout << type << " -------------------------" << std::endl;
	Item::Print();
	std::cout << "name -> \"" << name << "\"" << std::endl;
}
void Base::Write() {
	if (!debag) {
		std::cout << ">> Enter name\n<< ";
		std::cin >> name;
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}
}

Detail::Detail()
{
	shifr.clear();
	id = ID++;
	wh = ht = 0;
}
Detail::~Detail()
{
	shifr.clear();
	if (uplist) {
		Item* current = uplist->head;
		Item* next = NULL;
		while (current)
		{
			next = current->after;
			if (current != this)
			{
				if (current->Get_id() == id)
				{
					if (debag) {
						std::cout << "BB Delat means and BB Implement\n";
						std::system("pause");
					}
					delete current;
				}
			}
			current = next;
		}
	}
	if (debag) {
		std::cout << "BB Detail\n";
		std::system("pause");
	}
}
void Detail::Write()
{
	Base::Write();
	std::cout << ">> Enter width\n<< ";
	while (true)
	{
		std::cin >> wh;
		if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			std::cout << "ERROR" << std::endl << ">> Is not num" << std::endl << std::endl << ">> Num pls)\n<< ";
			std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
		}
		else
			if (wh > 0)
				break;
			else
				std::cout << ">> positive number please\n<< ";
	}
	std::cout << ">> Enter height\n<< ";
	while (true)
	{
		std::cin >> ht;
		if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			std::cout << "ERROR" << std::endl << ">> Is not num" << std::endl << std::endl << ">> Num pls)\n<< ";
			std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
		}
		else
			if (ht > 0)
				break;
			else
				std::cout << ">> positive number please\n<< ";
	}
	std::cout << ">> Enter shifr\n<< ";
	std::cin >> shifr;
}
void Detail::Print() {
	Base::Print();
	std::cout << "id\twh\tht\tshifr" << std::endl;
	std::cout << id << "\t" << wh << "\t" << ht << "\t" << shifr << std::endl;
}
bool operator> (const Detail& d1, const Detail& d2) {
	if (d1.ht * d1.wh > d2.ht * d2.wh)
		return true;
	else
		return false;
}
bool operator< (const Detail& d1, const Detail& d2) {
	if (d1.ht * d1.wh < d2.ht * d2.wh)
		return true;
	else
		return false;
}

Implement::Implement()
{
	detail_id = 0;
	count = 0;
}
Implement::~Implement()
{
	if (debag) {
		std::cout << "BB Implement\n";
		std::system("pause");
	}
}
bool foundid(Item* start, int id, bool d = true) {
	if (start == 0)
		return false;
	Item* current = start;
	while (current)
	{
		if (current->Get_id() == id)
		{
			return true;
		}
		current = current->after;
	}
	if (d)//Возможность отключить интерфейс
		std::cout << ">> I don't found id" << std::endl;
	return false;
}
void Implement::Write()
{
	Base::Write();
	do {
		std::cout << ">> Enter detail_id(0-Exit)\n<< ";
		while (true) {
			std::cin >> detail_id;
			if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
			{
				std::cout << "ERROR" << std::endl << ">> Is not num" << std::endl << std::endl << ">> Num pls)\n<< ";
				std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
				std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			}
			else // если всё хорошо
				break;
		}
	} while (detail_id != 0 ? !foundid(uplist->head, detail_id) : 0);
	if (!debag)
	{
		std::cout << ">> Enter count\n<< ";
		while (true) {
			std::cin >> count;
			if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
			{
				std::cout << "ERROR" << std::endl << ">> Is not num" << std::endl << std::endl << ">> Num pls)\n<< ";
				std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
				std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			}
			else // если всё хорошо
				break;
		}
	}
}
void Implement::Print() {
	Base::Print();
	std::cout << "detail_id\tcount" << std::endl;
	std::cout << detail_id << "\t\t" << count << std::endl;
}

Item* List::Create() {
	int a;
	std::cout << ">> What create?\n(1-Detail,2-Implement)\n<< ";
	while (true) {
		std::cin >> a;
		if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			std::cout << "ERROR" << std::endl << ">> Is not num" << std::endl << std::endl << ">> Num pls)\n<< ";
			std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
		}
		else // если всё хорошо
			break;
	}
	Base* b = NULL;
	Detail* d = NULL;
	Implement* i = NULL;
	switch (a)
	{
	case(int(Type::Detail)):
		d = new Detail;
		d->type = Type::Detail;
		break;
	case(int(Type::Implement)):
		i = new Implement;
		i->type = Type::Implement;
		break;
	default:
		return 0;
		break;
	}
	if (d) {
		b = d;
	}
	else {
		b = i;
	}
	b->uplist = this;
	b->Write();
	if (b->Get_id() == 0) { // Удаление памяти в случае если для фурнитуры не существовало детали
		delete b;
		b = NULL;
	}
	return b;
}

void List::Found()
{
	std::cout << ">>Enter found shifr" << std::endl << "<< ";
	std::string tmp;
	std::cin >> tmp;
	Item* current = head, * zis;
	while (current)//Поиск подходящего шифра
	{
		if (tmp == current->Get_shifr())
		{
			zis = current;
			zis->Print();
			int tmp_id = zis->Get_id();
			current = head;
			while (current)//Поиск фурнитуры принадлеащей данной детали
			{
				if (current != zis)//Проверка на то что это не найденая деталь
				{
					if (current->Get_id() == tmp_id)
					{
						current->Print();
					}
				}
				current = current->after;
			}
			break;//"Завершение" в случае найденной детали
		}
		current = current->after;
	}
	if (!current)
		std::cout << ">> I don't found this shifr " << std::endl;
}

void Swap(List* list, Item* ob1, Item* ob2) {
	if (!list || !ob1 || !ob2)
		;
	else
	{
		Item tmp1, tmp2;

		tmp1.after = ob1->after;
		tmp1.before = ob1->before;
		tmp2.after = ob2->after;
		tmp2.before = ob2->before;

		if (ob1->after == ob2 || ob1->before == ob2 || ob2->after == ob1 || ob2->before == ob1)
		{
			if (ob1->before == ob2)
			{
				ob1->before = tmp2.before;
				ob1->after = ob2;
				ob2->before = ob1;
				ob2->after = tmp1.after;
			}
			else
			{
				ob1->before = ob2;
				ob1->after = tmp2.after;
				ob2->before = tmp1.before;
				ob2->after = ob1;
			}
		}
		else
		{
			ob1->before = tmp2.before;
			ob1->after = tmp2.after;
			ob2->before = tmp1.before;
			ob2->after = tmp1.after;
		}

		//	Изменения адресов соседий
		if (ob1->before)
			ob1->before->after = ob1;
		if (ob1->after)
			ob1->after->before = ob1;
		if (ob2->before)
			ob2->before->after = ob2;
		if (ob2->after)
			ob2->after->before = ob2;

		//	Изменение адреса листов 
		//	Если объекты являлись 
		//	Началом или концом
		if (ob1 == list->head)
			list->head = ob2;
		if (ob1 == list->tail)
			list->tail = ob2;
		if (ob2 == list->head)
			list->head = ob1;
		if (ob2 == list->tail)
			list->tail = ob1;
	}
}

void List::Sort()
{
	List D;
	List I;
	Item* current = NULL, * start = NULL;

	//Разбитие на списки деталий и фурнитуры
	current = head;
	while (current != 0)
	{
		start = current->after;
		switch (((Base*)current)->type) {
		case(Type::Detail):
			D.Add(current);
			break;
		case(Type::Implement):
			I.Add(current);
			break;
		}
		current = start;
	}
	current = start = NULL;

	//сортировка деталий
	start = D.head;
	while (start)
	{
		current = start->after;
		while (current)
		{
			if (*(Detail*)current > *(Detail*)current->before)
			{
				Swap(&D, current, current->before);
				start = D.head;
				break;
			}
			current = current->after;
		}
		start = start->after;
	}
	current = start = NULL;

	//Соединение списков
	head = tail = NULL;
	current = D.head;
	Item* icurrent = I.head, * istart = NULL;
	while (current)
	{
		start = current->after;
		Add(current);
		while (icurrent)
		{
			istart = icurrent->after;
			if (current->Get_id() == icurrent->Get_id())
			{
				I.Remove(I.GetIndedx(icurrent));
				Add(icurrent);
			}
			icurrent = istart;
		}
		icurrent = I.head;
		current = start;
	}
	I.head = I.tail = D.head = D.tail = NULL;
}

Item& List::operator[] (const int index) {
	Item* tmp = GetItem(index + 1);
	if (!tmp) {
		tmp = new Item;
	}
	return *tmp;
}

//template < typename T >
//T& T::operator[] (const int index) {
//	return (T*)(uplist->GetItem(index));
//}

//Item& Item::operator[] (const int index) {
//	return *(uplist->GetItem(index));
//}
//
//Base& Base::operator[] (const int index) {
//	return *(Base*)(uplist->GetItem(index));
//}
//
//Detail& Detail::operator[] (const int index) {
//	return *(Detail*)(uplist->GetItem(index));
//}
//
//Implement& Implement::operator[] (const int index) {
//	return *(Implement*)(uplist->GetItem(index));
//}


