import java.util.Scanner;
public class javaflex {
    public static int fibwrec(int n){
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return fibwrec(n-1) + fibwrec(n-2);
    }

    public static int fibworec(int n) {
        int n1 = 0;
        int n2 = 1;
        int n3 = 1;
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        for(int i=1;i<n;i++){
            n3 = n2 + n1;
            n1 = n2;
            n2 = n3;
        }
        return n3;             
    }
    public static void main(String[] args) {
        int ch;
        int x,y,z;
        Scanner lmao = new Scanner(System.in);
        int check = 0;
        while(check == 0){
            System.out.println("\n Please Select Your Choice:\n");
            System.out.println("1. Fibonacci With Recursion\n");
            System.out.println("2. Fibonacci Without Recursion\n");
            System.out.println("3. Quit\n");
            ch = lmao.nextInt();
            switch (ch) {
                case 1:
                    System.out.println("\nEnter Number of terms you want the sequence\n");
                    x = lmao.nextInt();
                    System.out.println("the fibonacci sequence is:\t");
                    for (int i = 0; i <= x ; i++) {
                        y = fibwrec(i);
                        System.out.print(y + " ");
                    }
                    System.out.println("\n");
                    break;
                case 2:
                    System.out.println("\nEnter Number of terms you want in the sequence\n");
                    x = lmao.nextInt();
                    System.out.println("the fibonacci sequence is\t");
                    for (int j = 0; j <= x; j++) {
                        z = fibworec(j);
                        System.out.print(z + " ");
                    }
                    System.out.println("\n");
                    break;
                case 3:
                    check = -1;
                    break;
                default:
                    System.out.println("dont be too smart ok");
                    break;
            }
    }
} 
}