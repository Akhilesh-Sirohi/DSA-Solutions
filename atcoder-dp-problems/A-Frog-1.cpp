#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int M = 1e9+7;
const int Max=2e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_a

A frog wants to travel across N stones arranged in a line.
    •   Stone numbers run from 1 to N (inclusive).
    •   The height of stone i is denoted hᵢ.

The frog starts on stone 1 and must reach stone N.
On each move, if the frog is on stone i, it may jump to:
    •   stone i + 1, or
    •   stone i + 2.

Jumping from stone i to stone j costs |hᵢ − hⱼ|.

Compute the minimum total cost the frog can accumulate by the time it lands on stone N.
*/

int getMinJump(vector<int>&A){
    int n=A.size();
    vector<int>dp(n); // dp[i]= minimum cost to reach ith position
    dp[1]=abs(A[1]-A[0]);

    for(int i=2;i<n;i++){
        dp[i]=min(dp[i-1]+abs(A[i]-A[i-1]), dp[i-2]+abs(A[i]-A[i-2]));
    }
    return dp[n-1];

}
void solve(){
    int n;
    cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<getMinJump(A)<<"\n";
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
