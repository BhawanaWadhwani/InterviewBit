//eg - A : [ 1, 3, 4, 3, 2 ]
//001
//011
//100
//011
//010

//missing = 5 repeated =3
vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
    //let nos a(repeated) and b
    //sum from 1 to n = n(n+1)/2
    //found_sum-a+b = sum
    //b-a=sum-found_sum - 1.
    
    
    //sum_sq = n*(n+1)*(2*n+1)/6
    //found_sum_sq - a*a + b*b = sum_sq 
    //b^2 - a^2 = sum_sq - found_sum_sq - 2.
    
    //(b-a)(b+a) = sum_sq - found_sum_sq
    
    //2 divided by 1
    
    //(b+a) = sum_sq - found_sum_sq / sum-found_sum - 3.
    
    //2*b = 1. + 3.
    
    long long n=A.size();
    long long sum= 0; 
    long long sum_sq = 0;
    for(long long i=0;i<A.size();i++)
    {
        sum+=(i+1);
        sum_sq += (i+1)*(i+1);
        
        sum-=A[i];
        sum_sq -= (long long)A[i]*A[i]; //IMPORTANT if A is 10^5 multilplication of integers won't result in long long
    }
    
    sum_sq/=sum;
    long long b=(sum+sum_sq)/2;
    long long a=(b-sum);
    b=(int)b;
    a=(int)a;
    
    vector<int>ans;
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}
