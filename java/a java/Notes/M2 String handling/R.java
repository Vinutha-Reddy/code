class Box{
    double width;
    double height;
    double depth;
    Box(double w, double h, double d){
        width=w;
        height=h;
        depth=d;
    }
    public String toString(){
        return "Dimension are "+width+" by "+height+" by "+depth+".";
    }
}
public class R{
    public static void main(String[] args){
        String s1 = "Hello";
        String s2 = "Hello";
        String s3 = "Good Bye";
        String s4 = "HELLO";
        String s5 = "Welcome to home";
        String s6 = "home";
        String s7 = "HOME";
        String s8 = "Cambridge";
        String s9 = "Welcome to the world of programming language where you will learn different programming languages.";
        String s10 = " Hello Everyone ";
        String s11 = new String();
        char[] chars = { 'a', 'b', 'c' }; 
        String s12 = new String(chars);
        Box bo=new Box(11,13,15);
        String s="Box : "+bo;
        System.out.println(bo);
        System.out.println(s);
        System.out.println(s1.equals(s2));
        System.out.println(s1.equals(s3));
        System.out.println(s1.equals(s4));
        System.out.println(s1.equalsIgnoreCase(s4));
        System.out.println(s5.regionMatches(11,s6,0,4));
        System.out.println(s5.regionMatches(true,11,s7,0,4));
        System.out.println(s8.startsWith("Cam"));
        System.out.println(s8.endsWith("bridge"));
        System.out.println(s8.startsWith("ge",7));
        System.out.println(s6.compareTo(s7));
        System.out.println(s1.compareTo(s3));
        System.out.println(s1.compareTo(s2));
        //25-02-2025
        System.out.println("\n"+s6.compareToIgnoreCase(s7));
        System.out.println(s1.indexOf("l"));
        System.out.println(s5.lastIndexOf("o"));
        System.out.println(s8.indexOf("v"));
        System.out.println(s5.indexOf("to"));
        System.out.println(s9.lastIndexOf("lang"));
        System.out.println(s5.indexOf("e",3));
        System.out.println(s9.lastIndexOf("programming",74));
        System.out.println(s1.substring(1));
        System.out.println(s1.substring(1,3));
        System.out.println(s4.concat(" WORLD"));
        System.out.println(("HI ")+s4);
        System.out.println(s3.replace("Bye","Morning"));
        System.out.println(s1.replace("H","J"));
        System.out.println(s10.trim());
        System.out.println(s10.strip());
        System.out.println(s6.toUpperCase());
        System.out.println(s7.toLowerCase());
        System.out.println(String.join(":","Apple","Banana"));
        System.out.println(s11);
        System.out.println(s12);
        System.out.println(s1.getBytes());
        byte[] bytes = s8.getBytes();
        for (byte b : bytes){
            System.out.println(b+" ");
        }
        char[] charArray = s10.toCharArray();
        for (char ch : charArray){
            System.out.println(ch+" ");
        }
    }
}