import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int R, C, time, cnt, cheese;
	static int[][] map;

	static boolean[][] visit;	
	
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, 1, -1};	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		cheese = 0; time = 0;
		R = Integer.parseInt(st.nextToken());	C = Integer.parseInt(st.nextToken());
		map = new int[R][C];
		
		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < C; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] == 1) {cheese++;}
			}
		}
		
		while(true) {
			
			if(cheese == 0) break;

			marking();
			
			time++;	
			cnt = cheese;
			melt();
		}
		
		System.out.print(time + "\n" + cnt);
	}
	
	static void marking() {
		
		Queue<pos> q = new LinkedList<>();
		visit = new boolean[R][C];
		q.offer(new pos(0, 0));
		visit[0][0] = true;
		
		while (!q.isEmpty()) {
			pos n = q.poll();
			
			for (int i = 0; i < 4; i++) {
				int nx = n.x + dx[i];
				int ny = n.y + dy[i];
				
				if (nx < 0 || ny < 0 || R <= nx || C <= ny || visit[nx][ny]) continue;
				if (map[nx][ny] == 1) {map[nx][ny] = 7;}
				else if (map[nx][ny] == 0) {visit[nx][ny] = true; q.offer(new pos(nx, ny));}								
			}
		}
	}
	
	static void melt() {
		
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {if (map[i][j] == 7) {map[i][j] = 0; cheese--;}}
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