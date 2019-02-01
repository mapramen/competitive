#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

vector< vector<int> > v(N), c(N);
int ans[N], b[N];

int main(){
  int n, w;

  cin >> n >> w;
  for(int i = 1; i <= n; i++){
    int j;
    cin >> j;
    v[j].PB(i);
  }

  for(int i = 1; i < N; i++){
    b[i] = (i + 1) / 2;
    c[i].resize(v[i].size());
    for(int j = 0; j < c[i].size(); j++){
      c[i][j] = b[i];
      w -= b[i];
    }
  }

  for(int i = N - 1; i > 0 && w > 0; i--){
    for(int j = 0; j < c[i].size() && w > 0; j++){
      int k = min(w, i - c[i][j]);
      c[i][j] += k;
      w -= k;
    }
  }

  if(w != 0)
    printf("-1\n");
  else{
    for(int i = 1; i < N; i++){
      for(int j = 0; j < c[i].size(); j++){
        ans[v[i][j]] = c[i][j];
      }
    }

    for(int i = 1; i <= n; i++)
      cout << ans[i] << ' ';
    cout << '\n';
  }

  return 0;
}
