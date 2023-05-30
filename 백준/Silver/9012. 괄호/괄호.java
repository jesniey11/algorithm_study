import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		for (int t = 0; t < T; t++) {
			String str = br.readLine();
			char[] bracket = str.toCharArray();
			boolean isYes = false;
			
			Stack<Character> stack = new Stack<>();
			List<Character> list = new ArrayList<>();
			
			for (int i = 0; i < bracket.length; i++) {
				if (bracket[i] == '(') {stack.push(bracket[i]);}
				else if (bracket[i] == ')' && !stack.isEmpty()) {stack.pop();}
				else {list.add((bracket[i]));}
			}
			
			if (stack.isEmpty() && list.isEmpty()) {isYes = true;}
			
			if(isYes) System.out.println("YES");
			else System.out.println("NO");
		}
	}
}