#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int main()
{
	int zp;
	int fl;
	cout << "Vvedite chislo passagirov: ";
	cin >> zp;
	struct passe1
	{
		char fam[80];
		char nombil[20];
		double vesb;
	} ;
	passe1 *spis = new passe1[zp];

	for (int i = 0; i < zp; i++)
	{
		cout << "Vvedite familiu passagira " << i+1 << " :";
		cin >> spis[i].fam;
		cout << "Vvedite nomer bileta passagira " << i+1 << " :";
		cin >> spis[i].nombil;
		cout << "Vvedite ves bagaga passagira " << i+1 << " :";
		cin >> spis[i].vesb;
	}

	for (int i = 0; i < zp; i++)
	{
		if ( (spis[i].fam[0] > 96) && (spis[i].fam[0] < 123) )
		{
			spis[i].fam[0] = spis[i].fam[0] - 32;
			continue;
		}
	}
	
	passe1 tmp;
	for (int i = 0; i < zp-1; i++)
		for (int j = i + 1; j < zp; j++)
		{
			if (strcmp(spis[i].fam, spis[j].fam) == 1)
			{
				tmp = spis[i];
				spis[i] = spis[j];
				spis[j] = tmp;
			}
		}

	fl = 0;
	cout << endl;
	while (fl < zp)
	{
		if (spis[fl].vesb < 15)
		{
			cout << spis[fl].fam << endl;
		}
		fl++;
	}
	delete[]spis;
	return 0;
}