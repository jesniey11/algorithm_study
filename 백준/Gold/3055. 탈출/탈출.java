import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int R, C, ans;
	static char[][] map;
	
	// 고슴도치, 물
	static Queue<pos> dochi = new LinkedList<>();
	static Queue<pos> water = new LinkedList<>();
	
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		R = Integer.parseInt(st.nextToken()); C = Integer.parseInt(st.nextToken());
		map = new char[R][C];
		
		ans = Integer.MAX_VALUE;
		
		for (int r = 0; r < R; r++) {
			String str = br.readLine();
			map[r] = str.toCharArray();
			for (int c = 0; c < C; c++) {
				if(map[r][c] == 'S') {dochi.offer(new pos(r, c, 0));}
				if(map[r][c] == '*') {water.offer(new pos(r, c, 0));}
			}
		}
		
		flood();
		if(ans == Integer.MAX_VALUE) {System.out.println("KAKTUS");}
		else System.out.println(ans);
		
	}
	
	static void flood() {
		
		// 이동 기준 = 도치
		while(!dochi.isEmpty()) {
			
			int ws = water.size();
			
			for (int i = 0; i < ws; i++) {
				pos w = water.poll();
				
				for (int j = 0; j < 4; j++) {
					int nx = w.x + dx[j];
					int ny = w.y + dy[j];
					
					if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
					if(map[nx][ny] == '.' ) {map[nx][ny] = '*'; water.offer(new pos(nx, ny, 0));}
				}
				
			}
			
			int ds = dochi.size();
			
			for (int i = 0; i < ds; i++) {
				pos d = dochi.poll();
				for (int j = 0; j < 4; j++) {
					int nx = d.x + dx[j];
					int ny = d.y + dy[j];
					int nt = d.t + 1;
					
					if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
					
					if(map[nx][ny] == 'D') {ans = Math.min(ans, nt); return;} 
					if(map[nx][ny] == '.') {map[nx][ny] = 'S';	dochi.offer(new pos(nx, ny, nt));}
				}
			
			}
			
			
		}
		
	}
	
	static class pos {
		int x; int y; int t;
		public pos(int x, int y, int t) {
			super();	
			this.x = x;	this.y = y; this.t = t;
		}
	}
	
}