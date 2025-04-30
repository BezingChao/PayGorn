 class Student {
    String name; int rollNo, age;
 Student(String n, int r, int a) { name = n; rollNo = r; age = a; }
 void display() { System.out.println(name + " " + rollNo + " " + age); }
}
public class StudentDetails {
 public static void main(String[] args) { Student s = new Student("Alice", 101, 20);
s.display(); }
}
