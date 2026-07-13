class Solution {
public:
    bool dfs(int index, int i, int j, string &word, vector<vector<char>> &board) {
        if(index == word.size()) return true;
        if(i == board.size() || i < 0) return false;
        if(j == board[0].size() || j < 0) return false;
        if(word[index]!=board[i][j]) return false;    
        char original = board[i][j];
        board[i][j] = '#';
        index++;
        bool found = dfs(index, i+1, j, word, board) || dfs(index, i-1, j, word, board) || dfs(index, i, j+1, word, board) || dfs(index, i, j-1, word, board);
        board[i][j] = original;
        return found;
    } 

    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                ans = dfs(0, i, j, word, board);
                if(ans) return ans;
            }
        }
        return ans;
    }
};
