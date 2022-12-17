/*
Given a positive integer A, return its corresponding column title as appear in an Excel sheet.
*/
string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string Solution::convertToTitle(int n) {
    //convert a number into 26 base=> same logic as binary , just divide by 26
    string ans="";
    while(n>0)
    {
        int a=n%26;
        if(a==0){
            a=26;
            n--; //as there is no 0, the system starts from 1
        }
        ans+=s[a-1];
        n=n/26;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
