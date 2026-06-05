class Solution {
public:
    bool containsDuplicates(vector<char>&arr) {
        vector<int> hash(10, 0);
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == '.') continue;
            if(hash[arr[i]-'0']) return true;
            hash[arr[i]-'0']++;
        }
        return false; 
    }
    vector<char> createVectorOfBox(vector<vector<char>>& board, int x, int y) {
        vector<char> ans;
        for(int i = x-1; i <= x+1; i++) {
            for(int j = y-1; j <= y+1; j++) {
                ans.push_back(board[i][j]);
            }
        }
        return ans;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        //checking for rows
        for(int i = 0; i < board.size(); i++) {
            if(containsDuplicates(board[i])) return false;
        }
        //checking for columns
        for(int j = 0; j < board.size(); j++) {
            vector<char> col;
            for(int i = 0; i < board.size(); i++) col.push_back(board[i][j]);
            if(containsDuplicates(col)) return false;
        }
        //checking for squares
        for(int i = 1; i<board.size(); i+=3) {
            for(int j = 1; j < board.size(); j+=3){
                vector<char> vecBox = createVectorOfBox(board, i, j);
                if(containsDuplicates(vecBox)) return false;
            }
        }
        return true;
    }
};
