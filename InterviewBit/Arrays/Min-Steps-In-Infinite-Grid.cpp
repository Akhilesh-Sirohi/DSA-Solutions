/*
You are given a sequence of points and the order in which you need to cover the points.. 
Give the minimum number of steps in which you can achieve it. You start from the first point. You can move in all 8 directions.
*/
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    if(A.size()==0) return 0;
    int x=A[0],y=B[0];
    int ans=0;
    for(int i=1;i<A.size();i++) {
        /*
            to move from x1,y1 to x2,y2
            minimum number of request will be max(abs(x2-x1), abs(y2-y1));
            first we move diagonally then remaining distance horizonatlly or vertically
        */
        ans+= max(abs(A[i]-x), abs(B[i]-y));
        x=A[i]; y=B[i];
    }
    return ans;
}
