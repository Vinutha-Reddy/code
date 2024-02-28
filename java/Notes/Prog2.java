import java.util.Scanner;

public class Prog2 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the array size : ");
        int n = s.nextInt();
        int a[] = new int[n];
        System.out.println("Enter the array elements : ");
        for (int i = 0; i < n; i++)
            a[i] = s.nextInt();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
        System.out.println("The sum of the array elements is : " + sum);
    }
}
