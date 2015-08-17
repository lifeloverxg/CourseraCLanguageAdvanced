#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<stack>
using namespace std;
int main4(){
	char str[101];
	cin >> str;
	stack<int> s; s.push(0);
	int i = 1; char male = str[0];
	while (str[i] != 0 && !s.empty()){
		if (str[i] == male){
			s.push(i);
		}
		else{
			int man = s.top();
			s.pop();
			cout << man << " " << i << endl;
		}
		i++;
	}

	system("pause");
	return 0;
}