/*
Given four positive integers A, B, C, D, determine if there’s a rectangle such that the lengths of its sides are A, B, C and D (**in any order**).
*/
int Solution::solve(int A, int B, int C, int D) {
    //check on Length
    return (A==C && B==D) || (A==B && C==D) || (A==D && B==C);
}
