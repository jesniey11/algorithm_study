import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M, sum;
	
	static int[] dx = {0, -1, -1, -1, 0, 1, 1, 1};
	static int[] dy = {-1, -1, 0, 1, 1, 1, 0, -1};
	
	static int[][] map, move;
	static boolean[][] visit;
	
	static Queue<pos> cloud = new LinkedList<>();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		// N : 맵 크기, M : 이동 수
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		sum = 0;
		
		map = new int[N][N];
		move = new int[M][2];
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < N; j++) {map[i][j] = Integer.parseInt(st.nextToken());}
		}
	
		
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			
			// [i][0] : 방향 [i][1] : 거리
			move[i][0] = Integer.parseInt(st.nextToken()) - 1;
			move[i][1] = Integer.parseInt(st.nextToken());
		}
		
		//리스트 초기값 - 큐 두개 써야하나? 진짜? 
		cloud.offer(new pos(N-2, 0)); cloud.offer(new pos(N-2, 1));
		cloud.offer(new pos(N-1, 0)); cloud.offer(new pos(N-1, 1));
		
		for (int i = 0; i < M; i++) {
			
			int dir = move[i][0];
			int dist = move[i][1];
			
			visit = new boolean[N][N];
			
			Cloud(i, dir, dist);
			
			/*// test print
			System.out.println("-----"+ i + " After Cloud" +"-----");
			for (int n = 0; n < N; n++) {
				for (int m = 0; m < N; m++) {
					System.out.print(map[n][m] + " ");
				} System.out.println();
			}*/
			
			Copy();
			
			/*// test print
			System.out.println("-----"+ i + " After Copy" +"-----");
			for (int n = 0; n < N; n++) {
				for (int m = 0; m < N; m++) {
					System.out.print(map[n][m] + " ");
				} System.out.println();
			}*/
			
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++) {
					if(map[a][b] >= 2 && !visit[a][b]) {map[a][b] -= 2; cloud.offer(new pos(a, b));}
				}
			}
			
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {sum += map[i][j];}
		}
		
		bw.write(sum + "");
		bw.close();
	}
	
	// 왜 기존값이 증가하지?????
	// 이러면 while 탈출 못해!! 구름 수를 세서 for 넣어야 함!!
	// list에 넣고 move하고 물복사 하고 list clear
	static void Cloud(int num, int dir, int dist) {
		
		// 구름 있는 칸 수 만큼
		for (int i = 0; i < cloud.size(); i++) {
			
			pos now = cloud.poll();
			
			int nx = now.x + (dx[dir] * dist);
			int ny = now.y + (dy[dir] * dist);
			
			while(!isinBound(nx) || !isinBound(ny)) {
				if(!isinBound(nx)) nx = intoBound(nx);	
				if(!isinBound(ny)) ny = intoBound(ny);
			}
		
			cloud.offer(new pos(nx, ny));
			map[nx][ny]++;
			visit[nx][ny] = true;
		}
	}
	
	static void Copy() {
		
		while(!cloud.isEmpty()) {
			pos now = cloud.poll();
			int cnt = 0;
			
			for (int i = 0; i < 8; i++) {
				if(i % 2 == 0) continue;
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (map[nx][ny] != 0) cnt++;
			}
			
			map[now.x][now.y] += cnt;			
		}
		
	}
	
	static boolean isinBound(int xy) {
		
		if(xy < 0 || xy >= N) return false;
		return true;
	}
	
	static int intoBound(int xy) {
		
		if(xy < 0) {return xy + N;}
		else return xy - N;
		
	}
	
	
	static class pos {
		
		int x, y;
		
		public pos(int x, int y) {
			
			super();
			this.x = x;		this.y = y;
		}
	}
}