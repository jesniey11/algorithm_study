import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, k, time, num;
    static int[] field = new int[100001];

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        time = Integer.MAX_VALUE;
        num = 0;

        if(n != k) {BFS();}
        else {time = 0; num = 1;}

        System.out.println(time + "\n" + num);
    }

    static void BFS() {
        Queue<Integer> q = new LinkedList<>();
        q.offer(n);
        field[n] = 1;

        while (!q.isEmpty()) {

            int x = q.poll();
            if(time < field[x]) { return; }

            for(int i = 0; i < 3; i++) {
                int nx;
                if(i == 0) { nx = x-1; }
                else if(i == 1) { nx = x+1; }
                else { nx = x*2; }

                if(nx < 0 || 100000 < nx) continue;

                if(nx == k) {
                    time = field[x];
                    num++;
                }

                if(field[nx] == 0 || field[nx] >= field[x]+1) {
                    field[nx] = field[x] + 1;
                    q.offer(nx);
                }
            }
        }
    }
}