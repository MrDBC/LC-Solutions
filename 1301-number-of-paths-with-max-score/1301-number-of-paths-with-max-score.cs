public class Solution 
{
    private int[,][] dp;
    
    private const int MOD = 1000000007;
    
    public int[] PathsWithMaxScore(IList<string> board) 
    {
        int m = board.Count;
        int n = board[0].Length;
        
        dp = new int[m, n][];
        
        dp[m - 1, n - 1] = new int[] { int.MaxValue, int.MaxValue };
        
        int[] result = PathsWithMaxScore(board, 0, 0, m, n);
        
        //Chech whether we reached end
        if(dp[m - 1, n - 1][0] != int.MaxValue)
            return result;
        else
            return new int[]{ 0, 0 };
    }
    
    private int[] PathsWithMaxScore(IList<string> board, int r, int c, int m, int n)
    {
        if(r > m - 1 || c > n - 1 || board[r][c] == 'X')
            return new int[] { 0, 0 };
			
        //Base case once we reach the end, we return a zero sum with count as 1
        if(r == m - 1 && c == n - 1)
        {
            dp[r, c] = new int[] { 0, 1 };
            return dp[r, c];
        }
        
        if(dp[r, c] != null)
            return dp[r, c];
        
        int val = char.IsDigit(board[r][c]) ? (int)char.GetNumericValue(board[r][c]) : 0;
        
        int[] down = PathsWithMaxScore(board, r + 1, c, m, n);
        
        int[] right = PathsWithMaxScore(board, r, c + 1, m, n);
        
        int[] upRightDiag = PathsWithMaxScore(board, r + 1, c + 1, m, n);
        
        int[] next = new int[2];
        
        next[0] = Math.Max(down[0], Math.Max(right[0], upRightDiag[0]));
        
		//If the max is equal to the sum from left path add the count
        if(next[0] == down[0])
            next[1] = ((next[1] + down[1]) % MOD);
        
		//If the max is equal to the sum from right path add the count
        if(next[0] == right[0])
            next[1] = ((next[1] + right[1]) % MOD);
        
		//If the max is equal to the sum from diag path add the count
        if(next[0] == upRightDiag[0])
            next[1] = ((next[1] + upRightDiag[1]) % MOD);
        
		//Add the current location's val
        next[0] += val;
        
        dp[r, c] = next;
        
        return next;
    }
}