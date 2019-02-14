#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001

char s[N];

int main(){
  int n, ans = 0;

  scanf("%s", s);
  n = strlen(s);

  for(int i = 0; i < n; ++i){
    int score = 0, qmarks = 0;
    for(int j = i; j < n; ++j){
      char c = s[j];
      score += (c == '(');
      score -= (c == ')');
      qmarks += (c == '?');

      if(score < 0)
        break;

      if(qmarks > score)
        ++score, --qmarks;
      ans += (abs(score - qmarks) % 2 == 0 && qmarks >= score);
    }
  }

  printf("%d\n", ans);

  return 0;
}
