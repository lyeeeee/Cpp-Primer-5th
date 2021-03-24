#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct destination;
struct connection;

connection connect(destination*);

void disconnect(connection c);

void end_connection(connection *p) {
    disconnect(*p);
}
void f(destination &d) {
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [](connection *p){disconnect(*p);});
}

int main() {

}