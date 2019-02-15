#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

set<int> s;

void TakeInput(vector<int>& a){
  for(int i = 1; i <= 6; ++i){
    int j;
    cin >> j;
    a.PB(j);
  }
}

void Form(vector<int>& a, vector<int>& b, vector<int>& c){
  for(auto i : a){
    if(i == 0)
      continue;
    s.insert(i);
    for(auto j : b){
      s.insert(10 * i + j);
      for(auto k : c)
        s.insert(100 * i + 10 * j + k);
    }
  }
}

int main(){
  int n;
  vector<int> a, b, c;

  cin >> n;

  TakeInput(a);

  if(n > 1)
    TakeInput(b);

  if(n > 2)
    TakeInput(c);

  Form(a, b, c);
  Form(a, c, b);
  Form(b, a, c);
  Form(b, c, a);
  Form(c, a, b);
  Form(c, b, a);

  for(int i = 1; ; ++i){
    if(s.find(i) == s.end()){
      printf("%d\n", i - 1);
      return 0;
    }
  }
}
