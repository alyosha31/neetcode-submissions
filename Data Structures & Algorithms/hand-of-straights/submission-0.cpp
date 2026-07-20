class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return 0;
        sort(hand.begin(), hand.end());
        vector<int> hash(1e3+1, 0);
        for(int i = 0; i < n; i++) {
            hash[hand[i]]++;
        }
        int iterations = n/groupSize; 
        int ans = 1;
        for(int iter = 0; iter < iterations; iter++) {
            int last = -1;
            int turns = 0;
            for(int i = 0; i < n && turns < groupSize; i++) {
                if(hash[hand[i]]) {
                    if(last == -1) {
                        last = hand[i];
                        hash[hand[i]]--;
                        turns++;
                    }
                    else if(last+1 == hand[i]) {
                        last = hand[i];
                        hash[hand[i]]--;
                        turns++;
                    }
                    else if(last == hand[i]) {
                        continue;
                    }
                    else {
                        ans = 0;
                        break;
                    }
                }
            }
            if(turns < groupSize) ans = 0;
            if(!ans) break;
        }
        return ans;
    }
};
