import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M, T, stp, kts, ktp, sx, sy;
	static int[][] map, copymap;
	static boolean[][] visit;
	
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());
		
		map = new int[N][M];
		sx = 0; sy = 0;
		kts = 10001; ktp = 10001;
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] == 2) {sx = i; sy = j;    stp = Math.abs((N-1) - i) + Math.abs((M-1) - j);}
			}
		}
		
		KtoS();		
		KtoP();
        
		int ans = Math.min(ktp, kts+stp);
		
		if(ans <= T) {System.out.println(ans);}
		else System.out.println("Fail");
	}
	
	    // 기사 to 칼
		static void KtoS() {
			
			copymap = new int[N][M];
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {copymap[i][j] = map[i][j];}
			}
			
			visit = new boolean[N][M];
			Queue<pos> q = new LinkedList<>();
			q.offer(new pos(0, 0));
			visit[0][0] = true;
			
			while(!q.isEmpty()) {
				pos now = q.poll();
				
				if(now.x == sx && now.y == sy) {kts = (copymap[now.x][now.y] -2) * -1; return;}
				
				for (int i = 0; i < 4; i++) {
					int nx = now.x + dx[i];
					int ny = now.y + dy[i];

					if(nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny]) continue;
					if(copymap[nx][ny] != 1) {
						q.offer(new pos(nx, ny)); visit[nx][ny] = true;
						copymap[nx][ny] += copymap[now.x][now.y] - 1;
					}
				}
			}
		}
		
	
	// 기사 to 공주
	static void KtoP() {
		
		copymap = new int[N][M];
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {copymap[i][j] = map[i][j];}
		}
		
		visit = new boolean[N][M];
		Queue<pos> q = new LinkedList<>();
		q.offer(new pos(0, 0));
		visit[0][0] = true;
		
		while(!q.isEmpty()) {
			pos now = q.poll();
			
			if(now.x == N-1 && now.y == M-1) {ktp = copymap[now.x][now.y] * -1; return;}
			
			for (int i = 0; i < 4; i++) {
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];

				if(nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny]) continue;
				if(copymap[nx][ny] == 0) {
					q.offer(new pos(nx, ny)); visit[nx][ny] = true;
					copymap[nx][ny] += copymap[now.x][now.y] - 1;
				}
			}
		}
		
	}
	
	static class pos {
		int x; int y;

		public pos(int x, int y) {
			super();
			this.x = x;	this.y = y;
		}
	}
}