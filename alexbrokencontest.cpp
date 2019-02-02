#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  vector<string> v;
  string s;

  v.PB("Danil");
  v.PB("Olya");
  v.PB("Slava");
  v.PB("Ann");
  v.PB("Nikita");

  cin >> s;

  int c = 0;
  for(auto t : v){
    size_t f = s.find(t);
    while(f != string::npos){
      ++c;
      f = s.find(t, f + 1);
    }
  }
    
  if(c == 1)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
