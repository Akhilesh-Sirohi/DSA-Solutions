string Solution::solve(string A) {
    vector<string>k;
    string s="";
    int i=A.size()-1;
    while(i>=0){
        if(A[i]==' '){
            if(s.size()>0) k.push_back(s);
            s="";
        }
        else{
            s= A[i]+s;
        }
        i--;
    }
    if(s.size()>0) k.push_back(s);
    
    if(k.size()==0) return "";
    string ans= k[0];
    for(int i=1;i<k.size();i++){
        ans =ans+" "+k[i];
    }
    return ans;
    
}
