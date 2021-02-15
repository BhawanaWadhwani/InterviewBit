vector<int> Solution::spiralOrder(const vector<vector<int> > &A) 
{
    vector<int>arr;
    int l=0,r=A[0].size()-1;
    int top=0;
    int bottom=A.size()-1;
    
    int dir=0;

    while(l<=r && top<=bottom)
    {
        if(dir==0)
        {
            for(int i=l;i<=r;i++)
            {
                arr.push_back(A[top][i]);
            }
            dir=1;
            top++;
        }
        else if(dir==1)
        {
            for(int i=top;i<=bottom;i++)
            {
                arr.push_back(A[i][r]);
            }
            r--;
            dir=2;
        }
        else if(dir==2)
        {
            for(int i=r;i>=l;i--)
            {
                arr.push_back(A[bottom][i]);
            }
            bottom--;
            dir=3;
        }
        else
        {
            for(int i=bottom;i>=top;i--)
            {
                arr.push_back(A[i][l]);
            }
            l++;
            dir=0;
        }
    }
    return arr;
}
