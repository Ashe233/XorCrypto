#include"Xor.h"

//����ļ���дXor���������ļ��ܺ���������Main.cpp����
string XorEn(string key, string plaintext) {
	string ciphertext = plaintext;
	int lengthofplain = plaintext.length();
	for (int i = 0; i < lengthofplain; i++) {
		ciphertext[i] = ciphertext[i] ^ key[i % key.length()];
	}
	return ciphertext;
}