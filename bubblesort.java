import java.util.Scanner;

public class bubblesort {
    public static void main(String[] args) {
        Scanner lmao = new Scanner(System.in);
        int size;
        int temp;
        size = lmao.nextInt();
        int[] arr = new int[size];
        System.out.println("Enter the array elements\n");
        for (int i = 0; i < size; i++) {
            arr[i] = lmao.nextInt();
        }
        System.out.println("Performing bubble sort\n");
        for(int i = 0; i<size-1;i++){

            for(int j =0;j<size-i-1;j++){
                if(arr[j] > arr[j+1]){
                    temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        System.out.println("Displaying sorted array\n");
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }

    }
}
