#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 51

char s[N];
ll friend_mask[N];

ll GetMask(int n){
  ll mask = 0;
  for(int i = 0; i < n; ++i){
    if(s[i] == 'Y'){
      mask |= (1ll << i);
    }
  }
  return mask;
}

int GetPossibleFriends(int n, int i){
  ll mask = 0;
  for(int j = 0; j < n; ++j){
    if((friend_mask[i] & (1ll << j)) == 0){
      continue;
    }
    mask |= friend_mask[j];
  }
  mask &= (((1ll << n) - 1) ^ (1ll << i));
  mask ^= (mask & friend_mask[i]);
  return __builtin_popcountll(mask);
}

void Solve(){
  scanf("%s", s);

  int n = strlen(s);

  friend_mask[0] = GetMask(n);
  for(int i = 1; i < n; ++i){
    scanf("%s", s);
    friend_mask[i] = GetMask(n);
  }

  int max_possible_friends = 0, max_possible_friends_id = 0;
  for(int i = 0; i < n; ++i){
    int possible_friends = GetPossibleFriends(n, i);
    if(possible_friends > max_possible_friends){
      max_possible_friends = possible_friends, max_possible_friends_id = i;
    }
  }

  printf("%d %d\n", max_possible_friends_id, max_possible_friends);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}