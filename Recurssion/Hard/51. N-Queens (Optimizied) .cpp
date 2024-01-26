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

        vector<int>left(n, 0);
        vector<int> lowerDiagonal(2*n -1, 0);
        vector<int> upperDiagonal(2*n -1, 0);

        getQueues(0, n, board, ans, left, lowerDiagonal, upperDiagonal);

        return ans;
    }

    void getQueues(int col, int n, vector<string>& board, vector<vector<string>>& ans,
                vector<int>& left, vector<int>& lowerDiagonal, vector<int>& upperDiagonal){

            //if col value equal to n then we get ans-board storing it into ans vector
            if(col == n){
                ans.push_back(board);
                return;
            }


        for(int row=0; row<n; row++){
            cout<<2;
            //checking is it safe to place Queue in perticular box
            if(left[row] == 0 && lowerDiagonal[row + col] == 0
             && upperDiagonal[n-1 + col - row] == 0){
                //is it safe then store it into location
                cout<<1;
                board[row][col] = 'Q';
                left[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n-1 + col - row] = 1;

                getQueues(col+1, n, board, ans, left, lowerDiagonal, upperDiagonal);
                
                //removing Queue for backtracking
                board[row][col] = '.';
                left[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n-1 + col - row] = 0;
            }
        }
    }

};
