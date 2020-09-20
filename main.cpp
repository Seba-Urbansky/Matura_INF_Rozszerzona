#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

long silnia(int liczba) {
	long wynik = 1;
	for (int i = 1;i <= liczba; i++){
		wynik = wynik * i;
	}
	return wynik;
}

void zadanie_4_1(){
	fstream przyklad;
	przyklad.open ("liczby.txt");
	int n = 500;
	int tablica[n];
	int line = 0;
	while (!przyklad.eof())
	{
		przyklad >> tablica[line];
		line++;
	}
	int wynik=0;

	for(int i=0;i<n;i++)
	{
		int liczba = tablica[i];
		int k=1;
		while (liczba >= k)	{
			if(liczba==k){
				wynik++;
			}
			k*=3;
		}

	}
	cout << wynik << endl;
}

void zadanie_4_2() {
	fstream przyklad;
	przyklad.open ("przyklad.txt");
	int n = 500;
	int tablica[n];
	int line = 0;
	while (!przyklad.eof())
	{
		przyklad >> tablica[line];
		line++;
	}

	int wynik=0;

	for(int i=0;i<n;i++)
	{
		int liczba = tablica[i];
		int k = liczba;
		int suma = 0;
		while (k > 0){
			int cyfra=k%10;
			k=k / 10;
			suma = suma + silnia(cyfra);
		}

		if (liczba == suma) {
			cout << liczba << endl;
		}
	}
}

int nwd(int a, int b) {
	while (a!=b) {
		if (a>b) {
			a-=b;
		} else {
			b-=a;
		}
	}
	return a;
}


void zadanie_4_3() {
	fstream przyklad;
	przyklad.open ("liczby.txt");
	int n = 500;
	int tablica[n];
	int line = 0;
	while (!przyklad.eof())
	{
		przyklad >> tablica[line];
		line++;
	}

	int tymczasowa_pierwsza;
	int tymczasowa_dlugosc_ciagu;
	int tymczasowy_nwd_dzielnik;

	int pierwsza_liczba;
	int dlugosc_ciagu;
	int dzielnik;


	for(int i=0;i<n-2;i++){
		int a = tablica[i];
		int b = tablica[i+1];
		int c = tablica[i+2];

		int wynik = nwd(nwd(a,b),c);

		if (wynik>1) {

			if(tymczasowa_pierwsza == 0){
				tymczasowa_pierwsza = a;
				tymczasowa_dlugosc_ciagu = 3;
				tymczasowy_nwd_dzielnik = wynik;
			} else if(tymczasowy_nwd_dzielnik % wynik != 0) {
				tymczasowy_nwd_dzielnik = 0;
				tymczasowa_pierwsza = 0;
				tymczasowa_dlugosc_ciagu = 0;
			} else {
				tymczasowa_dlugosc_ciagu++;
			}

			if (tymczasowa_dlugosc_ciagu > dlugosc_ciagu){
				dlugosc_ciagu = tymczasowa_dlugosc_ciagu;
				pierwsza_liczba = tymczasowa_pierwsza;
				dzielnik = tymczasowy_nwd_dzielnik;
			}
		} else {
			tymczasowa_pierwsza = 0;
			tymczasowa_dlugosc_ciagu = 0;
			tymczasowy_nwd_dzielnik = 0;
		}

	}
	cout << dlugosc_ciagu << endl << pierwsza_liczba << endl << dzielnik << endl ;
}

int main() {
	// zadanie_4_1():
	// zadanie_4_2();
	zadanie_4_3();
	return 0;
}
