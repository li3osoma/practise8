#ifndef _RLE_H
#define _RLE_H

#include <string>
#include <iostream>
using namespace std;

string RLE(string str) {
	int str_size=1; //счетчик подсчета эл-ов входной строки
	int newstr_size = 0; //счетчик подсчета эл-ов рассматриваемой подстроки
	char same_count = 1; //подсчет идущих подр€д одинаковых символов
	int dif_count = 1; //подсчет идущих подр€д неодинаковых символов
	string new_str; //выходна€ строка
	string temp; //накопление подр€д идущих одинаковых или неодинаковых символов
	char ch0 = str.at(0), ch1;
	temp.push_back(ch0);
	while (str.at(str_size) != '\0') {
		ch1 = str.at(str_size);
		str_size++; 
		if (ch0 == ch1) {
			if(dif_count>1){ //если все предыдущие символы - неодинаковые
				dif_count--;
				temp.pop_back(); //убираем текущий символ из накоплени€
				new_str+=to_string((int)(-dif_count)); //добавл€ем в выходную строку число подр€д идущих неодинаковых символов 
				new_str+=temp; //добавл€ем в выходную строку все накопленные подр€д идущие неодинаковые символы
				newstr_size += temp.size() + 1;
				dif_count = 1;
				temp.clear();
				temp.push_back(ch1);
				same_count++; 
			}
			else {
				if (same_count + 1 == 128) { //если подр€д идущих символов не меньше 127
					new_str+=to_string((int)same_count); //добавл€ем в выходную строку число подр€д идущих одинаковых символов 
					new_str += temp; //добавл€ем в выходную строку все накопленные подр€д идущие одинаковые символы
					newstr_size += temp.size() + 1;
					same_count = 1;
				}
				else {
					same_count++;
				}
			}
		}
		else { //если текущий символ не равен предыдущему
			if (same_count > 1) { //если все предыдущие символы - одинаковые
				new_str += to_string((int)same_count); //добавл€ем в выходную строку число подр€д идущих одинаковых символов 
				new_str += temp; //добавл€ем в выходную строку все накопленные подр€д идущие одинаковые символы
				newstr_size += temp.size() + 1;
				same_count = 1;
				temp.clear();
				temp.push_back(ch1);
			}
			else {
				if (dif_count + 1 == 128) {//если подр€д идущих символов не меньше 127
					new_str += to_string((int)(-dif_count)); //добавл€ем в выходную строку число (с минусом) подр€д идущих неодинаковых символов 
					new_str += temp; //добавл€ем в выходную строку все накопленные подр€д идущие неодинаковые символы
					newstr_size += temp.size() + 1;
					dif_count = 1;
					temp.clear();
					temp.push_back(ch1);
				}
				else{
					dif_count++;
					temp.push_back(ch1);
				}
			}
		}

		ch0 = ch1;
	}
	if (str.at(str_size) == '\0') { //если достигнут конец строки
		if (same_count > 1) { //если в накоплении остались одинаковые символы
			new_str += to_string((int)same_count);
			new_str += temp;
			newstr_size += temp.size() + 1;
		}
		else { //если в накоплении остались неодинаковые символы
			new_str += to_string((int)(-dif_count));
			new_str += temp;
			newstr_size += temp.size() + 1;
		}
	}
	cout <<endl<< "Compressed string: " << new_str << endl<<endl;
	cout << "Length of initial string: " << str.size() << endl;
	cout << "Length of initial string: " << newstr_size << endl;
	cout << "Compression ratio: " << (double)(str.size()/(newstr_size*1.0)) << endl;

	return new_str;
}

#endif
