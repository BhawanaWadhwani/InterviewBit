//recursively finding 
//1
//1 1
//1 2 1 .. 1 (1+1) 1
//1 3 3 1 .. 1 (1+2) (2+1) 1
//1 4 6 4 1 .. 1 (1+3) (3+3) (3+1) 1
//1 5 10 10 5 1 .. 1 + (1+4) (4+6) (6+4) (4+1) 1
//A[i][j] = A[i-1][j]+ A[i-1][j-1]

vector<vector<int> > Solution::solve(int A) 
{
    vector<vector<int>>vec;
    vector<int>v;
    if(A==0)
    return vec;
    
    v.push_back(1);
    vec.push_back(v);
    if(A==1)
    return vec;
    
    v.push_back(1);
    vec.push_back(v);
    if(A==2)
    return vec;
    
    for(int i=2;i<A;i++)
    {
        v.clear();
        v.push_back(1);
        for(int j=0;j<i-1;j++)
        {
            v.push_back(vec[i-1][j]+vec[i-1][j+1]);
        }
        v.push_back(1);
        vec.push_back(v);
    }
    return vec;
}
