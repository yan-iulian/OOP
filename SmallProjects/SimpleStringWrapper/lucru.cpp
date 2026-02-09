#include <iostream>
using namespace std;

class Lucru {
	const int idProces;
	char* vector;
public:
	Lucru(int _id) :idProces(_id)
	{
		this->vector = new char[strlen("Anonim") + 1];
		strcpy_s(this->vector, strlen("Anonim") + 1, "Anonim");
	}
	Lucru(int _id, char* _vector) :idProces(_id)
	{
		this->vector = new char[strlen(_vector) + 1];
		strcpy_s(this->vector, strlen(_vector) + 1, _vector);
	}
	~Lucru()
	{
		cout << "\nApel destructor!";
		if (this->vector != nullptr)
		{
			delete[]this->vector;
			this->vector = nullptr;
		}
	}

	friend ostream& operator<<(ostream& out, const Lucru& l)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nId ul este: " << l.idProces;
		out << "\nVectorul este : " << l.vector;
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}
};

int main()
{
	Lucru  l1(0);
	cout << l1;
	Lucru l2(10, (char*)"Luiza");
	cout << l2;


	return 0;
}