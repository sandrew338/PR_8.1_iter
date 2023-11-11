// ƒано л≥терний р€док, €кий м≥стить посл≥довн≥сть символ≥в s[0], ..., s[n], ...
// 1. ¬и€снити, чи Ї в ц≥й посл≥довност≥ так≥ елементи s[iЦ1] , s[i+1]
// що s[iЦ1] Ц це знак плюс ('+'), а s[i+1] Ц знак м≥нус ('-'),
// та обчислити њх к≥льк≥сть.
// 2. «ам≥нити кожну групу символ≥в s[iЦ1] , s[i] , s[i+1] Ц таких, що s[iЦ1] Ц
// це знак плюс ('+'), а s[i+1] Ц знак м≥нус ('-') четв≥ркою з≥рочок "****".
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int QuantityOfSymb(char* str, char symb)
{
	if (strlen(str) < 1)
		return 0;
	int k = 0;
	for (int i = 0; str[i] != 0; i++)
		if (str[i] == symb)
			k++;
	return k;
}
char* Change(char* str)
{
	size_t len = strlen(str);
	if (len < 3)
		return str;
	char* tmp = new char[len * 3 / 2 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	size_t i = 0;
		while (i < len && str[i + 1] != 0)
		{
			if (str[i] == '+' && str[i + 1] == '+' || 
				str[i] == '-' && str[i + 1] == '-' ||
				str[i] == '=' && str[i + 1] == '=')
			{
				strcat(t, "***");
				t += 3;
				i += 2;
			}
			else
			{
				*t++ = str[i++];
				*t = '\0';
			}
		}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy(str, tmp);
	return tmp;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	int quant_plus = QuantityOfSymb(str, '+');
	int quant_minus = QuantityOfSymb(str, '-');
	int quant_equalSymb = QuantityOfSymb(str, '=');
	cout << "String contained:" << endl << quant_plus << " - '+'" << endl
		<< quant_minus << " - '-'" << endl << quant_equalSymb << " - '='" << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}