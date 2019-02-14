#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n, m;
  string p = "BGRY", s;

  cin >> s;
  n = s.size();
  m = (n - 1) / 4 + 1;

  do{
    string t;

    for(int j = 0; j < m; j++)
      t += p;

    int i, b = 0, g = 0, r = 0, y = 0;

    for(i = 0; i < n; i++){
      if(s[i] == '!'){
        if(t[i] == 'B')
          b++;
        else if(t[i] == 'G')
          g++;
        else if(t[i] == 'R')
          r++;
        else
          y++;
      }
      else
        if(s[i] != t[i])
          break;
    }

    if(i == n){
      printf("%d %d %d %d\n", r, b, y, g);
      return 0;
    }

  } while(next_permutation(p.begin(), p.end()));

  return 0;
}
