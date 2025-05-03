#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int M = 1e9+7;
const int Max=2e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_b

A frog wants to travel across N stones arranged in a line.
    •   Stone numbers run from 1 to N (inclusive).
    •   The height of stone i is denoted hᵢ.

The frog starts on stone 1 and must reach stone N.

If the frog is currently on Stone i, jump to one of the following: 
Stone {i+1,i+2,…,i+K} 
Here, a cost of ∣hi − hj∣ is incurred, where j is the stone to land on.

Compute the minimum total cost the frog can accumulate by the time it lands on stone N.
*/

int getMinJump(vector<int>&A, int k){
    int n=A.size();
    vector<int>dp(n); // dp[i]= minimum cost to reach ith position

    for(int i=1;i<n;i++){
        dp[i]=dp[i-1]+abs(A[i]-A[i-1]);
        for(int j=i-1;j>=0 && j>=i-k;j--){ // if k=2 => j={i-1, i-2}
            dp[i]=min(dp[i], dp[j]+abs(A[i]-A[j]));
        }
    }
    return dp[n-1];

}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<getMinJump(A, k)<<"\n";
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
