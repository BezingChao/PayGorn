// Program to display the addition result of any two integers
import java.util.Scanner;
public class Twointeger {
    public static void main(String[] args) {
        Scanner add = new Scanner(System.in);
        System.out.println("First Numer : ");
        int num1 = add.nextInt();
        System.out.println("Second Number : ");
        int num2 = add.nextInt();
        int sum = num1+num2;
        System.out.println("The Sum is : "+sum);
        add.close();

    }
}
