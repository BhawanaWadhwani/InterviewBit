vector<int> Solution::subUnsort(vector<int> &A) 
{
	
    int start=0, end=A.size()-1;
    while(start+1<A.size() && A[start]<=A[start+1])
    {
        start++;
    }
    
    if(start==A.size()-1)
    return {-1};
    
    while(end-1>=0 && A[end]>=A[end-1])
    {
        end--;
    }
    
    //  Now we have a sorted array from A[0], A[1], A[2].... A[start], 
    //  unsorted array from A[start+1],...., A[end],
    //  and again sorted array from A[end+1], A[end+2],.... A[A.size()-1]
    
    //  eg - [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60]
    // start = 3
    // end = 7
    
    // 0-3 sorted
    // 4-7 unsorted
    // 8-10 sorted
    
    // Now we will check if sorting the middle array results in a completly sorted array or not
    //This will be possible if the minimum element from (4-7) will be greater than A[start]
    //and also maximum ele from 4-7 is less than A[end+1]
    
    //minimum of (25, 40, 32, 31) = 25
    //maximum of (25, 40, 32, 31) = 40
    
    // 25 > 30 therefore the starting index is not correct
    // while(A[start]>25)
    // {
    //     start--
    // }
    
    //Similarly for end

    
    int maxi=INT_MIN,mini=INT_MAX;
   // cout<<start<<" "<<end<<" . ";
    for(int i=start;i<=end;i++) //IMPORTANT - take from start to end not from start +1 to end
    {
        maxi=max(maxi, A[i]);
        mini=min(mini, A[i]);
    }

    for(int i = 0; i < start; i++) 
    { 
        if(A[i] > mini) 
        {  
            start = i; 
            break; 
        }      
    }  
      
    for(int i = A.size() -1; i >= end+1; i--) 
    { 
        if(A[i] < maxi) 
        { 
            end = i; 
            break; 
        }  
    }  
      
    vector<int>v={start, end};
    return v;
}
    
//     vector<int>v2=A;
//     sort(v2.begin(), v2.end());
    
//     int start=0;
//     while(start<A.size() && A[start]==v2[start])
//     {
//         start++;
//     }
//     if(start==A.size())
//     {
//         return {-1};
//     }
    
//     int end=A.size()-1;
//     while(end>=0 && A[end]==v2[end])
//     {
//         end--;
//     }
//     vector<int>v;
//     v.push_back(start);
//     v.push_back(end);
//     return v;
// }
