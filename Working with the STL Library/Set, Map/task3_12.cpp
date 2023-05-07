#include<iostream>
#include<set>
#include<map>
#include <fstream>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>


using namespace std;




bool isNumber(string str)
{
	return all_of(str.begin(), str.end(), [](char ch) { return isdigit(ch); });
}

int main() {
	setlocale(LC_ALL, "RUS");
	ifstream file;
	string ss;
	file.close();
	multimap<string, int>let;
	map<string, int>num;
	string number = "0 1 2 3 4 5 6 7 8 9";
	string::size_type pos = 0, k;
	file.open("tempi.txt");
	if (!file.is_open())
		cout << "Не удалось открыть файл";
	else {
		string s;
		int i = 0; int k = 0;
		while (!file.eof()) {
			getline(file, s, ' ');
			if (isNumber(s)) {
				i += 1;
				num.emplace(s,i);
			}
			else {
				if (let.size() == 0) {
					string firstword = s;
				}
				k += 1;
				let.emplace(s, k);
			}
		}
		for (auto it = let.begin(); it != let.end(); it++) {
			int j=let.count(it->first);
			cout << it->first << "---" << j << endl;;
		}

	}

}