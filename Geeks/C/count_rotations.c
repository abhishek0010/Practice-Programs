#include <stdio.h>
#include <conio.h>

int count_rotations(int arr[], int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(i==size-1)
			return 0;
		if(arr[i]>arr[i+1])
			return i+1;
	}
}

int main()
{
	int arr[] = {6,7,8,9,1,2,3,4,5};
	printf("%d",count_rotations(arr,9));
	getch();
}