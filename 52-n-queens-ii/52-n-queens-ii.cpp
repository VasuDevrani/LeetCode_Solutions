class Solution {
public:
    
    bool isSafe(vector<string>board, int n, int col, int row)
    {
        for(int i=col;i>=0;i--)
        {
            if(board[row][i] == 'Q')
                return false;
        }
        int i = row, j = col;
        while(j>=0 && i>=0)
        {
            if(board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        i = row;
        j = col;
        while(j>=0 && i<n)
        {
            if(board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    void getBoards(vector<vector<string>>&ans, vector<string>&board, int n,int col)
    {
        if(col == n)
        {
            for(int i=0;i<ans.size();i++)
            {
                if(board == ans[i])
                    return;
            }
            ans.push_back(board);
            return ;
        }
        
        for(int i=0;i<n;i++) // rows
        {
            if(isSafe(board,n,col,i))
            {
                board[i][col] = 'Q';
                getBoards(ans,board,n,col+1);
                board[i][col] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<string>board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        vector<vector<string>>ans;
        
        getBoards(ans,board,n,0);
            
        return ans.size();
    }
};