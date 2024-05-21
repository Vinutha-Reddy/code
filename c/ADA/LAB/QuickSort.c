#include<stdio.h>
int i,j,m,temp,count=0;
int partition(int a[],int l,int n){
        int p=a[l];
        i=l;
        j=n+1;
        do{
            do{
                count++;
                i++;
            }while(i<n&&a[i]<p);
            do{
                count++;
                j--;
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
        int s=partition(a,l,n-1);
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
    for(i=0;i<m;i++)
        printf("%d\t",a[i]);
    printf("\nNumber of times basic operations executed :%d",count);
}