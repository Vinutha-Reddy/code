import java.util.Scanner;
public class Prog4 {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the total cost : ");
        double bill=s.nextDouble();
        if(bill<2000)
            bill-=(5.0/100)*bill;
        else if(bill<=5000)
            bill-=(25.0/100)*bill;
        else if (bill<=10000)
            bill-=(35.0/100)*bill;
        else
            bill-=(50.0/100)*bill;
        System.out.println("The discounted bill is : "+bill);
    }
}
