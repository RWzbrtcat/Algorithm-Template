
from math import inf
from heapq import heappush, heappop
from typing import List

class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        g = [[] for _ in range(n)]
        for a, b, c in edges:
            g[a].append((b, c + 1))
            g[b].append((a, c + 1))

        dis = [inf] * n
        dis[0] = 0
        visited = [False] * n
        pq = []
        heappush(pq, (0, 0))  # d, x, pre
        while pq:
            d, x = heappop(pq)
            if d > dis[x] or visited[x]:
                continue
            visited[x] = True
            for y, w in g[x]:
                if d + w < dis[y]:
                    dis[y] = d + w
                    heappush(pq, (dis[y], y))

        ans = sum(d <= maxMoves for d in dis)  # 统计每个节点是否到达
        for u, v, c in edges:
            a = max(maxMoves - dis[u], 0)
            b = max(maxMoves - dis[v], 0)
            ans += min(a + b, c)
        return ans