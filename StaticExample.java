 class StaticExample {
    static int count = 0;
 static void displayCount() {
 System.out.println("Count: " + count);
 }
 public static void main(String[] args) {
 count++;
 displayCount();
 }

}
