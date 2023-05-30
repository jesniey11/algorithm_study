import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static boolean[][] graph;
	static boolean[] visited;
	static int N, M, V;
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	
	public static void main(String[] args) throws IOException {
		
		st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken());
		
		//간선 연결 정보를 2차원 배열로 저장.
		//범위가 N+1인 이유는  노드번호와 통일하기 위해-노드를 0번부터 세지는 않으므로-서이다.
		graph = new boolean[N+1][N+1];
		
		//양방향이므로 graph[a][b] 와 [b][a]를 모두 한다
		//for문의 범위는 입력 범위와 일치한다
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			graph[a][b] = true;
			graph[b][a] = true;
		}
		
		visited = new boolean[N+1];
		DFS(V);
		
        bw.write("\n");
        
		visited = new boolean[N+1];
		BFS(V);
		
		bw.close();
	}
	
	public static void DFS(int v) throws IOException {
		
		//기본값 - 재귀하면 기본 세팅이다
		//방문한 노드를 true로 바꾸고 노드 번호를 출력한다
		visited[v] = true;
		bw.write(v + " ");
		
		//마지막 노드라면 return
		if(v == N+1) {return;}
		
		//graph[v][i] true 는 v번 노드와 i번 노드가 연결되어있다는 의미
		//visted[i] false 는 i 노드가 아직 미방문한 노드라는 의미
		//조건을 충족한다면 재귀
		for (int i = 1; i <= N; i++) {
			if (graph[v][i] && !visited[i]) {
				DFS(i);
			}
		}
	}
	
	public static void BFS(int v) throws IOException {
		
		//DFS는 스택 BFS는 큐 그러나 DFS는 재귀로 푸는 편
		//큐에 첫 노드 번호를 넣는다 - 재귀가 아니라서 첫 값만 여기다!!
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(v);
		
		//첫 노드를 방문한 노드로 바꾸고 출력
		visited[v] = true;
		bw.write(v + " ");
		
		//while 문의 조건 때문에 첫 노드 처리가 필요
		while(!q.isEmpty()) {
			//방금 방문한 노드를 큐에서 꺼내준다
			int tmp = q.poll();
			
			//두번째 방문 노드부터 마지막 노드까지, 첫 노드에 실행했던 것을 반복한다.
			for (int i = 1; i <= N; i++) {
				
				if (graph[tmp][i] && !visited[i]) {	
					q.add(i); visited[i] = true; 
					bw.write(i + " ");
				}
			}
		}
		
	}
	
}