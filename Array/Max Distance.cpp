//Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
//In order of N

int Solution::maximumGap(const vector<int> &A) 
{
    vector<int>LeftMin(A.size());
    vector<int>RightMax(A.size());
    
    LeftMin[0]=A[0];
    for(int i=1;i<A.size();i++)
    {
        LeftMin[i]=min(LeftMin[i-1], A[i]);
    }
    RightMax[A.size()-1]=A[A.size()-1];
    for(int i=A.size()-2;i>=0;i--)
    {
        RightMax[i]=max(RightMax[i+1], A[i]);
    }
    
    int i = 0, j = 0, maxDiff = -1;
    while (j < A.size() && i < A.size()) 
    {
        if (LeftMin[i] <= RightMax[j]) 
        {
            maxDiff = max(maxDiff, j - i);
            j = j + 1; //right side adding on
        }
        else
        {
            i = i + 1; //left side adding on
        }
    }
 
    return maxDiff;
}
