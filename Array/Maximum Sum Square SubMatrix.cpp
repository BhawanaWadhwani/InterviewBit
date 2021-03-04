//EXAMPLE
// [1, 1, 1, 1, 1]
// [2, 2, 2, 2, 2]
// [3, 8, 6, 7, 3]
// [4, 4, 4, 4, 4]
// [5, 5, 5, 5, 5]

int Solution::solve(vector<vector<int> > &A, int B) {
    int n=A.size();
    if(n==0)
    return 0;
    
    int m=A[0].size();
    
    // EXAMPLE ... A[i][j]+=A[i][j-1];
    // [1,  2,  3,  4,  5]
    // [2,  4,  6,  8, 10]
    // [3, 11, 17, 24, 27]
    // [4,  8, 12, 16, 20]
    // [5, 10, 15, 20, 25]

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            A[i][j]+=A[i][j-1];
        }
    }
    
    // EXAMPLE ... A[i][j]+=A[i-1][j];
    // [1,   2,  3,  4,  5]
    // [3,   6,  9, 12, 15]
    // [6,  17, 26, 36, 42]
    // [10, 25, 38, 52, 62]
    // [15, 35, 53, 72, 87]
    for(int j=0;j<m;j++)
    {
        for(int i=1;i<n;i++)
        {
            A[i][j]+=A[i-1][j];
        }
    }
    
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<A[i][j]<<" ";
    //     }
    //     cout<<" . ";
    // }
    
    
    // EXAMPLE 
    // [1,   2,  3,  4,  5]
    // [3,   6,  9, 12, 15]
    // [6,  17, 26, 36, 42]
    // [10, 25, 38, 52, 62]
    // [15, 35, 53, 72, 87]
    
    //i=2, j=2;
    //temp=26
    //i-B = 2-3<0
    //j-B = 2-3<0
    
    //for any i, j it is the sum of all the elements until A[i][j]
    //Now since we want only B*B matrix
    //we remove A[i-B][j] first
    //then we remove A[i][j-B] 
    //if we are removing both, we are removing the A[i-B][j-B] sum twice
    
    // {[1,   2,  3,  4,}  5]
    // {[3,   6,  9, [12],} 15]
    // {[6,  17, 26, 36,} 42]
    // {[10, 25, 38, 52,} 62]
    // {[[15], 35, 53, 72,} 87]
    
    //Eg i=5, j=4
    //sum=72
    //required sum will be of 3*3
    //remove 12 .. all the 4 elements sum of first 2 rows
    //remove 15 .. all the 5 elements sum of first col
    //therefore we are removing row[0]col[0] and row[1]col[0] twice
    //therfore add sum at [i-B][j-B]
    
    int max_sum=INT_MIN;
    for(int i=B-1;i<n;i++)
    {
        for(int j=B-1;j<m;j++)
        {
            int temp=A[i][j];
            if(i-B>=0)
            {
                temp-=A[i-B][j];
            }
            if(j-B>=0)
            {
                temp-=A[i][j-B];
            }
            if(i-B>=0 && j-B>=0)
            {
                temp+=A[i-B][j-B];
            }
            max_sum=max(max_sum, temp);
        }
    }
    
    return max_sum;
}
