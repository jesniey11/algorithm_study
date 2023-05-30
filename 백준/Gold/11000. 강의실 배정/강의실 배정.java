import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());
		
		int[][] lecture = new int[N][2];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			lecture[i][0] = Integer.parseInt(st.nextToken());	//start time
			lecture[i][1] = Integer.parseInt(st.nextToken());	//end time
		}
		
		Arrays.sort(lecture, new Comparator<int[]>() {

			@Override
			public int compare(int[] o1, int[] o2) {
				if(o1[0] == o2[0]) return o1[1] - o2[1];
				return o1[0] - o2[0];
			}
			
		});
		
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		pq.offer(lecture[0][1]);
		
		for (int i = 1; i < N; i++) {
			if(pq.peek() <= lecture[i][0]) {pq.poll();}
			pq.offer(lecture[i][1]);
		}
		
		System.out.println(pq.size());
	}
}