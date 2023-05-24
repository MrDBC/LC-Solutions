class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b, int k) {
        
        
        priority_queue<pair<int, int> >  pq2;
        priority_queue<int, vector<int>, greater<int> > largestk;
        int n= a.size();
        
        long long sum=0 ,  maxi=INT_MIN;
        
        for(int i=0; i<n; i++)
            pq2.push({b[i], a[i]});
        
        
        while( !pq2.empty()){
            int top_val = pq2.top().second; //5 25 15 22
            int multi_factor= pq2.top().first; // 30 25 25 22
            
            sum+= top_val; // 5 30 45 67
            
            // we are taking the current nums1 value, and the sum of the top (k-1) elements in the minheap
            if(largestk.size() > (k-1) ){
                sum-= largestk.top(); // 67-5 = 62
                largestk.pop();
            }
            
            if( largestk.size() == k-1){
                 // 1125,  62*22= 1384
                maxi = max( maxi, sum * multi_factor); // 1125, 1384
            }

            // we dont want this to be popped , so we are addint it at last
            largestk.push(top_val); // minheap  15 22 25
            
            pq2.pop();
        }
        
        // cout<<maxi<<endl;
        return maxi;
        
        
    }
};