#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, b, h, x, y, s, p;
	int n;
	// cout << "Vvedite a,b,n" << endl; // если надо будет вводить числа с рук
	// cin >> a >> b >> n; 
	a = 0.1;
	b = 1;
	n = 100;
	x = a;
	h = (b - a) / 10;
	for (x = 0.1; x < b + h / 2; x += h)
	{
		y = log(1 + pow(x, 2));
		s = -pow(x, 2);
		p = -pow(x, 2);
		for (double i = 2; i <= n; i++)
		{
			p *= -pow(x, 2) * (i - 1) / i;
			s += p;
		}
		s *= (-1);
		cout << "   " << x << "   " << y << "   " << s << endl;
	}
	cout << endl;
	return 0;
}
