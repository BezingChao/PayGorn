public class primeNumber {
    public static void main(String[] args) {
        for (int i = 100; i <= 200; i++) {
        if (isPrime(i)) System.out.print(i + " ");
        }
        }
        static boolean isPrime(int n) {
        for (int i = 2; i <= Math.sqrt(n); i++) if (n % i == 0) return false;
        return n > 1;
        }
}
