#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 100000000;
int M, N;
int fertile[13][13];
int dp[13][1 << 12];

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin >> M >> N;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> fertile[i][j];
    
    dp[0][0] = 1;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < (1 << N); ++j) {
            if (dp[i][j] == 0) continue;
            for (int k = 0; k < (1 << N); ++k) {
                bool valid = true;
                for (int l = 0; l < N; ++l) {
                    if ((k & (1 << l)) && !fertile[i][l]) valid = false;
                    if ((k & (1 << l)) && (l > 0) && (k & (1 << (l - 1)))) valid = false;
                    if ((k & (1 << l)) && (j & (1 << l))) valid = false;
                }
                if (valid) {
                    dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % MOD;
                }
            }
        }
    }
    
    int result = 0;
    for (int i = 0; i < (1 << N); ++i) {
        result = (result + dp[M][i]) % MOD;
    }
    
    cout << result << endl;
    return 0;
}