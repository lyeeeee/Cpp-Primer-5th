#include <vector>
#include <deque>

using namespace std;

int main() {
    vector<int> vec1(10);
    vector<int> vec2(10,1);
    vector<int> vec3 = {1,2,3};
    vector<int> vec4(vec1);
    vector<int> vec5{1,2,3};
    vector<int> vec6 = vec1;
}