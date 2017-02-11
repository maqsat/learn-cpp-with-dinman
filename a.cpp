#include "iostream"
#include "cstring"
#include "cstdlib"

int a[1000];
int n[1000];
int c[100000000];

int	main()
{
	char number1[256], number2[256], temp[2] = {0,0};

	std::cout<<"Enter number: ";
	std::cin>>number1;

	std::cout<<"Enter degree: ";
	std::cin>>number2;

	int len1,len2;

	len1 = strlen(number1);
	len2 = strlen(number2);

	for (int i = 0; i < len1; ++i)
	{
		temp[0] = number1[i];
		a[i] = atoi(temp);
		c[i] = a[i];
	}

	for (int i = 0; i < number2 -1; ++i)
	{
		my_pow();
	}z


	std::cout<<len1<<" "<<len2;
	return 0;
}