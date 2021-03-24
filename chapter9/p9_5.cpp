#include <vector>
#include <deque>

using namespace std;

int search(int target, vector<int>::iterator& beg, vector<int>:: iterator& end) {
    while (beg < end) {
        if (*beg == target) {
            return *beg;
        } else {
            beg++;
        }
    }
    return -1;
}
int main() {
    
}