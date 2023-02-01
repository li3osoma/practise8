#ifndef _TEST_H
#define _TEST_H

#include "RLE.h"
#include "LZ77.h"
#include "LZ78.h"
#include <iostream>
using namespace std;

void testRLE() {
	string str;
	cout << "Initial string: ";
	cin >> str;
	RLE(str+'\0');
}

void testLZ77() {
	string str = "0100001010100110100";
	LZ77(str);
}

void testLZ78() {
	string str = "aokaonaokaonaaok";
	LZ78(str);
}

#endif