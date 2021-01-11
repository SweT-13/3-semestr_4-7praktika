#include <string>
#include "ListA.h"

enum class Type
{
	None,
	Detail,
	Implement
};

class Base : public Item
{
public:
	std::string name;
	Type type;

	Base();
	virtual ~Base();

	virtual void Write();
	virtual void Print();
	virtual int Get_id() { return -1; };
	virtual std::string Get_shifr() { return " 	 "; };
	//Base& operator[] (const int index);
};

class Detail : public Base
{
public:
	Detail();
	~Detail();
	int id;
	double wh;
	double ht;
	std::string shifr;

	void Write();
	void Print();
	int Get_id() { return id; };
	std::string Get_shifr() { return shifr; }
	friend bool operator> (const Detail& d1, const Detail& d2);
	friend bool operator< (const Detail& d1, const Detail& d2);
	//Detail& operator[] (const int index);
};

class Implement : public Base
{
public:
	Implement();
	~Implement();
	int detail_id;
	int count;

	void Write();
	void Print();
	int Get_id() { return detail_id; };
	//Implement& operator[] (const int index);
};
