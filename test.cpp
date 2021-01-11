//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//	A();
//	virtual ~A();
//	virtual void printc();
//private:
//
//};
//
//A::A()
//{
//}
//
//A::~A()
//{
//	cout << " a ";
//}
//
//
//class B:public A
//{
//public:
//	B();
//	virtual ~B();
//
//private:
//
//};
//
//B::B()
//{
//}
//
//B::~B()
//{
//	cout << " b ";
//}
//
//class C:public B
//{
//public:
//	void printc() { cout << "cprint"; };
//	C();
//	~C();
//
//private:
//
//};
//
//C::C()
//{
//}
//
//C::~C()
//{
//	cout << " c ";
//}
//
//int main() {
//
//	A* p;
//	p = new C;
//	p->printc();
//	delete p;
//	return 0;
//}
