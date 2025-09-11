#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    string p = s;
    sort(p.begin(), p.end());

    // The minimum number of operations is equal to
    // the number of misplaced 1's that are in the prefix of the string where 0's should be.

    // 1 * 0 -> 0 * 1 (* is either 0 or 1)

    // 1 0 0 -> 0 0 1 (left shift)
    // 1 1 0 -> 0 1 1 (right shift)

    for (int i = 0; i < n; ++i) {
      if (s[i] != p[i]) ans++;
    }

    cout << ans / 2 << '\n';
  }
  return 0;
}
