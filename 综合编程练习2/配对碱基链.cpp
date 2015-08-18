#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
int main2(){
	int n; cin >> n; char str[256] = { 0 };
	for (int i = 0; i < n; i++){
		cin >> str;
		char res[256] = { 0 }; int len = strlen(str);
		for (int j = 0; j < len; j++){
			if (str[j] == 'A'){
				res[j] = 'T';
			}
			if (str[j] == 'T'){
				res[j] = 'A';
			}
			if (str[j] == 'G'){
				res[j] = 'C';
			}
			if (str[j] == 'C'){
				res[j] = 'G';
			}
		}
		cout << res << endl;
	}
	system("pause");
	return 0;
}