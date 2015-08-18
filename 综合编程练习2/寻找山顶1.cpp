#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int m, n; cin >> m >> n; int res[20][20];
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> res[i][j];
		}
	}
	int a, b, c, d;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (i - 1 >= 0){
				a = res[i - 1][j];
			}
			else{
				a = -1;
			}
			if (i + 1 < m){
				b = res[i + 1][j];
			}
			else{
				b = -1;
			}
			if (j - 1 >= 0){
				c = res[i][j - 1];
			}
			else{
				c = -1;
			}
			if (j + 1 < n){
				d = res[i][j + 1];
			}
			else{
				d = -1;
			}
			if (res[i][j] >= a&&res[i][j] >= b&&res[i][j] >= c&&res[i][j] >= d){
				cout << i << " " << j << endl;
			}
		}
	}
	system("pause");
	return 0;
}