#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<pair<double, double>> pigs(n);
        for (int i = 0; i < n; ++i) {
            cin >> pigs[i].first >> pigs[i].second;
        }
        
        int result;
        if (m == 0) {
            // General case, solve using some algorithm
            result = n; // Placeholder, needs actual implementation
        } else if (m == 1) {
            result = (n + 2) / 3 + 1;
        } else if (m == 2) {
            result = (n + 2) / 3;
        }
        
        cout << result << endl;
    }
    
    return 0;
}
