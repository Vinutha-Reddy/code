/*10. Design and implement C/C++ Program to sort a given set of n integer elements using Quick Sort 
method and compute its time complexity. Run the program for varied values of n> 5000 and 
record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read 
from a file or can be generated using the random number generator.  */
#include<stdio.h>
#include<stdlib.h>
int i,j,m,temp,count=0;
int partition(int a[],int l,int n){
    int p=a[l];
    i=l;
    j=n+1;
    do{
        do{
            i++;
            count++;
        }while(i<n&&a[i]<p);
        do{
            j--;
            count++;
        }while(j>l&&a[j]>p);
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    temp=a[l];
    a[l]=a[j];
    a[j]=temp;
    return j;
}
void Quick_Sort(int a[],int l,int n){
    if(l<n){
        int s=partition(a,l,n);
        Quick_Sort(a,l,s-1);
        Quick_Sort(a,s+1,n);
    }
}
int main(){
    int a[10000];
    printf("\nEnter the size of the array : ");
    scanf("%d",&m);
    printf("\nThe array elements are : ");
    for(i=0;i<m;i++){
        a[i]=rand();
        printf("%d\t",a[i]);
    }
    Quick_Sort(a,0,m);
    printf("\nThe sorted elements are : ");
    for(i=1;i<=m;i++)
        printf("%d\t",a[i]);
    printf("\nNumber of times basic operations executed :%d",count);
}

/*OUTPUT:
Enter the size of the array : 5
The array elements are : 41     18467   6334    26500   19169
The sorted elements are : 41    6334    18467   19169   26500
Number of times basic operations executed :18
*/