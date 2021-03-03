void Solution::setZeroes(vector<vector<int> > &A) {
    //IN ORDER OF N SPACE
    // set<int>row;
    // set<int>col;
    // for(int i=0;i<A.size();i++)
    // {
    //     for(int j=0;j<A[i].size();j++)
    //     {
    //         if(A[i][j]==0)
    //         {
    //             row.insert(i);
    //             col.insert(j);
    //         }
    //     }
    // }
    // for(auto i:row)
    // {
    //     for(int j=0;j<A[i].size();j++)
    //     {
    //         A[i][j]=0;
    //     }
    // }
    // for(auto j:col)
    // {
    //     for(int i=0;i<A.size();i++)
    //     {
    //         A[i][j]=0;
    //     }
    // }
    
    //MORE OPTIMIZED WAY
    //IN ORDER OF 1 SPACE
    
    bool first_row_has_zero=false;
    bool first_col_has_zero=false;
    
    for(int i=0;i<A[0].size();i++)
    {
        if(A[0][i]==0)
        {
            first_row_has_zero=true;
            break;
        }
    }
    for(int i=0;i<A.size();i++)
    {
        if(A[i][0]==0)
        {
            first_col_has_zero=true;
            break;
        }
    }
    
    //checked if the first row and col has zero or not
    
    for(int i=1;i<A.size();i++)
    {
        for(int j=1;j<A[i].size();j++)
        {
            if(A[i][j]==0)
            {
                A[i][0]=0; //first of row set to zero //we can't change the current one because we need to maintain initial values without extra space
                A[0][j]=0; //first of col set to zero
            }
        }
    }
    for(int i=1;i<A.size();i++)
    {
        for(int j=1;j<A[i].size();j++)
        {
            if(A[i][0]==0 || A[0][j]==0)
            {
                A[i][j]=0;
            }
        }
    }
    if(first_row_has_zero)
    {
        for(int i=0;i<A[0].size();i++)
        {
            A[0][i]=0;
        }
    }
    if(first_col_has_zero)
    {
        for(int i=0;i<A.size();i++)
        {
            A[i][0]=0;
        }
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
