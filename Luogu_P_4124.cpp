#include<bits/stdc++.h>
#define int long long
using namespace std;

int count_valid_numbers(int L, int R) {
    auto has_three_consecutive_digits = [](int num) {
        string s = to_string(num);
        for (int i = 0; i <= 8; ++i) {
            if (s[i] == s[i+1] && s[i+1] == s[i+2]) {
                return true;
            }
        }
        return false;
    };

    auto contains_8_and_4 = [](int num) {
        string s = to_string(num);
        return s.find('8') != string::npos && s.find('4') != string::npos;
    };

    int count = 0;
    for (int i = L; i <= R; ++i) {
        if (has_three_consecutive_digits(i) && !contains_8_and_4(i)) {
            ++count;
        }
    }
    return count;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int L, R;
    cin >> L >> R;
    cout << count_valid_numbers(L, R) << endl;
    return 0;
}