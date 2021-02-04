int Solution::solve(int A, vector<int> &B) {
    int total=0;
    for(int i=0;i<A;i++)
    {
        total+=B[i];
    }
    if(total%3!=0)
    {
        return 0;
    }
    
    vector<int>fromback(A,0);
    int req=total/3;
    int temp=0;
    
    for(int i=A-1;i>=0;i--)
    {
        temp+=B[i];
        if(temp==req)
        {
            fromback[i]=1;
        }
    }
    
    int count=0;
    temp=0;
    for(int i=0;i<A;i++)
    {
        temp+=B[i];
        if(temp==req)
        {
            for(int j=i+2;j<A;j++) //i+1 has to be middle array element
            {
                if(fromback[j]==1)
                {
                    count++;
                }
            }
        }
    }
    
    return count;
}
