 class Overloading {
    void display(int a) {
        System.out.println(a); }
        void display(String s) {
        System.out.println(s); }
        public static void main(String[] args) {
        Overloading obj = new Overloading();
        obj.display(10);
        obj.display("Hello");
        }
}
