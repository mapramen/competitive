#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100
#define B 10

int a[N], c[B];
queue<int> Q;

void Reset(){
  for(int i = 1; i < B; ++i){
    c[i] = 0;
  }

  for( ; !Q.empty(); Q.pop());
}

bool CanPrint(int i){
  for(int p = a[i] + 1; p < B; ++p){
    if(c[p] != 0){
      return false;
    }
  }
  return true;
}

int Pop(){
  int i = Q.front();
  Q.pop();
  --c[a[i]];
  return i;
}

void Push(int i){
  ++c[a[i]];
  Q.push(i);
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  Reset();

  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 0; i < n; ++i){
    Push(i);
  }

  int ans = 0;
  while(true){
    int i = Pop();
    if(!CanPrint(i)){
      Push(i);
      continue;
    }

    ++ans;
    if(i == m){
      break;
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}