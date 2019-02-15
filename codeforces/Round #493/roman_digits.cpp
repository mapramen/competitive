#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 12

vector<int> a{1, 5, 10, 50};
int c[N];

void Initialise(){
  set<int> S{0};

  for(int i = 1; i < N; ++i){
    set<int> T;
    for(auto x : S){
      for(auto y : a){
        T.insert(x + y);
      }
    }
    c[i] = T.size();
    swap(S, T);
  }
}

int main(){
  ll n;

  cin >> n;

  Initialise();

  ll ans = (n < N) ? c[n] : c[N - 1] + 49 * (n - N + 1);

  cout << ans << '\n';

  return 0;
}
