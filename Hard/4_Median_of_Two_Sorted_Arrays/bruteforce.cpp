#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:


    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num1 = nums1;
        vector<int> num2 = nums2;
        int ptr1 = 0;
        int ptr2 = 0;
        int size1 = num1.size();
        int size2 = num2.size();
        vector<int> result;
        while( ptr1<size1 && ptr2<size2 ){
            if( num1[ptr1] > num2[ptr2] ){
                result.push_back(num2[ptr2]);
                ptr2++;
            }else{
                result.push_back(num1[ptr1]);
                ptr1++;
            }
        }
        while( ptr1<size1 ){
            result.push_back(num1[ptr1]);
            ptr1++;
        }
        while( ptr2<size2 ){
            result.push_back(num2[ptr2]);
            ptr2++;
        }
        int netsize = size1+size2;
        double retval = 0.0;
        if(netsize%2==0){
            int i = 0;
            while(i<netsize/2){
                i++;
            }
            cout << "ri: "<< result[i-1] << "ri+1" << result[i] << endl;
            retval = (result[i-1]+result[i])/2.0;
            cout << "retval: " << retval << endl;
        }else{
            int j = 0;
            while(j<netsize/2){
                j++;
            }
            retval = result[j];
        }
        return retval;
    }
};