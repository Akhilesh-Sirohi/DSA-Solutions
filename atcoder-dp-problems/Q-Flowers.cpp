#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int Mod= 1e9+7;
const int Max=1e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_q

Time Complexity = O(nlogn)
Space Complexity = O(n)
*/

int getMaxBeauty(vector<int>&A, vector<int>&H){
    int n=A.size();
    vector<int>dp(n); // dp[i]=max beauty value till ith if ith flower is picked;
    dp[0]=A[0];

    set<vector<int>>S;
    S.insert({H[0], dp[0]});
    for(int i=1;i<n;i++){
        dp[i]=A[i];

        // now check for max value of dp[j] where j<i && H[j]<H[i]
        auto it=S.lower_bound({H[i], 0});
        if(it!=S.begin()){
            --it;

            //dp[j]=(*it)[1] and H[j]=(*it)[0]
            dp[i]=max(dp[i], (*it)[1]+A[i]);
            ++it;
        }

        // now delete the entries in S with H[j]>=H[i] and dp[j]<dp[i]
        auto it2=it;
        while(it2!=S.end() && (*it2)[1]<=dp[i]) ++it2; 
        S.erase(it,it2);
        S.insert({H[i], dp[i]});
    }
    return *max_element(dp.begin(),dp.end());
}

void solve(){
    int n,u,v;
    cin>>n;
    vector<int>H(n);
    vector<int>A(n);
    for(int i=0;i<n;i++) cin>>H[i];
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<getMaxBeauty(A,H);
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
