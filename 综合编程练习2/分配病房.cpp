#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main1(){
	int m; double a; cin >> m; cin >> a; char res[100][4] = { 0 }; 
	double resd[100]; int count = 0;
	for (int i = 0; i < m; i++){
		char str[4]; double d;
		cin >> str; cin >> d;
		if (d >= a){
			for (int j = 0; j < 3; j++){
				res[count][j] = str[j];				
			}
			resd[count++] = d;
		}
	}
	int index[100] = { 0 };
	for (int i = 0; i < count; i++){
		index[i] = i;
	}
	for (int i = 1; i < count; i++){
		for (int j = count - 1; j >= i; j--){
			if (resd[j - 1] < resd[j]){
				int temp = index[j];
				index[j] = index[j - 1];
				index[j - 1] = temp;
				double tempd = resd[j];
				resd[j] = resd[j - 1];
				resd[j - 1] = tempd;
			}
		}
	}
	for (int i = 0; i < count; i++){
		printf("%s %.1f\n", res[index[i]], resd[i]);
	}
	if (count == 0){
		cout << "None." << endl;
	}
	system("pause");
	return 0;
}