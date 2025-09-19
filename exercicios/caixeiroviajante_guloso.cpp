#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 

    vector<ll> x;
    vector<ll> y;
    ll id;
    ll menorDistancia = 3333333333333;

    while (cin >> id){
        ll x1, y1;
        cin >> x1;
        x.push_back(x1);

        cin >> y1;
        y.push_back(y1);
    }

    ll n = x.size();

    vector<ll> x_percorridos;
    vector<ll> y_percorridos;

    x_percorridos.push_back(x[0]);
    y_percorridos.push_back(y[0]);

    for (ll i = 0; i < n-1; i++){
        ll soma = 0;
        ll indice;
        for (ll j = 0; j < n; j++){
            if (i != j){
                ll dist_x = x_percorridos[i] - x[j];
                ll dist_y = y_percorridos[i] - y[j];
                ll dist = (sqrt(dist_x * dist_x + dist_y * dist_y) + 0.5);

                if(dist < menorDistancia){
                    menorDistancia = dist;
                    indice = j;
                }
            }
        }

        x_percorridos.push_back(x[indice]);
        y_percorridos.push_back(y[indice]);

        soma += menorDistancia;
    }

    cout << menorDistancia << endl;

    return 0;
}