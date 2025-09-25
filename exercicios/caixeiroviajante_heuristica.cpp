#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> x, y;
    ll id;

    while (cin >> id){
      ll x1, y1;
      cin >> x1;
      x.push_back(x1);

      cin >> y1;
      y.push_back(y1);
    }

    ll n = x.size();
    ll soma = 0;

    for (ll i = 0; i < n - 1; ++i) {
        ll dist_x = x[i+1] - x[i];
        ll dist_y = y[i+1] - y[i];
        ll dist = (sqrt(dist_x * dist_x + dist_y * dist_y) + 0.5);
        soma += dist;
    }

    ll dist_x = x[0] - x[n-1];
    ll dist_y = y[0] - y[n-1];
    soma += (sqrt(dist_x * dist_x + dist_y * dist_y) + 0.5);

    cout << soma << '\n';
    return 0;
}
