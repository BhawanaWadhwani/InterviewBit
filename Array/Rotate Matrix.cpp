void Solution::rotate(vector<vector<int> > &A) {
    int n=A.size();
    
    //vector<vector<int>> B(n,vector<int> (n));
    for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n-i-1;j++)
        {
            //Divide array into 4 parts along diagonals
            //move each part to 90 degrees
            int temp=A[i][j];
            A[i][j]=A[n-j-1][i];
            A[n-j-1][i]=A[n-i-1][n-j-1];
            A[n-i-1][n-j-1]=A[j][n-i-1];
            A[j][n-i-1]=temp;
        }
    }
}
