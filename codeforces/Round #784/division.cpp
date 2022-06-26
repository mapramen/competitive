#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int rating;
  scanf("%d", &rating);

  if(rating <= 1399){
    return 4;
  }

  if(rating <= 1599){
    return 3;
  }

  if(rating <= 1899){
    return 2;
  }

  return 1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("Division %d\n", Solve());
  }
  return 0;
}