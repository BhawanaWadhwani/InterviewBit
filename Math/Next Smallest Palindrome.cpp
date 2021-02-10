string Solution::solve(string A) 
{
    string initial_no=A;
    int l=0,r=A.size()-1;
    int n=A.size();
    
    while(l<=r) //we'll change the right digits and make it equal to left ones. For eg - "87654" = "87678" and "561389" - "561165"
    {
        if(A[l]!=A[r])
        {
            A[r]=A[l];
        }
        r--;
        l++;
    }
    
    if(A>initial_no) //if the number that is made palindrome is greater than initial number return the number
    return A;
    
    int count=1; //otherwise take a counter and add that counter to the mid digit/digits and then return the number
    l--;
    r++; //l and r are mid digit/ digits
    
    while(l>=0 && r<n && A[l]=='9' && A[r]=='9') //while left and right digits are 9 make them 0 and move it opp directions "129921" = "120021" "999"="000"
    {
        A[l]='0';
        A[r]='0';
        
        l--;
        r++;
    }
    
    //cout<<A<<" "<<l<<" "<<r<<' ';
    
    if(l>=0 && r<n) //still if we have valid left and right add 1 to them and make count 0 "12321" = "12421" "120021"="130031"
    {
        int num=A[l]-'0';
        num++;
        //cout<<num<<'\n';
        A[l]=(char)num+48;
        A[r]=(char)num+48;
        count=0;
    }
    
    if(count==1) //otherwise add 1 to start and end "00"="101" "000"="1001"
    {
        A[0]='1';
        A+='1';
    }
    
    //cout<<A<<" ";
    return A;
}
