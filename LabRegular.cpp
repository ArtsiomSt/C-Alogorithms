#include <regex>
#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	regex::flag_type flag = regex::ECMAScript;
	cmatch output;
	char str[40] = "(55f-D)+f+(4+5+f)*(f+4)=B";
	char vir1[] = "((\\d+|[a-z]|\\d+[a-z]|[A-Z]|(\\(((\\d+|[a-z]|\\d+[a-z]|[A-Z])[-|(\(+|/|*))])*(\\d+|[a-z]|\\d+[a-z]|[A-Z])\\)))[-|(\(+|/|*))])*(\\d+|[a-z]|\\d+[a-z]|[A-Z]|\\(((\\d+|[a-z]|\\d+[a-z]|[A-Z])[-|(\(+|/|*))])*(\\d+|[a-z]|\\d+[a-z]|[A-Z])\\))(=([a-z]|\\d+[a-z]|\\d+|[A-Z]))?";
	regex regf(vir1);
	regex_search(str, output, regf);
	cout << output[0] << endl;
	if (str == output[0]) cout << "yes";
	else cout << "no";
}

/*
char fam[] = "[^À-ß][à-ÿ]{3,20}";
char hom[] = "[ä]\\.\\s?\\d+";
char kv[] = "[ê][â]\\.\\s?\\d+";
regex regf(fam);
regex_search(str, output, regf);
cout << output[0] << " ";
regex regh(hom);
regex_search(str, output, regh);
cout << output[0] << " ";
regex regk(kv);
regex_search(str, output, regk);
cout << output[0];
return 0;
char vir[] = "((\\d|([a-z]{1}))*[-|(\(+|/|*))](\\d|[(a-z)]))*";
char vir[] = "((\\d+|[a-z]|\\d+[a-z]|[A-Z])[-|(\(+|/|*))])*(\\d+|[a-z]|\\d+[a-z]|[A-Z])(=([a-z]|\\d+[a-z]|\\d+|[A-Z]))?";
char vir[] = "((\\d+|[a-z]|\\d+[a-z]|[A-Z])[-|(\(+|/|*))])*((\\(((\\d+|[a-z]|\\d+[a-z]|[A-Z])[-|(\(+|/|*))])*(\\d+|[a-z]|\\d+[a-z]|[A-Z])\\))|(\\d+|[a-z]|\\d+[a-z]|[A-Z]))(=([a-z]|\\d+[a-z]|\\d+|[A-Z]))?";
char vir[] = "(([-|(\(+|/|*]\\d+|[a-z]|\\d+[a-z]|[A-Z])[-|(\(+|/|*))])*((\\(((\\d+|[a-z]|\\d+[a-z]|[A-Z])[-|(\(+|/|*))])*(\\d+|[a-z]|\\d+[a-z]|[A-Z])\\))|(\\d+|[a-z]|\\d+[a-z]|[A-Z]))(=([a-z]|\\d+[a-z]|\\d+|[A-Z]))?";
char vir[] = "((\\d+|[a-z]|\\d+[a-z]|[A-Z])[-|(\(+|/|*))])*((\\(((\\d+|[a-z]|\\d+[a-z]|[A-Z])[-|(\(+|/|*))])*(\\d+|[a-z]|\\d+[a-z]|[A-Z])\\)([-|(\(+|/|*]((\\d+|[a-z]|\\d+[a-z]|[A-Z])[-|(\(+|/|*))])*((\\(((\\d+|[a-z]|\\d+[a-z]|[A-Z])[-|(\(+|/|*))])*(\\d+|[a-z]|\\d+[a-z]|[A-Z])\\))|(\\d+|[a-z]|\\d+[a-z]|[A-Z])))?)|(\\d+|[a-z]|\\d+[a-z]|[A-Z]))(=([a-z]|\\d+[a-z]|\\d+|[A-Z]))?";
char vir[] = "((\\d+|[a-z]|\\d+[a-z]|[A-Z])[-|(\(+|/|*))])*((\\(((\\d+|[a-z]|\\d+[a-z]|[A-Z])[-|(\(+|/|*))])*(\\d+|[a-z]|\\d+[a-z]|[A-Z])\\)([-|(\(+|/|*]((\\d+|[a-z]|\\d+[a-z]|[A-Z])[-|(\(+|/|*))])*((\\(((\\d+|[a-z]|\\d+[a-z]|[A-Z])[-|(\(+|/|*))])*(\\d+|[a-z]|\\d+[a-z]|[A-Z])\\))|(\\d+|[a-z]|\\d+[a-z]|[A-Z])))?)|(\\d+|[a-z]|\\d+[a-z]|[A-Z]))(=([a-z]|\\d+[a-z]|\\d+|[A-Z]))?";	regex regf(vir);
*/
