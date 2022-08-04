#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 20001

bitset<N> S[N];

int main(){
  int q;
  scanf("%d", &q);

  while(q--){
    char op;
    int x, y;
    scanf(" %c%d%d", &op, &x, &y);
    
    if(op == '+'){
      S[x].set(y);
    }
    else if(op == '-'){
      S[x].reset(y);
    }
    else if(op == 'v'){
      printf("%lu\n", (S[x] | S[y]).count());
    }
    else if(op == '^'){
      printf("%lu\n", (S[x] & S[y]).count());
    }
    else if(op == '!'){
      printf("%lu\n", ((S[x] | S[y]) ^ (S[x] & S[y])).count());
    }
    else{
      printf("%lu\n", (S[x] ^ (S[x] & S[y])).count());
    }
  }

  return 0;
}