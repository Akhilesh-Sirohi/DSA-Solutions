/*
Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.
D means the next number is smaller, while I means the next number is greater.
*/
vector<int> Solution::findPerm(const string s, int n) {
    /*
     {1,2,3,4,0,-1,-2,-3,-4,5,6,7,-5}
     {7,8,9,10,6,5,4,3,2,11,12,13,1}
    */
    
    vector<int>A={1};
    int Max=1, Min=1;  //number in range [Min , Max] have been used, so if we need Increase then use Max+1, if we need smaller then use Min-1
    for(int i=0;i<n-1;i++){
        if(s[i]=='I'){
            Max++;
            A.push_back(Max);
        }
        else{
            Min--;
            A.push_back(Min);
        }
    }
    int x = 1-Min; //what needs to be added in Min to make it 1
    
    for(int i=0;i<n;i++){
        A[i]+=x;
    }
    return A;
}
