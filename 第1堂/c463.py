def dfs(adj, root, ans):
    children = len(adj[root])
    if children == 0:
        return 1
    height = 0
    for i in range(children):
        height = max(dfs(adj, adj[root][i], ans), height)
    ans[0] += height
    return height + 1

node = int(input())
adj = [[] for _ in range(node + 1)]
parent = [-1] * (node + 1)
ans = [0]

for i in range(1, node + 1):
    children, *child_nodes = map(int, input().split())
    for temp in child_nodes:
        adj[i].append(temp)
        parent[temp] = i

for i in range(1, node + 1):
    if parent[i] == -1:
        root = i
        break

dfs(adj, root, ans)
print(root)
print(ans[0])
