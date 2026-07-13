class Solution {
public:

    vector<string> convert_to_vector_string(vector<vector<int>> &board)  {
        vector<string> ans;
        for(int i = 0; i < board.size(); i++) {
            string t;
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] > 1e5) 
                t.push_back('Q');
                else t.push_back('.');
            }
            ans.push_back(t);
        }
        return ans;
    }

    void invalid(int row, int column, vector<vector<int>> &board) {
        //row
        for(int j = 0; j < board[row].size(); j++) {
            board[row][j]--;
        }
        //column
        for(int i = 0; i < board.size(); i++) {
            board[i][column]--;
        }
        //right diag
        int startCol = max(0, column-row);
        int startRow = max(0, row - (column - startCol));
        for(int i = startRow, j = startCol; i<board.size() && j < board.size(); i++, j++) board[i][j]--;
        //left diag
        startRow = min((int)board.size()-1, row+column);
        startCol = max(0, column - (startRow-row));
        for(int i = startRow, j = startCol; i>=0 && j < board.size(); i--, j++) board[i][j]--;

        board[row][column] = 2e5;        
    }

    void valid(int row, int column, vector<vector<int>> &board) {
        //row
        for(int j = 0; j < board[row].size(); j++) {
            board[row][j]++;
        }
        //column
        for(int i = 0; i < board.size(); i++) {
            board[i][column]++;
        }
        //right diag
        int startCol = max(0, column-row);
        int startRow = max(0, row - (column - startCol));
        for(int i = startRow, j = startCol; i<board.size() && j < board.size(); i++, j++) board[i][j]++;
        //left diag
        startRow = min((int)board.size()-1, row+column);
        startCol = max(0, column - (startRow-row));
        for(int i = startRow, j = startCol; i>=0 && j < board.size(); i--, j++) board[i][j]++;

        board[row][column] = 0;        
    }

    void dfs(int row, vector<vector<int>> &board, vector<vector<string>> &ans) {
        // termination conditions
        if(row == board.size()) {
            ans.push_back(convert_to_vector_string(board));
            return;
        }
        
        // main loop
        for(int j = 0; j < board[row].size(); j++) {
            if(board[row][j] == 0) {
                invalid(row, j, board);
                dfs(row+1, board, ans);
                valid(row, j, board);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;
        dfs(0, board, ans);
        return ans;
    }
};
