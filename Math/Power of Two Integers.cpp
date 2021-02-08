int Solution::isPower(int A) {
    if(A==1)
    return true;
    
    for(int i=2;i*i<=A;i++)
    {
        if(A%i==0)
        {
            int s=A;
            while(s%i==0)
            {
                s/=i;
            }
            if(s==1)
            return true;
        }
    }
    
    return false;
}

/*
another sol 

int Solution::isPower(int A) 
{
    if(A==1)
        return 1;
    int i;
    for(i=2;i*i<=A;i++)
    {
        int c=log(A)/log(i);
        if(pow(i,c)==A)
            return 1;
    }
    return 0;
}
*/

