#include<bits/stdc++.h>
using namespace std;

void binarY(int n) {

    int num = n, lim = 0;
    while (num) num /= 2, lim++;
    lim--;

    for (int i = lim; i >= 0; i--) {

        int res = n & (1 << i);
        if (res) cout << 1;
        else cout << 0;
    }
    cout << "\n";
}

bool is_palindrome(int n) {
    int len = 0, num = n; 
    while (num) num /= 2, len++;

    // cout << len << endl;

    int mask = 1 << (len - 1);

    for (int i = 0; i < len / 2; i++) {

        int maxk = 1 << i;
        if ((n & mask) and !(n & maxk)) 
            return false;
        else if (!(n & mask) and (n & maxk))
            return false;

        mask >>= 1;

    }

    return true;
}


int main() {

    vector < int > palindrome;
    int lim = 1 << 15;
    for (int i = 0; i < lim; i++) 
        if (is_palindrome(i)) 
            palindrome.push_back(i);

    // for (auto el: palindrome) cout << el << "\n";

    binarY(32767);
}