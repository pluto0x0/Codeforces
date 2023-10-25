#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5;
const int MAXA = 3e5;
typedef long long ll;

int n, a[N + 1], maxa = 0;
ll s[MAXA + 1], s2[MAXA + 1];
int ss[MAXA + 1], ss2[MAXA + 1];
ll p[N + 1];

void add(ll arr[], int x, ll v) {
    for(; x <= maxa; x += x & (-x))
        arr[x] += v;
}

ll sum(ll arr[], int x) {
    if(x <= 0) return 0;
    ll ret = 0;
    for(; x ; x -= x & (-x))
        ret += arr[x];
    return ret;
}

#define S(arr, l, r) (sum(arr, r) - sum(arr, (l) - 1))

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (maxa < a[i]) maxa = a[i];
    }
    memset(s, 0, sizeof(s));
    memset(s2, 0, sizeof(s2));
    memset(ss, 0, sizeof(ss));
    memset(ss2, 0, sizeof(ss2));
    for (int i = 1; i <= n; i++) {
        for(int v = a[i], l = 1, r = 1; l <= maxa; l = r + 1, v = a[i] / l, r = v ? a[i] / v : maxa) {
            if (r - l < 24) {
                int SS = 0, SS2 = 0;
                for(int j = l; j <= r; j++) SS += ss[j], SS2 += ss2[j];
                p[i] += ll(a[i]) * SS - ll(SS2) * v;
            }
            else
                p[i] += ll(a[i]) * S(s, l, r) - S(s2, l, r) * v;
        }
        p[i] += sum(s2, maxa);
        for(int l = 0, r = a[i] - 1; l <= maxa; l = r + 1, r = min(l + a[i] - 1, maxa))
            p[i] -= S(s, l, r) * l;
        add(s, a[i], 1), add(s2, a[i], a[i]);
        ss[a[i]]++, ss2[a[i]] += a[i];
    }
    for (int i = 1; i <= n; i++) cout << (p[i] += p[i - 1]) << " ";
    return 0;
}