/*
WYMAGANIA:
Zrobione:

Napisz program do obsługi banku. Program musi:
Umożliwiać obsługę klientów (wyświetl-ok(wszystkich uzytkownikow), dodaj-ok, edytuj-ok(po ID), usuń-ok(wszystkie dane))
Umożliwiać obsługę kont (wyświetl-ok(dane i konto), dodaj-ok do id, edytuj-ok, usuń-ok)
Umożliwiać wykonanie wpłat, wypłat, przelewów między kontami-ok
Uniemożliwiać wypłatę pieniędzy jeżeli na koncie jest mniej pieniędzy-ok
Umożliwiać utworzenie debetu-ok
Wykorzystać wskaźnik this-ok
Wykorzystać hermetyzację (public, protected, private)-ok
Wykorzystać klasę zaprzyjaźnioną-ok(w klasach konto i klienci sa przyjacielami z bankiem)
dodatkowe jakies funckcje-ok dodana statystyka,baza danych z plikow
Wykorzystać typedef-ok uzyte w konto.h(typ_operacji)
Zapisywać historię operacji wykonanych na koncie-ok
Umożliwiać wyświetlenie historii operacji wykonanych na koncie-ok
Wykorzystać funkcję zaprzyjaźnioną-ok(w main funkcja_if jest zaprzyjazniona z bankiem)
podpiac baze danych-zrobiona na plikach,zmiany zapisuja sie po zamknieciu programu
Do Zrobienia:




*/


#include "pch.h"
#include <iostream>
#include "klient.h"
#include "konto.h"
#include "bank.h"

void funkcja_id(bank &x)//funkcja zaprzyjazniona z bankiem
{
	cout << "ID kolejnego klienta: " << x.id_nowego_klienta << endl;
	cout << "Id kolejnego konta: " << x.id_nowego_konta << endl;
}


using namespace std;

int main()
{
	
	//zmienne przy menu
	int wybor;
	int wybor_2;
	int wybor_3;
	int wybor_4;


	bank b;//tworze moj bank
	



	while (1)
	{
		cout << "################################################" << endl;
		cout << "# Witaj w programie obslugi banku              #" << endl;
		cout << "#                                              #" << endl;
		cout << "# Wybierz jaki typ operacji chcesz wykonac     #" << endl;
		cout << "# 1.Obsluga klientow                           #" << endl;
		cout << "# 2.Obsluga kont                               #" << endl;
		cout << "# 3.Funkcje statystyczne                       #" << endl;
		cout << "# 4.Zaladuj klientow i historie z plikow       #" << endl;
		cout << "# Kazda inna opcja zakonczy dzialanie programu #" << endl;
		cout << "################################################" << endl;

		cin >> wybor;
		switch(wybor)
		{
			case 1:
			{
				cout << "*******************************" << endl;
				cout << "* Co dokladnie chcesz zrobic? *" << endl;
				cout << "*                             *" << endl;
				cout << "* 1.Wyswietlic klientow banku *" << endl;
				cout << "* 2.Dodac nowego klienta      *" << endl;
				cout << "* 3.Zmodyfikowac dane klienta *" << endl;
				cout << "* 4.Usunac klienta            *" << endl;
				cout << "*******************************" << endl;
				cin >> wybor_2;
					switch (wybor_2)
					{
						case 1://wyswietla klientow banku
						{
							b.wyswietl_klientow();
							break;
						}
						case 2://dodaje nowego klienta banku(bez konta)
						{
							b.dodaj_klienta();
							break;
						}
						case 3://modyfikuje dane klienta szukajac go po ID
						{
							b.modyfikuj_dane();
							break;
						}
						case 4://ususwa klienta o podancyh danych
						{
							b.usun_klienta();
							break;
						}
						default:
						{
							break;
						}
					}

				break;
			}
			case 2:
			{
				cout << "*****************************************************************************" << endl;
				cout << "* Co dokladnie chcesz zrobic?                                               *" << endl;
				cout << "*                                                                           *" << endl;
				cout << "* 1.Wyswietlic dane powiązane z kontem(stan,dane wlasciciela,historia sesji *" << endl;
				cout << "* 2.Dodac nowe konto                                                        *" << endl;
				cout << "* 3.Dokonac operacji na koncie                                              *" << endl;
				cout << "* 4.Usunac konto                                                            *" << endl;
				cout << "*****************************************************************************" << endl;
				cin >> wybor_3;
				switch (wybor_3)
				{
					case 1://wyswietla dnae klienta i jego konto
					{
						b.wyswietl_konto();
						
						break;
					}
					case 2://tworzy konto dla klienta o podany ID i startowa kwota
					{		
						b.dodaj_konto();
						break;
					}
					case 3://operajce na koncie
					{
						cout << "***********************************************************************" << endl;
						cout << "* Jaka operacje na koncie chcesz przeprowadzic?                       *" << endl;
						cout << "*                                                                     *" << endl;
						cout << "* Wszystkie te operacje beda zapisywane w histori operacji na kontach *" << endl;
						cout << "* 1.Wplata na konto                                                   *" << endl;
						cout << "* 2.Wyplata z konta                                                   *" << endl;
						cout << "* 3.Przelew miedzy kontami                                            *" << endl;
						cout << "***********************************************************************" << endl;

						cin >> wybor_4;
						switch (wybor_4)
						{
							case 1://wplata
							{
								b.wplata_na_konto();
								break;
							}
							case 2://wyplata i debet
							{
								b.wyplata_z_konta();
								break;
							}
							case 3://przelew
							{
								b.przelew();
								break;
							}
							default:
							{
								break;
							}
						}
					break;
						
					}
					case 4://usuwa konto o podanym id
					{
						b.usun_konto();
						break;
					}
					default:
					{
						break;
					}

					break;
				}
				break;
			}
			case 3://statystyka
			{
				b.statystyka();
				funkcja_id(b);
				break;
			}
			case 4://ladowanie z pliku
			{
				b.zaladuj_z_plikow();
				b.zaladuj_historie_z_plikow();
				break;
			}
			default:
			{
				b.zapisz_do_plikow();
				b.zapisz_historie_do_plikow();
				cout << "Konczenie programu..." << endl;
				cout << "Dane zostana zapisane do plikow bazy danych" << endl;
				return 0;
				break;
			}
			
		}
	}

	return 0;
}

