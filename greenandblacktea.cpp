#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int BlockNo(int a, int k){
  return a / k + (a % k != 0);
}

void Print(char c, int k){
  while(k--)
    putchar(c);
}

int main(){
  int n, a, b, i, j, k, x, y, z;
  char G = 'G', B = 'B';

  scanf("%d%d%d%d", &n, &k, &a, &b);

  if(a > b){
    swap(a, b);
    swap(G, B);
  }

  if(a < BlockNo(b, k) - 1){
    printf("NO\n");
    return 0;
  }

  while(b){
    Print(B, min(k, b));
    b -= min(k, b);

    if(BlockNo(a, k) < BlockNo(b, k)){
      Print(G, 1);
      a -= 1;
    }
    else{
      Print(G, min(k, a));
      a -= min(k, a);
    }
  }
  printf("\n");

  return 0;
}
