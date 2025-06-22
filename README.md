# Como utilizar o código

&emsp; Este código implementa uma calculadora com Notação Polonesa Reversa em C ([clique aqui para saber mais sobre como funciona esse tipo de calculadora](https://pt.wikipedia.org/wiki/Nota%C3%A7%C3%A3o_polonesa_inversa_). Para utilizá-lo, compile o código e rode-o em um software com acesso ao terminal. Recomenda-se utilizar o gcc do [WSL do VSCode](https://learn.microsoft.com/pt-br/windows/wsl/tutorials/wsl-vscode), o qual também foi usado para a criação desse código.
Ao rodar o código no terminal, este imprimirá o seguinte:

<div align="center">
<sup>Figura 1 — Rodando o código</sup>
  
![image](https://github.com/user-attachments/assets/af576cc8-2846-4fce-9428-a9c3bf3cfa9b)

<sub>Fonte: Autor (2025) </sub>
</div><br>

&emsp; Escreva expressões utilizando o espaço para saber os números. Exemplos são
```bash
3 2 + 9 2 * -
```

```bash
5 1 2 + 4 * + 3 -
```

```bash
4 53 2 - +
```

&emsp; Essas expressões são, respectivamente, equivalentes em notação comum, à:
```bash
3 + 2 - 9 * 2
```

```bash
 5 + ((1 + 2) * 4) - 3
```

```bash
53 - 2 + 4
```

&emsp; A saída do terminal ao se pressionar _enter_ deve ser como se segue:

<div align="center">
<sup>Figura 2 — Saída com sucesso</sup>

![image](https://github.com/user-attachments/assets/84f3e677-be8b-4319-92b5-512f6be492da)

<sub>Fonte: Autor (2025) </sub>
</div><br>

&emsp; Caso o usuário digite uma expressão inválida, porém, ele pode encontrar um dos três seguintes erros:

<div align="center">
<sup>Figura 3 — Operador Inválido</sup>
  
![image](https://github.com/user-attachments/assets/1b8a0622-9fe5-4452-84fd-2a179e9365d5)

<sub>Fonte: Autor (2025) </sub>
</div><br>

<div align="center">
<sup>Figura 4 — Expressão incorreta</sup>

![image](https://github.com/user-attachments/assets/e040ffc7-e5b9-481e-9f2c-6a3a840c291e)

<sub>Fonte: Autor (2025) </sub>
</div><br>

<div align="center">
<sup>Figura 5 — Número insuficientes de operandos</sup>

![image](https://github.com/user-attachments/assets/e4e238bb-23b4-4ef1-b3fd-c762606517f6)

<sub>Fonte: Autor (2025) </sub>
</div><br>

&emsp; Todos esses erros apontam para dificuldades com a formatação de uma expressão em notação polonesa reversa. Portanto, para garantir expressões adequadas, recomenda-se o estudo desse [website na seção 'Cálculo com o auxílio de uma pilha'](https://pt.wikipedia.org/wiki/Nota%C3%A7%C3%A3o_polonesa_inversa#C%C3%A1lculo_com_o_aux%C3%ADlio_de_uma_pilha_). Deve-se notar, porém, que neste código, a multiplicação é feita com *.

## Como o código é implementado

Nas linhas 1-3, importa-se as três bibliotecas necessárias para o funcionamento do código;

Na linha 5, define-se o **tamanho máximo de uma pilha como um macro**;

Nas linhas 7-10, define-se o **tipo de estrutura pilha** que contém valores e o seu tamanho atual;

Nas linhas 12-15, cria-se uma função que recebe como o endereço de uma variável do tipo pilha como parâmetro e a **inicializa definindo seu tamanho atual como 0**;

Nas linhas 17-19, cria-se uma função auxiliar para verificar se uma lista **está vazia**. Essa função será usada no momento de _pop_ um valor da pilha. Se a pilha está vazia ela retorna verdadeiro. Senão, retorna falso;

Nas linhas 21-25, cria-se a função **push** que recebe o endereço de uma pilha e o valor a ser adicionado à pilha como parâmetros e faz o seguinte:
1. Verifica se a pilha ainda tem espaço para novos valores. Caso não, retorna -1
2. Se a pilha tiver espaço, **inclui o valor dos parâmetros em seus valores**
3. Incrementa o tamanho atual da pilha;

Nas linhas 27-29, cria-se a função ((pop**. Essa função recebe o endereço de uma pilha como parâmetro e faz o seguinte:
1. Verifica se a pilha está vazia. Caso sim, retorna -1 (por essa razão não se pode usar -1 como um dos valores da expressão)
2. Caso não, decrementa o tamanho atual da pilha
3. **Retorna o último valor da pilha** (esse valor não é tecnicamente removido da pilha, mas não pode ser mais acessado devido ao decremento de tamanho atual);

&emsp; Na linha 32, inicia-se o fluxo principal do código.
1. Das linhas 33 à 37 há a inicialização das variáveis e da pilha
2. Nas linhas 39-40 há a instrução para o usuário e o recebimento do seu input
3. Na linha 42, remove-se o \n do final da expressão
4. Na linha 44, guarda-se o primeiro **token** da expressão recebida pelo usuário. Ele é identificado pela existência do espaço. Os próximos tokens são separados na linha 76 e são continuamente verificados para a permanência no loop das linhas 45-77;

## O loop while

&emsp; O loop while presente nas linhas 45-77 lida com a lógica principal da notação polonesa reversa. Ele dita que **caso o token seja um operando** (um número inteiro), então ele deve ser adicionado à pilha. **Caso não**, deve-se pegar os dois últimos operandos com a função _pop_ e realizar a operação instruída pelo usuário (se o usuário de fato registrou uma operação válida). Por último, adiciona-se o resultado dessa operação à pilha.

&emsp; A conclusão desse loop se dá caso não haja mais tokens a serem separados no _input_ do usuário. Então, verifica-se se **resta apenas um valor** na pilha. Se este for o caso, imprime-se esse resultado. Senão, houve um erro na expressão digitada pelo usuário.











