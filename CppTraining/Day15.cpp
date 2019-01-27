#include "CppTraining.h"

using namespace std;

class A
{
public:
	A()
	{
	}

	~A()
	{
	}

	static int i;
	static const int j = 0;

	static int GetK() {
		return k;
	}

private:
	static const int k = 10;

};

int A::i = 0;

void ClassMembersExample() {
	cout << A::GetK() << endl;
	A a;
	cout << a.GetK() << endl;
}

long int DoA(int x) {
	return x;
}

long int DoB(int x) {
	return x * 2;
}

long int DoNothing(int x) {
	return 0;
}

void FunctionPointersExample() {

	long(*func) (int);

	int r = 10;
	int f = 0;
	cin >> r >> f;

	switch (f)
	{
	case 1:
		func = DoA;
		break;
	case 2:
		func = DoB;
		break;
	default:
		cout << "Nothing assigned. " << endl;
		func = DoNothing;
		break;
	}

	cout << func(r) << endl; // Shorthand
	cout << (*func)(r) << endl;
}

int main() {
	//ClassMembersExample();
	FunctionPointersExample();

	system("pause");
	return 0;
}