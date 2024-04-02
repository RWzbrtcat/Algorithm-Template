
import javafx.util.Pair;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class dijkstra {
    public int reachableNodes(int[][] edges, int maxMoves, int n) {
        List<int[]>[] g = new ArrayList[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for(int[] e: edges){
            g[e[0]].add(new int[]{e[1], e[2] + 1});
            g[e[1]].add(new int[]{e[0], e[2] + 1});
        }
        int[] dis = new int[n];
        Arrays.fill(dis, Integer.MAX_VALUE);
        dis[0] = 0;
        boolean[] visited = new boolean[n];
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>((a, b) -> a.getKey() - b.getKey());
        pq.offer(new Pair<>(0, 0));
        while(!pq.isEmpty()){
            Pair<Integer, Integer> p = pq.poll();
            int d = p.getKey(), x = p.getValue();
            if(d < dis[x] || visited[x]) continue;
            visited[x] = true;
            for(int[] v: g[x]){
                int y = v[0], w = v[1];
                if(d + w < dis[y] && !visited[y]){
                    dis[y] = d + w;
                    pq.offer(new Pair<>(dis[y], y));
                }
            }
        }
        int ans = 0;
        for(int d: dis){
            if(d <= maxMoves) ans++;
        }
        for(int[] e: edges){
            int u = e[0], v = e[1], c = e[2];
            int a = Math.max(0, maxMoves - dis[u]);
            int b = Math.max(0, maxMoves - dis[v]);
            ans += Math.min(a + b, c);
        }
        return ans;

    }
}
