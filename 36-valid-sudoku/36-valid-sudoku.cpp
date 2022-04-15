class Solution {
bool isSafe(int r , int c, vector<vector<char>>& board){
        //row
        char val = board[r][c];
        for(int i = 0 ; i < 9 ; i++){
            if(i != c && board[r][i]==val) return false;
        }
        for(int i = 0 ; i < 9 ; i++) {
            if(i != r && board[i][c] == val) return false;
        }
        
        int y = (r/3)*3;
        int x = (c/3)*3;
        
        for(int i = y ; i < y+3 ; i++){
            for(int j = x ; j < x+3 ; j++){
                if(!(i == r && j == c) && board[i][j] == val ) return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] != '.'){
                    if(!isSafe(i,j,board)) return false;
                }
            }
        }
        return true;
    }
};