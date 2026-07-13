class Solution {
public:
    struct Node {
        Node* links[26];
        bool exist = false;
        bool end = false;

        Node* getLink(char ch) {
            return links[ch-'a'];
        }

        void setLink(char ch, Node* link) {
            links[ch-'a'] = link;
        } 

        void setExist() {
            exist = true;
        }

        bool getExist() {
            return exist;
        }

        void setEnd() {
            end = true;
        }

        bool getEnd() {
            return end;
        }

    };

    void dfs(int i, int j, Node* node, vector<vector<char>> &board) {
        if(i<0 || i > board.size()-1) return;
        if(j<0 || j > board[i].size()-1) return;
        if(board[i][j]=='#') return;
        if(!node->getLink(board[i][j])) return;

        char original = board[i][j];
        // marking cell visited
        board[i][j] = '#';
        Node* nextNode = node->getLink(original);
        if(nextNode->getEnd()) nextNode->setExist();
        dfs(i+1, j, nextNode, board);
        dfs(i-1, j, nextNode, board);
        dfs(i, j+1, nextNode, board);
        dfs(i, j-1, nextNode, board);
        board[i][j] = original;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node(); // creating a prefix tree
        for(int i = 0; i < words.size(); i++) {
            Node* node = root;
            for(int j = 0; j < words[i].size(); j++) {
                if(!node->getLink(words[i][j])) {
                    node->setLink(words[i][j], new Node());
                }
                node = node->getLink(words[i][j]);
            }
            node->setEnd();
        } // added all the words to a prefix tree
        Node* node = root; 
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(i, j, root, board);
            }
        }
        vector<string> ans;
        for(int i = 0; i < words.size(); i++) {
            node = root;
            for(int j = 0; j < words[i].size(); j++) {
                node = node->getLink(words[i][j]);
            }
            if(node->getExist()) ans.push_back(words[i]);
        }
        return ans;
    }
};
