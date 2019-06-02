# Descrição Geral do Trabalho

Neste trabalho cada equipe de alunos deverá implementar um algoritmo para
ordenação de registros. O programa deverá ler uma sequência de registros de
um arquivo e gerar um novo arquivo com os registros ordenados segundo uma
chave.

O arquivo de entrada conterá uma sequência registros. Cada registro conterá:
uma chave (cadeia de, no máximo, 20 caracteres) e um conteúdo (cadeia de, no
máximo, 50 caracteres). O arquivo de entrada terá formato de texto. Cada
linha conterá os dados de um registro: inicialmente a chave, seguida de uma
vírgula, seguida do conteúdo.

O arquivo de saída deve também ter formato texto, com os registros ordenados, um em cada linha. Ou seja, cada linha deve conter a chave, seguida de
uma vírgula, seguida do conteúdo. Não pode ser gerado nenhum caractere a
mais na saída.

## Observações:
1. O arquivo com os registros de entrada será chamado **entrada.dat**. O arquivo de saída deve ser chamado **saida.dat**.

2. O programa deve conter duas constantes: MAXNARQS, que indica o
número máximo de arquivos que o programa pode manter abertos ao
mesmo tempo; e MAXMEM, que indica o número máximo de bytes
que o programa usará da memória principal. O programa deve ser escrito
considerando-se esses limites. Estas constantes devem ter valor inicial 100
e 512MB (512 mega bytes).

3. Deve-se assumir que o arquivo a ser ordenado pode não caber na memória
principal. Não serão aceitos trabalhos que dependam de que todos os
registros caibam na memória principal.

4. Podem ser usadas bibliotecas para: executar funções básicas em arquivos
(abrir, fechar, ler entrada, gerar saída, modificar a posição corrente de
leitura/escrita no arquivo) e manipulação de estruturas básicas em memória
principal. Não pode ser usado código não implementado pela equipe cujo
fim seja processar dados em memória externa.

