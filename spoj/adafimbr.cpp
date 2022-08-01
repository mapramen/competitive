#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 3000001

int grundy[N], c[N];

void Initialize(){
  vector<int> moves;
  for(int a = 1, b = 1; b < N; b += a, a = b - a){
    moves.push_back(b);
  }

  for(int i = 1; i < N; ++i){
    for(int move: moves){
      if(move > i){
        break;
      }
      ++c[grundy[i - move]];
    }

    int g = 0;
    for( ; c[g] != 0; ++g);
    grundy[i] = g;

    for(int move: moves){
      if(move > i){
        break;
      }
      --c[grundy[i - move]];
    }
  }
}

int main(){
  Initialize();

  int n;
  scanf("%d", &n);

  int g = 0;
  while(n--){
    int x;
    scanf("%d", &x);
    g ^= grundy[x];
  }

  printf("%s\n", g != 0 ? "Ada" : "Vinit");

  return 0;
}