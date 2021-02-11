int Solution::titleToNumber(string A) {
    int num=0;
    
    for(int i=0;i<A.length();i++)
    {
        int nn=A[i]-'A'+1; // A=1 B=2 and so on
        num=num*26+nn; //initial num*26 + nn ...  eg- BC ..B=2 num=2 .... C=3 num=2*26 + 3
    }
    
    return num;
}
