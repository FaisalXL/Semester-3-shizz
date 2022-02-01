import java.util.Scanner;

public class primecheck {
    public static void main(String[] args) {
        int n;
        Scanner lmao = new Scanner(System.in);
        System.out.println("\nEnter number to check if prime\n");
        n = lmao.nextInt();
        int check = -1;
        if(n==0 || n==1){
            System.out.println("\n Neither prime nor composite\n");
        }
        else if(n==2){
            System.out.println("\n prime number\n");
        }
        else{
            for (int i = 2; i < n/2; i++) {
                if (n%i == 0) {
                    check = 0;
                }
            }
            if (check == 0) {
                System.out.println("Number is not prime\n");
            }
            else{
                System.out.println("Prime Number\n");
            }
        }
    }
    
}
