#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int M= 1e9+7;
const int Max=1e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_o

Time Complexity = O(n*(2^n)) 
Space Complexity = O(n*(2^n))
*/

int dp[21][1<<21];
int recur(vector<vector<bool>>&A, int i, int picked_mask){
    int n=A.size();
    if(i==n) return 1;
    if(dp[i][picked_mask]!=-1) return dp[i][picked_mask];
    int ans=0;
    for(int j=0;j<n;j++){
        if(A[i][j] && (picked_mask&(1<<j)) == 0) {
            ans=(ans+recur(A,i+1,picked_mask^(1<<j)))%M;
        }
    }
    dp[i][picked_mask]=ans;
    return ans;
}

int getNumberOfWays(vector<vector<bool>>&A){
    memset(dp,-1,sizeof(dp));
    return recur(A,0,0);

    // Time Complexity of below solution is (n^2)*(2^n)
    // int n=A.size();
    // int m=(1<<n);
    // vector<vector<int>>dp(n, vector<int>(m));
    // /*
    //     dp[i][j] = number of ways till ith men, where j is the bitmask of women already picked. 
    // */
    // for(int i=0;i<n;i++) {
    //     if(A[0][i]) dp[0][1<<i]=1;
    // }
    // for(int i=1;i<n;i++){
    //     for(int j=1;j<m;j++){
    //         for(int k=0;k<n;k++){
    //             if(A[i][k] && (j&(1<<k)) > 0){
    //                 dp[i][j]=(dp[i][j]+ dp[i-1][j^(1<<k)])%M;
    //             }
    //         }
    //     }
    // }
    // return dp[n-1][m-1];

}

void solve(){
    int n,a;
    cin>>n;
    vector<vector<bool>>A(n, vector<bool>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a;
            if(a==1) A[i][j]=true;
        }
    }
    cout<<getNumberOfWays(A);
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
