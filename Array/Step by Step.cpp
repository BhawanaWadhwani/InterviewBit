int Solution::solve(int A) {
    
    A=abs(A);
    //doesn't matter in possitive side or negtive;
     
    /* 
    initially let sum=0
    
    while sum<=target(A)
    sum+=i ( i=1,2,3...n)
    
    now if sum==target
    return
    
    otherwise if sum>target
    if from all the steps taken let one of the step be in negative direction
    
    if i th step was taken in negative direction sum would have been reduced by 2*i
    
    therefore the new sum = sum - 2*i =target
    2*i = sum - target
    
    so sum-target should be even
    
    otherwise more numbers would be added
    
    eg-
    sum = 1 + 2 + 3 + 4 + 5 (15)
    assume the target needed = 11
    2*i = 15 - 11
    i=2
    
    sum = 1 + 2 + 3 + 4 + 5 (15)
    assume the target needed = 12
    2*i = 15 - 12
    i = 1.5
    not possible 
    
    therefore, add one more number
    sum = 15 + 6 =21
    2*i = 21 - 12 
    2 * i = 6
    
    sum = 21 + 7 = 28
    2*i = 28 - 12 = 16
    i = 8
    (3+5 steps backward)
    */
    
    
    int sum = 0, step = 0; 
    while (sum < A || (sum - A) % 2 != 0) { 
        step++; 
        sum += step; 
    } 
    return step; 
    
    
    
}
