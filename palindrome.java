import java.util.Scanner;
public class palindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt(), rev = 0, temp = num;
        while (temp > 0) { rev = rev * 10 + temp % 10; temp /= 10; }
        System.out.println(num == rev ? "Palindrome" : "Not Palindrome");
        sc.close();
    }
}