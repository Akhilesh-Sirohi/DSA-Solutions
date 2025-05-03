#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int M = 1e9+7;
const int Max=2e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_c
*/

int getMaxHappiness(vector<vector<int>>&A){
    int n=A.size();
    vector<vector<int>>dp(n, vector<int>(3)); // dp[i][j]= maximum happiness on ith day if jth activity is picked on ith day
    for(int i=0;i<3;i++) {
        dp[0][i]=A[0][i];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j==k) continue; // can't pick the same activity that was picked earlier
                dp[i][j]=max(dp[i][j],dp[i-1][k]+A[i][j]);
            }
        }
    }

    return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}
void solve(){
    int n,k;
    cin>>n;
    vector<vector<int>>A(n, vector<int>(3));
    for(int i=0;i<n;i++) cin>>A[i][0]>>A[i][1]>>A[i][2];
    cout<<getMaxHappiness(A)<<"\n";
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
