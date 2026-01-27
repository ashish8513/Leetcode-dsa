# You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.

# Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.

# The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.

# Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

 from typing import List
import heapq
from collections import defaultdict

class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        adj = defaultdict(list)   # normal outgoing edges
        rev = defaultdict(list)   # incoming edges

        for u, v, w in edges:
            adj[u].append((v, w))
            rev[v].append((u, w))

        INF = float('inf')
        dist = [[INF, INF] for _ in range(n)]
        dist[0][0] = 0

        pq = [(0, 0, 0)]  # (cost, node, switch_used)

        while pq:
            cost, u, used = heapq.heappop(pq)

            if cost > dist[u][used]:
                continue

            # 1) Normal edges
            for v, w in adj[u]:
                if dist[v][0] > cost + w:
                    dist[v][0] = cost + w
                    heapq.heappush(pq, (dist[v][0], v, 0))

            # 2) Use switch once (reverse incoming edge)
            if used == 0:
                for v, w in rev[u]:
                    new_cost = cost + 2 * w
                    if dist[v][1] > new_cost:
                        dist[v][1] = new_cost
                        heapq.heappush(pq, (new_cost, v, 1))

        ans = min(dist[n - 1][0], dist[n - 1][1])
        return ans if ans != INF else -1
