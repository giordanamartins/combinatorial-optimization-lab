#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 

    vector<ll> x;
    vector<ll> y;
    ll id;

    while (cin >> id){
        ll x1, y1;
        cin >> x1;
        x.push_back(x1);

        cin >> y1;
        y.push_back(y1);
    }

    ll n = x.size();

    vector<bool> marcado(n, false);

    ll atual = 0;
    marcado[atual] = true;
    ll soma = 0;

    for (ll step = 1; step < n; ++step) {
        ll menorDistancia = 333333333333333333333;
        ll proximo = -1;

        for (ll j = 0; j < n; ++j) {
            if (!marcado[j]) {
                ll dist_x = x[atual] - x[j];
                ll dist_y = y[atual] - y[j];
                ll dist = (sqrt(dist_x * dist_x + dist_y * dist_y) + 0.5);

                if (dist < menorDistancia) {
                    menorDistancia = dist;
                    proximo = j;
                }
            }
        }

        soma += menorDistancia;
        atual = proximo;
        marcado[atual] = true;
    }

    ll dist_x = x[atual] - x[0];
    ll dist_y = y[atual] - y[0];
    soma += (sqrt(dist_x * dist_x + dist_y * dist_y) + 0.5);

    cout << soma << '\n';

    return 0;
}
