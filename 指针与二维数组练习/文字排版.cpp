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
	// kΪ�ڼ�������,n Ϊ�����ַ�����
	if (k == num)	return;
	int len = strlen(s[k]);
	if (n + len + 1 <= 80) { //n != 0Ҫ���ǿո񣡵�������С��40��n �� 0������������ν��
		//����㹻���ɣ�������ո��뵥��
		if (n != 0) cout << ' ';
		cout << s[k];
		if (n == 0) //���� n = 0 û�пո�
			PrintSingleWord(k + 1, len);
		else PrintSingleWord(k + 1, n + len + 1);

	}
	else {
		//�������ɣ����У�
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