#include <iostream>
#include <cmath>

using namespace std;

double sqrtdef(int, double);

double sqrtcustom(int, double);

void dialogue();

void dialogue2();

int main()
{
	int k;
	while (true)
	{
		cout << endl << "1 - continue with rec, 2 - without rec, else - break" << endl;
		cin >> k;
		switch (k)
		{
		case 1: dialogue(); break;
		case 2: dialogue2(); break;
		default:	return 1;
		}
	}
}


void dialogue()
{
	cout << endl;
	double a;
	int n;
	cout << "Vvedite chislo" << endl;
	cin >> a;
	cout << endl << "Vvedite tochnost" << endl;
	cin >> n;
	cout << sqrtcustom(n, a);
	return;
}


void dialogue2()
{
	cout << endl;
	double a;
	int n;
	cout << "Vvedite chislo" << endl;
	cin >> a;
	cout << endl << "Vvedite tochnost" << endl;
	cin >> n;
	cout << sqrtdef(n, a);
	return;
}


double sqrtcustom(int n, double a)
{
	double x;
	if (n <= 0) return (1 + a) / 2;
	else
	{
		x = sqrtcustom(n - 1, a);
		return 0.5 * (x + a / x);
	}
}


double sqrtdef(int n, double a)
{
	double x = (1 + a) / 2;
	for (int i = 0; i < n + 1; i++)
	{
		x = 0.5 * (x + a / x);
	}
	return x;
}