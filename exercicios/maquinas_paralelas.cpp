#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;

int main(){
    // deixa o código rápido
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // heuristíca 1 - insere as tarefas alternadamente nas máquinas
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

    // ---------------------------------------------------------------------------------
    // heuristíca 2 - insere as tarefas na máquina com menor tempo total disponível
    ll menorMaquina;
    for (int i = 0; i < tt; i++){
        cin >> v[i]; // vetor armazena o tempo de cada tarefa
        ll menorTempo = 111111111111111;
        for (int j = 0; j < tt; j++){
                if (vmaq[j] < menorTempo){ // se o tempo total de tarefas da máquina for menor que um número grande aleatório
                    menorTempo = vmaq[j]; // armazena o menor tempo para comparar com as demais nas próximas iterações
                    menorMaquina = j; // armazena em qual máquina a tarefa será inserida
                }
            }
            vmaq[menorMaquina] += v[i]; // aloca as tarefas nas máquinas disponíveis
            m = max(m, vmaq[menorMaquina]); // verifica o tempo máximo que uma máquina leva (solução)
    }
    cout << m << "\n";
    // ---------------------------------------------------------------------------------

    return 0;
}

