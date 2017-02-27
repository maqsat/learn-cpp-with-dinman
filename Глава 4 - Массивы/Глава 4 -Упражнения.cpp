//1 
#include "iostream"

int a[1000];

void quicksort(int i, int j)
{
	int left, right, p;
	left = i;
	right = j;
	p = a[(left + right)/2];
	do
	{
		//возрастанию
		while(a[i]<p) i++;
		while(a[j]>p) j--;

		//убыванию
		//while(a[i]>p) i++;
		//while(a[j]<p) j--;

		if(i<=j)
		{
			std::swap(a[i],a[j]);
			i++;j--;
		}
	}while(i<=j);

	if(j>left) quicksort(left,j);
	if(i<right) quicksort(i,right);
}

int main()
{
	int n;
	std::cout<<"Enter array count: ";
	std::cin>>n;

	std::cout<<"Enter array element: ";
	for (int i = 0; i < n; ++i)
	{
		std::cin>>a[i];
		std::cout<<" ";
	}

	quicksort(0,n-1);

	for (int i = 0; i < n; ++i)
	{
		std::cout<<a[i]<<" ";
	}

	return 0;
}

//2
#include "iostream"

int a[10] = {49,3,56,23,54,56,76,888,43,3};

void quicksort(int left, int right)
{
	int i = left, j = right;
	int pivot = a[(left + right) / 2]%10;

	do
	{
		while(a[i]%10 < pivot) i++;
		while(a[j]%10 > pivot) j--;
		//while(a[i]%10 > pivot) i++;
		//while(a[j]%10 < pivot) j--;

		if(i<j)
		{
			a[i] = a[i] + a[j];
			a[j] = a[i] - a[j];
			a[i] = a[i] - a[j];
		}
		i++;--j;

	} while (i<=j);

	if(right>i) quicksort(i,right);
	if(left<j) quicksort(left,j);
}

int main()
{
	quicksort(0,9);
	for (int i = 0; i < 10; ++i)
	{
		std::cout<<a[i]<<" ";
	}
	return 0;
}