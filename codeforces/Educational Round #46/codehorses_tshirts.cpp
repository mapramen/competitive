#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5

map< char, int > M[N];

int main(){
  int n;

  cin >> n;

  for(int x = -1; x < 2; x += 2){
    for(int i = 1; i <= n; ++i){
      string s;
      cin >> s;
      M[s.size()][s.back()] += x;
    }
  }

  int ans = 0;
  for(int i = 1; i < N; ++i){
    for(auto p : M[i]){
      ans += abs(p.second);
    }
  }

  ans /= 2;

  cout << ans << '\n';

  return 0;
}
