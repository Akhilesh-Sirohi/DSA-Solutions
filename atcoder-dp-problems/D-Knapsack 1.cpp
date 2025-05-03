#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int M = 1e9+7;
const int Max=2e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_d
*/

int getMaxValueForKnapsack(vector<int>&W, vector<int>&V, int maxWeight){
    int n=W.size();
    vector<vector<int>>dp(n, vector<int>(maxWeight+1)); // dp[i][j]= maximum value till ith index with weightLimit upto j
    
    for(int i=W[0];i<=maxWeight;i++) dp[0][i]=V[0];

    for(int i=1;i<n;i++){
        for(int j=1;j<=maxWeight;j++){
            dp[i][j]=dp[i-1][j]; // in case ith object is not  picked
            if(j>=W[i]) dp[i][j]=max(dp[i][j], dp[i-1][j-W[i]]+V[i]); // if ith object is picked
        }
    }

    return dp[n-1][maxWeight];
}
void solve(){
    int n,k, maxWeight;
    cin>>n>>maxWeight;
    vector<int>W(n);
    vector<int>V(n);
    for(int i=0;i<n;i++) cin>>W[i]>>V[i];
    cout<<getMaxValueForKnapsack(W,V,maxWeight)<<"\n";
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
