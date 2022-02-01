import java.util.Scanner;

public class complex {
    int a,b;
    public complex(int a, int b){
        this.a = a;
        this.b = b;
    }
    public void add(complex s1){
        System.out.print("The sum of the two complex numbers is: \n");
        int real = a + s1.a;
        int complex = b + s1.b;

        System.out.print(real + " +i " + complex);
    }
    public void subtract(complex s1){
        System.out.print("The difference of the two complex numbers is \n");
        int real = a - s1.a;
        int complex = b - s1.b;

        System.out.print(real + " +i " + complex + "\n");
    }
    public void multiply(complex s1){
        System.out.print("the product of two complex numbers is\n");
        int real = a*s1.a - b*s1.b;
        int complex = a*s1.b + b*s1.a;

        System.out.print(real + " +i " + complex + "\n");
    }
    public static void main(String[] args) {
        System.out.println("Welcome to Complex Number Arithmetic\n");
        Scanner lmao = new Scanner(System.in);
        int real, comp;
        System.out.println("Please enter two complex numbers:\n");
        System.out.println("first complex number, real part followed by complex part\n");
        real = lmao.nextInt();
        comp = lmao.nextInt();
        complex c1 = new complex(real, comp);
        System.out.println("second complex number, real part followed by complex part\n");
        real = lmao.nextInt();
        comp = lmao.nextInt();
        complex c2 = new complex(real, comp);
        int check = 0;
        int ch;
        while(check == 0){
            System.out.println("Please Select Your Desired Option\n");
            System.out.println("1. Add two complex numbers\n");
            System.out.println("2. Subtact two complex numbers\n");
            System.out.println("3. Multiply two complex numbers\n");
            System.out.println("4. Quit\n");

            ch = lmao.nextInt();
            switch (ch) {
                case 1:
                    c1.add(c2);
                    break;
                case 2:
                    c1.subtract(c2);
                    break;
                case 3:
                    c1.multiply(c2);
                    break;
                case 4:
                    check = -1;
                    break;
                default:
                    System.out.println("stfu bro");
                    break;
            }

        }
    }
}
