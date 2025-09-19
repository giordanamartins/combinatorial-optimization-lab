#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 

    auto tempo_limite = std::chrono::seconds(60);
    auto tempo_inicio = std::chrono::steady_clock::now();

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

        vector<ll> permut;
        for (ll i = 0; i < n; i++) {
        permut.push_back(i);
        }

        do {
            ll soma = 0;
            for (ll i = 0; i < n-1; i++){
                ll dist_x = x[permut[i]] - x[permut[i+1]];
                ll dist_y = y[permut[i]] - y[permut[i+1]];
                ll dist = (sqrt(dist_x * dist_x + dist_y * dist_y) + 0.5);

                soma += dist;
            }
            ll dist_x = x[permut[0]] - x[permut[n-1]];
            ll dist_y = y[permut[0]] - y[permut[n-1]];
            ll dist = (sqrt(dist_x * dist_x + dist_y * dist_y) + 0.5);

            soma += dist;

            if(soma < menorDistancia){
                menorDistancia = soma;
            }
            auto tempo_atual = std::chrono::steady_clock::now();
            auto tempo_decorrido = std::chrono::duration_cast<std::chrono::seconds>(tempo_atual - tempo_inicio);

            if (tempo_decorrido >= tempo_limite) {
                std::cout << "Tempo limite excedido. Encerrando o programa." << std::endl;
                cout << menorDistancia << endl;
                std::exit(EXIT_SUCCESS); 
            }
        } while (next_permutation(permut.begin(), permut.end()));

    return 0;
}