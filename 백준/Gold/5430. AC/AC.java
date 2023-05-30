import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
	
	static char[] command;
	static int num;
	static Deque<Integer> q;
	
	static boolean isLIFO;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < T; i++) {
						
			command = (br.readLine()).toCharArray();
			num = Integer.parseInt(br.readLine());
			
			st = new StringTokenizer(br.readLine(), "[],");
			q = new ArrayDeque<Integer>();
			
			for (int j = 0; j < num; j++) {
				int n = Integer.parseInt(st.nextToken());
				q.offer(n);
			}
			
			isLIFO = false;
			
			RD();
			
		}
	}
	
	static void RD () throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		for (int i = 0; i < command.length; i++) {
			
			// 명령어 'R' 입력시 - isLIFO 스위칭
			if (command[i] == 'R') {
				if (isLIFO) {isLIFO = false;}
				else isLIFO = true;
			}
			
			// 명령어 'D' 입력시
			else {
				// 큐가 비었으면 error 출력
				if (q.isEmpty()) { bw.write("error" + "\n"); bw.flush(); return; }
				// 안 비었으면 isLIFO 상태에 따라 true:뒤부터 / false:앞부터 poll
				else {
					if (isLIFO) {q.pollLast();}
					else q.pollFirst();
				}
			}
		}
		
		int qs = q.size();
		
		// 큐 원소의 개수가 0개 이상이면 출력 - 이 조건은 이미 56행에서 처리됨
		bw.write("[");
		for (int i = 0; i < qs; i++) {
			
			// 뒤부터 출력해야 함
			if (isLIFO) { bw.write(q.pollLast() + ""); }
			else bw.write(q.pollFirst() + "");
			
			// 마지막 출력 빼고는 "," 붙여준다
			if(!(i == qs-1)) bw.write(",");
		}
		bw.write("]" + "\n");
		bw.flush();
	}
}