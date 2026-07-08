class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0;
        int high = rows - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target < matrix[mid][0]) {
                high = mid - 1;
            }
            else if (target > matrix[mid][cols - 1]) {
                low = mid + 1;
            }
            else {

                int left = 0;
                int right = cols - 1;

                while (left <= right) {
                    int m = left + (right - left) / 2;

                    if (matrix[mid][m] == target)
                        return true;

                    if (matrix[mid][m] < target)
                        left = m + 1;
                    else
                        right = m - 1;
                }

                return false;
            }
        }

        return false;
    }
};