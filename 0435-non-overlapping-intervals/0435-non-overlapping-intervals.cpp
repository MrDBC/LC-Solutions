bool myComp( vector<int> a, vector<int> b ){
    return (a[0] == b[0])? (a[1]<b[1]) : (a[0]<b[0]) ;
} 
class Solution {
public:       
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if( n ==1)
            return 0;
        
        int num_removed = 0;
        sort( intervals.begin(), intervals.end() );
        int nextstart = intervals[n-1][0];
        
        // [[1,2],[1,3] [2,3],[3,4],]
        for( int i = n-2; i>=0; i-- ){
            
            if( intervals[i][1] > nextstart  ){
                num_removed++;
                nextstart= max( nextstart, intervals[i][0] ); // remove the interval having less start(left one)
                // so that the right interval has greater chance of not overlapping with the next left interval
            }
            else
                nextstart = intervals[i][0];
        }
        return num_removed;
    }
};