
/*
Find if the given number is a power of 2 or not. More specifically, find if the given number can be expressed as 2^k where k >= 1.
Note: The number length can be more than 64, which means the number can be greater than 2 ^ 64 (out of long long range)
*/
string divideByN(string s, long long n){
	string ans="";
	long long rem=0;
	long long i=0;
	while(i<s.size()){
		long long x=rem*10ll+(s[i]-'0');
		ans= ans+to_string(x/n);
		rem=x%n;
		i++;
	}
    long long k=0;
    while(k<ans.size() && ans[k]=='0') k++;
	return ans.erase(0,k);
}
int Solution::power(string A) {
    if(A=="1") return 0;
    long long n= INT_MAX;
    n++;
    while(A!="1"){
        if((A.back()-'0')%2) return 0;
        if(A.size()>10){
           A= divideByN(A,n);   
        }
        else A = divideByN(A,2);
       // cout<<"A: "<<A<<"\n";
    }
    return 1;
}
