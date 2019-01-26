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

class C
{
public:
	C(int c) : c(c)
	{
	}

	~C()
	{
	}

	void Xxx() {
		cout << "Xxx from C" << endl;
	};

	virtual void Conflict() {
		cout << "Conflict from C" << endl;
	};

	virtual void ToOverride() {
		cout << "ToOverride from C" << endl;
	};

private:
	int c;
};

class D
{
public:
	D(int d) : d(d)
	{
	}

	~D()
	{
	}

	void Xxx() {
		cout << "Xxx from D" << endl;
	};

	virtual void Conflict() {
		cout << "Conflict from D" << endl;
	};

	virtual void ToOverride() {
		cout << "ToOverride from D" << endl;
	};

private:
	int d;
};

class E : public C, public D
{
public:
	E(int c, int d, int e) : C(c), D(d), e(e)
	{
	}

	~E()
	{
	}

	virtual void ToOverride() {
		cout << "ToOverride from E" << endl;
	}

private:
	int e;
};

void MultipleInheritanceExample() {
	E *e = new E(3, 4, 5);
	//e->Xxx();
	e->C::Xxx();
	//e->Conflict();
	e->C::Conflict();
	e->ToOverride();
	e->C::ToOverride();

	D *ed = new E(3, 4, 5);
	ed->Xxx();
	ed->Conflict();
	dynamic_cast <C*>(ed)->Conflict();
	dynamic_cast <E*>(ed)->C::Conflict();
	ed->ToOverride();
}

class Animal
{
public:
	Animal()
	{
	}

	~Animal()
	{
	}

	void Dead() {
		cout << "Animal dead." << endl;
	};

private:

};

class Bird : public Animal
{
public:
	Bird()
	{
	}

	~Bird()
	{
	}

private:

};

class Horse : public Animal
{
public:
	Horse()
	{
	}

	~Horse()
	{
	}

private:

};

class Pegasus : public Bird, public Horse
{
public:
	Pegasus()
	{
	}

	~Pegasus()
	{
	}

private:

};

void DiamondOfDeathExample() {
	Pegasus *p = new Pegasus();
	//p->Dead();
	p->Bird::Dead();
}

int main()
{
	//DynamicCastExample();
	//MultipleInheritanceExample();
	DiamondOfDeathExample();

	system("pause");
	return 0;
}
