string Solution::convertToTitle(int A) {
    string s="";
    
    while(A>0)
    {
        int rem=A%26;
        A/=26;
        
        if(rem==0)
        {
            //if z subtract a with 1. ex- 26 Z... A=1 so reduce A
            s+="Z";
            A--;
            continue;
        }
        s+=('A'+rem-1);
    }
    s=string(s.rbegin(),s.rend());
    return s;
}
