//1-пример
#include<iostream>
using namespace std;
void rec(int n, int i, int j, int k)
{
	if (n > 1)
	{
		rec(n - 1, i, k, j);
		rec(1, i, j, k);
		rec(n - 1, k, j, i);
	}
	else
	cout << i << " " << j << endl;
}
void main()
{
	int n;
	cin >> n;
	rec(n,1,2,3);
	system("pause");
}

//2-пример
#include "iostream"
using namespace std;

void swap(int &x, int &y)
{
	int temp = x; x = y; y = temp;
}
void swap(double &x, double &y)
{
	double temp = x; x = y; y = temp;
}
void swap(long &x, long &y)
{
	long temp = x; x = y; y = temp;
}

int main()
{
	int x, y;
	cin >> x>>y;	
	cout << x << y << endl;
	swap(x, y);
	cout << x << y << endl;
	system("pause");
	return 0;
}

//3-пример
#include<iostream>
using namespace std;

int rec(int n,int sum=0)
{
	sum += n % 10;
	n = n/10;
	if (n == 0) return sum;
	else rec(n);
}
void main()
{
	int k, l, sumL, sumK;
	cin >> k >> l;
	sumL = rec(l);
	sumK = rec(k);
	if (sumK > sumL) cout << k; else cout << l;
	system("pause");
}
//4-пример
#include<iostream>
using namespace std;
int nod(int a, int b)
{
	if (a > b) a = a - b; else b = b - a;
	if (b == 0) return a;
	nod(a,b);
}
void main()
{
	int a, b;
	cin >> a >> b;
	cout<<nod(a, b);
	system("pause");
}
//5-пример
#include<iostream>
using namespace std;
void fibonachi(int, int&);
void test(int,int&);
int main()
{
	int n, number, &myRes = number, p, &m = p;
	cout << &m;
	cin >> n;
	fibonachi(n,number);
	cout << number << endl;
	test(number,p);
	if (p == 1) cout << "no"; else cout << "yes";
	system("pause");
	return 0;
}

void fibonachi(int k, int &my_res)
{
	int i;
	float x, y,g,f;
	x = (1 + sqrt(5)) / 2;
	y = (1 - sqrt(5)) / 2;
	g = f = 1;
	for (size_t i = 0; i < k; i++)
	{
		g *= y;
		f *= x;
	}
	my_res = fabs(f - g) / sqrt(5);
}

void test(int l,int &m)
{
	int last = 0, temp = 0;
	last = l % 10;
	l / 10;
	temp = l % 10;
	if (l==0) return;
	if (last<temp)
	{
		m = 1;
		return;
	}
	test(l, m);
}
