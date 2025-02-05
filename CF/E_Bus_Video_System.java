
import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class E_Bus_Video_System {
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

    public static void solve(int num_tc) {
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        int min = 0;
        int sum = 0;
        int max = 0;
        for(int i = 0; i < n; i++){
            //dbg("a[i]", a[i]);
            sum += a[i];
            //dbg("sum", sum);
            //dbg("min", min);
            if(sum < 0){
                min -= sum;
                sum -= sum;
            }
        }
        sum = 0;
        for(int i=  0; i < n; i++){
            sum += a[i];
            max = Math.max(max, sum);
        }
        
        int ans = (k - max - min) + 1;

        System.out.println(Math.max(ans, 0));
    }
    //1

    public static void main(String[] args) {
        int t = 1;
        //t = sc.nextInt();
        for (int T = 0; T < t; T++) {
            solve(T + 1);
        }
    }
}
