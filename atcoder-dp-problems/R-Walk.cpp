#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi 3.14159265358979323846

int Mod= 1e9+7;
const int Max=1e5+5;

/*
https://atcoder.jp/contests/dp/tasks/dp_r

Time Complexity = O(log(k)*n^3)
Space Complexity = O(n^2)
*/


vector<vector<long long>>product(vector<vector<long long>>a, vector<vector<long long>>b){
    int n1=a.size(), n2=b.size();
    assert(n1>0 && n2>0);
    int m1=a[0].size(), m2=b[0].size();
    assert(m1==n2);
    vector<vector<long long>>c(n1, vector<long long>(m2));
    for(int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
            for(int k=0;k<m1;k++){
                c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%Mod)%Mod;
            }
        }
    }
    return c;
}

vector<vector<long long>>power(vector<vector<long long>>matrix, int n){
    if(n==1) return matrix;
    if(n%2==1) return product(matrix, power(matrix, n-1));
    matrix=power(matrix, n/2);
    return product(matrix,matrix);
}

int getNumberOfDifferentPaths(vector<vector<long long>>&A, int k){
    if(k==0) return 0;
    auto matrix = power(A,k);
    long long ans=0;
    for(auto a:matrix){
        for(long long b:a) ans=(ans+b)%Mod;
    }
    return ans;
}


void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<long long>>A(n, vector<long long>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>A[i][j];
    }
    cout<<getNumberOfDifferentPaths(A, k);
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
