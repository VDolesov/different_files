#include<iostream>
#include<map>
#include<set>
#include <cctype>
#include<string>
#include <algorithm>


using namespace std;
//Восклицательное предложение! Вопросительное предложение? Повествовательное предложение.
int main() {
	setlocale(LC_ALL, "RUS");
	string s1; cout << "Введите текст " << endl;
	s1 = "Восклицательное предложение ujdyf! Вопросительное предложение[equybz? Повествовательное предложение pfkegs";
	set<string>vopr;
	string razdel = "!?.";
	string razd = "? ! , . : ; -  ";
	int n = 0;
	s1 += '.';
	string::size_type pos = 0, k;
	k = s1.find_first_of(razdel, pos);// конец предложения
	while (k != string::npos) { // пока существуют предложения

		string tmp; tmp = s1[k]; // tmp это знак препинания в конце предложения
		string h1; h1 = s1.substr(pos, k - pos);// конкретное предложение
		h1 += " ";
		string::size_type pos1 =0, k1;
		k1 = h1.find_first_of(razd);// конец первого слова
		while (k1 != string::npos) {
			string word; word = h1.substr(pos1, k1 - pos1);// слово
			if (tmp == "!" || tmp == "?") {
				vopr.insert(word);
				n += 1;
				cout << word << " ";
			}
			pos1 = k1+1;
			k1 = h1.find_first_of(razd, pos1);
		}
		
		pos = h1.size()+pos;
		k = s1.find_first_of(razdel, pos);
		
	}
	cout << endl;
	cout << n;
}