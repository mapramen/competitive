#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define PB push_back
#define MP make_pair
#define N 200001
#define B 30

int n, q, a[N];
ll T[N];
set<int> S[B + 1];

int MSB(int x){
  if(x == 0){
    return B;
  }
  int k;
  for(k = B - 1; k > -1 && (x & (1 << k)) == 0; --k);
  return k;
}

void BITUpdate(int i, int x){
  if(i == 0){
    return ;
  }
  for( ; i <= n; i += (i & -i))
    T[i] += x;
}

ll BITQuery(int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i))
    ans += T[i];
  return ans;
}

void Update(int i, int x){
  if(x == a[i]){
    return ;
  }

  int curMSB = MSB(a[i]), newMSB = MSB(x);
  if(curMSB != newMSB){
    S[curMSB].erase(i);
    S[newMSB].insert(i);
  }

  BITUpdate(i, x - a[i]);
  a[i] = x;
}

int Query(){
  if(S[B].size() > 0 && *S[B].begin() == 1){
    return 1;
  }

  for(int k = 0; k < B; ++k){
    int c = 0;
    for(auto i : S[k]){
      ++c;
      if(BITQuery(i - 1) == a[i]){
        return i;
      }
      if(c == 2){
        break;
      }
    }
  }

  return -1;
}

int main(){
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    S[B].insert(i);
    Update(i, x);
  }

  while(q--){
    int i, x;
    scanf("%d%d", &i, &x);
    Update(i, x);
    printf("%d\n", Query());
  }

  return 0;
}
