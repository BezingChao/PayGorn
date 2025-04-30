 class ConstructorExample {
    int x;
    ConstructorExample() {
    x = 10;
    }
    ConstructorExample(int a) {
    x = a;
    }
    ConstructorExample(ConstructorExample c) {
    x = c.x;
    }
    public static void main(String[] args) {
    ConstructorExample obj1 = new ConstructorExample();
    ConstructorExample obj2 = new ConstructorExample(20);
    ConstructorExample obj3 = new ConstructorExample(obj2);
    System.out.println(obj1.x + ", " + obj2.x + ", " + obj3.x);
    }
}
