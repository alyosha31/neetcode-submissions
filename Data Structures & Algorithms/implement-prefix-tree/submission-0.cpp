struct Node {
    Node* links[26];
    bool flag = false;

    Node* getLink(char c) {
        return links[c-'a'];
    }
    
    void setLink(char c, Node* n) {
        links[c-'a'] = n;
        return;
    }

    void setFlag() {
        flag = true;
        return;
    }

    bool getFlag() {
        return flag;
    }
};

class PrefixTree {
private: Node* root; 
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->getLink(word[i])) {
                Node* newNode = new Node();
                node->setLink(word[i], newNode);
            }
            node = node->getLink(word[i]);
        }
        node->setFlag();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->getLink(word[i])) return false;
            node = node->getLink(word[i]);
        }
        return node->getFlag();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++) {
            if(!node->getLink(prefix[i])) return false;
            node = node->getLink(prefix[i]);
        }
        return true;       
    }
};
