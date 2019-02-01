#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 20000

int main(){
  int i, n, y = 0;

  cin >> n;

  for(i = 0; i < n; i++){
    int x;
    string s;

    cin >> x >> s;

    if(y == 0){
      if(s != "South")
        break;
    }
    else if(y == N){
      if(s != "North")
        break;
    }

    if(s == "East" || s == "West")
      continue;

    if(s == "North"){
      if(x > y)
        break;
      y -= x;
    }
    else{
      if(x + y > N)
        break;
      y += x;
    }
  }

  if(i != n || y != 0)
    printf("NO\n");
  else
    printf("YES\n");

  return 0;
}
