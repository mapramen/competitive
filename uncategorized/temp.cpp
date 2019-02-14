#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define long pair<long, long>
#define PB push_back
#define MP make_pair

void BFS(int s, int t, vector< set<int> > &adj, vector<int> &d){
    int n = d.size();
    queue<int> Q;

    for(int i = 0; i < n; ++i){
        d[i] = 2 * n;
    }

    d[s] = 0;
    Q.push(s);

    while(!Q.empty() && d[t] >= n){
        int i = Q.front();
        Q.pop();
        for(auto j : adj[i]){
            if(1 + d[i] < d[j]){
                d[j] = 1 + d[i];
                Q.push(j);
            }
        }
    }
}

vector< vector<int> > DFS(int s, int t, vector< set<int> > &adj, vector<int> &d){
    vector< vector<int> > paths;

    if(s == t){
        paths.push_back(vector<int>{s});
        return paths;
    }

    for(auto k : adj[s]){
        if(d[k] != 1 + d[s]){
            continue;
        }
        vector< vector<int> > tPaths = DFS(k, t, adj, d);
        for(int x = 0; x < tPaths.size(); ++x){
            tPaths[x].push_back(s);
            paths.push_back(tPaths[x]);
        }
    }

    return paths;
}

vector<vector<string> > FindLadders(string start, string end, vector<string> &words) {
    map<string,int> wordsIndex;
    map<int,string> inverseWordsIndex;
    wordsIndex[start] = 0;

    for(auto s : words){
        if(wordsIndex.count(s) == 0){
            wordsIndex[s] = wordsIndex.size() - 1;
        }
    }

    if(wordsIndex.count(end) == 0){
        wordsIndex[end] = wordsIndex.size() - 1;
    }

    for(auto p : wordsIndex){
				cout << p.first << ' ' << p.second << '\n';
        inverseWordsIndex[p.second] = p.first;
    }

		printf("OK\n");

    int n = wordsIndex.size();
    vector< set<int> > adj(n);
    vector<int> d(n);

    for(int i = 0; 2 * i < n; ++i){
        string s = words[i];
        for(int x = 0; x < s.size(); ++x){
            char c = s[x];
            for(char d = 'a'; d <= 'z'; ++d){
                if(d == c){
                    continue;
                }
                s[x] = d;
                if(wordsIndex.count(s) > 0){
                    int j = wordsIndex[s];
                    if(j < i){
                        continue;
                    }
                    adj[i].insert(j);
                    adj[j].insert(i);
                }
            }
            s[x] = c;
        }
    }

		printf("OK\n");
		fflush(stdout);

    int s = wordsIndex[start], t = wordsIndex[end];
    BFS(s, t, adj, d);

    vector< vector<int> > paths = DFS(s, t, adj, d);

    vector< vector<string> > ans;

    for(auto path : paths){
        vector<string> v;
        for(auto i : path){
            v.push_back(inverseWordsIndex[i]);
        }
        reverse(v.begin(), v.end());
        ans.push_back(v);
    }

    return ans;
}

int main(){
	vector<string> words{"bb", "ab"};

	auto v = FindLadders("bb", "ab", words);

	for(auto u : v){
		for(auto s : u){
			cout << s << ' ';
		}
		cout << '\n';
	}

  return 0;
}
