int Solution::maximumGap(const vector<int> &A) {
   // using pigeonhole principle
   // the maximum diff between elements is max - min
   // now consider n-2 holes 
   // let the gap be evenly divided
   // therfore the gap will be max - min / (n - 1 ) ... 
   // 1 :- min, 2 :- min + gap, 3 :- min + 2*gap, 4 :- min + 3*gap, .... n :- min + (n-1)*gap
   // therefore min + (n-1)*gap = max
   // gap = max -min / (n-1)
   
   // now we have n bukets with value min + i. gap
   //each bucket will need a maximum and minimum value for comparision with next non empty bucket
   if(A.size()<2)
   return 0;
   
   int maxi=A[0];
   int mini=A[0];
   
   for(int i=1;i<A.size();i++)
   {
       maxi=max(maxi, A[i]);
       mini=min(mini, A[i]);
   }
   
   double gap = (double)(maxi - mini)/ (double)(A.size()-1);
   
   int max_bucket[A.size()-1];
   int min_bucket[A.size()-1];
   
   
//   memset(max_bucket, INT_MIN, sizeof(max_bucket));
//   memset(min_bucket, INT_MAX, sizeof(min_bucket));
   
   for(int i=0;i<A.size()-1;i++)
   {
       max_bucket[i]=INT_MIN;
       min_bucket[i]=INT_MAX;
   }
   for(int i=0;i<A.size();i++)
   {
       if(A[i]==mini || A[i]==maxi)
       continue;
       
       int idx = (double)(floor(A[i]-mini) / gap) ;
       //mini + idx.gap = A[i]
       //idx = A[i] - mini /gap
       
        max_bucket[idx] = max(max_bucket[idx], A[i]);
 
        min_bucket[idx] = min(min_bucket[idx], A[i]);
       
   }

   //check the maximum difference 
   int prev_value = mini;
   
   int res=0;
   
   for(int i=0;i<A.size()-1;i++)
   {
       if(min_bucket[i]==INT_MAX) //empty bucket
       {
           continue;
       }
       res=max(res, min_bucket[i] - prev_value);
       prev_value = max_bucket[i];
   }
   res=max(res, maxi-prev_value);
   return res;
   
}
