#ifndef _RLE_H
#define _RLE_H

#include <string>
#include <iostream>
using namespace std;

string RLE(string str) {
	int str_size=1; //������� �������� ��-�� ������� ������
	int newstr_size = 0; //������� �������� ��-�� ��������������� ���������
	char same_count = 1; //������� ������ ������ ���������� ��������
	int dif_count = 1; //������� ������ ������ ������������ ��������
	string new_str; //�������� ������
	string temp; //���������� ������ ������ ���������� ��� ������������ ��������
	char ch0 = str.at(0), ch1;
	temp.push_back(ch0);
	while (str.at(str_size) != '\0') {
		ch1 = str.at(str_size);
		str_size++; 
		if (ch0 == ch1) {
			if(dif_count>1){ //���� ��� ���������� ������� - ������������
				dif_count--;
				temp.pop_back(); //������� ������� ������ �� ����������
				new_str+=to_string((int)(-dif_count)); //��������� � �������� ������ ����� ������ ������ ������������ �������� 
				new_str+=temp; //��������� � �������� ������ ��� ����������� ������ ������ ������������ �������
				newstr_size += temp.size() + 1;
				dif_count = 1;
				temp.clear();
				temp.push_back(ch1);
				same_count++; 
			}
			else {
				if (same_count + 1 == 128) { //���� ������ ������ �������� �� ������ 127
					new_str+=to_string((int)same_count); //��������� � �������� ������ ����� ������ ������ ���������� �������� 
					new_str += temp; //��������� � �������� ������ ��� ����������� ������ ������ ���������� �������
					newstr_size += temp.size() + 1;
					same_count = 1;
				}
				else {
					same_count++;
				}
			}
		}
		else { //���� ������� ������ �� ����� �����������
			if (same_count > 1) { //���� ��� ���������� ������� - ����������
				new_str += to_string((int)same_count); //��������� � �������� ������ ����� ������ ������ ���������� �������� 
				new_str += temp; //��������� � �������� ������ ��� ����������� ������ ������ ���������� �������
				newstr_size += temp.size() + 1;
				same_count = 1;
				temp.clear();
				temp.push_back(ch1);
			}
			else {
				if (dif_count + 1 == 128) {//���� ������ ������ �������� �� ������ 127
					new_str += to_string((int)(-dif_count)); //��������� � �������� ������ ����� (� �������) ������ ������ ������������ �������� 
					new_str += temp; //��������� � �������� ������ ��� ����������� ������ ������ ������������ �������
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
	if (str.at(str_size) == '\0') { //���� ��������� ����� ������
		if (same_count > 1) { //���� � ���������� �������� ���������� �������
			new_str += to_string((int)same_count);
			new_str += temp;
			newstr_size += temp.size() + 1;
		}
		else { //���� � ���������� �������� ������������ �������
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
