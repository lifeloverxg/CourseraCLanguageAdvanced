#include<iostream>
#include<stdlib.h>
using namespace std;
int main1(){
	int n, a[100],flag=0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		if (a[i] == i){
			cout << i;
			flag = 1;
			break;
		}
	}
	if (!flag){
		cout << "N";
	}
	system("pause");
	return 0;
}