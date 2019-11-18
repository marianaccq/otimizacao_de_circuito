# Resolução de circuitos elétricos

Utilização de grafos para resolver circruitos elétricos. Esse programa lê um arquivo .txt com especificações de um circuito elétrico e retorna os valores de corrente de malha corresponde. 
O arquivo de texto deve seguir o seguinte padrão:

dim 2
r 20.0 0 1

r - resistor
v - fonte de tensão
w - fio

Iniciar com a dimenção (que corresponde a quantidade de nós), nas proximas linhas, iniciar com uma dessas 3 letras (r, v ou w), seguida do valor do componente, e os nós no qual se encontra. Por exemplo: r 20.0 0 1. Ou seja, há um resistor de 20omhs entre os nós 0 e 1.
