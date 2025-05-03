#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int M= 1e9+7;
const int Max=1e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_n

Time Complexity = O(n^3)
Space Complexity = O(n^2)
*/

int getMinCost(vector<int>&A){
    int n=A.size();

    vector<int>PrefixSum(n+1);
    vector<vector<int>>dp(n, vector<int>(n));
    /*
        dp[i][j] = minimum cost for combine all the slimes b/w ith and jth index inclusive
        dp[i][j]= sum[i,j] + min(dp[i+1][j], dp[i][i+1]+dp[i][j], dp[i][i+2]+dp[i+3][ij].... , dp[i][j-1])
                sum[i,j] needs to be added as in last operation we will need to combine all slimes
    */

    for(int i=0;i<n;i++){
        PrefixSum[i+1]=PrefixSum[i]+A[i];
        if(i!=n-1) dp[i][i+1]=A[i]+A[i+1];
    }

    for(int k=2;k<n;k++){
        for(int i=0;i+k<n;i++){
            int j=i+k;
            int sum=PrefixSum[j+1]-PrefixSum[i];
            dp[i][j]=sum+min(dp[i+1][j], dp[i][j-1]);
            for(int x=i+2;x<j;x++) dp[i][j]=min(dp[i][j], sum+dp[i][x-1]+dp[x][j]);
        }
    }
    return dp[0][n-1];
}

void solve(){
    int n;
    cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<getMinCost(A);
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
