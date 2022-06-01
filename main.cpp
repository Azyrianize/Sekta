#include <iostream>

using namespace std;


#define MAX_N 1000

int liczba_powtorzen;
long long int liczba_osob_n;
long long int osoba_ginie_k;
bool arrList[MAX_N];

int wpiszLiczbaPowtorzen()
{
	int n;
	cout << "Wpisz ile przypadkow ma byc rozpatrzonych:" << endl;
	cin >> n;
	return n;
}

int wpiszLiczbaOsob_n()
{
	long long int n;
	cout << "Wpisz ile jest osob w sekcie:" << endl;
	cin >> n;
	return n;
}

int wpiszOsobaGinie_k()
{
	long long int n;
	cout << "Wpisz ktora osoba ginie jako k-ta:" << endl;
	cin >> n;
	return n;
}

int main()
{
	liczba_powtorzen = wpiszLiczbaPowtorzen();

	for(int i = 0; i < liczba_powtorzen; i++)
	{
		int counter = 0;
		bool osoba_zyje = true;
		int ileMartwych = 0;

		liczba_osob_n = wpiszLiczbaOsob_n();
		osoba_ginie_k = wpiszOsobaGinie_k();

		if(osoba_ginie_k < 0)
		{
			osoba_ginie_k = liczba_osob_n + osoba_ginie_k + 1;
		}
		else if(osoba_ginie_k == 0)
        {
            osoba_ginie_k = liczba_osob_n;
        }

        if(liczba_osob_n == 1)
        {
            cout << "1" << endl;
        }
        else if(liczba_osob_n != 1 && osoba_ginie_k == liczba_osob_n)
        {
            long long int temp = 1;
            long long int wynik;
            while(temp < liczba_osob_n)
            {
                temp = temp * 2;
            }

            if(temp == liczba_osob_n)
            {
                cout << "1" << endl;
            }
            else
            {
                temp = (temp / 2);
                temp = liczba_osob_n - temp;

                wynik = (temp * 2) + 1;
                cout << wynik << endl;
            }
        }
        else
        {
            for(int j = 0; j < liczba_osob_n; j++)
            {
                arrList[j] = false;
            }

            while(osoba_zyje == true)
            {
                int livingPPL = 0;
                for(int k = 0; k < liczba_osob_n; k++)
                {
                    if(arrList[k] == false)
                    {
                        counter++;;

                        if((counter % 2) == 0)
                        {
                            arrList[k] = true;
                            ileMartwych++;

                            if(ileMartwych == osoba_ginie_k)
                            {
                                cout << "Osoba " << osoba_ginie_k << " ginie jako " << k+1 << "-a" << endl << endl;
                            }
                        }
                    }
                }

                for(int l = 0; l < liczba_osob_n; l++)
                {
                    if(arrList[l] == false)
                    {
                        livingPPL++;
                    }
                }

                if(livingPPL == 0)
                {
                    osoba_zyje = false;
                }
            }
        }


	}

	return 0;
}
