int Solution::maximumGap(const vector<int> &A) {
    priority_queue<int>pq;
    for(int i=0;i<A.size();i++)
    {
        pq.push(A[i]);
    }
    
    int ans=0;
    if(A.size()<2)
    return 0;
    
    int f=pq.top();
    pq.pop();
    int s;
    while(pq.size()>0)
    {
        s=pq.top();
        pq.pop();
        //cout<<f<<" "<<s<<" . ";
        int res=f-s;
        
        ans=max(ans,res);
        f=s;
    }
    
    return ans;
}
