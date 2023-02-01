#ifndef _LZ78_H
#define _LZ78_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;


string nodeToString(int i, char n) {
	return "<" + to_string(i) + "," + n + ">";
}

vector<string> dictionary(0);

int existInDictionary(string substr) {
	for (int i = 0;i < dictionary.size();i++) {
		if (substr == dictionary[i]) return i+1;
	}
	return 0;
}

string LZ78(string str) {
	string new_str = "", substr = "";
	int newstr_size = 0;
	int i = 1;
	substr = str[0];
	dictionary.push_back(substr);
	new_str+= nodeToString(0, str[0]);
	substr = "";
	while (i < str.size()) {
		if (existInDictionary(substr+str[i])) {
			if(i!=str.size()) substr += str[i];
			else {
				new_str += nodeToString(existInDictionary(substr), str[i]);
				newstr_size++;
			}
		}
		else {
			new_str += nodeToString(existInDictionary(substr), str[i]);
			newstr_size++;
			//dictionary.resize(dictionary.size() + 1);
			dictionary.push_back(substr + str[i]);
			substr="";
		}
		i++;
	}

	cout << "Initial string: " << str << endl;
	cout << endl << "Compressed string: " << new_str << endl << endl;
	cout << "Length of initial string: " << str.size() << endl;
	cout << "Length of initial string: " << newstr_size << endl;
	cout << "Compression ratio: " << (double)(str.size() / (newstr_size * 1.0)) << endl;
	return new_str;
}

#endif
