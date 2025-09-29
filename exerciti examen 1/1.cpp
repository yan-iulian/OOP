#include <iostream>
#include <fstream>
using namespace std;

class Student {
	const int id;
	char* nume=nullptr;
	int nrNote=0;
	int* note=nullptr;
	string email="-";
	bool nrPrezente[14];
	static float taxaRestanta;
public:

	Student(int _id) : id(_id) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy_s(this->nume, strlen("Anonim") + 1,"Anonim");

	}

	Student(int _id,const  char* _nume, int _nrNote, int* _note, string _email, bool _nrPrezente[12]) :id(_id)
	{
		if (_nume != nullptr)
		{
			this->nume = new char[strlen(_nume) + 1];
			strcpy_s(this->nume, strlen(_nume) + 1, _nume);
		}
		if (_nrNote > 0 && _note != nullptr)
		{
			this->nrNote = _nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = _note[i];
		}
		else
		{
			this->nrNote = 0;
			this->note = nullptr;

		}
		this->email = _email;
		for (int i = 0; i < 14; i++)
			this->nrPrezente[i] = _nrPrezente[i];
	}

	Student(const Student& s): id(s.id)
	{
		if (s.nume != nullptr)
		{
			this->nume = new char[strlen(s.nume) + 1];
			strcpy_s(this->nume, strlen(s.nume) + 1, s.nume);
		}
		if (s.nrNote > 0 && s.note != nullptr)
		{
			this->nrNote = s.nrNote;
			this->note = new int[s.nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = s.note[i];
		}
		else
		{
			this->nrNote = 0;
			this->note = nullptr;

		}
		this->email = s.email;
		for (int i = 0; i < 14; i++)
			this->nrPrezente[i] = s.nrPrezente[i];
	}

	~Student()
	{
		if (this->nume != nullptr)
		{
			delete[]this->nume;
			this->nume = nullptr;
		}
		if (this->note != nullptr)
		{
			delete[] this->note;
			this->note = nullptr;
		}
	}

	Student& operator=(const Student& s)
	{
		if (this != &s)
		{
			if (this->nume != nullptr)
			{
				delete[]this->nume;
				this->nume = nullptr;
			}
			if (this->note != nullptr)
			{
				delete[] this->note;
				this->note = nullptr;
			}
			if (s.nume != nullptr)
			{
				this->nume = new char[strlen(s.nume) + 1];
				strcpy_s(this->nume, strlen(s.nume) + 1, s.nume);
			}
			if (s.nrNote > 0 && s.note != nullptr)
			{
				this->nrNote = s.nrNote;
				this->note = new int[s.nrNote];
				for (int i = 0; i < this->nrNote; i++)
					this->note[i] = s.note[i];
			}
			else
			{
				this->nrNote = 0;
				this->note = nullptr;

			}
			this->email = s.email;
			for (int i = 0; i < 14; i++)
				this->nrPrezente[i] = s.nrPrezente[i];
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Student& s)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~";
		out << "\nId student : " << s.id;
		out << "\nNume student :" << s.nume;
		out << "\nNr de note : " << s.nrNote;
		out << "\nNote : ";
		for (int i = 0; i < s.nrNote; i++)
			out << s.note[i] << "\t";
		out << "\nEmail student :" << s.email;
		out << "\nPrezente: ";
		for (int i = 0; i < 14; i++)
			out <<boolalpha<< s.nrPrezente[i] << "\t";
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}


	friend ofstream& operator<<(ofstream& out, const Student& s)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~";
		out << "\nId student : " << s.id;
		out << "\nNume student :" << s.nume;
		out << "\nNr de note : " << s.nrNote;
		out << "\nNote : ";
		for (int i = 0; i < s.nrNote; i++)
			out << s.note[i] << "\t";
		out << "\nEmail student :" << s.email;
		out << "\nPrezente: ";
		for (int i = 0; i < 14; i++)
			out << boolalpha << s.nrPrezente[i] << "\t";
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}


	//get si set nume 

	const char* getNume()
	{
		return this->nume;
	}

	void setNume(char* _nume)
	{
		if (this->nume != nullptr)
		{
			delete[]this->nume;
			this->nume = nullptr;
		}
		if (_nume != nullptr)
		{
			this->nume = new char[strlen(_nume) + 1];
			strcpy_s(this->nume, strlen(_nume) + 1, _nume);

		}
		else
		{
			this->nume = nullptr;
		}
	}

	//get si set email
	void setEmail(string _email)
	{
		if (_email != " ")
			this->email = _email;
		else this->email = "-";
	}
	string getEmail()
	{
		return this->email;
	}

	//get si set pentru note si nrNote
	void setNote(int _nrNote, int* _note)
	{
		if (this->note != nullptr)
		{
			delete[]this->note;
			this->note = nullptr;
		}
		if (_nrNote > 0 && _note != nullptr)
		{
			this->nrNote = _nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i, this->nrNote; i++)
				this->note[i] = _note[i];
		}

		else {
			this->nrNote = 0;
			this->note = nullptr;
		}
	}

	int getNrNote()
	{
		return this->nrNote;
	}

	const int* getNote()
	{
		return this->note;
	}

	friend istream& operator>>(istream& in, Student& s)
	{
		cout << "\nIntroduceti numele studenului: ";
		if (s.nume != nullptr)
		{
			delete[]s.nume;
			s.nume = nullptr;
		}
		char buffer[30];
		in >> buffer;
		if (strcmp(buffer, " ") != 0)
		{
			s.nume = new char[strlen(buffer) + 1];
			strcpy_s(s.nume, strlen(buffer) + 1, buffer);
		}
		else {
			s.nume = new char[strlen("Anonim") + 1];
			strcpy_s(s.nume, strlen("Anonim") + 1, "Anonim");
		}
		cout << "\nIntroduceti nr de note si notele aferente :";
		int x;
		in >> x;
		int* v = new int[x];
		for (int i = 0; i < x; i++)
			in >> v[i];
		if (s.note != nullptr)
		{
			delete[]s.note;
			s.note = nullptr;
		}
		if (x > 0 && v != nullptr)
		{
			s.nrNote = x;
			s.note = new int[s.nrNote];
			for (int i = 0; i < s.nrNote; i++)
				s.note[i] = v[i];
		}
		else
		{
			s.nrNote = 0;
			s.note = nullptr;
		}
		delete[]v;
		cout << "\nIntroduceti emailul :";
		in >> s.email;

		cout << "\nIntroduceti prezentele : ";
		for (int i = 0; i < 14; i++)
		{
			cout << "\nPrezenta " << i + 1 << ":  ";
			in >> s.nrPrezente[i];
		}
		return in;
	}

	static float getRestanta()
	{
		return Student::taxaRestanta;
	}

	void setTaxaRestanta(float x)
	{
		if (x != 0 && x < 1000)
			Student::taxaRestanta = x;
	}

	Student& operator+(int _nota)
	{
		int n;
		n = this->nrNote + 1;
		int* v = new int[n];
		for (int i = 0; i < this->nrNote; i++)
			v[i] = this->note[i];
		v[n - 1] = _nota;

		delete[]this->note;
		this->note = v;
		this->nrNote = n;
		return *this;
	}


	friend ifstream& operator>>(ifstream& in, Student& s)
	{
		cout << "\nIntroduceti numele studenului: ";
		if (s.nume != nullptr)
		{
			delete[]s.nume;
			s.nume = nullptr;
		}
		char buffer[30];
		in >> buffer;
		if (strcmp(buffer, " ") != 0)
		{
			s.nume = new char[strlen(buffer) + 1];
			strcpy_s(s.nume, strlen(buffer) + 1, buffer);
		}
		else {
			s.nume = new char[strlen("Anonim") + 1];
			strcpy_s(s.nume, strlen("Anonim") + 1, "Anonim");
		}
		cout << "\nIntroduceti nr de note si notele aferente :";
		int x;
		in >> x;
		int* v = new int[x];
		for (int i = 0; i < x; i++)
			in >> v[i];
		if (s.note != nullptr)
		{
			delete[]s.note;
			s.note = nullptr;
		}
		if (x > 0 && v != nullptr)
		{
			s.nrNote = x;
			s.note = new int[s.nrNote];
			for (int i = 0; i < s.nrNote; i++)
				s.note[i] = v[i];
		}
		else
		{
			s.nrNote = 0;
			s.note = nullptr;
		}
		delete[]v;
		cout << "\nIntroduceti emailul :";
		in >> s.email;

		cout << "\nIntroduceti prezentele : ";
		for (int i = 0; i < 14; i++)
		{
			cout << "\nPrezenta " << i + 1 << ":  ";
			in >> s.nrPrezente[i];
		}
		return in;
	}

	static float getRestanta()
	{
		return Student::taxaRestanta;
	}

	void setTaxaRestanta(float x)
	{
		if (x != 0 && x < 1000)
			Student::taxaRestanta = x;
	}

	Student& operator+(int _nota)
	{
		int n;
		n = this->nrNote + 1;
		int* v = new int[n];
		for (int i = 0; i < this->nrNote; i++)
			v[i] = this->note[i];
		v[n - 1] = _nota;

		delete[]this->note;
		this->note = v;
		this->nrNote = n;
		return *this;
	}

	Student& operator--()
	{
		int n;
		n = this->nrNote - 1;
		int* v = new int[n];
		for (int i = 0; i < n; i++)
			v[i] = this->note[i];
		delete[]this->note;
		this->note = v;
		this->nrNote = n;
		return* this;
	}

	int operator[](int _index)
	{
		if (_index < this->nrNote && _index>0)
			return note[_index];
		else throw new exception("Index invalid!");
	 }

	bool operator==(const Student& s)
	{
		int m1=0;
		for (int i = 0; i < this->nrNote; i++)
			m1 += this->note[i];
		m1 = m1 / this->nrNote;
		int m2 = 0;
		for (int i = 0; i < s.nrNote; i++)
			m2 += s.note[i];
		m2 = m2 / s.nrNote;
		return m1 == m2;
	}

	explicit operator float()
	{
		int m1 = 0;
		for (int i = 0; i < this->nrNote; i++)
			m1 += this->note[i];
		m1 = m1 / this->nrNote;
		return m1;
	}

	float getMedie()
	{
		float m;
		for (int i = 0; i < this->nrNote; i++)
			m += this->note[i];
		return (m / this->nrNote);
	}

	static Student& getStudentMediaMax(Student* studenti, int nrStudenti)
	{
		Student* sMedieMare = &studenti[0];
		for (int i = 0; i < nrStudenti; i++)
			if (studenti[i].getMedie() > sMedieMare->getMedie())
				sMedieMare = &studenti[i];
		return *sMedieMare;
	}

	//serializare
	void writeToFile(fstream& f)
	{
		f.write((char*)&this->id, sizeof(int));

		int lg;
		lg = strlen(this->nume) + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->nume, lg);

		f.write((char*)&this->nrNote, sizeof(int));
		for (int i = 0; i < this->nrNote; i++)
			f.write((char*)&this->note[i], sizeof(int));

		lg = this->email.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->email.data(), lg);

		int nrPrezfix = 14;
		f.write((char*)&nrPrezfix, sizeof(int));
		for (int i = 0; i < 14; i++)
			f.write((char*)&this->nrPrezente[i], sizeof(bool));

	}

	//deserializare
	void readFromFile(fstream& f)
	{
		if (this->nume != nullptr)
		{
			delete[]this->nume;
			this->nume = nullptr;
		}
		if (this->note != nullptr)
		{
			delete[]this->note;
			this->note = nullptr;
		}

		

		int lg;
		f.read((char*)&lg, sizeof(int));
		this->nume = new char[lg + 1];
		f.read(this->nume, lg);

		f.read((char*)&this->nrNote, sizeof(int));
		this->note = new int[this->nrNote];
		for (int i = 0; i < this->nrNote; i++)
			f.read((char*)&this->note[i], sizeof(int));

		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg+1];
		f.read(buffer, lg);
		this->email = buffer;

		int nrPp;
		f.read((char*)&nrPp, sizeof(int));
		for (int i = 0; i < nrPp; i++)
			f.read((char*)&this->nrPrezente[i], sizeof(bool));



	}
	
};

float Student::taxaRestanta = 100;


int main()
{
	Student s(0);
	cout << s;
	bool prezente[14] = { 1,2,3,4,5,6,7,8,0,0,0,0,0,0 };

	int* note = new int [7] {10, 6, 8, 6 ,5, 10 ,5 };


	Student s2(1, "Marius", 7, note, "marius22@stud.ase.ro", prezente);
	cout <<s2;

	/*Student x(100);
	cin >> x;
	cout << x;*/

	/*s2 = s2 + 5;
	cout << s2;

	--s2;
	cout << s2;*/

	/*cout <<endl<< s2[3];

	try {
		cout << endl << s2[20];
	}
	catch (exception *ex)
	{
		cout << endl << ex->what();
		delete ex;
	}
	
	Student s3 = s2;
	cout <<endl<< (s2 == s3);*/

	cout << "\nMedia studentului este :" << (float)s2;

	/*fstream fileOut("Colectie.bin", ios::out | ios::binary);

	s2.writeToFile(fileOut);
	fileOut.close();*/

	/*fstream fileIn("Colecte.bin", ios::in | ios::binary);
	Student s3(100);
	s3.readFromFile(fileIn);*/
	cout << endl << endl << "Lucru cu fisiere";

	ofstream fileout("Studenti.txt");
	fileout << s2;
	fileout.close();

	ifstream filein("Studenti.txt");
	Student s4(100);
	filein >> s4;

	cout << s4;

	return 0;

}