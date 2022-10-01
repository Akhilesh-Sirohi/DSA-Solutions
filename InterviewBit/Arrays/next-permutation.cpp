/*
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.

If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted in an ascending order.
*/
class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n=A.size();
        if(n==1) return;
        multiset<int>S;
        //2 3 4 5=> 2 3 5 4; 2,3,5,4=> 2,4,3,5,
        S.insert(A[n-1]);
        bool p=1;
        for(int i=n-2;i>=0;i--){
            S.insert(A[i]);
            auto it=S.upper_bound(A[i]); 
            //upperbound in multiset give immediate greater element
            if(it!=S.end()){
                A[i]=*it;
                S.erase(it);
                it=S.begin();
                for(int j=i+1;j<n;j++){
                    A[j]=*it;
                    it++;
                }
                p=0;
                break;
            }
        }
        if(p) reverse(A.begin(),A.end());
    }
};
