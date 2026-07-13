class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i < n+1; i++) {
            parent[i] = i; //in the beginning, a node is its own parent
        }
    }

    int findUltParent(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findUltParent(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int ultp_u = findUltParent(u);
        int ultp_v = findUltParent(v);
        if(ultp_u == ultp_v) {
            return;
        }
        if(rank[ultp_u] < rank[ultp_v]) {
            parent[ultp_u] = ultp_v;
        }
        else if(rank[ultp_u] > rank[ultp_v]) {
            parent[ultp_v] = ultp_u;
        } 
        else {
            parent[ultp_u] = ultp_v;
            rank[ultp_v]++;
        }
    }

    void unionBySize(int u, int v) {
        int ultp_u = findUltParent(u);
        int ultp_v = findUltParent(v);
        if(ultp_u == ultp_v) {
            return;
        }
        if(size[ultp_u] < size[ultp_v]) {
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        }
        else if(size[ultp_u] > size[ultp_v]) {
            parent[ultp_v] = ultp_u;
            size[ultp_u] += size[ultp_v];
        } 
        else {
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        }
    }
};
class Solution {
public:
   
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //disjoint set
        //kruskal's algorithm for MST
        int n = edges.size();
        DisjointSet ds(n);
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            if(ds.findUltParent(u) == ds.findUltParent(v)) {
                return i;
            }
            ds.unionBySize(i[0], i[1]);
        }
        return vector<int>{};
    }
};
