int Solution::firstMissingPositive(vector<int> &A) {
    int n=A.size();
    int inf=1e9+7;
    for(int i=0;i<n;i++)
    {
        if(A[i]<1 || A[i]>n)
        {
            A[i]=inf;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(abs(A[i])!=inf)
        {
            A[abs(A[i])-1]=-A[abs(A[i])-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(A[i]>0)
        return i+1;
    }
    return n+1;
}
