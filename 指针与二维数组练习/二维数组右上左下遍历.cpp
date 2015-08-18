#include<iostream>
#include<stdlib.h>
using namespace std;
void show(int a[][100], int i, int j,int r){
	cout << a[i][j] << endl;
	int nexti = i + 1, nextj = j - 1;
	if (nexti == r || nextj < 0){
		return;
	}
	else{
		show(a, nexti, nextj, r);
	}
}
int main2(){
	int r, c, a[100][100]; cin >> r >> c;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < c; i++){
		show(a,0, i,r);
	}
	for (int i = 1; i < r; i++){
		show(a, i, c - 1, r);
	}
	system("pause");
	return 0;
}