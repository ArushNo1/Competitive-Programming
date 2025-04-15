
import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class B_MIN_GCD {
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
                if (s != null && s.hasMoreTokens()) {
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

    public static FastReader sc = new FastReader();
    public static StringBuilder out = new StringBuilder();
    public static DecimalFormat round = new DecimalFormat("#.00");
    public static double EPS = 1e-6;
    public static int MOD = (int) (1e9 + 7);
    public static int[] dx = {0, 0, 1, -1};
    public static int[] dy = {1, -1, 0, 0};

    public static void dbg(String varName, Object value) {
        int lineNumber = Thread.currentThread().getStackTrace()[2].getLineNumber();
        System.err.println(lineNumber + ": " + varName + " = " + value);
    }
    public static void dbg(String varName, Object[] arr){
        int lineNumber = Thread.currentThread().getStackTrace()[2].getLineNumber();
        System.err.println(lineNumber + ": " + varName + " = " + Arrays.toString(arr));
    }


    static long gcd(long x, long y) {
        if (y == 0) {
            return x;
        }
        return gcd(y, x % y);
    }

    public static void solve(int num_tc) {
        int n = sc.nextInt();
        long[] arr = new long[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextLong();
        }
        Arrays.sort(arr);
        if(arr[1] == arr[0]){
            out.append("Yes\n");
            return;
        }
        long g = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] % arr[0] != 0){
                continue;
            }
            if(g == 0){
                g = arr[i];
            } else {
                g = gcd(g, arr[i]);
            }
        }
        out.append(g != arr[0] ? "No\n" : "Yes\n");
    }

    public static void main(String[] args) {
        int t = 1;
        t = sc.nextInt();
        for (int T = 0; T < t; T++) {
            solve(T + 1);
        }
        System.out.println(out.toString());
    }
}
