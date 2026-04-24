# Análise de Complexidade de Algoritmos em C

Este projeto realiza uma análise empírica da complexidade assintótica de algoritmos clássicos de ordenação e busca. O programa gera massas de dados desordenados, executa os algoritmos, mede o tempo de processamento em segundos e plota automaticamente gráficos comparativos utilizando o Gnuplot.

## 🚀 Algoritmos Analisados

**Ordenação:**
* **Bubble Sort:** Complexidade O(n²) - Utilizado para demonstrar o comportamento quadrático (pior caso).
* **Merge Sort:** Complexidade O(n log n) - Utilizado para demonstrar a eficiência da divisão e conquista para grandes volumes de dados.

**Busca:**
* **Busca Sequencial:** Complexidade O(n) - Crescimento linear em relação à quantidade de elementos.
* **Busca Binária:** Complexidade O(log n) - Busca otimizada, exigindo que o array base esteja previamente ordenado.

## 🛠️ Arquitetura do Projeto

O código foi desenvolvido de forma modular para facilitar a manutenção e a inclusão de novos algoritmos no futuro:

* `algoritmos.h`: Arquivo de cabeçalho contendo as assinaturas das funções.
* `algoritmos.c`: Implementação da lógica de busca, ordenação e geração de dados.
* `main.c`: Arquivo principal responsável por orquestrar os testes, medir o tempo de execução (via `<time.h>`), exportar os dados para CSV e chamar o Gnuplot.

## ⚙️ Pré-requisitos

Para compilar e executar este projeto, você precisará ter instalado em sua máquina:
1.  **Compilador C:** GCC (GNU Compiler Collection).
2.  **Gnuplot:** Software utilizado para a geração automática dos gráficos.

**No Ubuntu / Debian / WSL:**
```bash
sudo apt update
sudo apt install build-essential gnuplot