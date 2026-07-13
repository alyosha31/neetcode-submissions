class Solution {
public:
    bool isValid(vector<int> &piles, int k, int h) {
        int hours_taken = 0;
        for(int i = 0; i<piles.size(); i++) {
            hours_taken+= piles[i]/k;
            if(piles[i]%k) hours_taken++;
        }
        if(hours_taken<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end(), [](int a, int b) {
            return a<b;
        });
        int ll = 1;
        int ul = piles[piles.size()-1];
        while(ll<ul) {
            int mid = ll + (ul-ll)/2;
            if(isValid(piles, mid, h)) {
                ul=mid;
            }
            else ll = mid+1;
        }
        return ll;
    }
};
