import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	/*
		N*N 개의 칸에 1~K 까지 K종류의 바이러스가 있다.
		1번부터 K번 순으로 상하좌우에 빈칸이 있다면 증식한다
		S초 후 X, Y에 있는 바이러스는?
		
		- 리스트 만들고 오름차순 정렬하기
		- 큐에 리스트 순으로 넣기
		- if Virus v.num == K 이면 증식 여부에 관계없이 S-- or sec ++
		- if S == 0 / sec == S 이면 return
	*/
	
	static int N, K, S, X, Y;
	static int[][] map;
	
	static List<Virus> list;
	static Queue<Virus> q;
	
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		N = Integer.parseInt(st.nextToken());	K = Integer.parseInt(st.nextToken());
		
		map = new int[N][N];
		
		list = new ArrayList<>();
		q = new LinkedList<>();
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] != 0) list.add(new Virus(map[i][j], 0, i, j));
			}
		}
		
		// 리스트 정렬
		Collections.sort(list, new Comparator<Virus>() {

			@Override
			public int compare(Virus o1, Virus o2) {
				return o1.num - o2.num;
			}
		});
		
		for (Virus v : list) {q.offer(v);}
		
		st = new StringTokenizer(br.readLine(), " ");
		S = Integer.parseInt(st.nextToken());	
		X = Integer.parseInt(st.nextToken());	Y = Integer.parseInt(st.nextToken());
		
		infect();
		
		System.out.println(map[X-1][Y-1]);
	}
	
	static void infect() {
		
		while(!q.isEmpty()) {
			Virus v = q.poll();
			
			if(v.sec == S) return;
			
			for (int i = 0; i < 4; i++) {
				int nx = v.x + dx[i];
				int ny = v.y + dy[i];
				
				if(nx < 0 || ny < 0 || N <= nx || N <= ny) continue;
				if(map[nx][ny] == 0) {
					map[nx][ny] = v.num;
					q.offer(new Virus(v.num, v.sec+1, nx, ny));
				}
			}
		}
	}
	
	static class Virus {
		int num; int sec; int x; int y;

		public Virus(int num, int sec, int x, int y) {
			super();	
			this.num = num; this.sec = sec;
			this.x = x;	this.y = y;
		}
	}
}