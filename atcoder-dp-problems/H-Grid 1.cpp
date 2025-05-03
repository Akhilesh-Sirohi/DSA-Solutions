#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int M = 1e9+7;
const int Max=2e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_h

Time Complexity = O(n*m) or O(h*w)
*/

int getNumberOfWays(vector<string>&grid){
    int n=grid.size(), m=grid[0].size();

    vector<vector<int>>dp(n, vector<int>(m)); // dp[i][j]= number of paths from 0,0 to i,j
    
    for(int i=0;i<n && grid[i][0]!='#';i++)  dp[i][0] = 1;
    for(int j=0;j<m && grid[0][j] != '#';j++) dp[0][j]=1;

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(grid[i][j]=='#') continue;
            dp[i][j]= (dp[i-1][j]+dp[i][j-1])%M;
        }
    }

    return dp[n-1][m-1];
}

void solve(){
    int h,w;
    cin>>h>>w;
    vector<string>grid(h);
    for(int i=0;i<h;i++) cin>>grid[i];

    cout<<getNumberOfWays(grid);
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
