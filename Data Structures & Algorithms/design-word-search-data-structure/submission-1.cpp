struct Node {
    Node* links[26];
    bool flag = false;

    void setLink(char ch, Node* link) {
        links[ch-'a'] = link;
    }

    Node* getLink(char ch) {
        return links[ch-'a'];
    }

    Node* getLinkNumeric(int i) {
        return links[i];
    }

    void setFlag() {
        flag = true;
    }

    bool getFlag() {
        return flag;
    }
};

class WordDictionary {
private: Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->getLink(word[i])) {
                node->setLink(word[i], new Node());
            }
            node = node->getLink(word[i]);
        }
        node->setFlag();
    }

    bool re_search(Node* node, int index, string word) {
        // terminating condition
        if(!node) return false;
        if(index==word.size()) return node->getFlag();

        bool found = false;

        if(word[index] == '.') {
            for(int i = 0; i < 26; i++) {
                found = found|re_search(node->getLinkNumeric(i), index+1, word);
                if(found) return true;
            }
            return found;
        }
        else {
            if(!node->getLink(word[index])) return false;
            return re_search(node->getLink(word[index]), index+1, word);
        }
        return false;
    }
    
    bool search(string word) {
        Node* node = root;
        return re_search(node, 0, word);
    }
};
