#include<iostream>
#include<stdlib.h>
using namespace std;
char ch[100][100];
void infect(int n){
	int r[10000], c[10000],index=0;
	//这里的r,c应该开大点,不能只开到100,要不然会出现Runtime Error
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (ch[i][j] == '@'){
				r[index] = i; c[index] = j; index++;
			}
		}
	}
	int i, j;
	for (int k = 0; k < index; k++){
		i = r[k]; j = c[k];
		if (i + 1 < n&&ch[i + 1][j] != '#'){
			ch[i + 1][j] = '@';
		}
		if (i - 1 >= 0 && ch[i - 1][j] != '#'){
			ch[i - 1][j] = '@';
		}
		if (j + 1 < n&&ch[i][j + 1] != '#'){
			ch[i][j + 1] = '@';
		}
		if (j - 1 >= 0 && ch[i][j - 1] != '#'){
			ch[i][j - 1] = '@';
		}
	}
}
int main6(){
	int n,m; cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> ch[i][j];
		}
	}
	cin >> m;
	for (int k = 0; k < m-1; k++){
		infect(n);
	}
	int count = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (ch[i][j] == '@'){
				count++;
			}
		}
	}
	cout << count;
	system("pause");
	return 0;
}