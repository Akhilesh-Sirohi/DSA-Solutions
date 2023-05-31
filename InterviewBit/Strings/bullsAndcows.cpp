string Solution::solve(string A, string B) {
    vector<int>X(10);
    for(char a:A) X[a-'0']++;
    
    //count bulls
    int bull=0;
    for(int i=0;i<B.size();i++) {
        if(A[i]==B[i]) {
            bull++;
            X[A[i]-'0']--;
        }
    }
    
    int cow=0;
    for(int i=0;i<B.size();i++){
        if(A[i]!=B[i]){
            if(X[B[i]-'0']>0){
                cow++;
                X[B[i]-'0']--;
            }
        }
    }
    return to_string(bull) +"A"+to_string(cow) +"B";
       
}
