//1
#include<iostream>
#include<string>
using namespace std;
string found(int x){
	int y;
	string inserted;
	y = x % 16;
	if (y > 9)
	{
		switch (y)
		{
			case 10: inserted = 'A'; break;
			case 11: inserted = 'B'; break;
			case 12: inserted = 'C'; break;
			case 13: inserted = 'D'; break;
			case 14: inserted = 'E'; break;
			case 15: inserted = 'F'; break;
		}
		return to_string(x / 16) + inserted;
	}
	else if (y == 0) return to_string(x / 16) + to_string(0);
	else return to_string(x / 16) + to_string(y);
}
void main()
{
	int x;
	cin >> x;
	cout << found(x);
	system("pause");
}

//2
#include<iostream>
using namespace std;
int nod(int x, int y)
{
	while (y != 0)
	{
		if (x > y) x = x - y;
		else y = y - x;
	}
	if (x == 1) return 1;
	else return 0;
}
int found(int p, int k)
{
	int i = 1;
	while (true)
	{
		if (nod(pow(p, i), k)) return i;
		i++;
	}
}
void main()
{
	cout<<found(9,21);
	system("pause");
}

//3
/*
#include <boost/lexical_cast.hpp>
int count = boost::lexical_cast<std::string>(123456).length();
*/
#include<iostream>
#include<typeinfo>
using namespace std;

int numberCount(int x)
{
	int count = 0;
	while (!x==0)
	{
		x /=  10;
		count++;
	}
	return count;
}

double is_natural(float a)
{
	if (a - int(a) == 0) return true;
	else return false;
}

int push(int l, int p)
{
	int s = 10; int copyP = p;
	while (p > 10)
	{
		s *= 10;
		p /= 10;
	}
	return l*s + copyP;
}

float push(float l, float p)
{
	if(is_natural(l))
	{
		float copyP = p; int intP,i;
		intP = int(p);
		i = numberCount(intP);
		return	l*pow(10,i)+copyP;
	}
	else
	{
		int k=0;
		while(!is_natural(l))
		{
			k++;
			l *= 10;
		}
		k += numberCount(p);
		return (l*pow(10,numberCount(p))+p)/pow(10,k);
	}
}

void main()
{
	float l, p;
	cin >> l >> p;

	l = abs(l); p = abs(p);

	if (is_natural(p) && is_natural(l))
	{
		int x = int(l); int y = int(p);
		cout << push(x, y);
	}
	else
	{
		cout<<push(l,p);
	}
	system("pause");
}

//4
#include<iostream>
using namespace std;

int findC(int a, int b){ return sqrt(a*a+b*b); }
double findC(double a, int b){ return sqrt(a*a + b*b); }
double findC(int a, double b){ return sqrt(a*a + b*b); }
double findC(double a, double b){ return sqrt(a*a + b*b); }

int is_natural(double x)
{
	if (x - int(x) == 0) return 1;
	else return 0;
}

void main()
{
	double a, b;
	cin >> a >> b;
	
	if (is_natural(a) && is_natural(b)) cout << findC(int(a),int(b));
	if (!is_natural(a) && !is_natural(b)) cout << findC(a, b);
	if (is_natural(a) && !is_natural(b)) cout << findC(int(a), b);
	if (!is_natural(a) && is_natural(b)) cout << findC(a, int(b));
	system("pause");
}

//5
#include<iostream>
using namespace std;

void main()
{
	double x1, x2, y1, y2;
	cin >> x1 >> x2 >> y1 >> y2;
	cout << sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	system("pause");
}

//6
#include<iostream>
using namespace std;

int countDigit(int x)
{
	int i=0;
	while (x!=0)
	{
		i++;
		x /= 10;
	}
	return i;
}

void main()
{
	int n, s,temp,i=0,result=0;
	cin >> n >> s;
	if (n > 9)
	{
		while (n != 0 )
		{
			
			temp = n % 10;
			int copyN = n;
			n /= 10;

			if (n % 10 + temp != s)
			{
				result = result * 10 + temp;
			}
			else n /= 10;
			if (countDigit(n) == 1 && s == temp) result = result * 10 + n;
		}

		n = 0;

		while (result !=0 )
		{
			n = n * 10 + result % 10;
			result /= 10;
		}
		cout << n<<endl;
	}
	else cout << "Error arguments"<< endl;
	system("pause");
}

//7
#include<iostream>
using namespace std;

int is_prime(int n)
{
	if (n == 1) return 0;
	for (size_t i = 2; i < n; i++)
	{
		if (n % i == 0) return 0;
	}
	return 1;
}

void main()
{
	int n;
	cin >> n;
	int flag = 1;
	for (size_t i = 2; i < n; i++)
	{
		if (is_prime(i))
		{
			if (is_prime(n - i))
			{
				cout << "YES, number have prime" << endl;
				flag = 0;
				break;
			}
		}
	}
	if (flag) cout << "No, number have not prime" << endl;
	system("pause");
}

//8
#include<iostream>
using namespace std;

int chek(int n)
{
	if (n % 11 == 0 && n!=0) return 1;
	else return 0;
}

int chek(double n)
{
	return 0;
}

void main(){
	double n;
	cin >> n;

	if (n - int(n) == 0) cout<<chek(int(n));
	else cout<<chek(n);
	system("pause");
}

//9
//не может заменит цифры из дробных чисел
#include<iostream>
using namespace std;

int sign(int x)
{
	if (x > 0) return 1;
	else return -1;
}

void change(int *a, int *b, int k, int l)
{
	int changeAtoB, changeBtoA, temp;

	int powK = pow(10, k), powL = pow(10, l);

	temp = *a / powK;
	changeAtoB = temp % 10;
	changeAtoB = abs(changeAtoB);

	temp = *b / powL;
	changeBtoA = temp % 10;
	changeBtoA = abs(changeBtoA);

	*a = *a - (changeAtoB*powK)*sign(*a) + (changeBtoA*powK)*sign(*a);
	*b = *b - (changeBtoA*powL)*sign(*b) + (changeAtoB*powL)*sign(*b);
}

void main()
{
	int a, b;
	int k, l;
	cin >> a >> b >> k >> l;
	change(&a, &b, k, l);

	cout << a << " " << b << endl;

	system("pause");
}

//10
#include<iostream>
using namespace std;

int increase(int n){
	while (true)
	{

	}
	return 0;
}
void main()
{
	int n;
	cin >> n;
	increase(n);
	system("pause");
}