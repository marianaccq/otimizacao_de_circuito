# Resolução de circuitos elétricos

Utilização de grafos para resolver circruitos elétricos. Esse programa lê um arquivo .txt com especificações de um circuito elétrico e retorna os valores de corrente de malha corresponde. 
O arquivo de texto deve seguir o seguinte padrão:

dim 2
r 20.0 0 1

r - resistor
v - fonte de tensão
w - fio

Iniciar com a dimenção (que corresponde a quantidade de nós), nas proximas linhas, iniciar com uma dessas 3 letras (r, v ou w), seguida do valor do componente, e os nós no qual se encontra. Por exemplo: r 20.0 0 1. Ou seja, há um resistor de 20omhs entre os nós 0 e 1.

Exemplo de arquivo txt:

dim 8\
v 12.0 0 1\
r 3.0 1 2\
r 4.0 2 3\
r 1.0 3 0\
w 0.0 4 2\
v 6.0 3 5\
r 8.0 4 5\
r 8.0 4 6\
w 0.0 6 7\
w 0.0 7 5\
