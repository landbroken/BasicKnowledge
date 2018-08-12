#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cctype>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

char encrypt[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789" };
char decryp[] = { "bcdefghijklmnopqrstuvwxyzaBCDEFGHIJKLMNOPQRSTUVWXYZA1234567890" };
void Encrypt(char aucPassword[], char aucResult[]) {
	int i = 0;
	while (aucPassword[i] != '\0') {
		if (aucPassword[i] >= '0'&&aucPassword[i] <= '9')
			aucResult[i] = decryp[aucPassword[i] - '0' + 52];
		else if (aucPassword[i] >= 'A'&&aucPassword[i] <= 'Z')
			aucResult[i] = decryp[aucPassword[i] - 'A'];
		else if (aucPassword[i] >= 'a'&&aucPassword[i] <= 'z')
			aucResult[i] = decryp[aucPassword[i] - 'a' + 26];
		cout << aucResult[i++];
	}
	cout << endl;
	return;
}

int unEncrypt(char result[], char password[]) {
	int i = 0;
	while (password[i] != '\0') {
		if (password[i] > '0'&&password[i] <= '9')
			result[i] = encrypt[password[i] - '1' + 52];
		else if (password[i] == '0')
			result[i] = '9';
		else if (password[i] > 'A'&&password[i] <= 'Z')
			result[i] = encrypt[password[i] - 'B' + 26];
		else if (password[i] == 'A')
			result[i] = 'z';
		else if (password[i] > 'a'&&password[i] <= 'z')
			result[i] = encrypt[password[i] - 'b'];
		else if (password[i] == 'a')
			result[i] = 'Z';
		cout << result[i++];
	}
	cout << endl;
	return 0;
}

int test_29() {
	char aucPassword[100];
	while (cin >> aucPassword) {
		char aucResult[100], password[100], result[100];
		cin >> password;
		Encrypt(aucPassword, aucResult);
		int ans = unEncrypt(result, password);
	}
	return 0;
}