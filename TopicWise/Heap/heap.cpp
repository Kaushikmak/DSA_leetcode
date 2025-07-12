#include <iostream>
#inclue <vector>

using namespace std;

class Heap {
public:
    vector<int> arr;
    int size = 0;
    void insert(int value){
        size++;
        arr.push_back(value);
        int currentIndex = arr.size()-1;
        while(currentIndex>1){
            int parent = index/2;
            if(arr[parent]<arr[currentIndex]){
                swap(arr[parent],arr[currentIndex]);
                currentIndex = parent;
            }else{
                return ;
            }
        }
    }
};