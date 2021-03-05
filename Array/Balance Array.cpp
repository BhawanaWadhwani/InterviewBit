int Solution::solve(vector<int> &A) {
    if(A.size()==0)
    return 0;
    if(A.size()==1)
    return 1;
    
    vector<long>suffix_even;
    vector<long>suffix_odd;
    long last_odd=0;
    long last_even=0;
    
    for(int i=0;i<A.size();i++)
    {
        if(i%2==0)  //odd 0 based indexing
        {
            last_odd+=A[i];
        }
        else
        {
            last_even+=A[i];
        }
        suffix_odd.push_back(last_odd);
        suffix_even.push_back(last_even);
    }
    
    last_odd=0;
    last_even=0;
    vector<long>right_even;
    vector<long>right_odd;
    for(int i=A.size()-1;i>=0;i--)
    {
        if(i%2==0)
        {
            last_odd+=A[i];
        }
        else
        {
            last_even+=A[i];
        }
        right_odd.push_back(last_odd);
        right_even.push_back(last_even);
    }
    reverse(right_odd.begin(), right_odd.end());
    reverse(right_even.begin(), right_even.end());
    // for(int i=0;i<A.size();i++)
    // {
    //     cout<<right_odd[i]<<" ";
    // }
    
    int c=0;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        long s_even=0;
        long s_odd=0;
        if(i-1>=0)
        {
            s_even+=suffix_even[i-1];
            s_odd+=suffix_odd[i-1];
        }
        if(i+1<n)
        {
            s_even+=right_odd[i+1];
            s_odd+=right_even[i+1];
        }
        if(s_even==s_odd)
        {
            c++;
        }
    }
    return c;
}
