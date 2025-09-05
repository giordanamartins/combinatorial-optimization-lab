#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;

int main(){
    // deixa o código rápido
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
    ll maq, tt, m = 0;
    cin >> maq >> tt;
    vector<ll> v(tt);  
    vector<ll> vmaq(maq); //vetor armazena a quantidade de máquinas disponíveis

    for (int i = 0; i < tt; i++){
        cin >> v[i]; // vetor armazena o tempo de cada tarefa
        vmaq[i % maq] += v[i]; // aloca as tarefas nas máquinas disponíveis
        m = max(m, vmaq[i % maq]); // verifica o tempo máximo que uma máquina leva (solução)
    }
    cout << m << "\n";

    return 0;
}
