#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

char s[101];

string ReadString(){
  if(scanf("%s", s) == EOF){
    exit(0);
  }
  return string(s);
}

int GetLanguage(string s){
  if(!islower(s.front()) || !isalpha(s.back())){
    return 0;
  }

  bool has_underscores = false, has_uppercase = false;
  char pc = '0';

  for(char c: s){
    if(c == '_' && pc == c){
      return 0;
    }

    has_underscores = has_underscores || (c == '_');
    has_uppercase = has_uppercase || isupper(c);
    pc = c;
  }

  if(has_underscores && has_uppercase){
    return 0;
  }

  return has_underscores ? 1 : 2;
}

string GetJavaString(string s){
  string ans;

  char pc = 'a';
  for(char c: s){
    if(isalpha(c)){
      ans.push_back(isalpha(pc) ? c : toupper(c));
    }
    pc = c;
  }

  return ans;
}

string GetCString(string s){
  string ans;

  for(char c: s){
    if(isupper(c)){
      ans.push_back('_');
    }
    ans.push_back(tolower(c));
  }

  return ans;
}

string Solve(){
  string s = ReadString();
  int language = GetLanguage(s);

  if(language == 0){
    return "Error!";
  }

  return language == 1 ? GetJavaString(s) : GetCString(s);
}

int main(){
  while(true){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}