#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 8
#define ALL_MASK ((1 << N) - 1)

int a[N], non_war_masks[N];

ll Solve(int available_friends_mask, ll sum){
  if(available_friends_mask == 0){
    return sum;
  }

  ll ans = 0;
  for(int tmask = available_friends_mask; tmask != 0; ){
    int i = __builtin_ctz(tmask);
    tmask ^= (1 << i);

    ans = max(ans, Solve((available_friends_mask ^ (1 << i)) & non_war_masks[i], sum + a[i]));
  }

  return ans;
}

int main(){
  for(int i = 0; i < N; ++i){
    scanf("%d", &a[i]);
  }

  int p;
  scanf("%d", &p);

  while(p--){
    int i, j;
    scanf("%d%d", &i, &j);
    --i, --j;

    non_war_masks[i] |= (1 << j);
    non_war_masks[j] |= (1 << i);
  }

  for(int i = 0; i < N; ++i){
    non_war_masks[i] ^= ALL_MASK;
  }

  printf("%lld\n", Solve(ALL_MASK, 0));

  return 0;
}