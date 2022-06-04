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
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        vector<vector<string>>ans;
        
        getBoards(ans,board,n,0);
            
        return ans;
    }
};

































    
    
//     bool isSafe1(int i, int col, vector<string> board, int row) {
        
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
//         for(int j=i;j<row && col1>=0;j++)
//         {
//             if(board[j][col1]=='Q')
//                 return false;
//             col1--;
//         }

//             return true;
//     }

//     void get_boards(vector<string>&board,vector<vector<string>>&ans,int col,int row)
//     {
// //         base case
//         if(col==row)
//         {
//             ans.push_back(board);
//             return;
//         }
// //         recursive case
//         for(int i=0;i<row;i++)
//         {
//             if(isSafe1(i,col,board,row))
//             {
//                 board[i][col]='Q';
//                 get_boards(board,ans,col+1,row);
//                 board[i][col]='.';
//             }
//         }
//     }
    
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>>ans;
//         string s(n,'.');
//         vector<string>board(n);
//         for(int i=0;i<n;i++)
//         {
//             board[i]=s;
//         }
//         get_boards(board,ans,0,n);    
//             return ans;
//     }
// };
