import java.util.Scanner;

class Sol {
    public static void main(String[] args) {
        String a, b;
        Scanner sc = new Scanner(System.in);
        a = sc.nextLine();
        b = sc.nextLine();
        int x = a.compareToIgnoreCase(b);
        if (x < 0) 
            System.out.println(-1);
        else if (x == 0)
            System.out.println(0);
        else System.out.println(1);
        sc.close();
    }
}