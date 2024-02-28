import java.util.Scanner;
class Prog1{
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the array size : ");
        int n=s.nextInt();
        int a[]=new int[n];
        System.out.println("Enter the array elements : ");
        for(int i=0;i<n;i++)
            a[i]=s.nextInt();
        System.out.println("The array elements are : ");
        for(int i=0;i<n;i++)
            System.out.print(a[i]+" ");
    }
}