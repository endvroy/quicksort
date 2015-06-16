#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define arraySize 100000

extern void quick_sort(int *low, int *high);

void fill_array(int a[], int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000;
	}
}

void prn_array(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%2d ", a[i]);
		if ((i + 1) % 10 == 0)
		{
			putchar('\n');
		}
	}
	putchar('\n');
}

int main(void)
{
	clock_t start, end;
	double timeElapsed;
	int a[arraySize];
	fill_array(a, arraySize);
	//prn_array(a, arraySize);
	putchar('\n');
	start = clock();
	quick_sort(a, &a[arraySize - 1]);
	end = clock();
	timeElapsed = (end - start) / (CLOCKS_PER_SEC);
	//prn_array(a, arraySize);
	if (start != 0)
	{
		printf("Time used in sorting: %d seconds\n", timeElapsed);
	}
	else
	{
		printf("CPU time not available\n");
	}
	return 0;
}
