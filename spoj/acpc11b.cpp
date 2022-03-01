#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> ReadArray(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  return a;
}

int Solve(){
  vector<int> a = ReadArray();
  vector<int> b = ReadArray();

  int ans = INT_MAX;
  for(int n = a.size(), m = b.size(), i = 0, j = 0; i < n; ++i){
    for( ; j < m && b[j] <= a[i]; ++j);
    if(j > 0){
      ans = min(ans, a[i] - b[j - 1]);
    }

    if(j != m){
      ans = min(ans, b[j] - a[i]);
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}