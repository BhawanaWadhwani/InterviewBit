bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) 
{
    //not given arrival and departure on same day. Therefore sort both the vectors and check if for k consecutive days stay is possible or not
    
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    for (int i=K; i<arrive.size();i++)
    {
        if (arrive[i]<depart[i-K])
            return false;
    }
    return true;
}
