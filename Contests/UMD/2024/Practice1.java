import java.text.DecimalFormat;
import java.util.*;

public class Problem1 {
    public static Scanner sc = new Scanner(System.in);
    public static DecimalFormat round = new DecimalFormat("#.00");
    public static double EPS = 1e-6;
    public static int MOD = (int) (1e9 + 7);
    public static int[] dx = {0, 0, 1, -1};
    public static int[] dy = {1, -1, 0, 0};

    public static void dbg(String varName, Object value) {
        int lineNumber = Thread.currentThread().getStackTrace()[2].getLineNumber();
        System.err.println(lineNumber + ": " + varName + " = " + value);
    }

    public static void solve(int num_tc){
        String a = sc.next();
        String b = sc.next();
        HashMap<Character, Integer> map = new HashMap<>();
        for(char c : a.toCharArray()){
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        for(char c : b.toCharArray()){
            if(map.containsKey(c) && map.get(c) > 0){
                map.put(c, map.get(c) - 1);
            }
            else{
                System.out.println("No");
                return;
            }
        }
        for (Map.Entry<Character, Integer> en : map.entrySet()) {
            Integer val = en.getValue();
            if(val != 0){
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
    public static void main(String[] args) {
        int t = 1;
        t = sc.nextInt();
        for(int T = 0; T < t; T++){
            solve(T + 1);
        }
    }
}
