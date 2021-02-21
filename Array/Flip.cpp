vector<int> Solution::flip(string A) {
    vector<int>v;
    
    int start=0;
    int zero=0,one=0;
    int max_so_far = 0;
    int l=-1,r=-1;

    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='0')
        {
            zero++;
        }
        else
        {
            one++;
        }
        //if flip
        int total_ones=zero-one;
        if(total_ones>max_so_far)
        {
            max_so_far=total_ones;
            l=start;
            r=i;
        }
        if(total_ones<0)
        {
            start=i+1;
            zero=0;
            one=0;
        }
    }
    if(l==-1 && r==-1)
    return v;
    
    v.push_back(l+1);
    v.push_back(r+1);
    return v;
}
