#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Cost(int m, string& a, string& b){
  int ans = 0;
  for(int i = 0; i < m; ++i){
    ans += abs(a[i] - b[i]);
  }
  return ans;
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<string> words(n);
  for(string& word: words){
    cin >> word;
  }

  int ans = INT_MAX;
  for(int i = 0; i < n; ++i){
    for(int j = i + 1; j < n; ++j){
      ans = min(ans, Cost(m, words[i], words[j]));
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