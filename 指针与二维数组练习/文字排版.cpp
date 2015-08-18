#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[1005][85];
int num;

void ini() {
	freopen("test.in", "r", stdin);
}

void PrintSingleWord(int k, int n) {
	// k为第几个单词,n 为该行字符数量
	if (k == num)	return;
	int len = strlen(s[k]);
	if (n + len + 1 <= 80) { //n != 0要考虑空格！但单词数小于40，n ＝ 0，在这里无所谓。
		//如果足够容纳，就输出空格与单词
		if (n != 0) cout << ' ';
		cout << s[k];
		if (n == 0) //这里 n = 0 没有空格！
			PrintSingleWord(k + 1, len);
		else PrintSingleWord(k + 1, n + len + 1);

	}
	else {
		//不够容纳，换行！
		cout << endl;
		cout << s[k];
		PrintSingleWord(k + 1, len);
	}
}


int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> s[i];
	PrintSingleWord(0, 0);
	return 0;
}