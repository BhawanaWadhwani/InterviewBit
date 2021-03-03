//eg - A : [ 1, 3, 4, 3, 2 ]
//001
//011
//100
//011
//010

//missing = 5 repeated =3
vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
    long long xor_n=A[0]; //can't start with zero
    long long sum=0;
    for(int i=1;i<=A.size();i++)
    {
        xor_n^=i;
    }
    //cout<<xor_n<<" ";
    for(int i=1;i<A.size();i++)
    {
        xor_n^=A[i];
        sum+=A[i];
    }
    //cout<<xor_n<<" "; 
    //a^b=xor_n  eg - a=3(11) and b=5(101)...xor=110 (6)
    //sum-a+b=total ... 
    int set_bit_no = xor_n & ~(xor_n-1); //rightmost set bit =2 (6 & 5)
    //cout<<set_bit_no<<" ";
    
    long long a=0, b=0;
    for(int i=0;i<A.size();i++)
    {
        if(set_bit_no & A[i]) //xor of all nos have rightmost set bit(2)...nos - 3,3,2 result will be xor of all nos excluding the repeated nos whose rightmost bit is set
        {
            a^=A[i];
        }
        else //xor of all other nos..nos = 1,4
        {
            b^=A[i];
        }
    }
    for(int i=1;i<=A.size();i++)
    {
        if(set_bit_no & i) //from 1 to n all nos whose right most bit is set...this xor will give ont of the number
        {
            a^=i;
        }
        else
        {
            b^=i;
        }
    }
    for(int i=0;i<A.size();i++) //check if we found b as missing element or vice versa
    {
        if(A[i]==b)
        {
            swap(a,b);
        }
    }

    vector<int>ans;
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}
