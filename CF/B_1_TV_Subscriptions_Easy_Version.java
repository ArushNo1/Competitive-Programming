
import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class B_1_TV_Subscriptions_Easy_Version {
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
        int d = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        
        int numunique = 0;
        int minuniquq = Integer.MAX_VALUE;
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < d; i++){
            map.put(a[i], map.getOrDefault(a[i], 0) + 1);
            if(map.get(a[i]) == 1){
                numunique++;
            }
        }
        minuniquq = numunique;
        if(numunique == 1){
            System.out.println(1);
            return;
        }
        for(int i = d; i < n; i++){
            if(map.getOrDefault(a[i], 0) == 0){
                numunique++;
            }
            map.put(a[i], map.getOrDefault(a[i], 0) + 1);
            if(map.get(a[i - d]) == 1){
                numunique--;
            }
            map.put(a[i - d], map.get(a[i - d]) - 1);
            minuniquq = Math.min(minuniquq, numunique);
        }
        System.out.println(minuniquq);
    }

    public static void main(String[] args) {
        int t = 1;
        t = sc.nextInt();
        for (int T = 0; T < t; T++) {
            solve(T + 1);
        }
    }
}
