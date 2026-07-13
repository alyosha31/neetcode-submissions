class LRUCache {
public:

    struct List {
        int key;
        int val;
        List* next = NULL;
        List* prev = NULL;

        List() {}

        List(int _key, int _val) {
            this->key = _key;
            this->val = _val;
        }
    };

    List* cache = new List(); 
    unordered_map<int, List*> mp;
    List* start = cache;
    List* end = cache;
    int capacity = -1;
    int size = 0;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void removeNode(List* node) {
        //starting node
        if(node == start) {
            List* temp = start;
            start = start->next;
            if(start) start->prev = NULL;
            temp->next = NULL;
        }
        //middle nod
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = NULL;
            node->next = NULL;
        }
        mp.erase(node->key);
    }

    void addNode(List* node) {
        end->next = node;
        node->prev = end;
        end = end->next;
        mp[node->key] = node;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        List* node = mp[key];
        if(node->next != NULL) {
            removeNode(node);
            addNode(node);
        }
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            List* node = mp[key];
            node->val = value; //value updated
            if(node->next != NULL) { //if node is not at the end already
                removeNode(node);
                addNode(node);    
            }
        }    
        else {
            if(size == capacity) {
                //removing start
                removeNode(start);
                size--;
            }
            List* newNode = new List(key, value);
            if(size == 0) {
                start = newNode;
                end = newNode;
                mp[key] = newNode;
            } else {
                addNode(newNode);
            }
            size++;
        }
    }
};
