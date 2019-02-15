#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  set<int> s;

  scanf("%d", &n);
  while(n--){
    int a;
    scanf("%d", &a);
    if(a){
      s.insert(a);
    }
  }

  printf("%lu\n", s.size());

  return 0;
}
