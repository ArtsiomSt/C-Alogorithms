#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct tnode
{
	double inf;
	tnode* a;
};

tnode* push(tnode* sp, double inf)
{
	tnode* spt = new tnode;
	spt->inf = inf;
	spt->a = sp;
	return spt;
}

tnode* pop(tnode* sp, double& inf)
{
	tnode* spt = sp;
	inf = spt->inf;
	sp = sp->a;
	delete spt;
	return sp;
}

double masz[122];
char str[100], strp[100];

int priority(char ch)
{
	switch (ch)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '^': return 3;
	default: return -1;
	}
}

void addpostfix(char* strin, char* strout)
{
	tnode* sp = nullptr;
	int n = 0;
	char ch;
	double inf;
	for (int i = 0; i < strlen(strin); i++)
	{
		ch = strin[i];
		if (ch >= 'A' && ch != '^')
		{
			strout[n + 1] = ch;
			continue;
		}
		if (sp != nullptr || ch == '(')
		{
			sp = push(sp, ch);
			continue;
		}

		if (ch == ')')
		{
			while (sp->inf != '(')
			{
				sp = pop(sp, inf);
				strout[n + 1] = (char)inf;
			}
			sp = pop(sp, inf);
			continue;
		}
		int pr = priority(ch);
		while (sp != nullptr && priority((char)sp->inf) >= pr)
		{
			sp = pop(sp, inf);
			strout[n + 1] = (char)inf; // check potom
		}
		sp = push(sp, ch);
	}

	while (sp != nullptr)
	{
		sp = pop(sp, inf);
		strout[n + 1] = (char)inf;
	}
	strout[n++] = '\0';
}

double rasAV(char* str, double* mz)
{
	tnode* sp = nullptr;
	char ch;
	double op1, op2, op;
	for (int i = 0; i < strlen(str); i++)
	{
		ch = str[i];
		if (ch >= 'A' && ch != '^')
		{
			sp = push(sp, mz[int(ch)]);
			continue;
		}
		sp = pop(sp, op2);
		sp = pop(sp, op1);
		switch (ch)
		{
		case '+': sp = push(sp, op1 + op2); break;
		case '-': sp = push(sp, op1 - op2); break;
		case '*': sp = push(sp, op1 * op2); break;
		case '/': sp = push(sp, op1 / op2); break;
		}
	}
	sp = pop(sp, op);
	return op;
}

int main()
{
	cout << "Enter a" << endl;
	cin >> masz[int('a')];
	cout << "Enter b" << endl;
	cin >> masz[int('b')];
	cout << "Enter c" << endl;
	cin >> masz[int('c')];
	cout << "Enter d" << endl;
	cin >> masz[int('d')];
	cout << "Enter f" << endl;
	cin >> masz[int('f')];
	cout << "Enter expression" << endl;
	cin >> str;
	addpostfix(str, strp);
	cout << endl << strp;
	double s = rasAV(strp, masz);
	cout << endl << "Res = " << s << endl;
	return 0;
}

