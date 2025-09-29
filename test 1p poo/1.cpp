#include <iostream>
using namespace std;

int main()
{
	int p=5;
	int *a = &p;

	int* q = nullptr;
	q = a;
	cout << *q; cout << endl;

	cout << a << endl << p;
	return 0;

}