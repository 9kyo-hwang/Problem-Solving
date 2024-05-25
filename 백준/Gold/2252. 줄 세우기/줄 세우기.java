import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static List<List<Integer>> adjacencyList;
    static List<Integer> orderOfVisit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        adjacencyList = new ArrayList<>();
        for (int i = 0; i <= N; i++) {
            adjacencyList.add(new ArrayList<>());
        }
        
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            adjacencyList.get(A).add(B);
        }
        
        topologySort();
        
        Collections.reverse(orderOfVisit);
        for (int node : orderOfVisit) {
            bw.write(node + " ");
        }
        bw.flush();
        bw.close();
        br.close();
    }

    static void DFS(boolean[] visited, int srcNode) {
        visited[srcNode] = true;
        for (int dstNode : adjacencyList.get(srcNode)) {
            if (!visited[dstNode]) {
                DFS(visited, dstNode);
            }
        }
        orderOfVisit.add(srcNode);
    }

    static void topologySort() {
        boolean[] visited = new boolean[N + 1];
        orderOfVisit = new ArrayList<>();
        for (int node = 1; node <= N; node++) {
            if (!visited[node]) {
                DFS(visited, node);
            }
        }
    }
}
