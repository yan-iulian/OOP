#include <iostream>
using namespace std;

void citire_matrice(int**& mat, int& m, int& n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
}
void afisare_matrice(int** mat, int& m, int& n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << mat[i][j] << "  ";
		cout << endl;
	}
}
//suma elementelor aflate pe randuri pare si coloane impare
void Suma(int**& mat, int& m, int& n, int& suma)
{
	 suma = 0;
	for (int i = 0; i < m; i = i + 2)
		for (int j = 1; j < n; j = j + 2)
			suma = suma + mat[i][j];
	for (int i = 0; i < m; i = i + 2) 
		for (int j = 0; j < n; j++) 
			if (j % 2 == 1 && (i + j) % 2 == 0)  // intersectia 
				suma =suma- mat[i][j];
			
}
//suma elementelor de pe diagonala principala
void suma_elem_pricipala(int**& mat, int& m, int& n, int &suma2)
{

	
		suma2 = 0;
		for (int i = 0; i < m; i++)
			suma2 = suma2 + mat[i][i];
	
}

//suma elementelor de pe conturul matricei
void suma_elemente_contur(int**& mat, int& m, int& n, int& suma3)
{
	suma3 = 0;
	for (int i = 0; i < n; i++)
		suma3 = suma3 + mat[0][i];
	for (int i = 0; i < n; i++)
		suma3 = suma3 + mat[m - 1][i];
	for (int i = 0; i < m; i++)
		suma3 = suma3 + mat[i][0];
	for (int i = 0; i < m; i++)
		suma3 = suma3 + mat[i][n - 1];
	suma3 = suma3 - mat[0][0] - mat[0][n - 1] - mat[m - 1][0] - mat[m - 1][n - 1];
}

//functie care inverseaza valorile de pe prima si ultima linie
void inversare(int**& mat, int& m, int& n)
{
	int* aux = new int[n];
	int j = 0;
	for (int i = 0; i < n; i++)
		aux[j++] = mat[0][i];
	for (int i = 0; i < n; i++)
		mat[0][i] = mat[m - 1][i];
	for (int i = 0; i < n; i++)
		mat[m - 1][i] = aux[i];

	delete[]aux;
		

}


int main()
{
	int m, n;
	cout << "Introduceti dimensiunile mat:" << endl;
	cout << "m="; cin >> m;
	cout << "n="; cin >> n;
	cout << endl;
	cout << "Introduceti elementele matricei:" << endl;


	int** mat = new int*[m];
	for (int i = 0; i < m; i++)
		mat[i] = new int[n];


	citire_matrice(mat, m, n);
	cout << "\nMatricea este :" << endl;
	afisare_matrice(mat, m, n);


	cout << "\nSuma ceruta este :";
	int suma;
	Suma(mat, m, n, suma);
	cout << " " << suma;


	int suma2;
	if (m == n) {
		suma_elem_pricipala(mat, m, n, suma2);
		cout << "\n\nSuma elementelor de pe diagonala principala (matrice patratica) este : " << suma2 << "\n";
	}
	else
		cout << "\nMatricea nu este patratica , eroare!" << endl;

	int suma3;
	suma_elemente_contur(mat, m, n, suma3);
	cout << "\nSuma elemetelor de pe contur este egala cu : " << suma3 << endl;

	inversare(mat, m, n);
	cout << "Matricea dupa inversarea primei linii cu ultima: " << endl;
	afisare_matrice(mat, m, n);



	for (int i = 0; i < m; i++) {
		delete[] mat[i];
	}
	delete[] mat; 
	return 0;

}