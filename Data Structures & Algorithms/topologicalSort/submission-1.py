class Solution:
    def topologicalSort(self, n: int, edges: List[List[int]]) -> List[int]:
        mp = defaultdict(list)

        for u, v in edges:
            mp[v].append(u)
        
        visited = [False for _ in range(n)]
        path = [False for _ in range(n)]
        res = []
        def dfs(i):
            if path[i]:
                return False
            if visited[i]:
                return True
            
            visited[i] = True
            path[i] = True
            for nei in mp[i]:
                if not dfs(nei):
                    return False
            
            path[i] = False
            res.append(i)
            return True
        
        for i in range(n):
            if not dfs(i):
                return []
        
        return res
