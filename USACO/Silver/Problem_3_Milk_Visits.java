
import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class Problem_3_Milk_Visits {
    static class FastReader {
        BufferedReader b;
        StringTokenizer s;
        public FastReader() {
            try {
                b = new BufferedReader(new InputStreamReader(new FileInputStream("milkvisits.in")));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
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
    static List<Integer> CC;
    static String breed;
    static void dfs(int node, int parent) {
        CC.add(node);
        for(int nb : adj[node]){
            if(nb != parent && breed.charAt(nb) == breed.charAt(node)){
                dfs(nb, node);
            }
        }
    }

    public static void solve(int num_tc) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        breed = sc.nextLine();
        adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i ++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj[u - 1].add(v - 1);
            adj[v - 1].add(u - 1);
        }
        StringBuilder out = new StringBuilder();
        int[] component = new int[m];
        int id = 1;
        for(int i = 0; i < n ;i++){
            if(component[i] != 0){
                continue;
            }
            CC = new ArrayList<>();
            dfs(i, -1);
            for(int c : CC){
                component[c] = id;
            }
            id++;
        }
        //System.out.println(Arrays.toString(component));


        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            char c = sc.next().charAt(0);
            a--;
            b--;
            if(breed.charAt(a) == c || breed.charAt(b) == c){
                out.append("1");
                continue;
            }
            if(component[a] != component[b]){
                out.append("1");
                continue;
            }
            out.append("0");
        }
        try {
            BufferedWriter bw = new BufferedWriter(new FileWriter("milkvisits.out"));
            bw.write(out.toString());
            bw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        int t = 1;
        //t = sc.nextInt();
        for (int T = 0; T < t; T++) {
            solve(T + 1);
        }
    }
}
