#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int M = 1e9+7;
const int Max=2e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_k

Time Complexity = O(n*k)
*/

bool isFirstPlayerWinner(vector<int>&A, int K){
    int n=A.size();
    sort(A.begin(),A.end());
    vector<bool>dp(K+1); // dp[i] = does person playing first at K=i wins?

    for(int i=1;i<=K;i++){
        for(int a:A) {
            if(a>i) break;
            dp[i]= dp[i] or !dp[i-a];
        }
    }
    return dp[K];
}

void solve(){
    int n,K;
    cin>>n>>K;
    vector<int>A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<(isFirstPlayerWinner(A,K) ? "First": "Second");
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
