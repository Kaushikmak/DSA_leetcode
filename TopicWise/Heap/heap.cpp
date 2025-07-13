#include <iostream>
#include <vector>

using namespace std;

class Heap {
public:
    vector<int> arr;
    int size;
    // constructor
    Heap() {
        // make zeroth index value to -1, as we will not be using it
        // using 1 based indexing
        arr[0] = INT_MIN;
        size = 0;
    }

    // max heap insertion
    void insert(const int value) {
        size++;
        arr.push_back(value);
        unsigned int currentIndex = arr.size() - 1;
        while (currentIndex > 1) {
            unsigned int parent = currentIndex / 2;
            if (arr[parent] < arr[currentIndex]) {
                swap(arr[parent], arr[currentIndex]);
                currentIndex = parent;
            } else {
                return;
            }
        }
    }

    // max heap deletion
    void _delete() {
        if (size == 0) {
            cerr << "Nothing to delete" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        // take root to it's correct position
        int i = 1;
        while (i < size) {
            const int left = 2 * i;
            const int right = 2 * i + 1;
            if (left < size && arr[i] < arr[left]) {
                swap(arr[i], arr[left]);
                i = left;
            } else if (right < size && arr[i] < arr[right]) {
                swap(arr[i], arr[right]);
                i = right;
            } else {
                return;
            }
        }
    }
};

void heapify(vector<int> &nums,const int index) {
    int current = index;
    const int left = 2*index;
    const int right = 2*index+1;
    const unsigned int n = nums.size();
    if (left<=n && nums[left] > nums[current]) {
        current = left;
    }
    if (right<=n && nums[right] > nums[current]) {
        current = right;
    }
    if (current!=index) {
        swap(nums[index],nums[current]);
        heapify(nums,current);
    }
}

void heapSort(vector<int> &nums) {
    unsigned int n = nums.size();
    while (n>1) {
        // step 1: swap
        swap(nums[1],nums[n]);
        n--;
        // heapify the first index
        heapify(nums,1);

    }
}