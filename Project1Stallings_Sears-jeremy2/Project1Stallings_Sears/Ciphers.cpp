#include "stdafx.h"
#include "Frequency.h"
#include "Ciphers.h"
#include <iostream> 
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

void shiftCipher(MonoDigrams mostFrequent, string cipher) {

	char english = 'A';
	string letter = mostFrequent.getLetters(); //will identify what the letter is that is most frequent
	char temp1 = letter[0];
	int key = temp1 - 69;//letter is converted to its respective ASCII value and is subtracted by the ASCII for E
	if (key < 0) {//if the key happens to be negative, we add 25 to it and shift that many times
		key += 25;
	}
	for (unsigned int i = 0; i < cipher.length(); i++) {//go through the entire cipher text string
		char temp2 = cipher[i];//grab each individual character
		temp2 -= key; //subtract the character by the key value
		if (temp2 < 65) { //if the character shift is less than the ASCII value for A, then add 26 to bring us back into the alphabet
			temp2 += 26;
		}
		cout << temp2; //output the corresponding text
	}

	cout << endl << "Does this look like English to you, kind sir or lady? y/n";
	
	while (true) {
		cin >> english;
		if (english == 'y') {
			cout << "This is a shift cipher, decoded with a key of " << key << endl;
			break;
		}
		else if (english == 'n') {
			break;
		}
		else {
			cout << "Not a valid input" << endl;
		}
	}

}

void substitutionCipher() {
	cout << "This is a substitution cipher and must be solved manually" << endl;
}

void vignereCipher(vector<MonoDigrams> trigrams, string s) {
	string hello;
	cout << "stopshere" << endl;
	cin >> hello;
}