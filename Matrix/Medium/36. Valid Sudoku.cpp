class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] != '.'){
                    if(isValid(i, j, board, board[i][j])== false) return false;
                }
            }
        }

        return true;
    }

    bool isValid(int row, int col, vector<vector<char>>& board, char ch){
        int dumRow = row;
        int dumCol = col;
        for(int i=0; i<9; i++){
            if(board[row][i] == ch && i!= dumCol) return false;

            if(board[i][col] == ch && i != dumRow) return false;

            int newRow = 3* (row/3) + i / 3;
            int newCol = 3 *(col/3) + i % 3;
            if(board[newRow][newCol] == ch && newRow != dumRow && newCol != dumCol) return false;
        }

     return true;
    } 
};
