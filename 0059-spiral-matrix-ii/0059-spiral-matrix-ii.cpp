class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));

        int left=0, right=n-1, top=0, bottom=n-1;
        // 0-ltor, 1- toptobottom, 2 - right to left, 3 bottom to top 
        int dir=0; 
        int val=1;
        while( left<= right and top<=bottom){

            if( dir==0){
                for(int i=left; i<=right; i++)
                    mat[top][i]= val++;
                ++top;
                dir++;
            }
            else if( dir ==1){
                for(int i=top; i<=bottom; i++)
                    mat[i][right]=val++;
                --right;
                dir++;
            }
            else if( dir==2){
                for(int i=right; i>=left; i--)
                    mat[bottom][i]= val++;
                --bottom;
                dir++;
            }
            else if( dir ==3){
                for(int i=bottom; i>=top; i--)
                    mat[i][left]=val++;
                ++left;
                dir=0;
            }
        }

        return mat;
    }
};