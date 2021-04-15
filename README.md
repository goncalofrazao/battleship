Este arquivo tem os seguintes ficheiros:

9x9-p1		exemplo de output produzido com o comando: ./wargame -j 0
9x9-p2  	exemplo de output produzido com o comando: ./wargame -j 0 -p 2 -1 1 -2 1 -3 1 -4 1
15x24-p1	exemplo de output produzido com o comando: ./wargame -j 0 -t 15x24
15x24-p2	exemplo de output produzido com o comando: ./wargame -j 0 -t 15x24 -p 2 -1 3 -2 3 -3 3 -4 3 -5 2 -6 2 -7 2 -8 2

play_game	bash script para fazer o programa wargame jogar contra ele prÛprio. SÛ funciona em Linux.

fich1-20210331-173907	exemplo de ficheiro modo "-j 1" produzido com: ./play_game -d 1 -1 1 -2 1 -3 1 -4 1
fich2-20210331-173907	exemplo de ficheiro modo "-j 2" produzido com: ./play_game -d 1 -1 1 -2 1 -3 1 -4 1
fich1-20210331-173916	exemplo de ficheiro modo "-j 1" produzido com: ./play_game -d 2 -1 1 -2 1 -3 1 -4 1
fich2-20210331-173916	exemplo de ficheiro modo "-j 2" produzido com: ./play_game -d 2 -1 1 -2 1 -3 1 -4 1
fich1-20210331-173925	exemplo de ficheiro modo "-j 1" produzido com: ./play_game -d 3 -1 1 -2 1 -3 1 -4 1
fich2-20210331-173925	exemplo de ficheiro modo "-j 2" produzido com: ./play_game -d 3 -1 1 -2 1 -3 1 -4 1
fich1-20210331-173934	exemplo de ficheiro modo "-j 1" produzido com: ./play_game -t 15x24 -d 1 -1 3 -2 3 -3 3 -4 3 -5 2 -6 2 -7 2 -8 2
fich2-20210331-173934	exemplo de ficheiro modo "-j 2" produzido com: ./play_game -t 15x24 -d 1 -1 3 -2 3 -3 3 -4 3 -5 2 -6 2 -7 2 -8 2
fich1-20210331-173939	exemplo de ficheiro modo "-j 1" produzido com: ./play_game -t 15x24 -d 2 -1 3 -2 3 -3 3 -4 3 -5 2 -6 2 -7 2 -8 2
fich2-20210331-173939	exemplo de ficheiro modo "-j 2" produzido com: ./play_game -t 15x24 -d 2 -1 3 -2 3 -3 3 -4 3 -5 2 -6 2 -7 2 -8 2
fich1-20210331-173942	exemplo de ficheiro modo "-j 1" produzido com: ./play_game -t 15x24 -d 3 -1 3 -2 3 -3 3 -4 3 -5 2 -6 2 -7 2 -8 2
fich2-20210331-173942	exemplo de ficheiro modo "-j 2" produzido com: ./play_game -t 15x24 -d 3 -1 3 -2 3 -3 3 -4 3 -5 2 -6 2 -7 2 -8 2


O script "play_game" permite correr um jogo de batalha naval entre duas inst‚ncias do programa,
uma em modo "-j 1" e outra em modo "-j 2". O script lanÁa as duas inst‚ncias do programa interligando
o stdout de uma ao stdin da outra e o stdout da segunda ao stdin da primeira utilizando pipes e fifos.

O script produz dois ficheiros com o output das duas inst‚ncias do programa, que ficam automaticamente
com nomes incluindo a data e hora da execuÁ„o do script.
O ficheiro fich1-<data>-<hora> fica com resultados dos tiros, e o ficheiro fich2-<data>-<hora> fica com os tiros.

… usado um filtro, entre o stdout de um programa e stdin do outro, que copia todas as linhas que tenham
apenas uma ˙nica string, descartando as restantes linhas. O objectivo È passar apenas as coordenadas dos tiros
e os resultados dos tiros entre os programas. O programa "wargame" deve ser feito para n„o escrever linhas
com uma ˙nica string que n„o sejam tiros ou resultados dos tiros. Se, por exemplo, quiser escrever alguma outra
mensagem em stdout que sÛ tenha uma ˙nica string numa linha, escreva um asterisco no inÌcio da linha,
conforme indicado no enunciado. Assim, o filtro descartar· a linha, n„o a passando de um programa para o outro.

O script n„o ajuda no caso do modo de posicionamento "-p 1", pois o n˙mero de peÁas de cada tipo È aleatÛrio
neste modo e o enunciado indica que o n˙mero de peÁas È passado na linha de comando.

As opÁıes do script s„o as opÁıes esperadas para o programa "wargame", que s„o passadas a ambas as inst‚ncias
do programa "wargame", sendo acrescentadas as opÁıes "-j 1 -p 2" ‡ primeira inst‚ncia e as opÁıes "-j 2 -p 2"
‡ segunda inst‚ncia. O script automaticamente retira a opÁ„o "-d n" dos par‚metros da linha de comando da
inst‚ncia do programa "wargame" que corre em modo "-j 1" por o modo de disparo n„o ser v·lido neste modo.

Exemplos de utilizaÁ„o do script play_game:
Jogo com tabuleiro 9x9 (default) em modo de disparo 3 com 1 peÁa de cada um dos tipos 1 a 4:
./play_game -d 3 -1 1 -2 1 -3 1 -4 1
Jogo com tabuleiro 15x24 em modo de disparo 2, com 3 peÁas dos tipos 1 a 4 e 2 peÁas dos tipos 5 a 8, perfazendo um total de 20 peÁas.
./play_game -t 15x24 -d 2 -1 3 -2 3 -3 3 -4 3 -5 2 -6 2 -7 2 -8 2
