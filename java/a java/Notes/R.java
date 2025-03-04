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
        System.out.println("1. "+bo);
        System.out.println("2. "+s);
        System.out.println("3. "+s1.equals(s2));
        System.out.println("4. "+s1.equals(s3));
        System.out.println("5. "+s1.equals(s4));
        System.out.println("6. "+s1.equalsIgnoreCase(s4));
        System.out.println("7."+s5.regionMatches(11,s6,0,4));
        System.out.println("8."+s5.regionMatches(true,11,s7,0,4));
        System.out.println("9. "+s8.startsWith("Cam"));
        System.out.println("10. "+s8.endsWith("bridge"));
        System.out.println("11. "+s8.startsWith("ge",7));
        System.out.println("12. "+s6.compareTo(s7));
        System.out.println("13. "+s1.compareTo(s3));
        System.out.println("14. "+s1.compareTo(s2));
        //25-02-2025
        System.out.println("\n15. "+s6.compareToIgnoreCase(s7));
        System.out.println("16. "+s1.indexOf("l"));
        System.out.println("17. "+s5.lastIndexOf("o"));
        System.out.println("18. "+s8.indexOf("v"));
        System.out.println("19. "+s5.indexOf("to"));
        System.out.println("20. "+s9.lastIndexOf("lang"));
        System.out.println("21. "+s5.indexOf("e",3));
        System.out.println("22. "+s9.lastIndexOf("programming",74));
        System.out.println("23. "+s1.substring(1));
        System.out.println("24. "+s1.substring(1,3));
        System.out.println("25. "+s4.concat(" WORLD"));
        System.out.println("26. "+("HI ")+s4);
        System.out.println("27. "+s3.replace("Bye","Morning"));
        System.out.println("28. "+s1.replace("H","J"));
        System.out.println("29. "+s10.trim());
        System.out.println("30. "+s10.strip());
        System.out.println("31. "+s6.toUpperCase());
        System.out.println("32. "+s7.toLowerCase());
        System.out.println("33. "+String.join(":","Apple","Banana"));
        System.out.println("34. "+s11);
        System.out.println("35. "+s12);
        byte[] bytes = s8.getBytes();
        System.out.println("36. ");
        for (byte b : bytes){
            System.out.println(b+" ");
        }
        char[] charArray = s10.toCharArray();
        System.out.println("37. ");
        for (char ch : charArray){
            System.out.println(ch+" ");
        }
    }
}

/*output:
1. Dimension are 11.0 by 13.0 by 15.0.
2. Box : Dimension are 11.0 by 13.0 by 15.0.
3. true
4. false
5. false
6. true
7.true
8.true
9. true
10. true
11. true
12. 32
13. 1
14. 0

15. 0
16. 2
17. 12
18. -1
19. 8
20. 88
21. 6
22. 24
23. ello
24. el
25. HELLO WORLD
26. HI HELLO
27. Good Morning
28. Jello
29. Hello Everyone
30. Hello Everyone
31. HOME
32. home
33. Apple:Banana
34.
35. abc
36. 67 97 109 98 114 105 100 103 101
37. H e l l o  E v e r y o  n e
 */