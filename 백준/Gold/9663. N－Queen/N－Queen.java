import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, ans;
    static int[] board;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        ans = 0; //경우의 수
        board = new int[n];

        queen(0);

        System.out.println(ans);
    }

    static void queen(int idx) {

        if(idx == n) { ans++; return; }

        for(int i = 0; i < n; i++) {
            board[idx] = i; // i행, idx열에 배치
            if(checkmate(idx)) {queen(idx+1);}
        }
    }

    static boolean checkmate(int idx) {
        for(int i = 0; i < idx; i++) {
            if(board[idx] == board[i] || Math.abs(board[idx] - board[i]) == Math.abs(idx - i)) { return false; }
        }
        return true;
    }

}
