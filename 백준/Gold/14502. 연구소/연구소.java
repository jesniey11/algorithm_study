import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M, ans;
	static int[][] map, copymap;
	
	static Queue<Virus> q;
	
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		ans = 0; 
		
		map = new int[N][M];
		q = new LinkedList<>();
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		wall(0);
		
		System.out.println(ans);
	}
	
	static void wall(int depth) {
		
		if(depth == 3) {virus(); return;}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) {
					map[i][j] = 1; wall(depth+1);
					map[i][j] = 0;
				}
			}
		}
	}
	
	static void virus() {
		
		copymap = new int[N][M];
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copymap[i][j] = map[i][j];
				if (copymap[i][j] == 2) {q.offer(new Virus(i, j));}
			}
		}
		
		while (!q.isEmpty()) {
			Virus v = q.poll();
			
			for (int i = 0; i < 4; i++) {
				int nx = v.x + dx[i];
				int ny = v.y + dy[i];
				
				if (nx < 0 || ny < 0 || N <= nx || M <= ny) continue;
				if (copymap[nx][ny] == 0) {
					copymap[nx][ny] = 2;
					q.offer(new Virus(nx, ny));
				}
			}
		}
		
		int cnt = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {if (copymap[i][j] == 0) cnt++;}
		}
		
		ans = Math.max(ans, cnt);
	}

	static class Virus {
		
		int x; int y;
		
		public Virus(int x, int y) {
			super();
			this.x = x;	this.y = y;
		}
		
	}
}