#include<iostream>
#include<map>
#include<set>
#include<string>
#include <algorithm>


//1 15 125 33 28 1473 156 145

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	string h; cout << "Введите строку" << endl; getline(cin, h);
	set<string>trex; set<string>dvux;
	set<string>::iterator it_2;
	set<string>::iterator it_3;
	string::size_type pos = 0, k;
	k = h.find_first_of(' ');
	h += ' ';
	while (k != string::npos) {
		string chislo = h.substr(pos, k - pos);// копия числа
		if (chislo.size() == 3) {
			for (int i = 0; i < chislo.size(); i++) {
				string chif_1;
				chif_1 = chislo[i];
				trex.insert(chif_1);
			}
		}
		if (chislo.size() == 2) {
			for (int i = 0; i < chislo.size(); i++) {
				string chif;
				chif = chislo[i];
				dvux.insert(chif);
			}
		}
		if (ispunct(h[k]))pos = k + 2; // если встречаются знаки пунктуации, то перейти на знак препинания + пробел 
		else pos = k + 1;
		k = h.find_first_of(' ', pos);
	}
	for (auto it_2 = dvux.begin(); it_2 != dvux.end(); it_2++) {
		if (trex.count(*it_2)==0) {
			cout << *it_2;
		}
	}
	
}