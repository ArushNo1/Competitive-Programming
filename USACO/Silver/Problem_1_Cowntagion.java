
import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class Problem_1_Cowntagion {
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

    public static FastReader sc = new FastReader();
    public static DecimalFormat round = new DecimalFormat("#.00");
    public static double EPS = 1e-6;
    public static int MOD = (int) (1e9 + 7);
    public static int[] dx = {0, 0, 1, -1};
    public static int[] dy = {1, -1, 0, 0};

    public static void dbg(String varName, Object value) {
        int lineNumber = Thread.currentThread().getStackTrace()[2].getLineNumber();
        System.err.println(lineNumber + ": " + varName + " = " + value);
    }

    static ArrayList<Integer>[] adj;
    static long ops = 0;
    static void dfs(int u, int p){
        if(adj[u].size() == 1 && p != -1){
            return;
        }
        //dbg("u", u);
        long numdoubles = 64 - Long.numberOfLeadingZeros(adj[u].size() - (p == -1 ? 0 : 1));
        //dbg("adj[u].size()", adj[u].size());
        //dbg("doubling", numdoubles);
        
        
        ops += numdoubles;
        for(int v : adj[u]){
            if(v == p) continue;
            ops++;
            //dbg("sending to", v);
            dfs(v, u);
        }
    }

    public static void solve(int num_tc) {
        long n = sc.nextInt();
        adj = new ArrayList[(int)n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i ++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj[u - 1].add(v - 1);
            adj[v - 1].add(u - 1);
        }
        dfs(0, -1);
        System.out.println(ops);
    }

    public static void main(String[] args) {
        int t = 1;
        //t = sc.nextInt();
        for (int T = 0; T < t; T++) {
            solve(T + 1);
        }
    }
}
