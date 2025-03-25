
import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class A_Circle_of_Students {
    static class FastReader {
        BufferedReader b;
        StringTokenizer s;
        public FastReader() {
            b = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while (s == null || !s.hasMoreElements()) {
                try {
                    s = new StringTokenizer(b.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return s.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine() {
            String str = "";
            try {
                if (s.hasMoreTokens()) {
                    str = s.nextToken("\n");
                } else {
                    str = b.readLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

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
    public static void dbg(String varName, Object[] value) {
        int lineNumber = Thread.currentThread().getStackTrace()[2].getLineNumber();
        System.err.println(lineNumber + ": " + varName + " = " + Arrays.toString(value));
    }

    public static void solve(int num_tc) {
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        
        boolean fail = false;
        for(int i = 1; i < n; i++){
            if(a[i] == a[i - 1] + 1 || a[i] == 1 && a[i - 1] == n){
                continue;
            }
            fail = true;
            break;
        }
        if(!fail){
            System.out.println("YES");
            return;
        }
        fail = false;
        for(int i = n - 2; i >= 0; i--){
            if(a[i] == a[i + 1] + 1 || a[i] == 1 && a[i + 1] == n){
                continue;
            }
            fail = true;
            break;
        }
        if(!fail){
            System.out.println("YES");
            return;
        }
        System.out.println("NO");


        Scanner sc = new Scanner(System.in);
    }

    public static void main(String[] args) {
        int t = 1;
        t = sc.nextInt();
        for (int T = 0; T < t; T++) {
            solve(T + 1);
        }
    }
}
