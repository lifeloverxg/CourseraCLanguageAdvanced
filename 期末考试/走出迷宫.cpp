//#include<iostream>
//#include<stdlib.h>
//#include<stack>
//using namespace std;
//int a[120][120] = { { 0 } }; int n, m; 
//typedef struct Point{
//	int x; int y;
//} point;
//typedef struct Path{
//	point p;
//	int direction;
//} path;
//point NextPos(point p, int di)
//{ /* ���ݵ�ǰλ�ü��ƶ����򣬷�����һλ�� */
//	point direc[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }; /* {������,������} */
//	/* �ƶ�����,����Ϊ�������� */
//	p.x += direc[di].x;
//	p.y += direc[di].y;
//	return p;
//}
//int main(){
//	cin >> n >> m;
//	char square[120][120] = { 0 }; point start, end;
//	for (int i = 0; i < n; i++){
//		cin >> square[i + 1] + 1;
//	}
//	for (int i = 0; i < n + 2; i++){
//		square[i][0] = square[i][m + 1] = '#';
//	}
//	for (int i = 0; i < m + 2; i++){
//		square[0][i] = square[n + 1][i] = '#';
//	}
//	for (int i = 1; i < n + 1; i++){
//		for (int j = 1; j < m + 1; j++){
//			if (square[i][j] == 'S'){
//				start.x = i; start.y = j;
//			}
//			if (square[i][j] == 'T'){
//				end.x = i; end.y = j;
//			}
//		}
//	}
//	stack<path> s; point curpos = start; path temp; int countstep = 0;
//	do{
//
//		if ((square[curpos.x][curpos.y] == '.' || 
//			square[curpos.x][curpos.y] == 'S' || square[curpos.x][curpos.y] == 'T')
//			&&(a[curpos.x][curpos.y]==0)){
//			temp.p.x = curpos.x; temp.p.y = curpos.y; temp.direction = 0;
//			s.push(temp); countstep++; a[curpos.x][curpos.y] = 1;
//			if (curpos.x == end.x&&curpos.y == end.y) {
//				cout << --countstep << endl;
//				return 0;
//			}			
//			curpos = NextPos(curpos, temp.direction);
//		}
//		else{
//			/* ��ǰλ�ò���ͨ�� */
//			if (!s.empty()){
//				temp = s.top(); s.pop(); countstep--; a[temp.p.x][temp.p.y] = 0;
//				while ((temp.direction == 3) && (!s.empty())) {
//					/* ǰһλ�ô������һ������(��) */
//					a[temp.p.x][temp.p.y] = -1;
//					temp = s.top(); s.pop(); countstep--; a[temp.p.x][temp.p.y] = 0;
//				}
//				/* û�����һ������(��) */
//				if (temp.direction<3) {
//					/* ����һ������̽�� */
//					temp.direction++;
//					s.push(temp); countstep++;
//					curpos = NextPos(temp.p, temp.direction); /* �趨��ǰλ���Ǹ��·����ϵ����ڿ� */
//				}
//			}
//		}
//	} while (!s.empty());
//	return 0;
//}