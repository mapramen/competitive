#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

char op[10];
int T[N];

void Add(int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

int Query(int l, int r){
  return Query(r) - Query(l - 1);
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  while(q--){
    int i, j;
    scanf("%s%d%d", op, &i, &j);

    if(op[0] == 'a'){
      Add(i, j);
    }
    else{
      printf("%d\n", Query(i, j));
    }
  }

  return 0;
}