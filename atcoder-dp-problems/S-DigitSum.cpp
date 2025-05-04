#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846
const int Mod= 1e9+7;
const int Max=1e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_s

Time Complexity = O(n*d*10)
Space Complexity = O(n*d)
*/


long long getCountOfNumbers(string s, int d){
    int n=s.size();
    /*
        To find count of numbers b/w [1,s], sum of whose digits is divisible by d;
        -> find count of numbers b/w [1,10000...(n-1)zeroes], [1,10000...(n-2)zeroes], [1,10000...(n-3)zeroes].... [1,10], [1,1]
                -> with each remainder value of sum of digits
        -> Now for a number 654321, ans will be 
                for number less than 600000 => (count(range_start, range_end, remainder) => count(1,100000, 0), count(1,100000, d-1), count(1,100000, d-2)...... +count(0,100000, (d-6)%2
                for numbers b/w [600001, 650000] => count(0,100000, d-6), count(0,10000, d-7), count(0,10000, d-8)... count(0,10000, d-11)
                for numbers b/w [650001, 654000] => count(0,10000, d), count(0,10000, d-1), count(0,10000, d-2)
    */

    vector<vector<long long>>dp(n, vector<long long>(d)); // dp[i][j] => numbers b/w [1, 10^i) whose sum of digits when divided by d leaves a remainder j
    dp[0][0]=1; 
    for(int i=1;i<n;i++){
        for(int j=0;j<d;j++){
            for(int k=0;k<10;k++){
                dp[i][(j+k)%d]=(dp[i][(j+k)%d]+dp[i-1][j])%Mod;
            }
        }
    }

   // cout<<"s: "<<s<<" d: "<<d<<"\n";
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<d;j++) cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }

    long long ans= Mod-1;  // number with less then n-1 digits.
    int prev_digit_sum=0;
    for(int i=0;i<n;i++){
        int a=s[i]-'0';
        for(int first_digit=0;first_digit<a;first_digit++){
            int rem = (d- (prev_digit_sum + first_digit)%d)%d;   // (prev_digit_sum + first_digit+rem) = d => rem = d-(prev_digit_sum + first_digit)%d;
            ans= (ans+dp[n-i-1][rem])%Mod;
            //cout<<"i: "<<i<<" first_digit: "<<first_digit<<"  rem: "<<rem<<"  ans: "<<ans<<"\n";
        }
        prev_digit_sum=(prev_digit_sum+a)%d;
    }
    if(prev_digit_sum%d==0) ans=(ans+1)%Mod;
    return ans;

}
void solve(){
    int d;
    string s;
    cin>>s>>d;
    cout<<getCountOfNumbers(s, d);
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
