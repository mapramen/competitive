#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  int c = 0;
  
  for(int i = 0; i < 5; ++i){
    int r;
    scanf("%d", &r);
    
    if(r == 1){
      ++c;
    }

    if(r == 2){
      --c;
    }
  }
  
  if(c == 0){
    return "DRAW";
  }

  return c > 0 ? "INDIA" : "ENGLAND";
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%s\n", Solve().c_str());
  }

  return 0;
}