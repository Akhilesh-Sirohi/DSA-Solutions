#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int Mod= 1e9+7;
const int Max=1e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_p

Time Complexity = O(n)
Space Complexity = O(n)
*/

int dp[Max][2];
int dfs(vector<vector<int>>&Adj, int u, int p, int color){ //color 0=> B, 1=> White

    if(dp[u][color] != -1) return dp[u][color];
    
    int ans=1;
    for(int v:Adj[u]){
        if(v==p) continue;
        int numWays=dfs(Adj,v,u,1)%Mod; // colored in white
        if(color==1) numWays=(numWays+dfs(Adj,v,u,0))%Mod; // only if the parent node color is white, then child can be colored in black
        ans = (ans*numWays)%Mod;
    }

    dp[u][color]=ans;
    return ans;
}

int getNumberOfWays(vector<vector<int>>&Adj){
    memset(dp,-1,sizeof(dp));
    return (dfs(Adj, 0, -1, 0) + dfs(Adj, 0, -1, 1))%Mod;
}

void solve(){
    int n,u,v;
    cin>>n;
    vector<vector<int>>Adj(n);
    for(int i=1;i<n;++i) {
        cin>>u>>v;
        Adj[u-1].push_back(v-1);
        Adj[v-1].push_back(u-1);
    }
    cout<<getNumberOfWays(Adj);
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
