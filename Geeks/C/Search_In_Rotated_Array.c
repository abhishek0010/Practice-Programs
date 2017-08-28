#include <stdio.h>
#include <conio.h>

//Long Implementation of finding pivot. 
//One can compare side elements in a sorted array to find out the pivot
int find_pivot(int arr[],int low, int high)
{
	if(low>high)
		return -1;
	if(low==high)
		return low;
	int mid = (low+high)/2;
	if(mid>low && arr[mid]<arr[mid-1])
		return mid-1;
	if(mid<high && arr[mid]>arr[mid+1])
		return mid;
	if(arr[low]>=arr[mid])
		return find_pivot(arr,low,mid-1);
	else
		return find_pivot(arr,mid+1, high);
}
int binary_search(int arr[], int start, int end, int num)
{
	if(start>end)
		return -1;
	int mid = (start+end)/2;
	if(arr[mid]==num)
		return mid;
	else if(arr[mid]>num)
		binary_search(arr,start,mid-1,num);
	else
		binary_search(arr,mid+1,end,num);

}
int search_num(int arr[], int size, int num)
{
	int pivot = find_pivot(arr,0,size-1);

	if(pivot==-1)
		return binary_search(arr,0,size-1,num);

	if(arr[pivot]==num)
		return pivot;
	else if(arr[0]<=num)
		return binary_search(arr,0,pivot-1,num);
	else
		return binary_search(arr,pivot+1,size-1,num);

}


int main()
{
	int arr[] = {6,7,8,9,1,2,3,4,5,};
	int index = search_num(arr,9,7);
	printf("%d",index);
	getch();
}