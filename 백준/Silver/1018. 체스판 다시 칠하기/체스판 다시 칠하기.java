import java.io.*;
import java.util.*;
import java.lang.Math.*;

public class Main {
    static int n, m, answer, w, b;
    static String[] board;

    static String[] bw = {
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB"
    };
    static String[] wb = {
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW"
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        answer = Integer.MAX_VALUE;

        board = new String[n];

        for(int i = 0; i < n; i++) {
            board[i] = br.readLine();
        }

        for(int i = 0; i <= n-8; i++) {
            for(int j = 0; j <= m-8; j++) {
                answer = Math.min(recolor(i, j, 0, 0), answer);
            }
        }

        System.out.println(answer);
    }

    static int recolor(int y, int x, int cnt_b, int cnt_w) {

        for(int i = 0; i < 8; i++) {
            int ny = i + y;
            for(int j = 0; j < 8; j++) {
                int nx = j + x;
                if (board[ny].charAt(nx) != bw[i].charAt(j)) { cnt_b++; }
                else if (board[ny].charAt(nx) != wb[i].charAt(j)) { cnt_w++; }
            }
        }

        return Math.min(cnt_b, cnt_w);
    }
}