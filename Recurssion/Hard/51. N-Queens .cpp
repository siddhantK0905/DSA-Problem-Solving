class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n,'.');

        // initailizing board with '.'
        for(int i=0; i<n; i++){
            board.push_back(s);
        }

        getQueues(0, n, board, ans);

        return ans;
    }

    void getQueues(int col, int n, vector<string>& board, vector<vector<string>>& ans){

            //if col value equal to n then we get ans-board storing it into ans vector
            if(col == n){
                ans.push_back(board);
                return;
            }


        for(int row=0; row<n; row++){
            //checking is it safe to place Queue in perticular box
            if(isSafe(row, col, board, n)){
                //is it safe then store it into location
                board[row][col] = 'Q';
                getQueues(col+1, n, board, ans);
                
                //removing Queue for backtracking
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, vector<string> board, int n){
        int dupRow = row;
        int dupCol = col;

        //Upper Diagonal
        while(row>= 0 && col >=0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        //left side
        row = dupRow;
        col = dupCol;
        while(row == dupRow && col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }

        //Lower Diagonal 
        row = dupRow;
        col = dupCol;

        while(row < n && col >=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }


        return true;
    }
};
