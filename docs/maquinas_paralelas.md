# 📝 Exercícios - Problema do Escalonamento de Tarefas em Máquinas Paralelas

## 1️⃣ Introdução

O **Problema do Escalonamento de Tarefas em Máquinas Paralelas** consiste em distribuir um conjunto de tarefas entre várias máquinas de forma a **minimizar o tempo total de conclusão (makespan)**.  
Cada máquina pode executar apenas uma tarefa por vez, e cada tarefa tem um tempo de processamento definido.

---

## 2️⃣ Código Implementado

O código foi implementado em **C++**, e realiza três heurísticas diferentes para o escalonamento de tarefas.

---

## 3️⃣ Heurística 1: Inserção Alternada
#### Descrição:
- As tarefas são distribuídas alternadamente entre as máquinas.
- A primeira tarefa vai para a Máquina 1, a segunda para a Máquina 2, e assim por diante.
- Quando todas as máquinas recebem uma tarefa, o ciclo se repete.

#### Exemplo:
````py
Máquinas: 2
Tarefas: [2, 4, 3, 5, 1]

Distribuição alternada:
Máquina 1: 2, 3, 1 → total = 6
Máquina 2: 4, 5    → total = 9
Makespan = 9
````

## 4️⃣ Heurística 2: Inserção na Máquina com Menor Tempo Total
#### Descrição:
- Para cada tarefa, escolhe-se a máquina que atualmente possui menor tempo total.
- A tarefa é adicionada a essa máquina, buscando equilibrar a carga.

#### Exemplo:
````py
Máquinas: 2
Tarefas: [2, 4, 3, 5, 1]

Passo 1: Máquina 1 = 0, Máquina 2 = 0 → Tarefa 2 vai para Máquina 1
Passo 2: Máquina 1 = 2, Máquina 2 = 0 → Tarefa 4 vai para Máquina 2
Passo 3: Máquina 1 = 2, Máquina 2 = 4 → Tarefa 3 vai para Máquina 1
...
````

## 5️⃣ Heurística 3: Inserção com Ordenação das Tarefas
#### Descrição:
- Ordena-se o vetor de tarefas em ordem decrescente de duração.
- Em seguida, aplica-se a Heurística 2: insere cada tarefa na máquina com menor tempo total.
- Essa abordagem prioriza as tarefas mais longas, buscando reduzir o makespan.

#### Exemplo:
````py
Tarefas: [2, 4, 3, 5, 1] → ordenadas → [5, 4, 3, 2, 1]
Máquinas: 2

Passo 1: Máquina 1 = 0, Máquina 2 = 0 → Tarefa 5 vai para Máquina 1
Passo 2: Máquina 1 = 5, Máquina 2 = 0 → Tarefa 4 vai para Máquina 2
Passo 3: Máquina 1 = 5, Máquina 2 = 4 → Tarefa 3 vai para Máquina 2 (menor total)
...
````

## 6️⃣ Comparação das Heurísticas
#### Dado o seguinte:
````py
Tarefas = [20, 18, 17, 2, 1, 1, 1, 1, 1, 1]
Máquinas = 3
````

### 🔹 Comparação em Lista Desbalanceada

| Heurística | Estratégia                           | Makespan | Distribuição (M1 / M2 / M3) |
|------------|--------------------------------------|----------|------------------------------|
| 1          | Inserção alternada                   | **24**   | (24 / 20 / 19)              |
| 2          | Inserção na máquina com menor tempo  | **23**   | (20 / 21 / 23)              |
| 3          | Ordenação decrescente + menor tempo  | **21**   | (21 / 21 / 21)              |

---

### 📌 **Conclusão:**

- Em listas **desbalanceadas** (tarefas muito grandes misturadas com várias pequenas), a **Heurística 3** é claramente superior, pois garante melhor equilíbrio.  
- A **Heurística 1** é a pior, pois ignora totalmente o tempo de cada tarefa.  
- A **Heurística 2** é intermediária, mas ainda sofre dependendo da ordem de chegada das tarefas.  
