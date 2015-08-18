#include<iostream>
#include<stdlib.h>
using namespace std;
int main4(){
	int m, n; cin >> m >> n; int res[20][20];
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> res[i][j];
		}
	}
	int a, b, c, d;
	for (int j = 0; j < n; j++){
		if (j == 0){
			b = res[1][0]; d = res[0][1];
			if (res[0][0] >= b&&res[0][0] >= d){
				cout << "0 0" << endl;
			}
		}
		else if (j == n - 1){
			b = res[1][n-1]; c = res[0][n-2];
			if (res[0][n-1] >= b&&res[0][n-1] >= c){
				cout << "0 "<<n-1 << endl;
			}
		}
		else{
			b = res[1][j]; c = res[0][j - 1]; d = res[0][j + 1];
			if (res[0][j] >= b&&res[0][j] >= c&&res[0][j]>=d){
				cout << "0 " << j<< endl;
			}
		}

	}
	for (int i = 1; i < m-1; i++){
		for (int j = 0; j < n; j++){
			if (i - 1 >=0 ){
				a = res[i - 1][j];
			}
			if (i + 1 < m){
				b = res[i + 1][j];
			}
			if (j - 1 >= 0){
				c = res[i][j - 1];
			}
			if (j + 1 < n){
				d = res[i][j + 1];
			}
			if (j == 0){
				if (res[i][j] >= a&&res[i][j] >= b&&res[i][j] >= c){
					cout << i << " " << j << endl;
				}
			}
			else if (j == n - 1){
				if (res[i][j] >= a&&res[i][j] >= b&&res[i][j] >= d){
					cout << i << " " << j << endl;
				}
			}
			else{
				if (res[i][j] >= a&&res[i][j] >= b&&res[i][j] >= c&&res[i][j] >= d){
					cout << i << " " << j << endl;
				}
			}
		}
	}
	for (int j = 0; j < n; j++){
		if (j == 0){
			a = res[m-2][0]; d = res[m-1][1];
			if (res[m-1][j] >= a&&res[m-1][j] >= d){
				cout << m-1<<" 0" << endl;
			}
		}
		else if (j == n - 1){
			a = res[m-2][j]; c = res[m-1][j - 1];
			if (res[m-1][j] >= a&&res[m-1][j] >= c){
				cout <<m-1<<" "<<j<< endl;
			}
		}
		else{
			a = res[m-2][j]; c = res[m-1][j - 1]; d = res[m-1][j + 1];
			if (res[m-1][j] >= a&&res[m-1][j] >= c&&res[m-1][j] >= d){
				cout << m - 1 << " " << j << endl;
			}
		}
	}
	system("pause");
	return 0;
}