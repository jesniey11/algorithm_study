import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int[] city = new int[n];
        int[] distance = new int[n-1];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n-1; i++) {
            distance[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            city[i] = Integer.parseInt(st.nextToken());
        }

        int fuel = 0;
        int money = 0;

        for (int i = 0; i < n-1; i++) {
            if(fuel < distance[i]) {
                // 지금 도시의 기름값이 다음 도시보다 비싸거나 다음 도시가 마지막 도시라면 최소한만 구매
                if(city[i] > city[i+1] || i+1 <= n-1) { fuel += distance[i]; }
                // 아니라면 다음 도시것까지 구매
                else { fuel += distance[i]+distance[i+1]; }
                money += city[i]*(fuel);
            }

            fuel = fuel - distance[i];
        }

        System.out.println(money);

    }
}