#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string plaintext;
int key;

void Entries() {

LP:
	cout << "  Enter plaintext : ";
	cin >> plaintext;
	for (int i = 0; i < plaintext.length(); i++) {

		if (plaintext[i] < 65 || plaintext[i] > 90) {
			cout << "  Your plaintext is not valid enter anther plaintext" << endl;
			goto LP;
		}
	}

	cout << "  Enter key (positive) : ";
	cin >> key;
	if (key < 0) {
		cout << "  Your key is negative enter anther key" << endl;
		cout << "  Enter key (positive) : ";
		cin >> key;
	}
}

void Encrypt()
{
	Entries();

	int k = key % 26;
	char temp;
	string ciphertext;

	for (int i = 0; i < plaintext.length(); i++) {

		temp = plaintext[i] + k;

		if (temp > 90) {
			temp -= 26;
		}
		ciphertext += temp;
	}
	cout << "  -------------------  " << endl;
	cout << "  Your Encrypt text : " + ciphertext << endl;
}

void Decrypt()
{
	Entries();

	int k = key % 26;
	char temp;
	string text;

	for (int i = 0; i < plaintext.length(); i++) {

		temp = plaintext[i] - k;

		if (temp < 65) {
			temp += 26;
		}
		text += temp;
	}
	cout << "  -------------------  " << endl;
	cout << "  Your Decrypt text : " + text << endl;
}

void Crack()
{
LP:
	cout << "  Enter ciphertext : ";
	cin >> plaintext;
	for (int i = 0; i < plaintext.length(); i++) {

		if (plaintext[i] < 65 || plaintext[i] > 90) {
			cout << "  Your plaintext is not valid enter anther plaintext" << endl;
			goto LP;
		}
	}

	char temp;
	string text;
	
	cout << "  Your Crack text : " << endl;
	for (int x = 25 ; x >= 0 ; x--) {
		
		text = "";
		for (int i = 0; i < plaintext.length(); i++) {

			temp = plaintext[i] - x;

			if (temp < 65) {
				temp += 26;
			}
			text += temp;
		}

		cout << "  " << x << ". " << text << endl;
	}
}

int main()
{
	string plaintext;
	int key;
	int option;
	bool next = true;

	cout << endl;
	cout << "  You are welcome in simple Substitution algorithm " << endl;

	do
	{
		plaintext = "";
		
		cout << "  -------------------  " << endl;
		cout << "  Choose from menu " << endl;
		cout << "  1. Encrpyt " << endl;
		cout << "  2. Decrpyt " << endl;
		cout << "  3. Crack " << endl;
		cout << "  4. End " << endl;
		cout << "  -------------------  " << endl;
		cout << "  Your option : ";
		cin >> option;

		switch (option) {
		case 1: Encrypt(); break;
		case 2: Decrypt(); break;
		case 3: Crack(); break;
		case 4: next = false; break;
		default: cout << "  Your choice is not valid" << endl; break;
		}

	} while (next);  

	system("PAUSE");
    return 0;
}

