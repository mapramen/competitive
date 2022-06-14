#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

char s[N];
int double_zero_count[N], double_one_count[N];

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  scanf("%s", s);
  
  for(int i = 2; i <= n; ++i){
    double_zero_count[i] = double_zero_count[i - 1] + (s[i - 1] == '0' && s[i - 2] == '0');
    double_one_count[i] = double_one_count[i - 1] + (s[i - 1] == '1' && s[i - 2] == '1');
  }

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    int ans = 1 + max(double_zero_count[r] - double_zero_count[l], double_one_count[r] - double_one_count[l]);
    printf("%d\n", ans);
  }

  return 0;
}