#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <sstream>

using namespace std;

class konto
{
	friend class bank;
private:
	unsigned int id_wlasciciel;
	unsigned int id_konta;

	double stan_konta;
	vector <string> historia;

	typedef int typ_operacji;//uzyte przy histori operacji

public:
	void wyswietl();
	void dodaj(unsigned int id,unsigned int id_wlasciciela);
	void dodaj_historie(typ_operacji x, unsigned int kwota_wplaty, unsigned int kwota_wyplaty, unsigned int kwota_przelewu,unsigned int id_skad_przelew,unsigned int id_dokad_przelew);
	void wyswietl_historie();



};