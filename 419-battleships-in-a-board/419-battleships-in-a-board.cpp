class Solution {
public:
    
    void markAll(int i, int j, int n, int m, vector<vector<char>>& board)
    {
        if(i >= 0 && j >= 0 && j < m && i < n && board[i][j] == 'X')
        {
            board[i][j] ='.';
            markAll(i+1, j, n, m, board);
            markAll(i, j+1, n, m, board);
            markAll(i, j-1, n, m, board);
            markAll(i-1, j, n, m, board);
        }
        return;
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        
        int n = board.size(), m = board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 'X')
                {
                    ans++;
                    markAll(i, j, n, m, board);
                }
            }
        }
        
        return ans;
    }
};