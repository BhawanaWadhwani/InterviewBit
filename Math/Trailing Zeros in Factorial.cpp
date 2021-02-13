int Solution::trailingZeroes(int A) {
    int c=0;
    while(A>0)
    {
        c+=A/5;
        A/=5;
    }
    return c;
}

// 10=5*2
// So we'll count number of 5's because factorial will have more 2's than 5

//5,10,15,20 - 1 5s
//25, 50, 75, 100 - 2 5s
//So number of 5 increases
// Hence solution 
//First divide by 5 add in count
//then divide by 25 
// then divide by 5^3 and so on

// So first divide by 5 and again by 5 (same logic extended)
