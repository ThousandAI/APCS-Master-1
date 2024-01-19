#include <bits/stdc++.h>

using namespace std;

long long int dfs(vector<vector<int>> &adj, int root, long long int &ans){
    int children = adj[root].size();
    if(children == 0) return 1;
    long long int height = 0;
    for(int i = 0; i < children; ++i){
        height = max(dfs(adj, adj[root][i], ans), height);
    }
    ans += height;
    return height + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int node, children, temp, root;
    long long int ans = 0;
    cin >> node;
    vector<vector<int>> adj(node+1);
    vector<int> parent(node+1, -1);

    for(int i = 1; i <= node; ++i){
        cin >> children;
        for(int j = 0; j < children; ++j){
            cin >> temp;
            adj[i].push_back(temp);
            parent[temp] = i;
        }
    }
    for(int i = 1; i <= node; ++i){
        if(parent[i] == -1){
            root = i;
            break;
        }
    }
    dfs(adj, root, ans);
    cout << root << "\n" << ans;
    return 0;
}
