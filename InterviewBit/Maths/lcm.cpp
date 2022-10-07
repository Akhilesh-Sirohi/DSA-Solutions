//find lcm of 2 numbers,
//lcm = a*b/hcf(a,b); __gcd(a,b) is inbuilt function to find hcf of (a,b)
long Solution::solve(int A, int B) {
    return 1ll*A*B/__gcd(A,B);
}
