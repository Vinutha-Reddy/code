import java.util.Random;

class Square implements Runnable {
    Thread t;
    int x;

    Square(int n) {
        x = n;
        t = new Thread(this, "Square");
        t.start();
    }

    public void run() {
        System.out.println("Square of " + x + " is : " + x * x);
    }
}

class Cube implements Runnable {
    Thread t;
    int x;

    Cube(int n) {
        x = n;
        t = new Thread(this, "Cube");
        t.start();
    }

    public void run() {
        System.out.println("Cube of " + x + " is : " + x * x * x);
    }
}

class Randomnum implements Runnable {
    Thread t;

    Randomnum() {
        t = new Thread(this, "Randomnum");
        t.start();
    }

    public void run() {
        int n,i=3;
        Random r = new Random();
        while (i-->0) {
            n = r.nextInt(100);
            System.out.println("Random number = " + n);
            Square s = new Square(n);
            Cube c = new Cube(n);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }

    public static void main(String[] args) {
        Randomnum a = new Randomnum();
    }
}