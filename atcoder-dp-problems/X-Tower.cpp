#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846

int Mod= 1e9+7;
const int Max=1e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_x

Time Complexity = O(n*MaxSi)
Space Complexity = O(n*MaxSi)
*/

struct Block{
    int w;
    int s;
    int v;
};

int getMaxScore(vector<Block>&A){
    int n=A.size();

    /*
        if block i is above j => 
                -   w_above_j = w_above_i + wi <= sj  ---(1)
                -   w_above_i <= si ----(2) 
                -   si <= w_above_i + wj ----(3) (else we would have put j above i)

                Adding (1,3)
                wi+si <= wj+sj
        so i can be kept above j only if wi+si <= wj+sj
    */

    sort(A.begin(),A.end(), [](const auto &a, const auto &b){
        return a.w+a.s < b.w + b.s;
    });

    int maxW=10001; // if weight goes above this, then it has to be the last block;
    int dp[n][maxW+1]; //dp[i][j]= max value till ith index when total weight is j
    memset(dp, 0, sizeof(dp));
    dp[0][A[0].w]=A[0].v;

    for(int i=1;i<n;i++){
        for(int j=0;j<=maxW;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]); // no need to pick ith
            if(j<=A[i].s){
                int x=min(maxW, j+A[i].w);
                dp[i][x] = max(dp[i][x], dp[i-1][j]+A[i].v);
            }
        }
    }

    int ans=0;
    for(int j=1;j<=maxW;j++) ans=max(ans,dp[n-1][j]);
    return ans;
}


void solve(){
    int n,w,s,v;
    cin>>n;
    vector<Block>A(n);
    for(auto &a:A){
        cin>>a.w>>a.s>>a.v;
    }
    cout<<getMaxScore(A);
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
