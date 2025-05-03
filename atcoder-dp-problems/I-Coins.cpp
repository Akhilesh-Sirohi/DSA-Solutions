#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int M = 1e9+7;
const int Max=2e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_h

Time Complexity = O(n^2)
*/

double getProbabilityOfMoreHeads(vector<double>&P){
    int n=P.size();

    vector<vector<double>>dp(n, vector<double>(n+1)); // dp[i][j]= probability of getting j heads uptill ith toss
    
    dp[0][1]=P[0]; dp[0][0] = 1-P[0]; 
    for(int i=1;i<n;i++) dp[i][0] = dp[i-1][0]*(1-P[i]);

    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j-1]*P[i]; // get head in this round
            dp[i][j]+=dp[i-1][j]*(1-P[i]); // get head in this round

        }
    }

    double ans=0; // total porabalilty of more heads then tails.
    for(int j=n; j>n-j; j--) ans+=dp[n-1][j];

    return ans;
}

void solve(){
    int n;
    cin>>n;
    vector<double>P(n);
    for(int i=0;i<n;i++) cin>>P[i];
    cout<<getProbabilityOfMoreHeads(P);
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
