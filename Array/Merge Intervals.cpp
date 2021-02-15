/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) 
{
    vector<Interval> sol;
    int i = 0;
    
    //smaller than the interval .... newInterval.start>intervals[i].end
    while(i < intervals.size() && newInterval.start>intervals[i].end)
        sol.push_back(intervals[i++]);
    
    //overalpping intervals.... newInterval.end>=intervals[i].start and updating new Intervals
    while(i < intervals.size() && newInterval.end>=intervals[i].start){
        newInterval.start = min(newInterval.start,intervals[i].start);
        newInterval.end = max(newInterval.end,intervals[i].end);
        i++;
    }
    
    sol.push_back(newInterval);
    
    //left intervals
    while(i < intervals.size())
        sol.push_back(intervals[i++]);
        
    return sol;
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

