#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int M = 1e9+7;
const int Max=2e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_l

Time Complexity = O(n^2)
*/

int getMaxDiff(vector<int>&A){
    int n=A.size();
    vector<vector<int>>dp(n, vector<int>(n, -1e18)); // dp[i][j]= maxDiff if the array is just [i, i+1, i+2, ...j-1, j]
    for(int i=0;i<n;i++) dp[i][i]=A[i];
    
    for(int k=1;k<n;k++){
        for(int i=0;i+k<n;i++){
            int j=i+k;
            //two choices, either pick from start or form end
            dp[i][j]=max(A[i]-dp[i+1][j], A[j]-dp[i][j-1]); // subtracting the other score as that will be diff for another player
        }
    }
    return dp[0][n-1];

}

void solve(){
    int n;
    cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<getMaxDiff(A);
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
