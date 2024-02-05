// write a java program for try and catch block

public class lab9 {
    public static void main(String[] args) {
        int a = 10;
        int b = 0;
        try {
            int c = a/b;
            System.out.println("c is " + c);
        }
        catch (ArithmeticException e) {
            System.out.println("Division by zero is not allowed");
        }
    }
}