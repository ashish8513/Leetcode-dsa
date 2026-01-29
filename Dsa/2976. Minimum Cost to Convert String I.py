# You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

# You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

# Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

# Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].


class Solution:
    def minimumCost(
        self,
        source: str,
        target: str,
        original: list[str],
        changed: list[str],
        cost: list[int]
    ) -> int:
        
        INF = 10**15
        n = 26
        
        # distance matrix
        dist = [[INF] * n for _ in range(n)]
        
        # cost 0 to convert same character
        for i in range(n):
            dist[i][i] = 0
        
        # fill direct conversions
        for o, c, w in zip(original, changed, cost):
            u = ord(o) - ord('a')
            v = ord(c) - ord('a')
            dist[u][v] = min(dist[u][v], w)
        
        # Floyd-Warshall
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if dist[i][k] + dist[k][j] < dist[i][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]
        
        # compute answer
        total_cost = 0
        for s, t in zip(source, target):
            if s == t:
                continue
            
            u = ord(s) - ord('a')
            v = ord(t) - ord('a')
            
            if dist[u][v] == INF:
                return -1
            
            total_cost += dist[u][v]
        
        return total_cost
