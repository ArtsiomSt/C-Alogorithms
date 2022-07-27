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
int menu();
bool fileopen(const char*);
void sortvstav(passe[], int);
void quicksort(passe[], int, int);
int p_dv(passe[], int, int);

int main()
{
	while (true)
	{
		switch (menu())
		{
		case 1: fadd(); break;
		case 2: fread(); break;
		case 3: rezscreen(); break;
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
		cout << "Enter name " << i + 1 << " : ";
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
	setlocale(LC_ALL, "Russian");
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
	cout << "1 - cортировка вставками; 2  - быстрая сортировка" << endl;
	int k;
	cin >> k;
	switch (k)
	{
		case 1: sortvstav(list, n); break;
		case 2: quicksort(list, 0 , n-1); break;
		default: cout << "net takou bukvu"; break;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (list[i].vesb <= 15)
		{
			cout << endl << list[i].fam << " Nomer bil: " << list[i].nomb << " Baggage weight: " << list[i].vesb << endl;
		}
		else continue;
	}

	cout << "Введите ключ поиска - ";
	int x;
	cin >> x;

	int pkey = p_dv(list, n, x);

	if (pkey == -1) cout << "Нет элемента с заданным ключом" << endl;

	else cout << "Номер элемента - " << pkey << " Фамилия пассажира - " << list[pkey].fam << endl;

	delete[]list;
	fclose(fl);
}

void sortvstav(passe a[], int n)
{
	int i, j;
	passe temp;
	for (i = 1; i < n; i++)
	{
		temp = a[i];
		for (j = i - 1; j >= 0 && strcmp(temp.fam, a[j].fam) == -1; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}

void quicksort(passe mas[], int first, int last)
{
	passe mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; //вычисление опорного элемента
	do
	{
		while (mas[f].vesb < mid.vesb) f++;
		while (mas[l].vesb > mid.vesb) l--;
		if (f <= l) //перестановка элементов
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quicksort(mas, first, l);
	if (f < last) quicksort(mas, f, last);
}

int p_dv(passe mas[], int n, int x) // x - ключ
{
	int i = 0, j = n - 1, m;
	while (i <= j)
	{
		if (mas[i].vesb == mas[j].vesb)
			if (mas[i].vesb == x) return i;
			else return -1;
		m = i + (j - i) * (x - mas[i].vesb) / (mas[j].vesb - mas[i].vesb);
		if (mas[m].vesb == x) return m;
		else if (x > mas[m].vesb) i = m + 1;
		else j = m - 1;
	}
	return -1;
}







