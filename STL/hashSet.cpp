// set is collection of entities and do not contain duplicates

/*
 * insertion operation in hashset O(1) while O(1) in array and O(n) in LL
 * deletion operation in hashset O(1) while O(1) in array and O(n) in LL
 * searching operation in hashset O(1) while O(n) in array and O(n) in LL
 */

#include <unordered_set>
#include <iostream>

using namespace std;

class HashSet {
public:
    void crudOnHashSet() {
        unordered_set<int> myHashSet;
        // insertion
        myHashSet.insert(2);
        myHashSet.insert(4);
        myHashSet.insert(2); // ignores duplicates
        // searching
        if (myHashSet.find(2)!=myHashSet.end()) { // myHashSet.end() represents end of container
            cout << "2 is present in hash set" << endl;
        }
        // check if element is present
        if (myHashSet.count(2)) {
            cout << "2 is present " << endl;
        }else {
            cout << "2 is not present" << endl;
        }
        // deletion
        myHashSet.erase(2); // return 1 if removed and 0 if not found
        // size
        const unsigned int n = myHashSet.size();
        // iteration
        for (const int items: myHashSet) {
            cout << items << " " ;
        }
        cout << endl;
        // clear
        myHashSet.clear();
        // check if empty
        bool isEmpty = myHashSet.empty();
    }
};
