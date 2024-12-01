class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            int target = 2 * arr[i];
            int index = customBinarySearch(arr, target);
            if (index >= 0 && index != i) {
                return true;
            }
        }
        return false;
    }

private:
    int customBinarySearch(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};