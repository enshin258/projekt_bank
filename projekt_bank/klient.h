#pragma once
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class klient
{
	friend class bank;
private:

	unsigned int id_klienta;
	string imie;
	string nazwisko;
	unsigned int wiek;
public:
	void wyswietl();
	void dodaj(unsigned int id);

};