#include<stdio.h>
#include <malloc.h>
#include<math.h>

int f1(int a, int b)
{
	if (b == 0)
		return a;
	return f1(b, a % b);
}

void f3(int *a, int b, int c)
{
	c %= b;
	if (c == 0)
		return;
	int tmp = f1(b, abs(c)), j, to, tmp2, tmp3;
	for (int i = 0; i < tmp; ++i)
	{
		tmp3 = a[i];
		j = i;
		do
		{
			if (c > 0)
				j = (j + c) % b;
			else
				j = (b + j + c) % b;	
			tmp2 = a[j];
			a[j] = tmp3;
			tmp3 = tmp2;
		} while (j != i);
	}
}

int main()
{
	int b, c;
	scanf_s("%d", &b);
	int *a = (int *)malloc(b * sizeof(int));
	if (a != 0)
	{
		for (int i = 0; i < b; ++i)
			scanf_s("%d", &a[i]);
		scanf_s("%d", &c);
		f3(a, b, c);
		free(a);
	for (int i = 0; i < b; i++) {
		printf_s("%d", a[i]);
		}
	}

	return 0;
}