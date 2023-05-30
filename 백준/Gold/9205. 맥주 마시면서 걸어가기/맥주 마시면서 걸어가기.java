import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int n;
	
	static List<pos> list;
	static boolean[][] cango;
	
	static boolean[] visit;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		for (int tc = 0; tc < T; tc++) {
						
			n = Integer.parseInt(br.readLine());
			
			list = new ArrayList<>();
			cango = new boolean[n+2][n+2];
			visit = new boolean[n+2];
			
			for (int i = 0; i < n+2; i++) {
				st = new StringTokenizer(br.readLine(), " ");
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				
				list.add(new pos(x, y));
			}
			
			for (int i = 0; i < n+2; i++) {
				for (int j = i + 1; j < n+2; j++) {
					if (dist(list.get(i), list.get(j)) <= 1000) {cango[i][j] = true; cango[j][i] = true;}
				}
			}
			go();
		}
	}
	
	static void go() {
		
		Queue<Integer> q = new LinkedList<>();
		q.offer(0);
		visit[0] = true;
		
		while (!q.isEmpty()) {
			int now = q.poll();
			
			// 펜타포트의 리스트 번호가 N+1임
			if (now == n+1) {System.out.println("happy"); return;} 
			
			for (int i = 0; i < n+2; i++) {
				if(now == i || visit[i]) continue;
				if(cango[now][i]) {q.offer(i);	visit[i] = true;}
			}
		
		}
		
		System.out.println("sad"); return;
	}
	
	static int dist(pos a, pos b) {
		return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
	}
	
	static class pos {
		
		int x; int y;
		public pos(int x, int y) {
			super();
			this.x = x;	this.y = y;
		}
	}
}