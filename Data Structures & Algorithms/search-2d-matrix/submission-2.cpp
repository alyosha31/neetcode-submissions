class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bot = matrix.size()-1;
        int target_row = 0;
        while(top<=bot) {
            int mid = top + (bot - top)/2;
            if(matrix[mid][matrix[mid].size()-1]<target) {
                top = mid+1;
            }
            else if(matrix[mid][0] > target) {
                bot = mid-1;
            }
            else {
                target_row = mid;
                break; 
            }
        }
        int l = 0;
        int r = matrix[target_row].size()-1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(matrix[target_row][mid] == target) return true;
            else if(matrix[target_row][mid]>target) r = mid-1;
            else l = mid+1;
        }
        return false;
    }
};
