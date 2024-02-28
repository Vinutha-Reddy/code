import java.util.Scanner;
public class Prog3 {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the number : ");
        int n=s.nextInt();
        if(n%2==0)
            System.out.println("Even number");
        else
            System.out.println("Odd number");
    }
}
