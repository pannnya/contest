#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <map>
#include <set>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define INF 1000000000

#define EPS (1e-10)
#define EQ(a, b) (abs((a)-(b)) < EPS)
#define EQV(a,b) (EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()))

typedef long long int LL;
typedef complex<double> P;
typedef pair<int, int> Pair;
typedef tuple<int, int, int> T3;

struct edge { int to, cost; };

vector<edge> es[805];
int memo[805][805][2];


bool has_ch(int i, int p) {
  for (int k = 0; k < es[i].size(); k++)
    if (es[i][k].to != p) return true;
  return false;
}

int time(int i, int p, bool r) {

  if (memo[i][p][r] >= 0) return memo[i][p][r];

  int leaf = 0;
  vector<edge> ch(es[i].begin(), es[i].end());
  for (int k = 0; k < ch.size(); k++) {
    if (ch[k].to == p) {
      ch.erase(ch.begin() + k--);
    }
  }
  /*
  printf("i = %d, p = %d, r = %d", i, p, r);
  cout << endl;
  for (int k = 0; k < ch.size(); k++) {
    cout << P(ch[k].to, ch[k].cost) << endl;
  }
  */
  int resp;
  if (r) {
    int sum = 0;
    for (int k = 0; k < ch.size(); k++) {
      int t = ch[k].to, c = ch[k].cost;
      if (has_ch(t, i))
	sum += c * 3 + time(t, i, true);
      else
	sum += c;
    }
    resp = sum + leaf;

  } else {
    int res = ch.size() == 0 ? 0 :INF;
    for (int j = 0; j < ch.size(); j++) {
      int sum;
      int t = ch[j].to, c = ch[j].cost;
      if (has_ch(t, i))
	sum = c * 2 + time(t, i, false);
      else
	sum = c;
      for (int k = 0; k < ch.size(); k++) {
	if (j == k) continue;
	int t = ch[k].to, c = ch[k].cost;
	if (has_ch(t, i))
	  sum += c * 3 + time(t, i, true);
	else 
	  sum += c;
      }
      res = min(res, sum);
    }
    resp = res + leaf;
  }

  //cout << " => " << resp << endl;
  return memo[i][p][r] = resp;
}

int main(){
  int n;
  while (cin >> n && n) {
    
    int p[805], d[805];

    for (int i = 2; i <= n; i++)
      cin >> p[i];

    for (int i = 2; i <= n; i++)
      cin >> d[i];

    for (int i = 0; i < 805; i++)
      es[i].clear();

    for (int i = 2; i <= n; i++) {
      es[i].push_back({p[i], d[i]});
      es[p[i]].push_back({i, d[i]});
    }

    memset(memo, -1, sizeof(memo));

    int ans = INF;
    for (int i = 1; i <= n; i++)
      ans = min(ans, time(i, 0, false));

    cout << ans << endl;
    
  }
  
  return 0;
}
