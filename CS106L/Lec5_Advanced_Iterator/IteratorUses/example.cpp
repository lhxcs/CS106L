#include <vector>
#include <iostream>
#include<algorithm>
#include <set>

const int ELEM_FIND = 1;

using std::set;
using std::cout;  using std::endl;
using std::vector;

void printVec(const vector<int>& vec) {
    for(auto elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    //sorting a vector
    vector <int> vec{3, 1, 4, 1, 5, 9, 2, 6};

    printVec(vec);
    std::sort(vec.begin(), vec.end());
    printVec(vec);

    //finding an element from a set
    set<int> elems{3, 1, 4, 1, 5, 9, 2, 6};
    cout << elems.size() << endl; //automatically remove the duplicate item
    auto testit = std::find(elems.begin(), elems.end(), ELEM_FIND);
    if(testit == elems.end()) {
        cout << "Not Found! :(" << endl;
    } else {
        cout << "Found: " << *testit << endl;
    }

    set<int>::iterator iter = elems.lower_bound(4);
    set<int>::iterator end = elems.upper_bound(6);
    cout << *(iter) << " " << *(end) << endl;

    for (; iter != end; ++iter) {
        cout << *(iter) <<" ";
    }
    cout << endl;
}