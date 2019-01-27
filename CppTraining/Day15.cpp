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

long Add(int & a, int & b) {
	return a + b;
}

long Subtract(int & a, int & b) {
	return a - b;
}

long Multiply(int & a, int & b) {
	return a * b;
}

long Divide(int & a, int & b) {
	return a / b;
}

long Execute(long(*)(int &, int &)); // Declare

long Execute(long(*f)(int &, int &), int i, int j) { // Define
	return f(i, j);
}

void FunctionPointerArrayExample() {
	long(*funcs[4])(int &, int &);

	auto addf = Add;
	auto addfa = &Add;

	funcs[0] = &Add;
	funcs[1] = Subtract; // Shorthand??
	funcs[2] = &Multiply;
	funcs[3] = &Divide;

	int a, b;
	cin >> a >> b;

	for (size_t i = 0; i < 4; i++)
	{
		cout << (*funcs[i])(a, b) << endl;
		cout << funcs[i](a, b) << endl; // Shorthand
		cout << Execute(funcs[i], a, b) << endl; // Yet again, redirect to someone else
	}
}

int main() {
	//ClassMembersExample();
	//FunctionPointersExample();
	FunctionPointerArrayExample();

	system("pause");
	return 0;
}