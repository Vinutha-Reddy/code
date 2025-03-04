public class StringConstructor {
    public static void main(String[] args) {
        String s1 = new String(); // default constructor
        System.out.println("1. " + s1);
        char[] chars = { 'a', 'b', 'c', 'd', 'e', 'f' };
        String s2 = new String(chars); // String(char[ ] chars)
        String s3 = new String(chars, 2, 3); // String(char[ ] chars, int startIndex, int numChars)
        System.out.println("2. " + s2);
        System.out.println("3. " + s3);
        char[] c = { 'J', 'a', 'v', 'a' };
        String s4 = new String(c);
        String s5 = new String(s4); // String(String strObj)
        System.out.println("4. " + s4);
        System.out.println("5. " + s5);
        byte[] ascii = { 65, 66, 67, 68, 69, 70 };
        String s6 = new String(ascii); // String(byte[ ] chrs)
        System.out.println("6. " + s6);
        String s7 = new String(ascii, 2, 3); // String(byte[ ] chrs, int startIndex, int numChars)
        System.out.println("7. " + s7);
    }
}
