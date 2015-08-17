#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<stack>
using namespace std;
int main(){
	char str[101]; 
	while (cin.getline(str, 101)){
		int i = 0;
		cout << str << endl;
		stack<int> s;
		while (str[i] != 0){
			if (str[i] != '('&&str[i] != ')'){
				str[i] = ' ';
			}
			if (str[i] == '('){
				s.push(i);
			}
			if (str[i] == ')'){
				if (s.empty()){
					str[i] = '?';
				}
				else{
					str[i] = ' '; str[s.top()] = ' ';
					s.pop();
				}
			}
			i++;
		}
		int t;
		while (!s.empty()){
			t = s.top(); str[t] = '$';
			s.pop();
		}
		cout << str << endl;
	}
	system("pause");
	return 0;
}