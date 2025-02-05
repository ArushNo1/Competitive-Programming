
import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class D_Masha_and_a_Beautiful_Tree {
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

    static int[] a;
    static int n;
    static boolean fail = false;
    static public int cost(int l, int r){
        if(fail){
            return -1;
        }
        int start = n;
        for(int i= l; i <= r; i++){
            start = Math.min(start, a[i]);
        }
        if(l + 1 == r){
            if(a[l] == start && a[r] == start + 1){
                return 0;
            }
            if(a[l] == start + 1 && a[r] == start){
                return 1;
            }
            fail = true;
            return -1;
        }
        int mid = start + (r - l) / 2;
        int midind = l + (r - l) / 2;
        int sum = 0;
        for(int i = l; i <= r; i++){
            boolean shouldFlip = (a[i] > mid) == (i > midind);
            if(shouldFlip){
                sum++;
            }
            else{
                sum--;
            }
        }
        //dbg("mid, l, r", mid + " " + l + " " + r);
        if(Math.abs(sum) != (r - l + 1)){
            fail = true;
            return -1;
        }
        int left = cost(l, midind);
        int right = cost(midind + 1, r);
        if(fail) return -1;
        //dbg("l, r, sum" , l + " " + r + " " + sum);
        return left + right + (sum > 0 ? 0 : 1);
    }

    public static void solve(int num_tc) {
        n = sc.nextInt();
        a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
            a[i]--;
        }
        if(n == 1){
            System.out.println(0);
            return;
        }
        int ans = cost(0, n - 1);
        a = null;
        fail = false;
        System.out.println(ans);
    }

    public static void main(String[] args) {
        int t = 1;
        t = sc.nextInt();
        for (int T = 0; T < t; T++) {
            solve(T + 1);
        }
    }
}
