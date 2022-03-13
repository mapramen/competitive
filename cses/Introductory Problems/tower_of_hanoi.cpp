#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void TowerOfHanoi(int n, char from, char to, char use){
  if(n == 0){
    return;
  }

  TowerOfHanoi(n - 1, from, use, to);
  printf("%c %c\n", from, to);
  TowerOfHanoi(n - 1, use, to, from);
}

int main(){
  int n;
  scanf("%d", &n);

  printf("%d\n", (1 << n) - 1);
  TowerOfHanoi(n, '1', '3', '2');
  
  return 0;
}