// CppTraining.cpp : Defines the entry point for the application.
//

#include "CppTraining.h"

using namespace std;

class A
{
public:
	A();
	~A();
	int GetA() const {
		return a;
	}
	int GetAA() const {
		return  aa;
	}
	virtual void M() const {
		cout << "M from A" << endl;
	}
protected:
	int a;
private:
	int aa;
};

A::A()
{
}

A::~A()
{
}

class B : public A
{
public:
	B();
	~B();
	virtual void M() const {
		cout << "M from A" << endl;
	}
private:

};

B::B()
{
}

B::~B()
{
}

void DynamicCastExample() {
	A *ba = new B();
	B *bb = dynamic_cast <B*>(ba);
	ba->M();
	bb->M();
}

int main()
{

	DynamicCastExample();

	system("pause");
	return 0;
}
