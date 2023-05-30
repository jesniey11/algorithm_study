import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		int N = Integer.parseInt(br.readLine());
		
		st = new StringTokenizer(br.readLine(), " ");
		Stack<int[]> stack = new Stack<>();		
		
		for (int i = 1; i <= N; i++) {
			
			int height = Integer.parseInt(st.nextToken());
			
			while (!stack.isEmpty()) {
				if(stack.peek()[1] < height) {stack.pop();}
				else {bw.write(stack.peek()[0] + " ");	break;}
			}
			
			if (stack.isEmpty()) {bw.write("0 ");}
			
			stack.push(new int[] {i, height});			
		}
		
		bw.close();
	}
}