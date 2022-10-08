#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

char s[N], t[N];

vector<int> GetCharacteristic(int n, char s[]){
  vector<int> a;
  for(int i = 1; i < n; ++i){
    if(s[i] != s[i - 1]){
      a.push_back(i);
    }
  }
  return a;
}

ll Solve(){
  int n;
  scanf("%d%s%s", &n, s, t);

  vector<int> a = GetCharacteristic(n, s);
  vector<int> b = GetCharacteristic(n, t);

  if(s[0] != t[0] || s[n - 1] != t[n - 1] || a.size() != b.size()){
    return -1;
  }

  ll ans = 0;
  for(int i = 0; i < a.size(); ++i){
    ans += abs(a[i] - b[i]);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}