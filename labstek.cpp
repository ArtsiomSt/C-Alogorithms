#include <iostream>
#include <iomanip>

using namespace std;

int menu();

struct tnode
{
	int inf;
	tnode* a;
};

struct stack
{
	tnode* min;
	tnode* top = nullptr;
	int size = 0;

	bool empty()
	{
		if (top) return false;
		else return true;
	}

	void push(int inf)
	{
		tnode* spt = new tnode;
		spt->inf = inf;
		spt->a = top;
		top = spt;
		size++;
	}

	void pop()
	{
		tnode* spt = top;
		top = top->a;
		delete spt;
		size--;
	}

	tnode* search(int x)
	{
		tnode* spt = top;
		if (!top) return nullptr;
		while (spt->inf != x && spt->a != nullptr) spt = spt->a;
		if (spt->inf == x) return spt;
		else return nullptr;
	}

	void dellmin()
	{
		tnode* spt = top;
		tnode* min = top;
		while (spt != nullptr)
		{
			if (spt->inf < min->inf) min = spt;
			spt = spt->a;
		}

		delete spt;

		while (top != min)
		{
			tnode* spt = top;
			top = top->a;;
			delete spt;
		}
	}

	void vuvod()
	{
		tnode* spt = top;
		while (spt != nullptr)
		{
			cout << spt->inf << setw(5);
			spt = spt->a;
		}
	}

	void labda1()
	{
		tnode* spt = top;

		if (top->inf % 10 == 5)
		{
			tnode* spp = top;
			top = top->a;
			spt = top;
			delete spp;
		}

		while (spt->a != nullptr)
		{
			if (spt->a->inf % 10 == 5)
			{
				spt->a = spt->a->a;
			}
			else spt = spt->a;
		}
	}
};	

int main()
{
	stack labs;
	int inf;
	while (true)
	{
		switch (menu())
		{
		case 1:
		{
			inf = 0;
			cout << "vvedite info  ";
			cin >> inf;
			labs.push(inf);
		}; break;
		case 2: labs.labda1(); break;
		case 3: labs.vuvod(); break;
		case 5: return 0; break;
		default: "Vam ban!";
		}
		cout << endl;
		system("pause");
		system("cls");
	}
	return 0;
}

int menu()
{
	setlocale(LC_ALL, "Russian");
	cout << "Выбор: " << endl;
	cout << "1 - ВВести данные и записать их в стек" << endl;
	cout << "2 - выполнить" << endl;
	cout << "3 - вывести" << endl;
	cout << "5 - Завершить программу" << endl;
	int i;
	cin >> i;
	return i;
}