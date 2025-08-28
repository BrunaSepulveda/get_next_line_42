# get_next_line_42
Este projeto não só permitirá que você adicione uma função muito prática à sua coleção, mas também fará com que você aprenda o incrível conceito de variáveis estáticas em programação em C.

|            Parte Mandatória     | Informação |
| :------------------------------ | :------------------------------------------------------------------------------------------- |
| Nome da função                  |   get_next_line                                                                              |
| Protótipo                       |  char *get_next_line(int fd);                                                                |
| Ficheiros para entregar         |  get_next_line.c, get_next_line_utils.c, get_next_line.h                                     |
| Parâmetros fd                   |  fd: O file descriptor a ser lido                                                                                         |
| Valor de retorno                |  A linha lida, se tudo correr bem NULL, se não houver nada a ser lido ou em caso de erro   |
| Funções externas autorizadas    |  read, malloc, free                                                                                         |

## Descrição
Escreva uma função que retorne uma linha lida de um file descriptor.
<ul>
  <li>Chamadas repetidas (por exemplo, usando um loop) para a sua função get_next_line() devem permitir que você leia o arquivo de texto apontado pelo file descriptor, uma linha de cada vez, até o final.</li>
  <li>Sua função deve retornar a linha que foi lida. Se não houver mais nada para ler ou se ocorrer um erro, ela deve retornar NULL.</li>
  <li>Certifique-se de que sua função funcione corretamente tanto ao ler de um arquivo quanto ao ler da entrada padrão.</li>
  <li>Por favor, note que a linha retornada deve incluir o caractere terminador \n, exceto se o final do arquivo foi atingido e não termina com um caractere \n.</li>
  <li>O arquivo get_next_line.h deve conter pelo menos o protótipo da função get_next_line().</li>
  <li>Adicione todas as funções auxiliares necessárias no arquivo get_next_line_utils.c.</li>
</ul>
