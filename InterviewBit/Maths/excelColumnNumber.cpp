/*
Given a column title A as appears in an Excel sheet, return its corresponding column number.
*/
int Solution::titleToNumber(string s) {
    //26 Bit Integer, denoted by capital letters => A means 1, B means 2
    int ans=0;
    for(char ch:s){
        ans=ans*26+(ch-'A')+1;
    }
    return ans;
}
