/*
You are given an integer N and the task is to reverse the digits of the given integer. 
Return 0 if the result overflows and does not fit in a 32 bit signed integer
*/
int Solution::reverse(int A) {
    bool isneg=0;
    if(A<0)
    {
        isneg=1;
        A=abs(A);
    }
    int rev=0;
    while(A>0)
    {
        int digit= A%10;
        if(rev>INT_MAX/10 || (rev==INT_MAX/10 && digit>INT_MAX%10)) //otherwise int ki range paar
        return 0;
        A=A/10;
        rev= rev*10+digit;
    }
    if(isneg==1)
    {
        rev=-rev;
    }
    return rev;
}
