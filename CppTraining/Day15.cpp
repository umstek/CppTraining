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

int main() {
	cout << A::GetK() << endl;
	system("pause");
	return 0;
}