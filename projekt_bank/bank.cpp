#pragma once
#include "pch.h"
#include "bank.h"

void bank::wyswietl_klientow()
{

	cout << "Klienci banku to...: " << endl;
	if (this->klienci.empty())
	{
		cout << "Brak klientow " << endl;	
	}

	auto it = klienci.begin();
	auto it_1 = konta.begin();


	for (it;it!=klienci.end();it++)
	{
		it->wyswietl();
		
	}
	for (it_1; it_1 != konta.end(); it_1++)
	{
		it_1->wyswietl();
	}

}
void bank::dodaj_klienta()
{
	klient x;
	x.dodaj(this->id_nowego_klienta);
	this->klienci.push_back(x);
	id_nowego_klienta++;

	
}
void bank::modyfikuj_dane()
{

	string imie_mod;
	string nazwisko_mod;

	int id_mod;
	cout << "Podaj Id klienta którego dane chcesz zmodyfikowc" << endl;
	cin >> id_mod;
	auto it = klienci.begin();
	for (it;it!=klienci.end();it++)
	{
		if (id_mod == it->id_klienta)
		{
			cout << "Aktualne dane: " << endl;
			it->wyswietl();
			cout << endl;
			cout << "Wprowadz nowe dane " << endl;
			id_mod = it->id_klienta;
			it->dodaj(id_mod);
			
		}
	}


}void bank::usun_klienta()
{
	string imie_usu;
	string nazwisko_usu;
	int wiek_usu;
	cout << "Podaj wszystkie dane klienta do usuniecia,uwaga usunie tez powiazane konta!" << endl;
	cout << "Imie:" << endl;
	cin >> imie_usu;
	cout << "Nazwisko:" << endl;
	cin >> nazwisko_usu;
	cout << "Wiek:" << endl;
	cin >> wiek_usu;
	auto it = klienci.begin();
	auto it_1 = konta.begin();
	for (it; it!=klienci.end(); it++)
	{
		if (it->imie == imie_usu && it->nazwisko == nazwisko_usu && it->wiek == wiek_usu)
		{
			for (it_1; it_1!=konta.end() ;it_1++)
			{
				if (it_1->id_wlasciciel ==it->id_klienta)
				{
					konta.erase(it_1);
					break;
				}
			}
			klienci.erase(it);
			break;
		}
	}
}
void bank::wyswietl_konto()
{
	int id_klienta_wys;
	cout << "Podaj Id klienta dla ktorego wswietlic konto i jego dane osobowe" << endl;
	cin >> id_klienta_wys;
	auto it = klienci.begin();
	auto it_1 = konta.begin();
	for (it;it!=klienci.end();it++)
	{
		if (it->id_klienta == id_klienta_wys)
		{
			it->wyswietl();
		}

	}
	for (it_1;it_1!=konta.end();it_1++)
	{
		if (it_1->id_wlasciciel == id_klienta_wys)
		{

			it_1->wyswietl();
			it_1->wyswietl_historie();

		}

	}


}
void bank::dodaj_konto()
{
	int id_klienta_stworzenie;
	cout << "Podaj Id uzytkownika dla ktorego chcesz stworzyc konto i ilosc kwoty poczatkowej" << endl;
	cout << "ID: " << endl;
	cin >> id_klienta_stworzenie;
	
	auto it = klienci.begin();

	for (it;it!=klienci.end();it++)
	{
		if (it->id_klienta == id_klienta_stworzenie)
		{
			konto x;
			x.dodaj(this->id_nowego_konta, id_klienta_stworzenie);
			id_nowego_konta++;
			x.id_wlasciciel = id_klienta_stworzenie;
			konta.push_back(x);
		}
		
	}
/*	auto it_1 = konta.begin();

	for (it_1;it_1!=konta.end();it_1++)
	{
		if (it_1->id_wlasciciel == id_klienta_stworzenie && it_1->historia.empty())
		{
			it_1->dodaj_historie(1, 0, 0, 0, 0, 0);
		}
	}
	*/

}
void bank::wplata_na_konto()
{
	double kwota_wplata;
	unsigned int id_konta_wplata;
	cout << "Podaj jaka kwote chcesz wplacic i konto ID" << endl;
	cout << "ID konta: " << endl;
	cin >> id_konta_wplata;
	cout << "Kwota do wplaty: " << endl;
	cin >> kwota_wplata;
	auto it = konta.begin();
	for (it;it!=konta.end();it++)
	{
		if (id_konta_wplata == it->id_konta)
		{
			it->stan_konta += kwota_wplata;
			it->dodaj_historie(2, kwota_wplata, 0, 0, 0, 0);
			cout << "Stan konta po wplacie to: " << it->stan_konta << endl;
		}
	}

}
void bank::wyplata_z_konta()
{
	int wybor_5;
	double kwota_wyplata;
	int id_konta_wyplata;
	cout << "Podaj jaka kwote chcesz wyplacic z konta i jego ID" << endl;
	cout << "ID konta: " << endl;
	cin >> id_konta_wyplata;
	cout << "Kwota do wyplaty: " << endl;
	cin >> kwota_wyplata;
	auto it = konta.begin();
	for (it;it!=konta.end();it++)
	{
		if (id_konta_wyplata == it->id_konta)//znalezino konto
		{
			if (it->stan_konta-kwota_wyplata > -5000)
			{
				if (it->stan_konta >= kwota_wyplata)
				{
					it->stan_konta -= kwota_wyplata;
					it->dodaj_historie(3, 0, kwota_wyplata, 0, 0, 0);
					cout << "Stan konta po wyplacie: " << it->stan_konta << endl;
					break;
				}
				else
				{
					cout << "Niewystarczajaca liczba srodkow na koncie!" << endl;
					cout << "Czy utworzyc zwiekszyc debet?(Max 5000 zl)" << endl;
					cout << "1. Tak" << endl;
					cout << "2. Nie" << endl;
					cin>>wybor_5;
					switch (wybor_5)
					{
					case 1:
					{
						it->stan_konta -= kwota_wyplata;
						it->dodaj_historie(3, 0, kwota_wyplata, 0, 0, 0);
						cout << "Stan konta po wyplacie: " << it->stan_konta << endl;
						break;

						break;
					}
					case 2:
					{
						break;
					}
					default:
						break;
					}
				}
			}
			else
			{
				cout << "Operacja nie moze zostac zrealizwana bo stan konta przekroczy maksymalny debet!!!" << endl;
			}

		}
	}
	
}
void bank::przelew()
{
	bool udane_wyslanie = 0;
	bool udane_odebranie = 0;
	unsigned int id_wyslania;
	unsigned int id_odebrania;
	unsigned int id_konta_skad;
	unsigned int id_konta_dokad;
	double kwota_przelewu;
	cout << "Podaj id kont do przelewu i kwote: " << endl;
	cout << "ID konta wykonujacego przelew: " << endl;
	cin >> id_konta_skad;
	cout << "ID konnta do ktorego ma pojsc przelew: " << endl;
	cin >> id_konta_dokad;
	cout << "Kwota przelewu: " << endl;
	cin >> kwota_przelewu;
	for (int i=0;i<konta.size();i++)
	{
		if (id_konta_skad == this->konta[i].id_konta)
		{
			if (this->konta[i].stan_konta >= kwota_przelewu)
			{
				this->konta[i].stan_konta -= kwota_przelewu;
				id_wyslania = i;
				udane_wyslanie = 1;
			}
			else
			{
				cout << "NIewystarczajaca liczba srodkow do przeprowadzenia przelewu" << endl;
				
			}
		}

	}

	for (int i = 0; i < konta.size(); i++)
	{
		if( this->konta[i].id_konta == id_konta_dokad)
		{
			this->konta[i].stan_konta += kwota_przelewu;
			id_odebrania = i;
			udane_odebranie = 1;
		}

	}
	if (udane_wyslanie && udane_odebranie)
	{
		this->konta[id_wyslania].dodaj_historie(5, 0, 0, kwota_przelewu, id_odebrania, id_wyslania);
		this->konta[id_odebrania].dodaj_historie(4, 0, 0, kwota_przelewu, id_odebrania, id_wyslania);
		cout << "Przelew udany" << endl;
	}
	else if (udane_wyslanie && !udane_odebranie)
	{
		this->konta[id_wyslania].stan_konta += kwota_przelewu;
		cout << "Przelew nieudany" << endl;
	}
	else if (!udane_wyslanie && udane_odebranie)
	{
		this->konta[id_odebrania].stan_konta -= kwota_przelewu;
		cout << "Przelew nieudany" << endl;
	}
	else
	{
		cout << "Nie odnaleziono odpowiednich kont" << endl;
	}

}
void bank::usun_konto()
{

	unsigned int id_konta_usu;
	cout << "Podaj ID konta do usuniecia/zamkniecia" << endl;
	cin >> id_konta_usu;
	auto it = konta.begin();
	for  (it ;it!=konta.end(); it++)
	{
		if (it->id_konta == id_konta_usu)
		{
			konta.erase(it);
			break;
		}
	}
}
void bank::statystyka()
{

	double srednia_wieku = 0;
	unsigned int suma_wieku = 0;
	double sredni_stan_konta = 0;
	double suma_stan_konta = 0;
	double max_stan_konta = 0;
	unsigned int id_najbogatsze_konto = 0;
	unsigned int id_najbogatszy_klient = 0;
	cout << "Aktualnie dostêpne statystyki: " << endl;
	cout << "Ilosc klientow banku: " << this->klienci.size() << endl;
	cout << "Ilosc kont w banku: " << this->konta.size() << endl;
	cout << "Srednia wieku klientow: " << endl;
	auto it = klienci.begin();
	for (it;it!=klienci.end();it++)
	{
		suma_wieku += it->wiek;

	}
	if (this->klienci.size() == 0)
	{
		cout << "Brak damych..." << endl;
	}
	else
	{
		srednia_wieku = suma_wieku / this->klienci.size();
		cout << srednia_wieku << endl;
		srednia_wieku = 0;
		cout << "Sredni stan konta:" << endl;
	}
	auto it_1 = konta.begin();
	for (it_1;it_1!=konta.end();it_1++)
	{
		suma_stan_konta += it_1->stan_konta;
		if (it_1->stan_konta > max_stan_konta)
		{
			max_stan_konta = it_1->stan_konta;
			id_najbogatsze_konto = it_1->id_konta;
			id_najbogatszy_klient = it_1->id_wlasciciel;
		}

	}
	if (this->konta.size() == 0)
	{
		cout << "Brak damych..." << endl;
	}
	else
	{
		sredni_stan_konta = suma_stan_konta / this->konta.size();
		cout << sredni_stan_konta << endl;
		sredni_stan_konta = 0;
	}
	cout << "Najbogatsze konto nalezy do klienta o ID: " << id_najbogatszy_klient << endl;
	cout << "Jest to konto o id: " << id_najbogatsze_konto << endl;
	cout << "Jego stan wynosi: " << max_stan_konta << endl;



}
void bank::zaladuj_z_plikow()
{
	fstream plik_klienci;
	fstream plik_konta;

	string p_imie;
	string p_nazwisko;
	unsigned int p_wiek;

	unsigned int p_id_wlasciciel;
	double p_stan_konta;
	
	plik_klienci.open("klienci.txt", ios::in);
	if(plik_klienci.good())
	{
		while(plik_klienci >> p_imie >> p_nazwisko >> p_wiek)
		{

			klient x;
			x.id_klienta = this->id_nowego_klienta;
			x.imie = p_imie;
			x.nazwisko = p_nazwisko;
			x.wiek = p_wiek;
			this->klienci.push_back(x);
			id_nowego_klienta++;
		}

	}

	plik_klienci.close();


	plik_konta.open("konta.txt", ios::in);

	if(plik_konta.good())
	{
		while (plik_konta >> p_id_wlasciciel >> p_stan_konta)
		{
			
			konto y;
			y.id_konta = this->id_nowego_konta;
			y.id_wlasciciel = p_id_wlasciciel;
			y.stan_konta = p_stan_konta;
			//y.dodaj_historie(1, p_stan_konta, 0, 0, 0, 0);
			this->konta.push_back(y);
			id_nowego_konta++;
		}

	}

	plik_konta.close();
}
void bank::zapisz_do_plikow()
{
	fstream plik_klienci;
	fstream plik_konta;

	plik_klienci.open("klienci.txt", ios::out);
	for (int i=0;i<klienci.size();i++)
	{
		plik_klienci << this->klienci[i].imie << " ";
		plik_klienci << this->klienci[i].nazwisko << " ";
		plik_klienci << this->klienci[i].wiek << endl;
	}
	plik_klienci.close();

	plik_konta.open("konta.txt", ios::out);
	for (int i=0;i<konta.size();i++)
	{
		plik_konta << this->konta[i].id_wlasciciel << " ";
		plik_konta <<this->konta[i].stan_konta << endl;

	}
	plik_konta.close();
}
void bank::zapisz_historie_do_plikow()
{
	fstream plik_historia;
	plik_historia.open("historia.txt", ios::out);
	for (int i = 0; i < this->konta.size(); i++)
	{
		for (int j = 0; j < konta[i].historia.size(); j++)
		{
			plik_historia << "Id_konta: " << this->konta[i].id_konta <<" "<< this->konta[i].historia[j] << endl;
		}
	}
	plik_historia.close();
}
void bank::zaladuj_historie_z_plikow()
{
	unsigned int p_id_konta;
	string p_historia_operacji;
	string historia_operacji;
	fstream plik_historia;
	string kosz;
	plik_historia.open("historia.txt", ios::in);
	if (plik_historia.good())
	{
		while (plik_historia>>kosz>>p_id_konta)
		{
				getline(plik_historia, p_historia_operacji);
				p_historia_operacji.erase(p_historia_operacji.begin());
				for (int i = 0; i < konta.size(); i++)
				{
					if (p_id_konta == konta[i].id_konta)
					{
						/*
						for (int j = 0; j < konta[i].historia.size(); j++)
						{
							this->konta[i].historia[j] = p_historia_operacji;

						}
						*/
						this->konta[i].historia.push_back(p_historia_operacji);
					}
				}
		
		}

	}

}