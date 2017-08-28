#include <stdio.h>
#include <conio.h>

#define MAX 100000

typedef struct 
{
	int first;
	int second;
}pair;

pair find_sum_pair(int arr[], int size, int sum)
{
	int hash_map[MAX] = {0};

	int i,temp;
	for(i=0;i<size;i++)
	{
		temp = sum-arr[i];
		if(temp>=0 && hash_map[temp]==1)
			return {arr[i], temp};
		hash_map[arr[i]]=1;
	}
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	pair p = find_sum_pair(arr,9,17);
	printf("%d\t%d",p.first,p.second);
	getch();
}