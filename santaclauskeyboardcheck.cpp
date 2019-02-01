#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 26

vector< set<int> > m(B);

int main(){
  int ans;
  string s, t;

  cin >> s >> t;

  for(int i = 0; i < s.size(); i++){
    int j = s[i] - 'a', k = t[i] - 'a';
    m[j].insert(k), m[k].insert(j);
  }

  ans = 0;
  for(int i = 0; i < B; i++){
    if(m[i].size() > 1){
      printf("-1\n");
      return 0;
    }

    if(m[i].size() == 1){
      if(*m[i].begin() != i)
        ans++;
    }
  }

  cout << ans / 2 << '\n';

  for(int i = 0; i < B; i++){
    if(m[i].size() == 1){
      int j = *m[i].begin();
      if(j < i)
        printf("%c %c\n", 'a' + j, 'a' + i);
    }
  }

  return 0;
}
