import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        long[] city = new long[n];
        long[] dist = new long[n-1];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n-1; i++) {
            dist[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            city[i] = Integer.parseInt(st.nextToken());
        }

        long min = city[0];
        long money = city[0]*dist[0];

        for (int i = 1; i < n-1; i++) {
            if(min > city[i]) { min = city[i]; }
            money += min * dist[i];
        }

        System.out.println(money);

    }
}
