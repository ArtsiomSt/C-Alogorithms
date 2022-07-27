#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n, i, m, j, k;
	cout << "VVedite razmeri n and m" << endl;
	cin >> n >> m;

	int** s = new int* [n];
	for (int i = 0; i < n; i++)
		s[i] = new int[m];

	double* a = new double [n];

	k = n * m;
	cout << "Vvedite massiv ( " << k << " ) chisel" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cin >> s[i][j];
	}
	cout << endl;
	cout << " Vash massiv : " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << s[i][j] << "   ";
		}
		cout << endl;
	}
	for (i = 0; i < n; i++)
	{
		a[i] = 0;
		for (j = 0; j < m; j++)
		{
			if ((s[i][j] < s[i][j + 1]) || (j == m - 1)) continue;
			else 
				{
					a[i] = 1;
					break;
				}
		}
	}
	cout << "Resulruishiu massiv : " << endl;
	for (i = 0; i < n; i++)
	{
		cout << a[i];
	}
	for (int i = 0; i < n; i++)
		delete[] s[i];
	delete[] s;
	return 0;
}

	
