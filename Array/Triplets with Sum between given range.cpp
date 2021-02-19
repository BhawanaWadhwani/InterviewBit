int Solution::solve(vector<string> &A) 
{
//needed in O(1) time. 
    if(A.size()<3)
    return 0;
    
    double a=stof(A[0]);
    double b=stof(A[1]);
    double c=stof(A[2]);
    
    if((a+b+c)>1 && (a+b+c)<2)
    return 1;
    
    double sum=a+b+c;
    
    for(int i=3;i<A.size();i++)
    {
        double temp=stof(A[i]);
        
        if(sum<1)
        {
            if(temp > min(a,min(b,c)))
            {
                if(a<b && a<c)
                {
                    a=temp;
                    sum=a+b+c;
                }
                else if(b<a && b<c)
                {
                    b=temp;
                    sum=a+b+c;
                }
                else
                {
                    c=temp;
                    sum=a+b+c;
                }
            }
        }
        else if(sum>2)
        {
            if(temp<max(a,max(b,c)))
            {
                if(a>b && a>c)
                {
                    a=temp;
                    sum=a+b+c;
                }
                else if(b>a && b>c)
                {
                    b=temp;
                    sum=a+b+c;
                }
                else
                {
                    c=temp;
                    sum=a+b+c;
                }
            }
        }
        
        if(sum>1 && sum<2)
        return 1;
    }
    return 0;
}
