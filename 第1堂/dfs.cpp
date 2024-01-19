#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, int root){
    cout << root << " ";
    int children = adj[root].size();
    if(children == 0) return;
    for(int i = 0; i < children; ++i){
        dfs(adj, adj[root][i]);
    }
}


int main()
{
    vector<vector<int>> adj = {{4,7,1},{},{5},{2,6,0},{},{},{},{}};
    int root = 3;
    dfs(adj, root);
    return 0;
}
