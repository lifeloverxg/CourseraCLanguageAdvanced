#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main3(){
	float sum1=0, sum2=0, sum3=0, a=0, b=0, c=0;
	int id, n; char ch; float f;
	cin >> id; cin >> n;
	for (int i = 0; i < n; i++){
		cin >> ch; cin >> f;
		sum1 += f;
		if (ch == 'A'){
			a += f;
		}
		if (ch == 'B'){
			b += f;
		}
		if (ch == 'C'){
			c += f;
		}
	}
	cin >> id; cin >> n;
	for (int i = 0; i < n; i++){
		cin >> ch; cin >> f;
		sum2 += f;
		if (ch == 'A'){
			a += f;
		}
		if (ch == 'B'){
			b += f;
		}
		if (ch == 'C'){
			c += f;
		}
	}
	cin >> id; cin >> n;
	for (int i = 0; i < n; i++){
		cin >> ch; cin >> f;
		sum3 += f;
		if (ch == 'A'){
			a += f;
		}
		if (ch == 'B'){
			b += f;
		}
		if (ch == 'C'){
			c += f;
		}
	}
	printf("1 %.2f\n", sum1);
	printf("2 %.2f\n", sum2);
	printf("3 %.2f\n", sum3);
	printf("A %.2f\n", a);
	printf("B %.2f\n", b);
	printf("C %.2f\n", c);	
	system("pause");
	return 0;
}