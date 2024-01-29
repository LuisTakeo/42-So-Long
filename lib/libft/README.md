# 42-Libft

Primeiro projeto realizado na minha formação de Engenharia de Software na 42, a qual fiz minha primeira biblioteca própria de funções em C.


## Funções

### Principais:
- ft_isdigit -> Verifica se o caractere é um número (0-9).
- ft_isalpha -> Verifica se o caractere é uma letra maiuscula ou minuscula.
- ft_isalnum -> Verifica se o caractere é um alfanumérico.
- ft_isascii -> Verifica se o caractere faz parte da tabela ASCII. 
- ft_isprint -> Verifica se o caractere é imprimível.
- ft_strlen -> Recebe uma string e retorna o tamanho dela.
- ft_memset -> Preenche os primeiros **n** bytes apontados por **s** com o caractere **c**.
- ft_bzero -> Preenche os primeiros **n** bytes apontados por **s** com o número 0 (ou '\0').
- ft_memcpy -> Copia um espaço de memória.
- ft_memmove -> Copia um espaço de memória, podendo ocorrer overlap.
- ft_strlcpy -> Copia uma string com base no seu buffer total e garante o '\0' no final do destino.
- ft_strlcat -> Concatena duas strings com base no tamanho total.
- ft_toupper -> Transforma o caractere alfabetico minúsculo em maiúsculo.
- ft_tolower -> Transforma o caractere alfabetico maiúsculo em minúsculo.
- ft_strchr -> Busca o caractere informado em uma string a partir de seu início.
- ft_strrchr -> Busca o caractere informado em uma string a partir de seu final.
- ft_strncmp -> Busca uma string informada em uma quantidade n de caracteres da string.
- ft_memchr -> Busca um byte em um bloco de memória.
- ft_memcmp -> Compara dois blocos de memória
- ft_strnstr -> Verifica se há uma substring dentro de uma string.
- ft_atoi -> Transforma uma string com números em int.
- ft_calloc -> Faz uma alocação de memória e inicializa cada byte com '\0'.
- ft_strdup -> Traz uma cópia da string informada com espaço de memória alocado.
- ft_substr -> Retorna uma substring de uma string.
- ft_putchar_fd -> imprime o caractere informado no fd e retorna o valor de quanto foi imprimido.
- ft_putstr_fd -> Imprime a string (char *) informada no fd e retorna a quantidade de caracteres imprimidos.
- ft_putendl_fd -> Executa a mesma função da ft_putstr_fd e, em seu final, adciona uma quebra de linha.
- ft_putnbr_fd -> Converte e imprime o número.
- ft_striteri -> Itera sob a string, executando uma função para cada caractere.
- ft_strmapi -> Itera sob uma string, criando uma nova string com cada caractere tratado por uma função.
- ft_strjoin -> Junta duas strings em uma só.
- ft_strtrim -> Busca um caractere e remove no começo e no final do texto.
- ft_itoa -> Transforma número inteiro para char *.
- ft_split -> Divide uma string em strings menores, com base no separador.
- ft_putnull_fd -> Imprime na tela o valor NULL.

### Bonus:
- ft_lstnew_bonus -> Cria um novo nó com o conteúdo recebido.
- ft_lstadd_front_bonus -> Adiciona um nó no começo da lista.
- ft_lstsize_bonus -> Verifica e retorna a quantidade de nós da lista.
- ft_lstlast_bonus -> Retorna com o nó do final da lista.
- ft_lstadd_back_bonus -> Adiciona um nó no final da lista.
- ft_lstdelone_bonus -> Remove o nó e seu conteúdo.
- ft_lstclear_bonus -> Limpa uma lista e todos seus nós.
- ft_lstiter_bonus -> Itera e executa uma função para cada conteúdo do nó.
- ft_lstmap_bonus -> Mapeia a lista e seus conteúdos, retornando novos conteúdos em uma nova lista de mesmo tamanho.

### Adicionais:
- get_next_line -> Recebe um File Descriptor e retorna com a próxima linha lida.
- ft_printf -> Imprime um texto e seus argumentos com base na formatação da string ('%'). Versão 'mini' da printf original, sendo englobado os formatos "cspdiuxX%" e as flags '#', '+' e ' ' (space). 
- ft_putnbrbase_fd -> Imprime um valor numérico em uma base numeral.
- ft_putpointer_fd -> Imprime o valor de um ponteiro em seu hexadecimal.

## Modo de uso

### Instruções:

 1. Para uso da libFT em seu projeto, antes de tudo, é necessário ter o compilador de C em seu sistema (gcc).
 2.  Execute o seguinte comando para compilação, a qual irá gerar um arquivo **libft.a**.    

>     $ make all bonus new_fun

 3. Após isso, para usar a **libft.a**, será necessário ter um arquivo com a função `main`. Neste arquivo, insira os seguintes `#include`:

>     $ main.c

    `#include "libft.h"`
    `#include "get_next_line.h" // para uso da get_next_line`
	`#include "ft_printf.h" // para uso da ft_printf`
 4. Após isso, faça a compilação do seu arquivo main com a libft.a para gerar seu executável:
    

> `$ gcc main.c libft.a`

 5. Caso queira remover os objects da libft:

> `$ make clean`

 7. Caso deseja remover os objects e a libft.a:
> `$ make fclean`
