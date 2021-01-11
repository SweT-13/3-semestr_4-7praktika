#include <string>
extern bool debag;

class Item;

class List
{
public:
	Item* head;
	Item* tail;
	List();
	~List();
	void Add(Item* obj);
	void Del(const int n);
	Item* Remove(const int n);
	Item* GetItem(const int n);
	int Count();
	void Clear();
	void Insert(Item* obj, const int n);
	int GetIndedx(const Item* obj);

	Item* Create();
	void Found();
	void Sort();
	Item& operator[] (const int index);
};

class Item
{
public:
	Item* before;
	Item* after;
	List* uplist;
	Item();
	virtual ~Item();
	virtual void Write() {};
	virtual void Print();
	virtual int Get_id() { return -1; };
	virtual std::string Get_shifr() { return " 	 "; }

	//Item& operator[] (const int index);
};

void Print(const List* L);