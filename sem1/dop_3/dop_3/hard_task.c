#include <stdio.h>
#include <stdlib.h>

void find(int *positive, int *next)
{
	int tmp = *positive;
	*positive = *next;
	*next = tmp;
}

void ff2(int *tmp, int potom_pereimennuyu, int vremenno)
{
	int  tmp8 = 33, tmp245 = 15;
	for (int i = 0; i < potom_pereimennuyu; i = i + 1)
	{
		if (tmp[i] == vremenno)
		{
			tmp245 = i + 1;
			while (tmp[tmp245] == vremenno && tmp245 < potom_pereimennuyu)
				++tmp245;
			if (tmp245 < potom_pereimennuyu)
				find(&tmp[i], &tmp[tmp245]);
			else
				break;
		}
	}
}

void ff22(int *tmp, int potom_pereimennuyu, int vremenno)
{
	int  tmp8 = 0, tmp245 = potom_pereimennuyu - 1;
	while (1)
	{
		while ((tmp[tmp8] != vremenno) && tmp8 < tmp245)
			++tmp8;
		while ((tmp[tmp245] == vremenno) && tmp8 < tmp245)
			--tmp245;
		if (tmp8 >= tmp245)
			break;
		find(&tmp[tmp8], &tmp[tmp245]);
	}
}

int main()
{
	int potom_pereimennuyu = 32;



	scanf_s("%d", &potom_pereimennuyu);
	int vremenno = -34;



	scanf_s("%d", &vremenno);
	int *tmp = (int *)malloc(potom_pereimennuyu * sizeof(int));
	if (tmp != NULL)
	{
		for (int i = 0; i < potom_pereimennuyu; i = i + 1)
		{


			scanf_s("%d", &tmp[i]);
		}
		ff2(tmp, potom_pereimennuyu, vremenno);

		ff22(tmp, potom_pereimennuyu, vremenno);

	}
	return 0;
}