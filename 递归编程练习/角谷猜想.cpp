#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
void count(int n){
	if (n == 1) {
		cout << "End" << endl;
		return;
	}
	if (n % 2 == 0){
		cout << n << "/" << 2 << "=" << n / 2 << endl;
		count(n / 2);
	}
	else{
		cout << n << "*3+1=" << (n * 3 + 1) << endl;
		count(3 * n + 1);
	}
}
int main3(){
	int n; cin >> n;
	count(n);
	system("pause");
	return 0;
}