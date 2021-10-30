#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

char s[N];
vector<pii> v;

int Move(int p, int i, int moveType){
  v.push_back({moveType, i});
  for(int k = moveType == 1 ? 3 : 1; k != 0; --k, ++i){
    s[i] = s[i] == '0' ? '1' : '0';
  }
  return p ^ 1;
}

void FillMoves(int n, int p){
  v.clear();

  if(p == 0){
    return;
  }

  p %= 2;

  int i = n - 1;
  while(i >= 0){
    if(p == 1){
      if(s[i] == '0'){
        --i;
        continue;
      }
      p = Move(p, i, 2);
      continue;
    }

    if(s[i] == '0'){
      if(i == 0 || s[i - 1] == '0' || s[i - 2] == '0'){
        --i;
        continue;
      }
      p = Move(p, i - 2, 1);
      continue;
    }

    if(s[i - 1] == '0'){
      p = Move(p, i - 2, 1);
      continue;
    }
    
    int j = i;
    for( ; s[j] == '1'; --j);

    if((i - j) % 2 == 1){
      p = Move(p, j, 1);
      p = Move(p, j + 3, 2);
      continue;
    }

    while(i - j >= 2){
      p = Move(p, j, 1);
      p = Move(p, j, 2);
      j += 2;
    }
  }
}

void Solve(){
  scanf("%s", s);

  int n = strlen(s);

  int p = 0;
  for(int i = 0; i < n; ++i){
    p += (s[i] == '1');
  }

  if(p == n && n % 2 == 0){
    printf("NO\n");
    return;
  }

  FillMoves(n, p);
  
  printf("YES\n%lu\n", v.size());

  if(v.empty()){
    return;
  }

  printf("%d\n", v.front().first);

  for(auto [move, pos]: v){
    printf("%d\n", pos);
  }
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    Solve();
  }

  return 0;
}