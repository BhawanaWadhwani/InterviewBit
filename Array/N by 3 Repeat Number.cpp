int Solution::repeatedNumber(const vector<int> &A) {
    //We will take 2 random numbers and check if they exist in the array
    int c1=0, c2=0;
    int num1=INT_MAX, num2=INT_MAX;
    
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        if(A[i]==num1)
        {
            c1++;
        }
        else if(A[i]==num2)
        {
            c2++;
        }
        else if(c1==0)
        {
            c1++;
            num1=A[i];
        }
        else if(c2==0)
        {
            c2++;
            num2=A[i];
        }
        else
        {
            c1--;
            c2--;
        }
    }
    c1=0;
    c2=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==num1)
        c1++;
        else if(A[i]==num2)
        c2++;
    }
    if(c1>n/3)
    return num1;
    if(c2>n/3)
    return num2;
    
    return -1;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
