//#include<iostream>  
//using namespace std;
//struct PosType /* �Թ�����λ������ */
//{
//	int x; /* ��ֵ */
//	int y; /* ��ֵ */
//};
//#define MAXLENGTH 25 /* ���Թ����������Ϊ25 */  
//typedef int MazeType[MAXLENGTH][MAXLENGTH]; /* �Թ�����[��][��] */
///* ȫ�ֱ��� */
//MazeType m; /* �Թ����� */
//int curstep = 1; /* ��ǰ�㼣,��ֵΪ1 */
//int a[MAXLENGTH];
//int b[MAXLENGTH];
//int c[MAXLENGTH];
//struct SElemType/* ջ��Ԫ������ */
//{
//	int ord; /* ͨ������·���ϵģ���ţ� */
//	PosType seat; /* ͨ�������Թ��еģ�����λ�ã� */
//	int di; /* �Ӵ�ͨ����������һͨ����ģ�����(0��3��ʾ������) */
//};
//#define STACK_INIT_SIZE 10 /* �洢�ռ��ʼ������ */  
//#define STACKINCREMENT 2 /* �洢�ռ�������� */  
//struct SqStack   //SqStack  
//{
//	SElemType *base; /* ��ջ����֮ǰ������֮��base��ֵΪNULL */
//	SElemType *top; /* ջ��ָ�� */
//	int stacksize; /* ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ */
//}; /* ˳��ջ */
//bool Pass(PosType b)
//{ /* ���Թ�m��b������Ϊ1(��ͨ��·��)��return true, ����return false�� */
//	if (m[b.x][b.y] == 1)
//		return true;
//	else
//		return false;
//}
//void FootPrint(PosType a)
//{ /* ʹ�Թ�m��a�����ű�Ϊ�㼣(curstep) */
//	m[a.x][a.y] = curstep;
//}
//PosType NextPos(PosType c, int di)
//{ /* ���ݵ�ǰλ�ü��ƶ����򣬷�����һλ�� */
//	PosType direc[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }; /* {������,������} */
//	/* �ƶ�����,����Ϊ�������� */
//	c.x += direc[di].x;
//	c.y += direc[di].y;
//	return c;
//}
//
//void MarkPrint(PosType b)
//{ /* ʹ�Թ�m��b�����ű�Ϊ-1(����ͨ����·��) */
//	m[b.x][b.y] = -1;
//}
//bool InitStack(SqStack *S)
//{ /* ����һ����ջS */
//	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
//	if (!(*S).base)
//		exit(1); /* �洢����ʧ�� */
//	(*S).top = (*S).base;
//	(*S).stacksize = STACK_INIT_SIZE;
//	return true;
//}
//bool Push(SqStack *S, SElemType e)
//{ /* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
//	if ((*S).top - (*S).base >= (*S).stacksize) /* ջ����׷�Ӵ洢�ռ� */
//	{
//		(*S).base = (SElemType *)realloc((*S).base, ((*S).stacksize + STACKINCREMENT)*sizeof(SElemType));
//		if (!(*S).base)
//			exit(1); /* �洢����ʧ�� */
//		(*S).top = (*S).base + (*S).stacksize;
//		(*S).stacksize += STACKINCREMENT;
//	}
//	*((*S).top)++ = e;
//	return true;
//}
//bool StackEmpty(SqStack S)
//{ /* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
//	if (S.top == S.base)
//		return true;
//	else
//		return false;
//}
//bool Pop(SqStack *S, SElemType *e)
//{ /* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
//	if ((*S).top == (*S).base)
//		return false;
//	*e = *--(*S).top;
//	return true;
//}
//bool MazePath(PosType start, PosType end) /* �㷨3.3 */
//{ /* ���Թ�maze�д��ڴ����start������end��ͨ���������һ�� */
//	/* �����ջ��(��ջ�׵�ջ��)��������TRUE�����򷵻�FALSE */
//	SqStack S;
//	PosType curpos;
//	SElemType e;
//	InitStack(&S);
//	curpos = start;
//	do
//	{
//		if (Pass(curpos))
//		{ /* ��ǰλ�ÿ���ͨ��������δ���ߵ�����ͨ���� */
//			FootPrint(curpos); /* �����㼣 */
//			e.ord = curstep;
//			a[curstep] = e.seat.x = curpos.x;
//			b[curstep] = e.seat.y = curpos.y;
//			c[curstep] = e.di = 0;
//			Push(&S, e); /* ��ջ��ǰλ�ü�״̬ */
//			curstep++; /* �㼣��1 */
//			if (curpos.x == end.x&&curpos.y == end.y) /* �����յ�(����) */
//				return true;
//			curpos = NextPos(curpos, e.di);
//		}
//		else
//		{ /* ��ǰλ�ò���ͨ�� */
//			if (!StackEmpty(S))
//			{
//				Pop(&S, &e); /* ��ջ��ǰһλ�� */
//				curstep--;
//				while ((e.di == 3) && (!StackEmpty(S))) /* ǰһλ�ô������һ������(��) */
//				{
//					MarkPrint(e.seat); /* ���²���ͨ���ı��(-1) */
//					Pop(&S, &e); /* �˻�һ�� */
//					curstep--;
//				}
//				if (e.di<3) /* û�����һ������(��) */
//				{
//					e.di++; /* ����һ������̽�� */
//					Push(&S, e);
//					a[curstep] = e.seat.x = curpos.x;
//					b[curstep] = e.seat.y = curpos.y;
//					c[curstep] = e.di;
//					curstep++;
//					curpos = NextPos(e.seat, e.di); /* �趨��ǰλ���Ǹ��·����ϵ����ڿ� */
//				}
//			}
//		}
//	} while (!StackEmpty(S));
//	return false;
//}
//
//void Print(int x, int y)
//{ /* ����Թ��Ľ� */
//	int i, j;
//	for (i = 0; i<x; i++)
//	{
//		for (j = 0; j<y; j++)
//			cout << '/t' << m[i][j];
//		cout << endl;
//	}
//}
////stack.h  
//
//void main()
//{
//	PosType begin, end;
//	int i, j, x, y, x1, y1;
//	cout << "�������Թ�������,����(������ǽ)��";
//	cin >> x >> y;
//	for (i = 0; i<x; i++) /* �����ܱ�ֵΪ0(ͬǽ) */
//	{
//		m[0][i] = 1; /* ���ܱ� */
//		m[x - 1][i] = 1;
//	}
//	for (j = 1; j<y - 1; j++)
//	{
//		m[j][0] = 1; /* ���ܱ� */
//		m[j][y - 1] = 1;
//	}
//	for (i = 1; i<x - 1; i++)
//	for (j = 1; j<y - 1; j++)
//		m[i][j] = 1; /* ����ͨ����ֵΪ1 */
//	cout << "�������Թ���ǽ��Ԫ����";
//	cin >> j;
//	cout << "�����������Թ���ǽÿ����Ԫ������,������" << endl;
//	for (i = 1; i <= j; i++)
//	{
//		cin >> x1 >> y1;
//		m[x1][y1] = 0; /* ����ǽ��ֵΪ0 */
//	}
//	cout << "�Թ��ṹ����:" << endl;
//	Print(x, y);
//	cout << "��������������,������";
//	cin >> begin.x >> begin.y;
//	cout << "�������յ������,������";
//	cin >> end.x >> end.y;
//	if (MazePath(begin, end)) /* ���һ��ͨ· */
//	{
//		cout << "���Թ�����ڵ����ڵ�һ��·������:" << endl;
//		Print(x, y); /* �����ͨ· */
//		for (i = 1; i<curstep; i++)
//			cout << a[i] << " " << b[i] << " " << c[i] << endl;
//	}
//	else
//		cout << "���Թ�û�д���ڵ����ڵ�·��" << endl;
//}