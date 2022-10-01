/*
 Given a sorted array A containing N integers both positive and negative.
You need to create another array containing the squares of all the elements in A and return it in non-decreasing order.
  */
void solveInNlogN(vector<int>&A){
    for(int i=0;i<A.size();i++) A[i]=A[i]*A[i];
    sort(A.begin(),A.end());
}
void solveInN(vector<int>&A){
    /*
     step 1: square the array and 
     step 2: use count sort
    */
    vector<int>X(1e6+5);
    for(int a:A) X[a*a]++;
    int j=0;
    for(int i=0;i<X.size();i++){
        while(X[i]--){
            A[j]=i;
            j++;
        }
    }
}
vector<int> Solution::solve(vector<int> &A) {
   // solveInNlogN(A);
    solveInN(A);
    return A;
}
