#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define arraySize 200000

extern void quick_sort(int *low, int *high);

void random_write(int size)
{
	srand(time(NULL));
	FILE *fp;
	int i, a;
	if ((fp = fopen("in.txt", "w")) == NULL)
	{
		printf("file open failed\n");
		exit(-1);
	}

	for (i = 0; i<size; i++)
	{
		a = rand() % size;
		fprintf(fp, "%d ", a);
	}

	if (fclose(fp)){
		printf("file close failed\n");
		exit(-1);
	}
}

int input(int a[])
{
	FILE *fp;
	int i;
	if ((fp = fopen("in.txt", "r")) == NULL)
	{
		printf("file open failed\n");
		exit(-1);
	}

	for (i = 0; i<100000; i++)
	{
		if (fscanf(fp, "%d", &a[i]) < 0) break;
	}

	if (fclose(fp)){
		printf("file close failed\n");
		exit(-1);
	}
	return i;
}

void output(int arr[],int size)
{
	FILE *fp1;
	int i;
	if ((fp1 = fopen("out.txt", "w")) == NULL)
	{
		printf("file open failed\n");
		exit(-1);
	}

	for (i = 0; i<size; i++)
	{
		fprintf(fp1, "%d ", arr[i]);
	}

	if (fclose(fp1)){
		printf("file close failed\n");
		exit(-1);
	}
}

void fill_array(int a[], int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % arraySize;
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
	int a[arraySize];

	random_write(100000);
	int size=input(a);

	clock_t start, end;
	start = clock();
	quick_sort(a, &a[size - 1]);
	end = clock();
	double timeElapsed;
	timeElapsed = (double)(end - start) / (CLOCKS_PER_SEC);
	output(a,size);
	//prn_array(a, arraySize);

	if (start != -1)
	{
	//	printf("CLOCK_PER_SEC= %d\n", CLOCKS_PER_SEC);
		printf("Time used in sorting: %f seconds\n", timeElapsed);
	}
	else
	{
		printf("CPU time not available\n");
	}
	return 0;
}
