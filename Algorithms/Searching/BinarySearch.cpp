#include <vector>
using namespace std;

class BinarySearch {
public:
    static int search(const vector<int> &nums, const int target) {
        return binarySearch(nums, target);
    }

    static int search(const vector<int> &nums, const int target, const bool isRotated=false) {
        if (isRotated==true) {
            return binarySearchRotated(nums, target);
        }
        return binarySearch(nums,target);
    }

    static int search(const vector<int> &nums, const int target, const bool isRotated=false, const int byK=0) {
        if (isRotated==true) {
            if (byK==0) {
                return binarySearchRotated(nums, target);
            }
            return binarySearchKSorted(nums,target,byK);
        }
        return binarySearch(nums,target);
    }

    static int firstOccurrence(const vector<int> &nums, const int target) {
        return binarySearchFirstOccurrence(nums, target);
    }

    static int lastOccurrence(const vector<int> &nums, const int target) {
        return binarySearchLastOccurrence(nums, target);
    }

    static vector<int> findRange(const vector<int> &nums, int target) {
        int first = binarySearchFirstOccurrence(nums, target);
        if (first == -1) {
            return {-1, -1};
        }
        int last = binarySearchLastOccurrence(nums, target);
        return {first, last};
    }



private:
    static int binarySearch(const vector<int> &nums, const int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left <= right) {
            const int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return mid;
            }
            if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    static int binarySearchRotated(const vector<int> &nums, const int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left <= right) {
            const int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[right] >= target && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }

    static int binarySearchFirstOccurrence(const vector<int> &nums, const int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        int result = -1;
        while (left <= right) {
            const int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                result = mid;
                right = mid - 1;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }

    static int binarySearchLastOccurrence(const vector<int> &nums, const int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        int result = -1;
        while (left <= right) {
            const int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                result = mid;
                left = mid + 1;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }

    static int binarySearchKSorted(const vector<int> &nums, const int target, const int k) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left <= right) {
            const int mid = left + ((right - left) >> 1);
            const int start = max(left, mid - k);
            const int end = min(right, mid + k);
            for (int i = start; i <= end; ++i) {
                if (nums[i] == target) {
                    return i;
                }
            }
            if (target > nums[mid]) {
                left = mid + k + 1;
            } else {
                right = mid - k - 1;
            }
        }
        return -1;
    }
};
