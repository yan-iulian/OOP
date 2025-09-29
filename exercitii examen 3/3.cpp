#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
using namespace std;

enum TC {
	BENZINA, MOTORINA , GAZ , ELECTRIC , HIBID
};

class Vehicul {
	string marca="-";
	int anFabricatie=0;
	float greutate=0.0;
public:
	Vehicul() {}

	Vehicul(string _marca, int _anFabricatie, float _greutate)
	{
		this->marca = _marca;
		this->anFabricatie = _anFabricatie;
		this->greutate = _greutate;
	}

	friend ostream& operator<<(ostream& out, const  Vehicul& v)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nMarca :" << v.marca;
		out << "\nAn fabricatie :" << v.anFabricatie;
		out << "\nGreutatea :" << v.greutate;
	
		return out;
	}

	Vehicul(const Vehicul& v)
	{
		this->marca = v.marca;
		this->anFabricatie = v.anFabricatie;
		this->greutate = v.greutate;
	}

	Vehicul& operator=(const Vehicul& v)
	{
		if (this != &v)
		{
			this->marca = v.marca;
			this->anFabricatie = v.anFabricatie;
			this->greutate = v.greutate;
		}
		return *this;
	}

	virtual void afisare()
	{
		cout << "\nVehiculul merge !";
	}
};

class Masina :public Vehicul {
	int nrLocuri=0;
	TC tipC=TC::BENZINA;
	int vitezaMx=0;
public:
	Masina():Vehicul() {}

	Masina(string _marca , int _anFabricatie , float _greutate ,int _nrLocuri, TC _tipC, int _vitezaMax):Vehicul(_marca,_anFabricatie,_greutate)
	{
		this->nrLocuri = _nrLocuri;
		this->tipC = _tipC;
		this->vitezaMx = _vitezaMax;
	}

	Masina(Vehicul _v, int _nrLocuri, TC _tipC, int _vitezaMax):Vehicul(_v)
	{
		this->nrLocuri = _nrLocuri;
		this->tipC = _tipC;
		this->vitezaMx = _vitezaMax;
	}

	friend ostream& operator<<(ostream& out, const Masina& m)
	{
		
		out << (Vehicul)m;
		out << "\nNr de locuri: " << m.nrLocuri;
		out << "\nTip Combustiil: " << m.tipC;
		out << "\nViteza maxima: " << m.vitezaMx;
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}

	Masina(const Masina& m) :Vehicul(m)
	{
		this->nrLocuri = m.nrLocuri;
		this->tipC = m.tipC;
		this->vitezaMx = m.vitezaMx;
	}
	Masina& operator=(const Masina& m)
	{
		if (this != &m)
		{
			Vehicul::operator=(m);
			this->nrLocuri = m.nrLocuri;
			this->tipC = m.tipC;
			this->vitezaMx = m.vitezaMx;
		}
		return *this;
	}

	void afisare()override {
		cout << "\nMasina depaseste !";
	}

	bool operator<(const Masina& m)const {
		return this->nrLocuri < m.nrLocuri;
	}
};


template <typename T>
class ClasaTemplate {
	T valoare=T();
	int valoareInt=0;

public:
	ClasaTemplate() {}

	ClasaTemplate(T _valoare, int _valoareaInt)
	{
		this->valoare = _valoare;
		this->valoareInt = _valoareaInt;
	}



};

int main()
{
	Vehicul v1;
	Vehicul v2("Volkswagen", 2010, 2000);
	Vehicul v3("Audi", 2018, 2500);

	Masina m1;
	Masina m2(v3, 4, MOTORINA, 260);
	Masina m3(v2, 6, MOTORINA, 220);
	Masina m4(m3);
	Masina m5("MERCEDES", 2018, 3000, 2, BENZINA, 290);
	//cout << v2 << v3;
	//
	//cout << m2;

	v2 = m2;
	//cout << v2;

	Vehicul* pv4 = new Vehicul();
	pv4->afisare();

	pv4 = &m2;
	pv4->afisare();

	ClasaTemplate<float> obiect1(12, 3);
	ClasaTemplate<float> obiect2(14, 3);

	ClasaTemplate<float>* listaObiecte = new ClasaTemplate<float>[2] { obiect1, obiect2 };

	vector<Masina> listaMasini;
	listaMasini.push_back(m2);
	listaMasini.push_back(m1);
	listaMasini.push_back(m4);
	listaMasini.push_back(m5);
	listaMasini.push_back(m3);

	/*for (int i = 0; i < listaMasini.size(); i++)
		cout << listaMasini[i];*/

	set<Masina> listaMasini2;
	listaMasini2.insert(m2);
	listaMasini2.insert(m2);
	listaMasini2.insert(m4);
	listaMasini2.insert(m2);

	/*set<Masina>::iterator it;
	for (it = listaMasini2.begin(); it!=listaMasini2.end(); it++)
		cout << *it;*/

	list<Masina> listMasini;
	listMasini.push_back(m1);
	listMasini.push_front(m2);
	listMasini.push_back(m3);
	listMasini.push_back(m2);

	//list<Masina>::iterator it2;
	//for (it2 = listMasini.begin(); it2 != listMasini.end(); it2++)
	//	cout << *it2;

	map<int, Masina> mapMasini;
	mapMasini[0] = m1;
	mapMasini[10] = m2;
	mapMasini[0] = m3;

	map<int, Masina> ::iterator itm;
	for (itm = mapMasini.begin(); itm != mapMasini.end(); itm++)
		cout << endl<< (*itm).first << "\t" << (*itm).second;

	return 0;


}