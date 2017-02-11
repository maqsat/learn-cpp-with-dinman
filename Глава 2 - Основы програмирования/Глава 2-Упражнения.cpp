//1-exercise
#include<iostream>
using namespace std;
float main()
{

	int a, b, check,copy_a, copy_a_a;
	
	cin>>a;
	
	for (int i = 1; i < 10; i++)
	{
		copy_a_a = copy_a = a * 10 + i;
		check = 0;

		while (copy_a != 0)
		{
			check = check * 10 + copy_a % 10;
			copy_a /= 10;
		}

		cout << i << "=>";
		if (copy_a_a == check) cout << "Polindrome";
		else cout << "Don't polindrome";
		cout << endl;

	}


	//system("pause");
}

//2-exercise
#include<iostream>
using namespace std;
float main()
{
	int a, b, c, mulA, mulB, nod = 1;
	cin >> a >> b;
	if (a > b) c = b;
	else c = a;
	for (int i = 1; i <= c; i++)
	{
		if (a%i == 0) mulA = i;
		if (b%i == 0) mulB = i;
		if (mulA == mulB) nod = mulA;
	}

	cout << nod;
	//system("pause");
}

//3-exercise
#include<iostream>
#include<string>
using namespace std;

string zero_to_nine[10] = { "ноль", "один", "два", "три", "четыре", "пиять" , "честь" , "семь" , "восемь" , "девять" };
string ten_to_handred[10] = { "", "десять","двадцать", "тридцать", "сорок", "пятьдесять", "шестьдесять", "семьдесять", "восемдесять", "девяносто" };
string eleven_to_ninetin[10] = {"", "одинадцать", "двенадцать", "тринадцать","четырнадцать", "пятьнадцать", "шестьнадцать", "семьнадцать", "восемнадцать", "девятнадцать" };
string handred_to_thousand[10] = { "","сто", "двести", "триста", "четыреста", "пиятьсот" , "честьсот" , "семьсот" , "восемьсот" , "девятьсот" };
string thousand[2] = { "","тысяче" };
string million[2] = { "","миллион" };

void combain(int n)
{
	if (n > 99) { cout << handred_to_thousand[n / 100] << " "; n -= (n / 100) * 100; }
	if (n >= 11 && n <= 19) { cout << eleven_to_ninetin[n%10] << " "; n = 0; }
	if (n > 9) { cout << ten_to_handred[n / 10] << " ";  n -= (n / 10) * 10; }
	if (n > 1) cout << zero_to_nine[n] << " ";
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	int n,count = 0;
	cin >> n;

	if (n >= 1000000)
	{
		int millions_temp = n / 1000000;
		combain(millions_temp);
		cout << million[1] << " ";
		n %= 1000000;
	}
	

	if (n >= 1000)
	{
		int thousansd_temp = n / 1000;
		combain(thousansd_temp);
		cout << thousand[1] << " ";
		n %= 1000;
	}

	if (n >= 1)
	{
		combain(n);
	}
	else if (n == 0) cout<<zero_to_nine[0] << endl;
	else cout << "Overly large dates ..." << endl;

	//system("pause");
	return 0;
}

//4-exercise
#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_CTYPE, "rus");
	int a, b, c;
	bool flag = true;

	while (flag)
	{
		a = rand() % 10;
		b = rand() % 10;
		cout << "Сколько будет " << a << " * " << b << " = ";
		cin >> c;
		if (a*b == c) 
		{
			cout << "Молодец!!!"<<endl;
			flag = false;
		}
		else cout << "Попровуйте еще раз"<<endl;
	}

	//system("pause");
}

//5-exercise
#include<iostream>
using namespace std;

void main()
{
	int a[100], n, m, temp = 0,i = 0;
	cin >> n >> m;
	
	do
	{
		if (n % 10 != m)
		{
			a[i] = n % 10;
			i++;
		}
		
		n /= 10;
	} while (n);

	for (int j = i-1; j >= 0; j--)
	{
		temp = temp * 10 + a[j];
	}

	cout << temp << endl;

	//system("pause");
}

//6-exercise
#include<iostream>
void main()
{
	float a, b, sum=0,k=0;
	std::cin >> a >> b;
	for (size_t i = a; i <= b; i++)
	{
		sum += i;
		k++;
	}
	std::cout << sum / k;
}
7-exercise
#include<iostream>
using namespace std;

int factorial(int n)
{
	if (n == 0) return 1;
	return n*factorial(n - 1);
}

bool is_int(float n)
{
	if (n == (int)n) return true;
	else return false;
}

void main()
{
	float n, sum = 1;
	cin >> n;
	bool flag = true;

	for (int i = 1; i <= n; i++)
	{
		sum *= factorial(i);
	}

	cout << "sum: " << sum << endl;

	for (int i = 1; i <= n; i++)
	{

		if (is_int(sum / factorial(i)) && is_int(sqrt(sum / factorial(i))))
		{
			cout << i << endl;
			flag = false;
		}
	}

	if (flag) cout << "Not foud" << endl;
	//system("pause");
}

//8-exercise
#include<iostream>
using namespace std;
void main()
{
	int a, b, c, k = 0;
	cin >> a >> b >> c;
	if (a <= b + c) k++;
	if (b <= a + c) k++;
	if (c <= b + b) k++;
	if (k==3) cout<<"It's triangle";
	else cout << "It's don't triangle";
}

//9-exercise
#include<iostream>
using namespace std;

void main()
{
	int n;

	cin >> n;
	
	for (size_t i = 1; i < n; i++)
	{
		for (size_t j = i; j < n; j++)
		{
			for (size_t k = j; k < n; k++)
			{
				if (i + j + k == n) cout << i << "+" << j << "+" << k << "=" << n << endl;
			}
		}
	}
	
	//system("pause");
}

//10-exercise
#include<iostream>
using namespace std;

bool is_prime(int n)
{
	if (n == 1) return false;
	for (size_t i = 2; i < n; i++)
	{
		if (n % i == 0) return false;
	}

	return true;
}
void main()
{
	int n, m;

	cin >> n >> m;
	
	for (size_t i = n; i < m; i++)
	{
		if (is_prime(i))
		{
			if (is_prime(i + 1)) cout << i << " " << i + 1 << endl;
			if (is_prime(i + 2)) cout << i << " " << i + 2 << endl;
		}

	}
	
	//system("pause");
}