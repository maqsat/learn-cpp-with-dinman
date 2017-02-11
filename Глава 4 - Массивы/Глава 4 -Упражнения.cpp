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