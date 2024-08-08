/*9. Design and implement C/C++ Program to sort a given set of n integer elements using Selection 
Sort method and compute its time complexity. Run the program for varied values of n> 5000 and 
record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read 
from a file or can be generated using the random number generator.  */
#include<stdio.h>
#include<stdlib.h>
int i,j,min,temp,count=0;
void Selection_Sort(int a[],int n){
    for(i=0;i<=n-1;i++){
        min=i;
        for(j=i+1;j<=n;j++){
            count++;
            if(a[j]<a[min])
                min=j;
                
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
}
int main(){
    int a[10000],n;
    printf("\nEnter the size of the array : ");
    scanf("%d",&n);
    printf("\nThe array elements are : ");
    for(i=0;i<n;i++){
        a[i]=rand();
        printf("%d\t",a[i]);
    }
    Selection_Sort(a,n);
    printf("\nSorted elements are : ");
    for(i=1;i<=n;i++)
        printf("%d\t",a[i]);
    printf("\nNumber of times basic operations executed :%d",count);
}

/*OUTPUT:
Enter the size of the array : 5
The array elements are : 41 18467 6334 26500 19169
Sorted elements are : 41 6334 18467 19169 26500
Number of times basic operations executed :15
*/