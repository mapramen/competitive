#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

char s[2][N];

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n, ans = INT_MAX, ansx = 1;
    bool is_horizontal_needed = 0;
    vector< vector<int> > v(2);

    scanf("%d", &n);
    for(int i = 0; i < 2; i++)
      scanf("%s", s[i]);

    for(int i = 0; i < n && is_horizontal_needed == 0; i++)
      is_horizontal_needed = (s[0][i] == '*' && s[1][i] == '*');

    if(is_horizontal_needed == 0){
      int cnt = 0;
      for(int i = 0; i < n; i++)
        cnt += (s[0][i] == '*' || s[1][i] == '*');
      ans = min(ans, max(0, cnt - 1));
    }

    for(int x = 0; x < 2; x++){
      for(int i = 0; i < n; i++){
        if(s[x][i] == '*')
          v[x].PB(i);
      }
    }

    int i1 = 0, i2 = 0, n1 = v[0].size(), n2 = v[1].size();
    for( ; i1 < n1 - 1 && i2 < n2 - 1; ansx++){
      if(v[0][i1 + 1] == v[1][i2 + 1]){
        i1++;
        i2++;
      }
      else{
        if(v[0][i1 + 1] < v[1][i2 + 1]){
          if(v[1][i2] < v[0][i1 + 1]){
            i1++;
            i2++;
          }
          else
            i1++;
        }
        else{
          if(v[0][i1] < v[1][i2 + 1]){
            i1++;
            i2++;
          }
          else
            i2++;
        }
      }
    }

    ansx += max(0, n1 - i1 - 1) + max(0, n2 - i2 - 1);
    ans = min(ans, ansx);

    printf("%d\n", ans);
  }

  return 0;
}
