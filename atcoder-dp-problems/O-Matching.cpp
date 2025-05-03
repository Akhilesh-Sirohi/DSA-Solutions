#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int Mod= 1e9+7;
const int Max=1e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_n

Time Complexity = O(n*(2^n))
Space Complexity = O((2^n))
*/

int getNumberOfWays(vector<vector<bool>>&A){

    int n = (int)A.size();
    int m = 1 << n;        // total # masks
    vector<int> rowMask(n);     // rowMask[i] : bitset of women man-i can take i.e women liked by ith man
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (A[i][j]) rowMask[i] |= (1 << j);
        }
    }

    vector<int> dp(m, 0); //
    dp[0] = 1;                        // nobody matched yet

    for (int mask = 0; mask < m; ++mask){ // picked women mast
        /*
            __builtin_popcount gives number of on bits i.e count of bits set to 1,
            __builtin_popcount(mask) = count of men that has been assigned
        */

        int man = __builtin_popcount(mask);   // next man to assign 
        if (man == n) continue;               // all matched

        // women this man likes and are still free
        int freeLiked = rowMask[man] & ~mask; // bit set in rowMask[man] but not in mask

        // iterate over set bits in freeLiked
        for (int w = freeLiked; w; w &= w - 1)
        {
            int womanBit = w & -w;            // lowest set bit
            int nextMask = mask | womanBit;
            dp[nextMask] += dp[mask];
            if (dp[nextMask] >= Mod) dp[nextMask] -= Mod;
        }
    }

    return dp[m - 1];               // all n women chosen

}

void solve(){
    int n,a;
    cin>>n;
    vector<vector<bool>>A(n, vector<bool>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a;
            if(a==1) A[i][j]=true;
        }
    }
    cout<<getNumberOfWays(A);
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
