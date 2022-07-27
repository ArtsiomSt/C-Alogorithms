#include <iostream>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <io.h>

using namespace std;

struct passe
{
	char fam[50];
	int nomb;
	double vesb;
} *list, tmp, zhel;

char fname[20] = "";
FILE* fl, * fz;

int n = 0;
void fadd();
void fread();
void rezscreen();
void rezfile();
int menu();
bool fileopen(const char*);

int main()
{
	while (true)
	{
		switch (menu())
		{
		case 1: fadd(); break;
		case 2: fread(); break;
		case 3: rezscreen(); break;
		case 4: rezfile(); break;
		case 5: return 0; break;
		default: "Vam ban!";
		}
		system("pause");
		system("cls");
	}
	return 0;
}

int menu()
{
	setlocale(LC_ALL, "Russian");
	cout << "Выбор: " << endl;
	cout << "1 - ВВести данные и записать их в файл" << endl;
	cout << "2 - Прочитать исходный файл" << endl;
	cout << "3 - Вывести результат обработки" << endl;
	cout << "4 - Записать результат в файл" << endl;
	cout << "5 - Завершить программу" << endl;
	int i;
	cin >> i;
	return i;

}

bool fileopen(const char* param)
{
	if (!strlen(fname)) // strlen - true kogda ne pustoi, kogda pustoi - false
	{
		cout << "Enter the file name: " << endl;
		cin >> fname;
	}

	if (fopen_s(&fl, fname, param))
	{
		cout << "File ne otkrilsya" << endl;
		return false;
	}
	else return true;
}

void fadd()
{
	if (!fileopen("ab+")) return;
	int i, zp;
	cout << "Enter the number of passagirs: ";
	cin >> zp;
	for (i = 0; i < zp; i++)
	{
		cout << "Enter name " << i+1 << " : ";
		cin >> zhel.fam;
		cout << "Enter nomer bileta " << i + 1 << " : ";
		cin >> zhel.nomb;
		cout << "Enter bagage wight " << i + 1 << " : ";
		cin >> zhel.vesb;
		fwrite(&zhel, sizeof(passe), 1, fl);
	}
	fclose(fl);
}

void fread()
{
	if (!fileopen("rb")) return;
	n = _filelength(_fileno(fl)) / sizeof(passe);
	list = new passe[n];
	fread(list, sizeof(passe), n, fl);

	for (int i = 0; i < n; i++)
	{
		cout << endl << "Familia: " << list[i].fam << " Nomer bil: " << list[i].nomb << " Baggage weight: " << list[i].vesb << endl;
	}

	cout << endl;
	delete[]list;
	fclose(fl);
}

void rezscreen()
{
	if (!fileopen("rb")) return;
	n = _filelength(_fileno(fl)) / sizeof(passe);
	list = new passe[n];
	fread(list, sizeof(passe), n, fl);
	
	for (int i = 0; i < n; i++)
	{
		if ((list[i].fam[0] > 96) && (list[i].fam[0] < 123))
		{
			list[i].fam[0] = list[i].fam[0] - 32;
			continue;
		}

	}

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(list[i].fam, list[j].fam) == 1)
			{
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}

	for (int i = 0; i < n; i++)
	{
		if (list[i].vesb <= 15)
		{
			cout << endl << list[i].fam << " Nomer bil: " << list[i].nomb << " Baggage weight: " << list[i].vesb << endl;
		}
		else continue;
	}

	delete[]list;
	fclose(fl);
}

void rezfile()
{
	char frezname[20];
	cout << "enter the name of the text file" << endl;
	cin >> frezname;

	if (fopen_s(&fz, frezname, "wt+"))
	{
		cout << "Pochemy to file ne sozdalsya";
		return;
	}

	if (!fileopen("rb"))
	{
		cout << "popafsya";
		return;
	}
	n = _filelength(_fileno(fl)) / sizeof(passe);
	list = new passe[n];
	fread(list, sizeof(passe), n, fl);
	
	for (int i = 0; i < n; i++)
	{
		if ((list[i].fam[0] > 96) && (list[i].fam[0] < 123))
		{
			list[i].fam[0] = list[i].fam[0] - 32;
			continue;
		}
	
	}

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(list[i].fam, list[j].fam) == 1)
			{
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}

	for (int i = 0; i < n; i++)
	{
		if ((list[i].vesb) <= 15)
		{
			fwrite(&list[i], sizeof(passe), 1, fz);
		}
		else continue;
	}

	delete[]list;
	fclose(fl);
	fclose(fz);
}







