#include<bits/stdc++.h>
#define int long long
using namespace std;
#define N 12
int f[N][N][100],mod;
void init(){
    for(int i = 0;i <= 9;i++)   f[1][i][i % mod]++;
    for(int i = 2;i < N;i++){
        for(int j = 0;j <= 9;j++){
            for(int k = 0;k < mod;k++){
                for(int t = 0;t <= 9;t++){
                    int s = (k - j % mod + mod) % mod;
                    f[i][j][k] += f[i-1][t][s];
                }
            }
        }
    }
}
int get(int n){
    if(!n)  return 1;
    vector<int> num;
    while(n)    num.push_back(n % 10),n /= 10;
    int res = 0,last = 0;
    for(int i = num.size() - 1;i >= 0;i--){
        int x = num[i];
        for(int j = 0;j < x;j++)    res += f[i + 1][j][(mod - last) % mod];
        last = (last + x) % mod;
        if(!i && !last) res++;
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b;
    while(cin>>a>>b>>mod){
        memset(f,0,sizeof f);
        init();
        cout<<get(b) - get(a - 1)<<endl;
    }
    return 0;
}