#include <stdio.h>
#include <conio.h>

typedef struct
{
	int first;
	int second;
} pair;

pair find_sum_pair(int arr[], int size, int num)
{
	int i=0;
	for(i=0;i<=size-1;i++)
	{
		if(arr[i]>arr[i+1])
			break;
	}
	int l = (i+1)%size;
	int r = i;

	while(l!=r)
	{
		int sum = arr[l]+arr[r];
		if(sum==num)
			return {l,r};
		else if(sum>num)
			r = (r+size-1)%size;
		else
			l = (l+1)%size;
	}
	return {-1,-1};
}


int main()
{
	int arr[] = {6,7,8,9,1,2,3,4,5,};
	pair p = find_sum_pair(arr,9,11);
	int i;
	printf("%d\t%d",p.first,p.second);
	getch();
}