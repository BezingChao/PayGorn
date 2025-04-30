abstract class AbstractExample {
    abstract void show();
}
class Concrete extends AbstractExample {
 void show()
{
 System.out.println("Abstract method implemented");
}
 public static void main(String[] args) {
 Concrete obj = new Concrete();
 obj.show();
 }
}
