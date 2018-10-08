//判断一个字符串是否问回文字符串

#include <stdio.h>
#include <string.h>

//0 - palindrome
//1 - not palindrome
int is_palindrome(const char* str)
{
	if (str == NULL) {
		return 1;
	}
	int l = strlen(str);
	if (l == 0 || l == 1) {
		return 0;
	}

	for(int i =0; i <= l/2; i++) {
		if(str[i] != str[l-i-1])
			return 1;
	}

	return 0;
}

void main()
{
	while(1) {
		char str[1024] = "";
		printf("enter your string, max length 1024.\n");
		scanf("%s", str);
		if (is_palindrome(str) == 0)
			printf("%s is palindrome\n", str);
		else
			printf("%s is not palindrome\n", str);
	}
}
