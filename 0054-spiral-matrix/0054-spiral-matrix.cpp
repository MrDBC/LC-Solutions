class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n=matrix[0].size();
        vector<int> ans;
        int top=0, down=m-1, left=0, right=n-1;
        int dirs= 0;
        while( top<=down && left<=right){
            
            // left to right movement
            if(!dirs){
                for( int i=left; i<=right; i++)
                    ans.push_back(matrix[top][i]);
                top++;
                dirs=1; 
            }
            
            // top to down movement
            else if( dirs==1){
                for( int i=top; i<=down; i++)
                    ans.push_back(matrix[i][right]);
                right--;
                dirs=2;
            }
            
            // right to left movement
            else if( dirs==2){
                for( int i=right; i>=left; i--)
                    ans.push_back(matrix[down][i]);
                down--;
                dirs=3;
            }
            
            // bottom to top movement
            else{
                for( int i=down ; i>=top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
                dirs=0;
            }
        }
        
        return ans;
    }
};