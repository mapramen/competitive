#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

queue<int> Q;

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    Q.push(i);
  }

  for(bool skip = true; !Q.empty(); skip = !skip){
    if(skip){
      Q.push(Q.front());
    }
    else{
      printf("%d ", Q.front());
    }
    Q.pop();
  }
  printf("\n");

  return 0;
}