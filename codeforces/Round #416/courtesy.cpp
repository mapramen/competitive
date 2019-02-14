#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int a, b;

  cin >> a >> b;
  for(int x = 1; ; x++){
    if(x > a){
      if(x % 2)
        cout << "Vladik\n";
      else
        cout << "Valera\n";
      break;
    }
    else{
      a -= x;
      swap(a, b);
    }
  }
  
  return 0;
}
