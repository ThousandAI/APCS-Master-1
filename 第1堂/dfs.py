def dfs(adj, root):
    print(root, end=" ")
    children = len(adj[root])
    if children == 0:
        return
    for i in range(children):
        dfs(adj, adj[root][i])


adj = [[4, 7, 1], [], [5], [2, 6, 0], [], [], [], []]
root = 3
dfs(adj, root)
