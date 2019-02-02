#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 26
#define N 100001

char s[N], t[N];
bool good[B];

void Initialise(){
  string s;
  cin >> s;
  for(auto c : s){
    int i = c - 'a';
    good[i] = 1;
  }
}

int main(){
  Initialise();

  int q, n;
  scanf("%s%d", s, &q);
  n = strlen(s);

  while(q--){
    int m, i, j, k, nx, mx;
    bool valid = 1;

    scanf("%s", t);
    m = strlen(t);

    for(j = m - 1, k = n - 1; j > -1 && k > -1 && s[k] != '*'; j--, k--){
      if(t[j] != s[k]){
        if(s[k] != '?')
          break;
        int x = t[j] - 'a';
        if(good[x] == 0)
          break;
      }
    }

    mx = m - (m - j);
    nx = n - (m - j);
    for(i = 0, k = 0; i <= mx && k <= nx; i++, k++){
      if(t[i] != s[k]){
        if(s[k] == '?'){
          int x = t[i] - 'a';
          if(good[x] == 0)
            break;
        } else if(s[k] == '*'){
          int x = t[i] - 'a';
          if(good[x] == 0){
            k--;
          }
          else
            i--;
        } else
          break;
      }
    }

    if(i > mx && (k > nx || (k == nx && s[k] == '*')))
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}
