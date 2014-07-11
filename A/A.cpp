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

#define EPS (1e-10)
#define EQ(a, b) (abs((a)-(b)) < EPS)
#define EQV(a,b) (EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()))

typedef long long int LL;
typedef complex<double> P;
typedef pair<int, int> Pair;
typedef tuple<int, int, int> T3;

int main(){
  int x, y, s;
  while (cin >> x >> y >> s && x) {
    
    double xr = (double)(100 + x) / 100;
    double yr = (double)(100 + y) / 100;

    int ans = -1;    
    for (int a = 1; a < 1000; a++) {
      for (int b = 1; b < 1000; b++) {

	if (a * (100 + x) / 100 + b * (100 + x) / 100 != s) continue;

	ans = max(ans, (int)(a * yr) + (int)(b * yr));
	ans = max(ans, a * (100 + y) / 100 + b * (100 + y) / 100);
      }
    }

    cout << ans << endl;
  }

  return 0;
}
