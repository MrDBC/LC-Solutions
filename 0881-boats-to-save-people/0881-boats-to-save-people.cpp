class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n= people.size();
        
        // 1 2 2 3
        sort(people.begin(), people.end());
        
        // [5,1,4,2] limit =6

        int i=0,j=n-1, boats=0;
        while( i<=j){
            if( i==j){
                ++boats;
                break;
            }
            if( people[i]+people[j] <= limit)
                ++i;
            
            ++boats;
            --j;
        }
        return boats;
    }
};