
#include "pch.h"

//to poniezej zeby nie krzyczalo na funkcje ctime uzyta przy dacie do histori operacji
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "konto.h"
#include <fstream>

void konto::dodaj(unsigned int id,unsigned int id_wlasciciela)
{
	this->id_konta = id;
	this->id_wlasciciel = id_wlasciciela;
	cout << "Podaj kwote startowa" << endl;
	cin >> stan_konta;

}

void konto::wyswietl()
{
	cout << "ID konta: " << id_konta << endl;
	cout << "ID wlasciciela: " << id_wlasciciel<< endl;
	cout << "Kwota na koncie: " << stan_konta << endl;
	cout << endl;
}

void konto::dodaj_historie(typ_operacji x,unsigned int kwota_wplaty,unsigned int kwota_wyplaty,unsigned int kwota_przelewu,unsigned int id_skad_przelew,unsigned int id_dokad_przelew)
{
	string jaka_operacja;//mowi co sie stalo na koncie
	string pelny_raport;//typ operacji i data jej wykonania
	
	//to poniezej sluzy do zamiany inta na stringa
	ostringstream s_kwota_wplaty;
	s_kwota_wplaty << kwota_wplaty;
	ostringstream s_kwota_wyplaty;
	s_kwota_wyplaty << kwota_wyplaty;
	ostringstream s_kwota_przelewu;
	s_kwota_przelewu << kwota_przelewu;
	ostringstream s_skad_przelew;
	s_skad_przelew << id_skad_przelew;
	ostringstream s_dokad_przelew;
	s_dokad_przelew << id_dokad_przelew;

	string napis_kwota_wplaty = s_kwota_wplaty.str();
	string napis_kwota_wyplaty = s_kwota_wyplaty.str();
	string napis_kwota_przelewu = s_kwota_przelewu.str();
	string napis_skad_przelew = s_skad_przelew.str();
	string napis_dokad_przelew= s_dokad_przelew.str();




	time_t czas = time(NULL);//pobiera aktualna date
	char *ptr = ctime(&czas);//konwertuje na stringa

	switch (x)
	{
		case 1://utworzenie konta
		{
			jaka_operacja = "Operacja: Utworzenie konta : ";
			break;
		}
		case 2://wplata na konto
		{
			jaka_operacja = "Operacja: Wplata na konto kwoty : " + napis_kwota_wplaty + " zl ";
			break;
		}
		case 3://wyplata z konta
		{
			jaka_operacja = "Operacja: Wyplata z konta kwoty : " + napis_kwota_wyplaty + " zl ";
			break;
		}
		case 4://przelew przychodzacy
		{
			jaka_operacja = "Operacja: Przelew na to konto kwoty : " + napis_kwota_przelewu + " zl z konta o ID: " + napis_skad_przelew + " ";
			break;
		}
		case 5://przelew wychodzacy
		{
			jaka_operacja = "Operacja: Przelew z tego konta kwoty : " + napis_kwota_przelewu + " zl na konto o ID: " + napis_dokad_przelew + " ";
			break;
		}
	}
	pelny_raport = jaka_operacja + ptr;
	this->historia.push_back(pelny_raport);

}
void konto::wyswietl_historie()
{
	for (int i = 0; i < historia.size(); i++)
	{
		cout << this->historia[i] << endl;
	}
}




