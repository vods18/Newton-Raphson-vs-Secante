# Newton-Raphson vs Secante
Atividade acadêmica realizando um experimento para comparar as iterações dos métodos Newton-Raphson e Secante na resolução de equações não lineares. 

Justificativa do critério de parada:
Utilizamos a diferença entre raiz estimada atual e raiz estimada na iteração anterior (módulo do erro absoluto), pois nos demonstrou ser um método com maior precisão matemática para o problema envolvido.


Como executar:
```bash
make
./ep01 < sample.in > sample.csv
cat sample.csv

