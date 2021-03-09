void Solution::arrange(vector<int> &A) 
{
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        A[i]+=(A[A[i]]%n)*n;
    }
    for(int i=0;i<n;i++)
    {
        A[i]/=n;
    }
}
//4, 0, 2, 1, 3
//A[0] = A[A[0]] = A[4] = 3
//we store A[0] as A[0] + (A[A[0]]%n)*n
//that is A[0]=4+(3*5) = 4+15 = 19
//now if we retirve for A[1]
//A[1] = A[0] = 4
//we store A[1] as A[1] + (A[A[1]]%n)*n
//A[1] = 0 + (19%5)*5
//we do this because 19%5=4 that was the actual value, because we edited the previous value in such a way
//that A[i] was A[i] + b*n
//so modulo b*n divided by n will be 0, left will be A[i]

//in last A[i]/=n
//A[i] = a + b*n
//here a < n
//therefore, a/n = 0 
