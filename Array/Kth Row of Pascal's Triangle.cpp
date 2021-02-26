//Kth row in pascal triangle will have K+1 elements
//First element will be one
//All the other elements will be equal to nCr
//1
//1 1
//1 2 1
//1 3 3 1 ... 3C0(1) 3C1(3) 3C2(3) 3C3(1)
//1 4 6 4 1 ... 4C0(1) 4C1(4) 4C2(6) 4C3(4) 4C4(1)
//1 5 10 10 5 1 ... 5C0(1) 5C1(5) 5C2(10) 5C3(10) 5C4(5) 5C5(1)

//nCr = n! / (n-r)! * r!
//nCr-1 = n! / (n-r+1)! *(r-1)!
//nCr-1 = (nCr * (n-r)! * r!) / ((n-r+1)! *(r-1)!)
//nCr-1 = (nCr * r) / (n-r+1)
//nCr = nCr-1 * (n-r+1) / r
vector<int> Solution::getRow(int A)
{
    vector<int>v;
    int prev=1; //nC0
    v.push_back(prev);
    for(int i=1;i<=A;i++)
    {
        int cur=(prev*(A-i+1))/i; 
        v.push_back(cur);
        prev=cur;
    }
    return v;
}

