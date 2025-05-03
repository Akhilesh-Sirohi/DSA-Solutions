#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int M = 1e9+7;
const int Max=2e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_g

Time Complexity = O(n+m)
*/

int dfs(vector<vector<int>>&Adj, vector<int>&dp, int u){
    if(dp[u]!=-1) return dp[u];
    int maxPathLen=0;
    for(int v:Adj[u]) {
        // as directed acyclic graph, so no need to worry about cycle.
        maxPathLen=max(maxPathLen, 1+dfs(Adj,dp,v));
    }
    dp[u]=maxPathLen;
    return maxPathLen;
}

int getLongestPath(vector<vector<int>>&Adj){
    int n=Adj.size();
    vector<int>dp(n,-1); // dp[i]=longest path starting from i;
    int maxPathLen=0;
    for(int i=0;i<n;i++){
        if(dp[i]==-1) dp[i]=dfs(Adj, dp, i);
        maxPathLen=max(maxPathLen, dp[i]);
    }
    return  maxPathLen;
}

void solve(){
    int n,m,u,v;
    cin>>n>>m;
    vector<vector<int>>Adj(n);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        Adj[u-1].push_back(v-1);
    }

    cout<<getLongestPath(Adj);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    solve();

}
