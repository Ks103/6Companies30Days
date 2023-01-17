class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
                
        # Floyd-warshall
        
        dp = [[float('inf') for _ in range(n)] for _ in range(n)]
        for ed in edges:
            u, v, weight = ed[0], ed[1], ed[2]
            dp[u][v] = dp[v][u] = weight
        
        for k in range(n):
            for u in range(n):
                for v in range(n):
                    dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v])
        
        ans = -1
        min_neighbor = float('inf')
        for u in range(n):
            cur_neighbor = 0
            for v in range(n):
                if v != u and dp[u][v] <= distanceThreshold:
                    cur_neighbor += 1
            if cur_neighbor <= min_neighbor:
                min_neighbor = cur_neighbor
                ans = u
        
        return ans
