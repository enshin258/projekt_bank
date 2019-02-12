#include "pch.h"
#include "klient.h"

void klient::dodaj(unsigned int id)
{
	this->id_klienta = id;
	cout << "Podaj dane klienta:" << endl;
	cout << "Imie:" << endl;
	cin >> imie;
	cout << "Nazwisko:" << endl;
	cin >> nazwisko;
	cout << "Wiek:" << endl;
	cin >> wiek;
}

void klient::wyswietl()
{
	cout << "ID klienta: " << id_klienta << endl;
	cout << "Imie: " << imie << endl;
	cout << "Nazwisko: " << nazwisko << endl;
	cout << "Wiek: " << wiek << endl;
	cout << endl;
}


