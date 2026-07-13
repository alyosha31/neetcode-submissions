class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; //min-heap
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        while(pq.size()>k) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>k) pq.pop();

        return pq.top();
    }
};
