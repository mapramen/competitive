#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  vector<string> S(2);
  for(int i = 0; i < 2; ++i){
    cin >> S[i];
    sort(S[i].begin(), S[i].end());
    reverse(S[i].begin(), S[i].end());
  }

  int i = -1, cnt = 0;
  string c;

  while(!S[0].empty() && !S[1].empty()){
    int j = S[0].back() < S[1].back() ? 0 : 1;
    
    if(j == i && cnt == k){
      j = 1 ^ j;
    }

    c.push_back(S[j].back());
    cnt = 1 + (j == i ? cnt : 0);
    i = j;

    S[i].pop_back();
  }

  return c;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}