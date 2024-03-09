#include<iostream>
#include<vector>
using namespace std;


pair<int, int> my_minmax(int a, int b) {
    if ( a < b ) return {a, b};
    else return {b, a};
}


int main() {
    vector<int> v {3, 1, 4, 1, 5, 2, 6};
    auto iter = v.begin();
    std::advance(iter, 4);
    v.erase(iter);
    for(auto elem : v) {
        cout << elem << endl;
    }
}