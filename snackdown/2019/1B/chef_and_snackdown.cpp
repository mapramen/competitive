#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int t;
  set<int> S{2010, 2015, 2016, 2017, 2019};

  cin >> t;
  while(t--){
    int n;
    cin >> n;
    if(S.find(n) == S.end()){
      cout << "NOT ";
    }
    cout << "HOSTED\n";
  }

  return 0;
}
