/** Примеры структыры выбора **/


//if
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n > 2 && n < 6) cout << "Spring"; else
		if (n>5 && n < 9) cout << "Summer"; else
			if (n>8 && n < 12) cout << "Autumn"; else cout << "Winter";
	//system("pause");
}


//switch
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	switch (n)
	{
	case 5 + 1: cout << "YES"; break;
	case 10 + 1: cout << "YES"; break;
	case 5 + 10: cout << "YES"; break;
	default: cout << "NO";
	}
	//system("pause");
}


//max is a,b,s
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	int max = a;
	if (b > c) { if (max < b)  max = b; }
	else if (max < c)  max = c;
	cout << max;
	//system("pause");
}


//culculator
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	float a, b;  char c;
	cin >> a >> c >> b;
	switch (c)
	{
	case '+': cout << a << "+" << b << "=" << a + b << endl; break;
	case '-': cout << a << "-" << b << "=" << a - b << endl; break;
	case '*': cout << a << "*" << b << "=" << a * b << endl; break;
	case '/': cout << a << "/" << b << "=" << a / b << endl; break;
	default: cout << "undefined char";
	}
	
	//system("pause");
}


//spot max
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	float a, b,c;
	cin >> a >> b >> c;
	if ((a + c) > (a + b) && (a + c) > (b + c)) cout << "a + c"; else
		if ((a + b) > (b + c)) cout << "a + b"; else cout << "b + c";
	
	//system("pause");
}


/** Примеры структуры повторения **/


//multiplication table
#include <iostream.h>
#include <conio.h>
main()
{
 int i, j;
	for (i=2; i<=9; i++)
	{
		for (j=1; j<=10; j++)
		cout<<(i*j)<<" ";
		cout<<endl;
	}
	//system("pause");
}


//factorial
#include<iostream>
using namespace std;

int main()
{
	int n = 10, sum = 1;

	for (size_t i = 1; i <= n; i++)
	{
		sum *= i;
	}

	cout << sum;
	//system("pause");
}


//spot primes
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int a, b;
	bool flag;
	cin >> a >> b;
	for (int i = a; i < b; i++)
	{
		flag = true;
		for (int j = 2; j < i/2; j++)
		{
			if (i%j == 0)  flag = false;
		}

		if (flag) cout << i << endl;
	}

	//system("pause");
}

//find number is most contain units
#include<iostream>
using namespace std;
float one(int number)
{
	int count = 0;
	while (number!=0)
	{
		int temp = number % 10;
		number /= 10;
		if (temp==1) count++;
	}
	return count;
}
float main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int countA = one(a);
	int countB = one(b);
	int countC = one(c);
	if (countA > countB && countA > countC) cout << a; else
		if (countB > countC) cout << b; else cout << c;
	//system("pause");
}

//is polindrome
#include<iostream>
using namespace std;
float main()
{
	int a, b, copyA;
	cin >> a;
	b = 0;
	copyA = a;
	while (copyA > 0)
	{
		b = b * 10 + copyA % 10;
		copyA/=10;
	}
	if (a == b) cout << "YES"; else cout << "NO";
	//system("pause");
}

//count units and zeros number in binary number
#include<iostream>
using namespace std;
float main()
{
	int N, count1=0, count0=0;
	cin >> N;
	while (N != 0)
	{
		if(N%2 == 0) count0++; else count1++;
		N /= 2;
	}
	cout << 0 << "=>" << count0 << endl;
	cout << 1 << "=>" << count1 << endl;
	//system("pause");
}