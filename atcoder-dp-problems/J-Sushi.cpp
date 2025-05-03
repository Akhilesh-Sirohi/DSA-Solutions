#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int M = 1e9+7;
const int Max=2e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_j

Time Complexity = O(n^3)
*/


double getExpectedOps(vector<int>&A){
    double N=A.size();
    /*
        let, 
        - i be the count of dishes with 1 sushi, 
        - j be the count of dishes with 2 sushi,
        - k be the count of dishes with 3 sushi,
        - dp[i][j][k] = Number of Ops for 'i' dishes with 1 sushi, 'j' dishes with 2 shushi, 'k' dishes with 3 sushi 
        when a roll is made, 4 things can happen, 1. empty, 2. eat from 1 sushi dishes, 3. eat from 2 shushi dishes, 4 eat from 3 sushi dishes
        dp[i][j][k] = 1+  // new operation made
                    ((N-(i+j+k))/N)*dp[i][j][k] + // probability of landing on empty plate and count of ops for same state
                    (i/N)* dp[i-1][j][k] +  // probability of landing on dish with 1 sushi * count of ops for dp[i-1][j][k]
                    (j/N)*dp[i+1][j-1][k] + 
                    (k/N)*dp[i][j+1][k-1]
        dp[i][j][k]*(1-(N-(i+j+k)/N) = 1 + (i/N)* dp[i-1][j][k] + (j/N)*dp[i+1][j-1][k] + (k/N)*dp[i][j+1][k-1]
        dp[i][j][k]*(1-1+(i+j+k)/N) = 1 + (i/N)* dp[i-1][j][k] + (j/N)*dp[i+1][j-1][k] + (k/N)*dp[i][j+1][k-1]
        dp[i][j][k] = (1/(i+j+k))* (N + (i* dp[i-1][j][k] + j*dp[i+1][j-1][k] + k*dp[i][j+1][k-1])
    */
    int x=0,y=0,z=0;
    for(int a:A) {
        if(a==1) x++;
        else if(a==2) y++;
        else z++;
    }

    double dp[x+y+z+1][y+z+1][z+1]; // N=x+y+z
    dp[0][0][0]=0;
    for(int k=0;k<=z;k++){
        for(int j=0;j<=y+z;j++){
            for(int i=0;i<=N;i++){
                if(i+j+k>N) break;
                if(i+j+k==0) continue;
                dp[i][j][k]=N;
                if(i!=0) dp[i][j][k]+=i*dp[i-1][j][k];
                if(j!=0) dp[i][j][k]+=j*dp[i+1][j-1][k];
                if(k!=0) dp[i][j][k]+=k*dp[i][j+1][k-1];
                dp[i][j][k]=dp[i][j][k]/(i+j+k);
            }
        }
    }
    return dp[x][y][z];

}

void solve(){
    int n;
    cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<setprecision(15)<<getExpectedOps(A);
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
