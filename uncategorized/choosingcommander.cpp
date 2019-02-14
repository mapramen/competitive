#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 27

int T[N * B][2], cnt[N * B * 2], nxt = 1;

void Update(int k, int val){
  int i = 0;
  for(int x = B - 1; x > -1; x--){
    int j = ((k & (1 << x)) > 0);
    if(T[i][j] == 0)
      T[i][j] = nxt++;
    i = T[i][j];
    cnt[i] += val;
  }
}

int QueryX(int i, int j){
  if(T[i][j] == 0)
    return 0;
  else
    return cnt[T[i][j]];
}

int Query(int p, int l){
  int ans = 0, i = 0;
  for(int x = B - 1; x > -1; x--){
    int j = ((p & (1 << x)) > 0);
    int k = ((l & (1 << x)) > 0);

    if(k == 1)
      ans += QueryX(i, 1 ^ j ^ k);
      
    i = T[i][j ^ k];
    if(i == 0)
      break;
  }
  return ans;
}

int main(){
  int q;

  scanf("%d", &q);
  while(q--){
    int t, p;
    scanf("%d%d", &t, &p);
    if(t == 1)
      Update(p, 1);
    else if(t == 2)
      Update(p, -1);
    else{
      int l;
      scanf("%d", &l);
      printf("%d\n", Query(p, l));
    }
  }

  return 0;
}
