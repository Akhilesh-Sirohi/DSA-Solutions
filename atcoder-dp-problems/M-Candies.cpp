#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int Mod = 1e9+7;
const int Max=2e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_m

Time Complexity = O(n^K)
*/

int getNumberOfWays(vector<int>&A, int K){
    int n=A.size();
    /*
        dp[i][j]= number of ways to distribute j candies upto ith child.
        dp[i][j] = sum(dp[i-1][j], dp[i-1][j-1], dp[i-1][j-2]...., dp[i-1][j-ai])
    */

    vector<vector<int>>dp(n, vector<int>(K+1));
    vector<vector<int>>prefixSum(n, vector<int>(K+1)); // prefixSum
    dp[0][0]=1; prefixSum[0][0]=1;
    for(int i=1;i<=K;i++) {
        if(i<=A[0]) dp[0][i]=1; // as no candie should be left
        prefixSum[0][i]=dp[0][i]+prefixSum[0][i-1];
    }
    
    for(int i=1;i<n;i++){
        dp[i][0]=1; prefixSum[i][0]=1;
        for(int j=1;j<=K;j++){
            dp[i][j]=(prefixSum[i-1][j] - (j>A[i] ? prefixSum[i-1][j-A[i]-1]: 0) +Mod)%Mod;
            prefixSum[i][j]=(prefixSum[i][j-1]+dp[i][j])%Mod;
        }
    }

    return dp[n-1][K];
}

void solve(){
    int n,K;
    cin>>n>>K;
    vector<int>A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<getNumberOfWays(A,K);
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
