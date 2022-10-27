#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool AddWord(set<char>& S){
  char start_letter = '\0', c = '\0';
  while(true){
    c = getchar();

    if(c == '*'){
      exit(0);
    }

    if(!isalpha(c)){
      break;
    }

    if(isalpha(start_letter)){
      continue;
    }

    start_letter = c;
  }

  if(isalpha(start_letter)){
    S.insert(toupper(start_letter));
  }

  return c == ' ';
}

bool Solve(){
  set<char> S;
  while(AddWord(S));
  return S.size() == 1;
}

int main(){
  while(true){
    printf("%s\n", Solve() ? "Y" : "N");
  }
  return 0;
}