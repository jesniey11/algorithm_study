import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M, max;
	static int[][] map, copymap;
	
	static boolean[][] visit;
	
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		max = 0;
		
		map = new int[N][M];
		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			for (int j = 0; j < M; j++) {if(str.charAt(j) == 'L') {map[i][j] = 1;}}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if(map[i][j] != 0) {TresureFinder(i, j);}
			}
		}
		
		System.out.println(max - 1);
	}
	
	static void TresureFinder(int x, int y) {
		
		visit = new boolean[N][M];
		copymap = new int[N][M];
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {copymap[i][j] = map[i][j];}
		}
		
		Queue<pos> q = new LinkedList<>();
		q.offer(new pos(x, y));
		visit[x][y] = true;
		
		while(!q.isEmpty()) {
			pos now = q.poll();
			
			for (int i = 0; i < 4; i++) {
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				
				if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny]) continue;
				if (copymap[nx][ny] != 0) {
					q.offer(new pos(nx, ny)); visit[nx][ny] = true;
					copymap[nx][ny] += copymap[now.x][now.y];
					max = Math.max(max, copymap[nx][ny]);
				}
			}
		}
		
//		// test print
//		System.out.println("x : " + x + " | y : " + y);
//		System.out.println("------------- map -------------");
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < M; j++) {
//				System.out.print(copymap[i][j] + " ");
//			}
//			System.out.println();
//		} System.out.println();
//		// test print end
	}
	
	static class pos {
		int x; int y;
		public pos(int x, int y) {
			super();
			this.x = x;	this.y = y;
		}
	}
}