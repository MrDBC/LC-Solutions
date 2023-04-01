class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int,int>> pr;
        
        int n= groupSizes.size();
        for(int i=0;i <n; i++)
            pr.push_back({groupSizes[i], i});
        
        sort(begin(pr), end(pr));
        
        
        vector<vector<int>> ans;
        
        // 1  3 3 3  3 3 3
        vector<int> temp;
        for(int i=0;i <n; i++){
            
            int grpsize = pr[i].first, id= pr[i].second;
            
            // cout<<grpsize<<" "<<id<<endl;
            if( temp.size()< grpsize){
                temp.push_back(id);
            }
            
            
            if(temp.size()== grpsize){
                ans.push_back(temp);
                temp.clear();
            }
        }
        
        return ans;
            
    }
};