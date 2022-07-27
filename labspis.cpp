#include <iostream>
#include <iomanip>

using namespace std;

int menu();
void vipoln();

struct tnode
{
	char inf;
	tnode* left;
	tnode* right;
};

struct spisok
{
	tnode* front = nullptr;
	tnode* back = nullptr;

	void push(char inf)
	{
		tnode* spt = new tnode;
		spt->inf = inf;
		spt->right = nullptr;
		if (front == nullptr)
		{
			spt->left = nullptr;
			front = back = spt;
			return;
		}
		back->right = spt;
		spt->left = back;
		back = spt;
	}

	void pushn(char inf)
	{
		tnode* spt = new tnode;
		spt->inf = inf;
		if (front == nullptr)
		{
			spt->left = nullptr;
			spt->right = nullptr;
			front = spt;
			back = front;
		}
		spt->right = front;
		front->left = spt;
		spt->left = nullptr;
		front = spt;
	}

	void pop()
	{
		tnode* spt = front;
		front = front->right;
		delete spt;
		if (!front) back = nullptr;
		else return;
	}

	void print()
	{
		tnode* spt = front;
		while (spt != nullptr)
		{
			cout << spt->inf << " ";
			spt = spt->right;
		}
	}

	int size()
	{
		int size = 0;
		tnode* spt = front;
		while (spt != nullptr)
		{
			size++;
			spt = spt->right;
		}
		return size;
	}


	tnode* vneshf()
	{
		tnode* spt = front;
		return spt;
	};

	tnode* vneshb()
	{
		tnode* spt = back;
		return spt;
	};

}spis1, spis2, spis3;



int main()
{
	char inf;
	while (true)
	{
		inf = 0;
		switch (menu())
		{
		case 1:
		{
			inf = 0;
			cout << "vvedite info  ";
			cin >> inf;
			spis1.push(inf);
		}; break;
		case 2: vipoln(); break;
		case 3:
		{
			spis1.print();
			cout << endl;
			spis2.print();
			cout << endl;
		}break;
		case 4:
		{
			inf = 0;
			cout << "vvedite info  ";
			cin >> inf;
			spis2.push(inf);
		}; break;
		case 5: return 0; break;
		case 6: spis3.print(); break;
		default: cout << "Vam ban!";
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
	cout << "1 - ВВести данные и записать их в cписок1" << endl;
	cout << "2 - выполнить" << endl;
	cout << "3 - вывести" << endl;
	cout << "4 - ВВести данные и записать их в cписок2" << endl;
	cout << "6 - вывести новый список" << endl;
	cout << "5 - Завершить программу" << endl;
	int i;
	cin >> i;
	return i;
}

void vipoln()
{
	tnode* front1 = spis1.vneshf();
	tnode* front2 = spis2.vneshf();
	tnode* back1 = spis1.vneshb();
	tnode* back2 = spis2.vneshb();
	int n = spis1.size()+spis2.size();
	for (int i = 0; i < spis1.size(); i++)
	{
		while (front1 != nullptr)
		{
			if ((front1->inf > 96) && (front1->inf < 123)) spis3.push(front1->inf);
			else spis3.pushn(front1->inf);
			front1 = front1->right;
		}
	}

	for (int i = 0; i < spis2.size(); i++)
	{
		while (front2 != nullptr)
		{
			if ((front2->inf > 96) && (front2->inf < 123)) spis3.push(front2->inf);
			else spis3.pushn(front2->inf);
			front2 = front2->right;
		}
	}
}