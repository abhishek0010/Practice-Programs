#include<stdio.h>
#include<conio.h>

void Array_Rotation(int arr[], int size, int pos)
{
     //O(size*pos)
     int i = 0;
     for(i=0;i<pos;i++)
     {
                       int j = 0;
                       int temp = arr[0];
                       for(j=0;j<size-1;j++)
                       {
                                          arr[j]=arr[j+1];                
                       }
                       arr[size-1]=temp;
     }
}

int gcd(int a, int b)
{
    if(b ==0)
         return 1;
    else
        return gcd(b,a%b);
}

void juggling_rotation(int arr[], int size, int pos)
{
     //O(size)
     int i,j,k,temp;
     for(i=0;i<gcd(size,pos);i++)
     {
                                 temp = arr[i];
                                 j =i;
                                 while(1)
                                 {
                                         k = j+pos;
                                         if(k>=size)
                                                    k=k-size;
                                         if(k==i)
                                                 break;
                                         arr[j]=arr[k];
                                         j=k;
                                 }
                                 arr[j] = temp;
     }
     
}

void reverse(int arr[], int start, int end)
{
     
     while(start<end)
     {
                     
                     int temp = arr[start];
                     arr[start]= arr[end];
                     arr[end] = temp;
                     start++;
                     end--;
                     }
}

void reversal_rotation(int arr[],int size, int pos)
{
     //O(size)
         reverse(arr, 0, pos-1);
         reverse(arr, pos, size-1);
         reverse(arr, 0, size-1);
}

//BLOCK SWAP IMPLEMENTATION DUE

void display_array(int arr[],int size)
{
     int i = 0;
     for(i=0;i<size;i++)
     {
                     printf("%d ",arr[i]);
     }
}

int main()
{
    //int size = 9;
    int arr[] = {1,2,3,4,5,6,7,8,9};
    reversal_rotation(arr,9,7);
    display_array(arr,9);
    getch();
}
