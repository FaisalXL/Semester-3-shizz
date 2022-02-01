import java.util.Scanner;
import java.util.Arrays;
public class stringmethods {
    public static void main(String[] args) {
        String s1;
        s1 = "hey my name is rajesh name name";//16-21
        String s2 = "rajesh";
        String s3 = "faisal";
        boolean t1;
        s2 = s1.substring(15, 21);
        //s1 = s1.replace(s2, s3);
        //char[] n1 = s3.toCharArray();
        //Arrays.sort(n1);
        //s3 = new String(n1);
        //t1 = s1.equalsIgnoreCase(s2);
        /*String[] s4 = s1.split(" ");
        int counter = 0;
        for(int i = 0;i<s4.length;i++){
            if (s4[i].equals("name")){
                counter++;
            }
            System.out.println(s4[i]);
        }*/
        System.out.println(s2);
    }    
}
