#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;

typedef struct{
	char key[10];
	int data;
}Record;

int Compare(void const *a,void const *b)
{
	return strcmp( ((Record *)a)->key, ((Record *)b)->key);
}

int n_compare(void const *a,void const *b)
{
	return ((Record *)a)->data - ((Record *)b)->data;
}

void Input(Record array[])
{
	printf("请输入数据个数：");
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		printf("key:");
		scanf("%s",array[i].key);
		printf("data:");
		scanf("%d",&array[i].data);
	}
}

void Print(Record array[])
{
	for(int i = 0; i < n; i++)
	{
		printf("key:%s   ",array[i].key);
		printf("data:%d\n",array[i].data);
	}
}

int main()
{
	Record array[50];
	Input(array);
	qsort(array,n,sizeof(Record),n_compare);
	Print(array);
	return 0;
}

