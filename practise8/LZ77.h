#ifndef _LZ77_H
#define _LZ77_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


string nodeToString(int o, int l, char n) {
	return "<" + to_string(o) + "," + to_string(l) + "," + n + ">";
}

string compareBack(string str, string substr,int* start_substr) {
	if(*start_substr>substr.size()){
		for (int i = 0;i <= *start_substr - substr.size();i++) {
			if (substr == str.substr(i, substr.size())) {
				return nodeToString(*start_substr - i, substr.size(), str[*start_substr + substr.size()]);
			}
		}
	}
	return "";
}

string LZ77(string str) {
	int f = 0;
	string new_str = "",substr="",res="";
	int newstr_size = 0;
	int i = 0;

	while(i<str.size()) {
		f = 0;
		if (i == 0) {
			new_str += nodeToString(0, 0, str[i]);
			i++;
			newstr_size++;
		}
		else {
			int j = 0;
			while (j<str.size()-i) {
				substr = str.substr(i,str.size()-i-j);
				res = compareBack(str, substr, &i);
				if (res != "") {
					new_str += res;
					newstr_size++;
					i+= str.size() - i - j-1;
					f = 1;
					break;
				}
				j++;
			}
			if (!f && j== str.size() - i) {
				new_str += nodeToString(0, 0, str[i]);
				newstr_size++;
			}
			i++;
		}
	}
	cout << "Initial string: " << str << endl;
	cout << endl << "Compressed string: " << new_str << endl << endl;
	cout << "Length of initial string: " << str.size() << endl;
	cout << "Length of initial string: " << newstr_size << endl;
	cout << "Compression ratio: " << (double)(str.size() / (newstr_size * 1.0)) << endl;

	return new_str;
}

#endif
