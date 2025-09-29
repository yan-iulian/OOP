#include <iostream>
using namespace std;

#include<iostream>
using namespace std;
class Masina {
	string model;
	int nrDeplasari;
	float* distantaDeplasari;
	float pret;
	const int anFabricatie;
public:
	Masina(int _anFabricatie) : anFabricatie(_anFabricatie) {
		this->model = "-";
		this->nrDeplasari = 0;
		this->distantaDeplasari = nullptr;
		this->pret = 0;
	}
	Masina(string _model, int _nrDeplasari, float* _distantaDeplasari, float _pret, int _anFabricatie) : anFabricatie(_anFabricatie) {
		this->model = _model;
		this->pret = _pret;
		if (_nrDeplasari > 0 && _distantaDeplasari != nullptr) {
			this->nrDeplasari = _nrDeplasari;
			this->distantaDeplasari = new float[this->nrDeplasari];
			for (int i = 0; i < this->nrDeplasari; i++)
				this->distantaDeplasari[i] = _distantaDeplasari[i];
		}
		else {
			this->nrDeplasari = 0;
			this->distantaDeplasari = nullptr;
		}
	}
	Masina(const Masina& m) :anFabricatie(m.anFabricatie) {
		this->model = m.model;
		this->pret = m.pret;
		if (m.nrDeplasari > 0 && m.distantaDeplasari != nullptr) {
			this->nrDeplasari = m.nrDeplasari;
			this->distantaDeplasari = new float[this->nrDeplasari];
			for (int i = 0; i < this->nrDeplasari; i++)
				this->distantaDeplasari[i] = m.distantaDeplasari[i];
		}
		else {
			this->nrDeplasari = 0;
			this->distantaDeplasari = nullptr;
		}
	}
	Masina& operator=(const Masina& m) {
		if (this != &m) {
			if (this->distantaDeplasari != nullptr) {
				delete[] this->distantaDeplasari;
				this->distantaDeplasari = nullptr;
			}
			this->model = m.model;
			this->pret = m.pret;
			if (m.nrDeplasari > 0 && m.distantaDeplasari != nullptr) {
				this->nrDeplasari = m.nrDeplasari;
				this->distantaDeplasari = new float[this->nrDeplasari];
				for (int i = 0; i < this->nrDeplasari; i++)
					this->distantaDeplasari[i] = m.distantaDeplasari[i];
			}
			else {
				this->nrDeplasari = 0;
				this->distantaDeplasari = nullptr;
			}
		}
		return *this;
	}

	Masina& operator++()
	{
		this->pret++;
		return *this;
	}

	Masina& operator++(int)
	{
		Masina copie = *this;
		this->pret++;
		return *this;

	}

	float operator+(float _distanta)
	{
		if (_distanta > 0)
		{
			float total = 0;
			for (int i = 0; i < this->nrDeplasari; i++)
				total += this->distantaDeplasari[i];
			total += _distanta;
			return total;
		}
		return 0;
	}
};

int main()
{
	return 0;
}