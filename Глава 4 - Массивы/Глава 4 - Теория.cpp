/*** Сортировка **/

//Bubble sort
#include<iostream>
using namespace std;

void main()
{
	const int size = 10;
	int A[size] = { 5, 9, 3, 4, 8, 6, 1, 7, 9, 23 };

	int temp;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - 1; j++)
		{
			if (A[i] < A[j])
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}

	system("pause");
}

//Selection sort
#include<iostream>
using namespace std;

int main()
{
	const int n = 10;
	int arr[n] = { 1,9,4,5,3,6,9,0,5,2 };

	int start = 0, min, min_pos;

	while (start != n-1)
	{
		min = arr[start];
		min_pos = start;

		for (int i = start + 1; i < n; i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
				min_pos = i;
			}
		}

		if (min_pos != start)
		{
			arr[min_pos] = arr[min_pos] + arr[start];
			arr[start] = arr[min_pos] - arr[start];
			arr[min_pos] = arr[min_pos] - arr[start];
		}

		start++;
	}

	for (size_t i = 0; i < n; i++)
	{
		cout << i << " ";
	}

	system("pause");

}

//Quick Sort
#include<iostream>

int arr[15] = { 2,9,4,8,5,3,0,5,3,9,7,0,4,6,2 };

void quick_sort(int i, int j)
{
	int left = i;
	int right = j;
	int pivot = arr[(i + j) / 2];

	do
	{
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) --j;

		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++; --j;
		}

	} while (i<=j);

	if (j > left) quick_sort(left, j);
	if (i < right) quick_sort(i, right);
}

int main()
{
	quick_sort(0, 14);
	for (size_t i = 0; i < 15; i++)
	{
		std::cout << arr[i] << " ";
	}

	system("pause");
	return 0;
}

//Shell sort
#include<iostream>

void shell_sort(int arr[],int n)
{
	int middle = n/2;
	int change;
	int middle_copy;

	do
	{
		do
		{
			change = 0;
			for (size_t i = 0; i < n-middle; i++)
			{
				if (arr[i] > arr[i + middle])
				{
					std::swap(arr[i], arr[i + middle]);
					change = 1;
				}
			}
		} while (change);

		middle_copy = middle;
		middle /= 2;
	} while (middle_copy != middle);

}

int main()
{
	int arr[20] = { 3,9,4,0,5,7,5,0,3,1,2,1,9,5,9,5,4,0,4,80 };
	shell_sort(arr,20);
	for (size_t i = 0; i < 20; i++)
	{
		std::cout << arr[i] << " ";
	}

	system("pause");
	return 0;
}

//Сортировка массива при известном интервале значений элементов
#include<iostream>

int main()
{
	int n = 13;
	int arr[10] = { 4,1,5,3,5,35,12,6,5,4 };
	int temp_arr[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };

	for (int i = 0; i < 10; ++i)
	{
		temp_arr[arr[i]] +=1;
	}

	for (int i = 0; i < 13; ++i)
	{
		for (int j = 0; j < temp_arr[i]; ++j)
		{
			std::cout<<i<<" ";
		}
	}

	return 0;
}


/*** Поиск заданного элемента в массиве **/


//Последовательный поиск элемента
#include <iostream>

int search(int array[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		if(n == array[i]) return i;
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	int array[10] = { 1,2,3,4,5,6,7,8,9,0 };

	int n;
	std::cin>>n;

	std::cout<<search(array,n);

	return 0;
}

//Binary search
#include <iostream>

int binary_search(int array[],int size, int searched)
{
	int left = 0;
	int right = size-1;
	int middlie = (left+right)/2;

	while(left<=right)
	{
		if(array[middlie] == searched) return middlie;
 
		if(searched < middlie) right = middlie - 1;
		else left = middlie + 1;

		middlie = (left+right)/2;
	}

	return -1;
}

int main()
{
	int size = 10;
	int numbers[size] = {0,1,2,3,4,5,6,7,8,9};
	int searched = 1;

	int pos = binary_search(numbers,size,searched);

	if(pos == -1) std::cout<<"Not found";
	else std::cout<<"Searched number's index " << pos;
	/* code */
	return 0;
}


/*** Арифметика больших чисел **/


//Вычитание чисел
#include <iostream>
#include <cstdlib>
#include <cstring>

int a[100],b[100],c[100];

void output(int k, int p)
{
	int i;
	while(c[k]==0 && k>0) --k;

	if(p==2) std::cout<<"-";

	for(i=k; i>=0;--i)
	{
		std::cout<<c[i];
	}
	std::cout<<"\n";
}

void done(int len1,int len2, int p)
{
	int k;
	if(len1>len2) k=len1;
	else k=len2;

	if(p==2)
	{
		for (int i = 0; i < k; ++i)
		{
			std::swap(a[i],b[i]);
		}
	}

	for (int i = 0; i < k; ++i)
	{
		c[i] = a[i] - b[i] + c[i];

		if(c[i]<0)
		{
			c[i+1] -=1;
			c[i]   +=10;
		}
	}

	output(k,p);
}

void max(int len1,int len2)
{
	int p;
	if(len1>len2)
	{
		p=1;
		done(len1,len2,p);
		return;
	}

	if(len1<len2)
	{
		p=2;
		done(len1,len2,p);
		return;
	}

	p=1;
	for (int i = len1-1; i >=0 ; --i)
	{
		if(a[i]>b[i])
		{
			done(len1,len2,p);
			return;
		}
		if(a[i]<b[i])
		{
			p=2;
			done(len1,len2,p);
			return;
		}
	}

	done(len1,len2,p);
	return;
}

void input()
{
	char temp[2] = {0,0}, s[100];
	int i,p,len1, len2;

	p=0;
	std::cin>>s;
	len1 = strlen(s);
	i = len1-1;
	while(i>=0)
	{
		temp[0] = s[i];
		a[p]  = atoi(temp);
		p++;--i;
	}

	p=0;
	std::cin>>s;
	len2 = strlen(s);
	i = len2-1;
	while(i>=0)
	{
		temp[0] = s[i];
		b[p]  = atoi(temp);
		p++;--i;
	}

	max(len1,len2);
}

int main()
{
	input();
	return 0;
}

//Сложение чисел
#include <iostream>
#include <cstdlib>
#include <cstring>

int a[100],b[100],c[100];

void output(int k)
{
	for(int i=k - 1; i>=0;--i)
	{
		std::cout<<c[i];
	}
	std::cout<<"\n";
}

void done(int len1,int len2)
{
	int k;
	if(len1>len2) k=len1;
	else k=len2;

	for (int i = 0; i < k; ++i)
	{
		c[i] = a[i] + b[i] + c[i];

		if(c[i]>9)
		{
			c[i+1] +=1;
			c[i]   -=10;
		}
	}

	output(k);
}

void input()
{
	char temp[2] = {0,0}, s[100];
	int i,p,len1, len2;

	p=0;
	std::cin>>s;
	len1 = strlen(s);
	i = len1-1;
	while(i>=0)
	{
		temp[0] = s[i];
		a[p]  = atoi(temp);
		p++;--i;
	}

	p=0;
	std::cin>>s;
	len2 = strlen(s);
	i = len2-1;
	while(i>=0)
	{
		temp[0] = s[i];
		b[p]  = atoi(temp);
		p++;--i;
	}

	done(len1,len2);
}

int main()
{
	input();
	return 0;
}

//Умножения чисел
#include <iostream>
#include <cstdlib>
#include <cstring>

int a[100], b[100], c[100];

void output(int k, int is_negative)
{
	while(c[k] == 0 && k>0) --k;

	if (is_negative) std::cout<<"-";

	for (int i=k; i>=0; --i)
	{
		std::cout<<c[i];
	}
	std::cout<<"\n";
}

void done(int len1, int len2,int is_negative)
{
	int k;

	if(len1>len2) k = len1; else k = len2;

	for (int i = 0; i < len1; ++i)
	{
		for (int j = 0; j < len2; ++j)
		{
			c[i+j] = c[i+j] + a[i] * b[j];

			if(c[i+j]>9)
			{
				c[i+j+1] += (c[i+j]/10);
				c[i+j]   %= 10;
			}
		}
	}

	output(k,is_negative);
}

void input()
{
	char temp[2] = {0,0}, s[100];
	int i,p,len1,len2,is_negative1 = 0,is_negative2 = 0, is_negative = 0;;

	p=0;
	std::cin>>s;
	i = strlen(s) - 1;
	while(i>=0)
	{
		temp[0] = s[i];
		if(atoi(temp) == 0 && i == 0) is_negative1 = 1;
		a[p] = atoi(temp);
		p++; --i;
	}
	len1 = p;

	p=0;
	std::cin>>s;
	i = strlen(s) - 1;
	while(i>=0)
	{
		temp[0] = s[i];
		if(atoi(temp) == 0 && i == 0) is_negative2 = 1;
		b[p] = atoi(temp);
		p++; --i;
	}
	len2 = p;


	if((is_negative1 && is_negative2) || (!is_negative1 && !is_negative2)) is_negative = 0;
	else  is_negative = 1;

	done(len1,len2,is_negative);
}

int main()
{
	input();
	return 0;
}