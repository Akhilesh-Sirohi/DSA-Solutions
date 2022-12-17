int Solution::isPalindrome(string A) {
    int i=0, j = A.size()-1;
    while(i<j){
        if(!isalnum(A[i])){
            i++;
            continue;
        }
        if(!isalnum(A[j])){
            j--;
            continue;
        }
        if(isalpha(A[i])) A[i] = tolower(A[i]);
        if(isalpha(A[j])) A[j] = tolower(A[j]);
        if(A[i]!=A[j]){
            return 0;
        }
        i++;
        j--; 
    }
    return 1;
}
