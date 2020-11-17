#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

#define BASE64CHAR unsigned char*
#define MAX_INPUT_SIZE 256
BASE64CHAR base64Table = (BASE64CHAR)"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

BASE64CHAR base64_encode(BASE64CHAR str, int len) {
	BASE64CHAR str_en = NULL;
	int str_len;
	int i = 0;
	if (len % 3 == 0)	str_len = (len / 3) * 4;
	else   str_len = (len / 3 + 1) * 4;
	str_en = (BASE64CHAR)malloc(sizeof(unsigned char) * str_len + 1);
	str_en[str_len] = '\0';
	//以3位字节为单位进行编码
	for ( int j = 0; i < str_len - 2; i += 4, j += 3) {   //i控制encode后的字符，j控制原字符串字符
		*(str_en + i) = base64Table[str[j] >> 2];
		*(str_en + i + 1) = base64Table[(str[j] & 0x3) << 4 | str[j + 1] >> 4];
		*(str_en + i + 2) = base64Table[(str[j + 1] & 0x0f) << 2 | str[j + 2] >> 6];
		*(str_en + i + 3) = base64Table[str[j + 2] & 0x3f];
	}
	switch (len % 3) {
	case 1:
		*(str_en + i - 2) = '=';
		*(str_en + i - 1) = '=';
		break;
	case 2:
		*(str_en + i - 1) = '=';
		break;
	}
	return str_en;
}


int main() {
	BASE64CHAR str_en = NULL;
	char input_str[MAX_INPUT_SIZE] ;
	scanf("%s", input_str);
	BASE64CHAR str = (BASE64CHAR)input_str;
	//str = (unsigned char*)"hello,world";
	int len = strlen((const char*)str);
	str_en = base64_encode(str, len);
	std::cout << "After base64encode:" << str_en << std::endl;
	return 0;
}