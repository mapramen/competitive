#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<string> ReadLine(){
  vector<string> v;

  char c = '\0';
  string s;
  while(c != '\n'){
    scanf("%c", &c);
    
    if(c != ' ' && c != '\n'){
      s.push_back(c);
      continue;
    }

    if(!s.empty()){
      v.push_back(s);
    }
    s.clear();
  }

  return v;
}

unordered_set<string> ReadInsignificantWords(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }
  getchar();

  unordered_set<string> insignificant_words;
  while(n--){
    insignificant_words.insert(ReadLine().front());
  }

  return insignificant_words;
}

void UpdateDP(int m, vector<int>& dp, string& abbreviation, string& word){
  vector<int> t(m + 1);

  for(int i = 1, n = word.size(); i <= n; ++i){
    char c = toupper(word[i - 1]);
    for(int j = m; j != 0; --j){
      int ansx = c == abbreviation[j - 1] ? (dp[j - 1] + t[j - 1]): 0;
      t[j] += ansx;
    }
  }

  for(int j = 0; j <= m; ++j){
    dp[j] = t[j];
  }
}

int Calculate(unordered_set<string>& insignificant_words, vector<string>& line){
  string abbreviation = line[0];
  int n = abbreviation.size();

  vector<int> dp(n + 1);

  dp[0] = 1;
  for(int k = 1; k < line.size(); ++k){
    if(insignificant_words.count(line[k])){
      continue;
    }
    UpdateDP(n, dp, abbreviation, line[k]);
  }

  return dp[n];
}

void Solve(){
  unordered_set<string> insignificant_words = ReadInsignificantWords();

  while(true){
    vector<string> line = ReadLine();
    if(line[0] == "LAST" && line[1] == "CASE"){
      break;
    }

    int ans = Calculate(insignificant_words, line);

    if(ans == 0){
      printf("%s is not a valid abbreviation\n", line[0].c_str());
    }
    else{
      printf("%s can be formed in %d ways\n", line[0].c_str(), ans);
    }
  }
}

int main(){
  while(true){
    Solve();
  }
  return 0;
}