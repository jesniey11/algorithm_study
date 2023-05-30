import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M;
	static int[] ladsnake, cnt;
	
	static boolean[] visit;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		ladsnake = new int[1001];
		for (int i = 0; i < N+M; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			ladsnake[x] = y;
		}
		
		visit = new boolean[101];
		cnt = new int[101];
		move(1);
	}
	
	static void move(int n) {
		Queue<Integer> q = new LinkedList<>();
		q.offer(n);
		visit[n] = true;
		cnt[n] = 0;
		
		while (!q.isEmpty()) {
			int t = q.poll();
			if (t == 100) {System.out.println(cnt[t]); return;}
			
			for (int i = 1; i <= 6; i++) {

				if (t+i > 100) continue;
				if (visit[t+i]) continue;
				
				visit[t+i] = true;
				
				if(ladsnake[t+i] != 0) {
					if(!visit[ladsnake[t+i]]) {
						q.offer(ladsnake[t+i]);
						visit[ladsnake[t+i]] = true; 
						cnt[ladsnake[t+i]] = cnt[t] + 1;
					}
				}
				else {q.offer(t+i); cnt[t+i] = cnt[t] + 1;}
			}
		}
	}
}