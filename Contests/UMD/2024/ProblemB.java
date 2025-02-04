
import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class ProblemB {
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
        int[][] mat = new int[4][4];
        boolean[] contained = new boolean[17];
        ArrayList<Integer> zeroPos = new ArrayList<>();
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                mat[i][j] = sc.nextInt();
                contained[mat[i][j]] = true;
                if(mat[i][j] == 0)
                    zeroPos.add(i * 4 + j);
            }
        }
        int[][] indeces = {
            {0, 1, 2, 3},
            {0, 1, 3, 2},
            {0, 2, 1, 3},
            {0, 2, 3, 1},
            {0, 3, 1, 2},
            {0, 3, 2, 1},
            {1, 0, 2, 3},
            {1, 0, 3, 2},
            {1, 2, 0, 3},
            {1, 2, 3, 0},
            {1, 3, 0, 2},
            {1, 3, 2, 0},
            {2, 0, 1, 3},
            {2, 0, 3, 1},
            {2, 1, 0, 3},
            {2, 1, 3, 0},
            {2, 3, 0, 1},
            {2, 3, 1, 0},
            {3, 0, 1, 2},
            {3, 0, 2, 1},
            {3, 1, 0, 2},
            {3, 1, 2, 0},
            {3, 2, 0, 1},
            {3, 2, 1, 0}
        };
        ArrayList<Integer> missing = new ArrayList<>();
        for(int i = 1; i < 16; i++){
            if(!contained[i]){
                missing.add(i);
            }
        }
        int maxsum = 0;
        for(int i = 0; i < 24; i++){
            for(int j = 0; j < 4; j++){
                int pos = zeroPos.get(j);
                mat[pos / 4][pos % 4] = missing.get(indeces[i][j]);
            }
            int rsum = 0;
            for(int r = 0; r < 4; r++){
                int prod = 1;
                for(int c = 0; c < 4; c++){
                    prod *= mat[r][c];
                }
                rsum += prod;
            }
            int csum = 0;
            for(int c = 0; c < 4; c++){
                int prod = 1;
                for(int r = 0; r < 4; r++){
                    prod *= mat[r][c];
                }
                csum += prod;
            }
            maxsum = Math.max(maxsum, rsum);
            maxsum = Math.max(maxsum, csum);
        }
        System.out.println("The maximum number of coins that can be collected is: " + maxsum);
    }

    public static void main(String[] args) {
        int t = 1;
        t = sc.nextInt();
        for (int T = 0; T < t; T++) {
            solve(T + 1);
        }
    }
}
