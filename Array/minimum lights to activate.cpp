int Solution::solve(vector<int> &A, int B) {
    int count=0;
    int n=A.size();
    
    
    for(int i=0;i<n;i++)
    {
        int l=i-B+1;
        int r=i+B-1;
        
        int res=-1;
        for(int j=r;j>=l;j--)
        {
            if(A[j]==1)
            {
                res=j;
                break;
            }
        }
        
        if(res==-1)
        {
            return -1;
        }
        
        count++;
        i=res+B-1;
    }
    
    
    
    return count;
}
