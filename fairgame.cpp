#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

int c[N];

int main(){
  int n;
  vector<int> ans;

  cin >> n;
  for(int i = 1; i <= n; ++i){
    int j;
    cin >> j;
    ++c[j];
  }

  for(int i = 1; i < N; ++i)
    if(2 * c[i] == n)
      ans.PB(i);

  if(ans.size() == 2){
    cout << "YES\n";
    for(auto x : ans)
      cout << x << ' ';
    cout << '\n';
  }
  else
    cout << "NO\n";

  return 0;
}
