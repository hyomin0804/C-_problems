#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int bits = 2;
    
    int cnt = bitset<5>(bits).count();

    cout << cnt;

    return 0;
}
