#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define P 31
#define MOD 1000000007

vector<string> words;
map<int,vector<int>> prefix_hash_to_word_index;

void AddWord(int i, string& word){
  int hsh = 0;
  for(char c: word){
    hsh = (1ll * hsh * P + (c - 'a' + 1)) % MOD;
    prefix_hash_to_word_index[hsh].push_back(i);
  }
}

vector<string> GetWordsWithPrefix(string& prefix){
  int hsh = 0;
  for(char c: prefix){
    hsh = (1ll * hsh * P + (c - 'a' + 1)) % MOD;
  }

  vector<string> ans;

  auto it = prefix_hash_to_word_index.find(hsh);
  if(it == prefix_hash_to_word_index.end()){
    return ans;
  }

  for(int i: it->second){
    if(words[i] != prefix && string(words[i], 0, prefix.size()) == prefix){
      ans.push_back(words[i]);
    }
  }

  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  words.resize(n);
  for(string& word: words){
    cin >> word;
  }
  sort(words.begin(), words.end());
  words.erase(unique(words.begin(), words.end()), words.end());

  for(int i = 0; i < words.size(); ++i){
    AddWord(i, words[i]);
  }

  int q;
  scanf("%d", &q);

  for(int k = 1; k <= q; ++k){
    string prefix;
    cin >> prefix;

    vector<string> ans = GetWordsWithPrefix(prefix);

    printf("Case #%d:\n", k);

    if(ans.empty()){
      printf("No match.\n");
      continue;
    }
    
    for(string word: ans){
      cout << word << '\n';
    }
  }
  
  return 0;
}