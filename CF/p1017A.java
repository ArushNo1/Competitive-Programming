
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class p1017A {
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int n = sc.nextInt();
        ArrayList<Student> students = new ArrayList<Student>();
        for(int i = 0; i < n; i++){
            int score = sc.nextInt();
            score += sc.nextInt();
            score += sc.nextInt();
            score += sc.nextInt();
            students.add(new Student(i + 1, score));
        }
        Collections.sort(students);
        for(int i = 0; i < n; i++){
            if(students.get(i).id == 1){
                System.out.println(i + 1);
                break;
            }
        }
    }

    static class Student implements Comparable<Student> {
        int id;
        int score;
        public Student(int id, int score) {
            this.id = id;
            this.score = score;
        }
        public int compareTo(Student o) {
            if(o.score != this.score) return o.score - this.score;
            return this.id - o.id;
        }
    }
}