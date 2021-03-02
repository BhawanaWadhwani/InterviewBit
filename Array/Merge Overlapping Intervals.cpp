/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool compare(Interval a, Interval b)
 {
     return a.start<b.start;
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), compare);
    
    vector<Interval>ans;
    ans.push_back(A[0]);
    int last=A[0].end;
    
    for(int i=1;i<A.size();i++)
    {
        if(A[i].start>ans[ans.size()-1].end)
        {
            ans.push_back(A[i]);
        }
        else
        {
            ans[ans.size()-1].end=max(ans[ans.size()-1].end, A[i].end);
            last=max(ans[ans.size()-1].end, A[i].end);
        }
    }
    
    return ans;
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
