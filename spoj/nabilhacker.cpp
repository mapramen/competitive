#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Move(string& src, string& dst){
  if(src.empty()){
    return;
  }
  dst.push_back(src.back());
  src.pop_back();
}

string Solve(){
  string s;
  cin >> s;

  string lft, rght;
  for(char c: s){
    if(isalnum(c)){
      lft.push_back(c);
      continue;
    }

    if(c == '-'){
      if(!lft.empty()){
        lft.pop_back();
      }
      continue;
    }

    if(c == '<'){
      Move(lft, rght);
    }
    else{
      Move(rght, lft);
    }
  }

  while(!rght.empty()){
    Move(rght, lft);
  }

  return lft;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}