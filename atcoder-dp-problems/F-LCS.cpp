#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int M = 1e9+7;
const int Max=2e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_f
*/


string getLCS(string s, string t){
    int n=s.size(), m=t.size();
    vector<vector<int>>dp(n,vector<int>(m)); // dp[i][j] = Longest common subsequence upto the index i in s and index j in t
    for(int i=0;i<n;i++) {
        if(s[i]==t[0] or (i>0 && dp[i-1][0]==1)) dp[i][0]=1;
    }
    for(int j=0;j<m;j++) {
        if(t[j]==s[0] or (j>0 && dp[0][j-1]==1)) dp[0][j]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=max({dp[i][j-1], dp[i-1][j]});
            if(s[i]==t[j]) dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
        }
    }
    int max_len=dp[n-1][m-1];

    // now we need to create the string
    int i=n-1, j=m-1;
    string ans="";
    while(i>=0 && j>=0 && max_len>0){
        if(s[i]==t[j] && dp[i][j]==max_len){ // pick
            ans+=s[i];
            max_len--;
            i--;
            j--;
        }
        else if(i>0 && dp[i-1][j]==max_len) i--; // i can be skipped
        else j--; // skip j
    }
    reverse(ans.begin(), ans.end());
    return ans;

}
void solve(){
    string s, t;
    cin>>s>>t;
    cout<<getLCS(s,t)<<"\n";
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
