class Solution {
public:
    bool isSafe1(int row, int col, vector<string> board, int n) {
        // check upper diagonal
        int duprow = row;
        int dupcol = col; 
        
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        col = dupcol; 
        row = duprow;
        while(col>=0) {
            if(board[row][col] == 'Q') 
                return false;
            col--; 
        }
    
        row = duprow;
        col = dupcol; 
        while(row<n && col>=0) {
            if(board[row][col] == 'Q') 
                return false;
            row++;
            col--; 
        }
        
        return true; 
    }

    void get_boards(vector<string>&board,vector<vector<string>>&ans,int col,int row)
    {
//         base case
        if(col==row)
        {
            ans.push_back(board);
            return;
        }
//         recursive case
        for(int i=0;i<row;i++)
        {
            if(isSafe1(i,col,board,row))
            {
                board[i][col]='Q';
                get_boards(board,ans,col+1,row);
                board[i][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n,'.');
        vector<string>board(n);
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        get_boards(board,ans,0,n);    
            return ans;
    }
};
    
    
    
//     bool place_queen(vector<string>&board,int col,int i,int row)
//     {
//         for(int j=col;j>=0;j--)
//         {
//             if(board[i][j]=='Q')
//                 return false;
//         }
//         int col1=col;
//         for(int j=i;j>=0 && col>=0;j--)
//         {
//             if(board[j][col]=='Q')
//                 return false;
//             col--;
//         }
//         for(int j=i;j<row && col1<row;j++)
//         {
//             if(board[j][col1]=='Q')
//                 return false;
//             col1--;
//         }

//             return true;
//     }
    