class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<vector<int>> G(n+1);

        for(vector<int>& path: paths){
            G[path[0]].push_back(path[1]);
            G[path[1]].push_back(path[0]);
        }

        vector<int> answer(n, 0);

        // we need to plant a flower in each garden(with a particular color)
        for(int i=1; i<=n; i++){

            // lets mark the color used by its adjacent garden's flower as used
            vector<bool> color_used(5, false);
            for(auto adj_flower: G[i])
                color_used[answer[adj_flower-1]] = true;

            // now run over the 4 types of flower(i.e, 1 ,2 ,3 4)
            // and give the current garden(i) flower the first unused color we encounter
            for(int col=1; col<=4; col++){
                if( color_used[col] == false){
                    answer[i-1]= col;
                    break;
                }
            }
            
        }

        return answer;
    }
};