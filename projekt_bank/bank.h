#pragma once
#include "pch.h"
#include "klient.h"
#include "konto.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

class bank
{
private:
	friend class klient;
	friend class konto;
	friend void funkcja_id(bank&);
	vector <klient> klienci;
	vector <konto> konta;
	unsigned int id_nowego_klienta;
	unsigned int id_nowego_konta;

public:
	//funkcje zwiazanie z klientem
	void wyswietl_klientow();
	void dodaj_klienta();
	void modyfikuj_dane();
	void usun_klienta();
	//funkcje zwiazane z kontem
	void wyswietl_konto();
	void dodaj_konto();
	void wplata_na_konto();
	void wyplata_z_konta();
	void przelew();
	void usun_konto();
	void statystyka();
	void zaladuj_z_plikow();
	void zaladuj_historie_z_plikow();
	void zapisz_do_plikow();
	void zapisz_historie_do_plikow();

};