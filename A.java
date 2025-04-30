 class A {
    void show()
 {
 System.out.println("Class A method");
 }
}
class B extends A {
 public static void main(String[] args) {
 B obj = new B();
 obj.show();
 }
}
