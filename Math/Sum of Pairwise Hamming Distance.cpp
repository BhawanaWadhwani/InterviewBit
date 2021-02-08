int Solution::hammingDistance(const vector<int> &A) {
    long ans=0;
    
    for(int i=0;i<32;i++)
    {
        unsigned x=1<<i;
        long c=0;
        
        for(int j=0;j<A.size();j++)
        {
            if(A[j] & x)
            {
                c++;
            }
        }
        
        long c2=A.size()-c;
        ans+=(2*c*c2);
        ans%=1000000007;
    }
    return ans%1000000007;
}
