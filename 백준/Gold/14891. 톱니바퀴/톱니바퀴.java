import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static boolean[] canRotate, visit;
	static int[][] gear;
	static int[] order;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		// 자석 정보 배열
		// 자석 번호, 자성(N = 0, S = 1)
		gear = new int[4][8];
		for (int i = 0; i < 4; i++) {
			String str = br.readLine();
			for (int j = 0; j < 8; j++) {gear[i][j] = (int) str.charAt(j) - '0';}
		}
		
        // 회전 수
		int K = Integer.parseInt(br.readLine());
        
		// 회전 명령
		// N번 기어를 시계(1) / 반시계(-1) 방향으로 돌려라
		for (int i = 0; i < K; i++) {
				
			canRotate = new boolean[4];
			visit = new boolean[4];
			order = new int[4];
				
			st = new StringTokenizer(br.readLine());
			int gnum = Integer.parseInt(st.nextToken()) - 1;
			order[gnum] = Integer.parseInt(st.nextToken());
				
			canRotate[gnum] = true;
			RTcheck(gnum, order[gnum]);
	
			for (int j = 0; j < 4; j++) {
				if (canRotate[j]) {gear[j] = Rotate(j, order[j]);}
			}
		}
			
		int sum = 0;
			
		for (int i = 0; i < 4; i++) {
		    if(gear[i][0] == 1) {sum += Math.pow(2, i);}
		}
			
		System.out.println(sum);
		
	}
	
	static void RTcheck(int x, int d) {
		
		// 굳이 visit가 전부 true일 필요는 없음!!
		visit[x] = true;
		
		// 아직 방문하지 않은 자석 중
		if (x+1 < 4 && !visit[x+1]) {
			if (gear[x][2] != gear[x+1][6]) {
				
				canRotate[x+1] = true;
				order[x+1] = -1*d; 
				RTcheck(x+1, order[x+1]);
			}
		}
		
		if (0 <= x-1 && !visit[x-1]) {
			if (gear[x][6] != gear[x-1][2]) {
				
				canRotate[x-1] = true; 
				order[x-1] = -1*d; 
				RTcheck(x-1, order[x-1]);
			}
		} 
		
		return;
	}
	
	// 받아오는 인자는 현재 돌릴 자석의 인자여야 함
	static int[] Rotate(int x, int d) {
	
		int[] newgear = new int[8];
		
		// 시계방향 회전
		if (d == 1) {
			
			for (int i = 0; i < 8; i++) {
				
				if(i == 0) {newgear[i] = gear[x][7];}
				else newgear[i] = gear[x][i-1];
			}
		}
		
		// 반시계방향 회전
		if (d == -1) {
			
			for (int i = 0; i < 8; i++) {
				
				if(i == 7) {newgear[i] = gear[x][0];}
				else newgear[i] = gear[x][i+1];
			}
		}
		return newgear;
	}
}