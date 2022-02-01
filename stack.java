import java.util.Scanner;
public class stack {
    int top = -1;
    int[] arr;
    int size = 6;
    public stack(){
        arr = new int[size];
    }
    void pop(){
        if (top == -1) {
            System.out.println("stack underflow\n");
        }
        else{
            if(top == 0){
                top = -1;
            }
            else{
                top--;
            }
        }
    }
    void push(int n){
        if (top == -1) {
            System.out.println("entering first element in stack\n");
            top = 0;
            arr[top] = n;
        }
        else if(top == size - 1){
            System.out.println("Stack overflow\n");
        }
        else{
            top++;
            arr[top] = n;
        }
    }
    void display(){
        if (top == -1) {
            System.out.println("stack is empty\n");
            return;
        }
        for(int i=top;i>=0;i--){
            System.out.println(arr[i]);
        }
    }

    public static void main(String[] args) {
        stack s1 = new stack();
        Scanner lmao = new Scanner(System.in);
        int check = 0;
        int ch;
        int n;
        while(check == 0){
            System.out.println("enter your desried choice\n");
            System.out.println("1.Push\n");
            System.out.println("2.Pop\n");
            System.out.println("3.Display\n");
            System.out.println("4.Exit\n");
            ch = lmao.nextInt();
            switch (ch) {
                case 1:
                    System.out.println("Enter element to push\n");
                    n = lmao.nextInt();
                    s1.push(n);
                    break;
                case 2:
                    s1.pop();
                    break;
                case 3:
                    s1.display();
                    break;
                case 4:
                    check = -1;
                default:
                    System.out.println("Enter Valid Option\n");
                    break;
            }
        }
    }
}
