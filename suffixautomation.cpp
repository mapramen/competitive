#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

typedef struct state {
  int len;
  int link;
  int dsubcount;
  int pcount;
  map<char,int> nxt;
}state;

class SuffixAutomation {
  public:
    int sz;
    int last;
    vector<state> st;
    vector< pii > base;

    ~SuffixAutomation(){ st.clear(); }

    void SuffixAutomationExtend(char c){
      int cur = ++sz, p;
      st[cur].len = st[last].len + 1;
      st[cur].pcount = 1;

      for(p = last; p != -1 && !st[p].nxt.count(c); p = st[p].link)
        st[p].nxt[c] = cur;

      if(p == -1)
        st[cur].link = 0;
      else{
        int q = st[p].nxt[c];

        if(st[p].len + 1 == st[q].len)
          st[cur].link = q;
        else{
          int clone = ++sz;

          st[clone].len = st[p].len + 1;
          st[clone].link = st[q].link;
          st[clone].nxt = st[q].nxt;

          for( ; p != -1 && st[p].nxt[c] == q; p = st[p].link)
            st[p].nxt[c] = clone;

          base.PB(MP(st[clone].len, clone));
          st[q].link = st[cur].link = clone;
        }
      }

      base.PB(MP(st[cur].len, cur));
      last = cur;
    }

    void BuildSuffixAutomation(string s){
      st.clear();
      st.resize(2 * s.size());
      last = sz = 0;
      st[0].link = -1;

      for(int i = 0; s[i] != '\0'; i++)
        SuffixAutomationExtend(s[i]);
    }

    void FillDistinctSubstringCount(int i = 0){
      if(st[i].dsubcount == 0){
        st[i].dsubcount = (i != 0);

        for(auto it : st[i].nxt){
          int k = it.second;
          FillDistinctSubstringCount(k);
          st[i].dsubcount += st[k].dsubcount;
        }
      }
    }

    void FillPatternCount(){
      sort(base.begin(), base.end(), greater< pii >());
      for(auto it : base){
        int q = it.second, p = st[q].link;
        st[p].pcount += st[q].pcount;
      }
    }

    int DistinctSubstringCount(int i){
      return st[i].dsubcount;
    }

    int PatternCount(int i){
      return st[i].pcount;
    }

    void TraverseSuffixAutomationDFS(int i, string s){
      for(auto it : st[i].nxt){
        string st = s;
        st.PB(it.first);
        TraverseSuffixAutomationDFS(it.second, st);
      }
    }

    void TraverseSuffixAutomation(){
      TraverseSuffixAutomationDFS(0, string(""));
    }
};

int main(){
  int t;

  scanf("%d", &t);

  while(t--){
    string s;
    SuffixAutomation sa;

    cin >> s;
    sa.BuildSuffixAutomation(s);
    sa.FillCounts(0);

    printf("%d\n", sa.DistinctSubstringCount(0));
  }

  return 0;
}
