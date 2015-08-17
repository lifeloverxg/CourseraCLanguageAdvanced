#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
void reverse(char *str){
	int i = 0;
	while (str[i] != ' ' && str[i] != 0){
		i++;
	}
	int low = 0, high = i - 1,temp;
	while (low < high){
		temp = str[low];
		str[low] = str[high];
		str[high] = temp;
		low++; high--;
	}
	if (str[i] == 0){
		return;
	}
	else{
		reverse(str + i+1);
	}
}
int main1(){
	char str[501] = { 0 };
	cin.getline(str, 501);
	reverse(str);
	cout << str;
	system("pause");
	return 0;
}

#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
void fun(char t[], int len)
{
	for (int k = len - 1; k >= 0; k--)
		cout << t[k];
}

int main2()
{
	char s[501], temp[500];
	int j = 0, l;
	gets(s);
	l = strlen(s);
	for (int i = 0; i<l; i++)
	{
		if (s[i] != ' ') { 
			temp[j++] = s[i]; if (i == l - 1) fun(temp, j); 
		}
		else {
			fun(temp, j);
			cout << " ";	j = 0;
		}
	}
	system("pause");
	return 0;
}