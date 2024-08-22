import java.util.*;

public class D_Alien_Interpreter{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] arr = sc.nextLine().split("-");
        sc.close();

        String output = "";
        String current = "";
        for(String s : arr){
            if (s.equals("org")){
                output += current + " ";
                current = "";
            } else if(s.contains("org")){
                output += s.charAt(0);
                output += current + " ";
                current = "";
            }
            else {
                current = s;
            }
        }
        System.out.println(output);

    }

}