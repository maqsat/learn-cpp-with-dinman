//1-пример
#include <iostream>

int main()
{
	int counter = 0,finish,start;
	int n = 10;
	int a[n] = {13,5,6,7,5,7,0,8,0,5};

	int min = 0,max = 0;
	for (int i = 1; i < n; ++i)
	{
		if(a[min] > a[i]) min = i;
	}

	for (int i = 0; i < n; ++i)
	{
		if(a[max] < a[i]) max = i;
	}

	if(max>min) 
	{
		start = min;
		finish = max;
	}
	else 
	{
		start = max;
		finish = min;
	}

	for (int i = start + 1; i < finish; ++i)
	{
		if(a[i]%2 == 0) counter++;
	}

	std::cout<<counter;
	return 0;
}

//2-пример
#include <iostream>
#include <cstdlib>
int sum = 0,pos,n,k,l,array[100];

void rec(int pos)
{
	l--;
	if(l<0) 
	{
		std::cout<<sum;
		exit(1);
	}
	
	sum+=array[pos];

	rec(array[pos]);	
}

int main()
{
	std::cin>>n>>k>>l;
	for (int i = 0; i < n; ++i) std::cin>>array[i];

	sum = 0;
	rec(k);
	return 0;
}

//3-пример
#include <iostream>

int main()
{
	int n = 10,k,t;
	int a[n] = {4,5,3,6,7,2,6,8,1,5};

	std::cin>>k>>t;

	int start = 0,min,min_pos;

	while(start != n-1)
	{
		min = a[start];
		min_pos = start;

		for (int i = start; i < n; ++i)
		{
			if(min>a[i])
			{
				min = a[i];
				min_pos = i;
			}
		}

		if(min_pos != start)
		{
			a[start]   = a[start] + a[min_pos];
			a[min_pos] = a[start] - a[min_pos];
			a[start]   = a[start] - a[min_pos];
		}

		start++;
	}

	int sum = 0;

	for (int i = 0; i < n; ++i)
	{
		std::cout<<a[i]<<" ";
	}
	std::cout<<"\n";
	for (int i = 0; i < k; ++i)
	{
		sum += a[i];
	}

	if(sum>t) std::cout<<"NO\n";
	else std::cout<<"Yes\n";
}

//4-пример
#include "iostream"
#include "cstdlib"

int a[100], size, length, max_length, number;

void rec(int pos)
{
	if(pos == size)
	{
		if(max_length == 1) number = a[0];
		std::cout<<max_length<<" "<<number;
		exit(1);
	}

	if(a[pos] == a[pos+1])
	{
		length++;
		rec(pos+1);
	}
	else
	{
		if(max_length<length)
		{
			max_length = length;
			number = a[pos];
			length = 1;
		}
	}

	length = 1;
	rec(pos+1);
}

int main()
{
	std::cin>>size;
	for (int i = 0; i < size; ++i)
	{
		std::cin>>a[i];
	}

	length = 1;
	max_length = 1;
	rec(0);
}


//5 - пример
#include "iostream"

int main()
{
	int pos, i, temp, n = 10;
	int a[n] = { 4,5,6,2,6,7,0,0,5,0};

	pos = n-1;
	while(a[pos] == 0) --pos;

	i = 0;

	while(i<pos)
	{
		if(a[i] == 0)
		{
			a[i] = a[i] + a[pos];//3-2
			a[pos] = a[i] - a[pos];//
			a[i] = a[i] - a[pos];

			while(a[pos] == 0) --pos;
		}	
		i++;
	}

	for (int i = 0; i < n; ++i)
	{
		std::cout<<a[i]<<" ";
	}

	return 0;
}