
#include "stdafx.h"

//#include <stdio.h>
#include <string.h>
//#include <iostream>
#include <Windows.h>

void encrypt_str(const char *apStr, const char *apKey, char *apOutStr)
{
	unsigned strLength = strlen(apStr);
	unsigned keyLength = strlen(apKey);
	unsigned key_i = 0;

	for (unsigned i = 0; i < strLength; ++i)
	{
		apOutStr[i] = apStr[i] ^ apKey[key_i++];

		if (key_i >= keyLength)
			key_i = 0;
	}
}

void decrypt_str(const char *apStr, const char *apKey, char *apOutStr)
{
	unsigned strLength = strlen(apStr);
	unsigned keyLength = strlen(apKey);
	unsigned key_i = 0;

	for (unsigned i = 0; i < strLength; ++i)
	{
		apOutStr[i] = apStr[i] ^ apKey[key_i++];

		if (key_i >= keyLength)
			key_i = 0;
	}
}

int main(int argc, char* argv[])
{

	char originStr[100] = "stringt";
	char key[100] = "key";
	printf("Enter string:");
	scanf("%s", originStr);

	printf("Enter key:");
	scanf("%s", key);
	char encrypt_buffer[100] = { 0 };
	char decrypt_buffer[100] = { 0 };

	encrypt_str(originStr, key, encrypt_buffer);
	decrypt_str(encrypt_buffer, key, decrypt_buffer);

	printf("original: %s\n", originStr);
	printf("key     : %s\n", key);

	printf("encrypted - %s\n", encrypt_buffer);
	printf("decrypted - %s\n", decrypt_buffer);
	system("pause");
	return 0;
}