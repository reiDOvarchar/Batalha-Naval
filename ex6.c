#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int campo1[8][8] = {0},campo2[8][8] = {0},campo_jogador1[8][8] = {0},campo_jogador2[8][8] = {0},ganhou1 = 0,ganhou2 = 0,jogador_horizontal1,jogador_vertical1,
jogador_horizontal2,jogador_vertical2,horizontal_vertical,posicao_horizontal,posicao_vertical,contnavio3 = 0;
int a = 0;
bool verif = false;
void jogo() {

    printf("\n\n");
    printf("Campo do player 1:\n");
    for(int i = 0; i<8;i++){
        printf("\t");
        for(int j = 0; j < 8; j++){
            if(campo1[i][j] == 0){
                printf(". ");
            }
            if(campo1[i][j] == 1){
                printf(". ");
            }
            if(campo1[i][j] == 2){
                printf(". ");
            }
            if(campo1[i][j] == 3){
                printf("X ");
            }
            if(campo1[i][j] == 4){
                printf("O ");
            }
        }
        printf("\n");
    }
    printf("\n\n");

    printf("Campo do player 2:\n");
    for(int i = 0; i<8;i++){
        printf("\t");
        for(int j = 0; j < 8; j++){
            if(campo2[i][j] == 0){
                printf(". ");
            }
            if(campo2[i][j] == 1){
                printf(". ");
            }
            if(campo2[i][j] == 2){
                printf(". ");
            }
            if(campo2[i][j] == 3){
                printf("X ");
            }
            if(campo2[i][j] == 4){
                printf("O ");
            }
        }
        printf("\n");
    }
    printf("\n\n");

}

int main(){

    printf("Legenda:\n\n. - Espaco vazio que pode ser preenchido\nW - Navio\no - Espaco vazio que nao pode ser preenchido");

    system("color b");
    printf("Posicione os navios no campo do player 1:");

    //Mostrando matriz do campo
    printf("\n\n\n");
    for(int i = 0; i<8;i++){
        printf("\t");
        for(int j = 0; j < 8; j++){
            if(campo1[i][j] == 0){
                printf(". ");
            }
            if(campo1[i][j] == 1){
                printf("W ");
            }
        }
        printf("\n");
    }
    printf("\n\n");

    //Player 1
    // Posicionando os navios de 4 posicoes na horizontal ou vertical

    printf("Insira os navios de quatro espacos:\n\n");
    printf("\n\nDeseja inserir o navio na vertical ou na horizontal? ('1' para horizontal e '2' para vertical):");
    while(verif == false){
        scanf("%d",&horizontal_vertical);
        if(horizontal_vertical == 1 || horizontal_vertical == 2){

                //navio de quatro posicoes na horizontal

            if(horizontal_vertical == 1){
                printf("\n\nDigite um numero de 1 a 8 para escolher a linha da posicao do navio de 4 posicoes:\n");
                while(verif == false){
                    scanf("%d",&posicao_horizontal);
                    if(posicao_horizontal >= 1 && posicao_horizontal <= 8){
                        verif = true;
                    }
                }
                verif = false;
                printf("\n\nDigite em qual coluna da linha o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 3 proximos espacos serao preenchidos com navio)\n");
                while(verif == false){
                    scanf("%d",&posicao_vertical);
                    if(posicao_vertical >= 1 && posicao_vertical <= 5){
                       for(int i = 0; i<3; i++){
                            if(posicao_vertical-1 != 0){
                                campo1[posicao_horizontal+(i-2)][posicao_vertical-2] = 2;
                            }
                        }
                        for(int i = 0; i<4; i++){
                            campo1[posicao_horizontal-1][posicao_vertical-1] = 1;
                            campo1[posicao_horizontal][posicao_vertical-1] = 2;
                            campo1[posicao_horizontal-2][posicao_vertical-1] = 2;
                            posicao_vertical++;
                        }
                        for(int i = 0; i<3; i++){
                            if(posicao_vertical-4 != 5){
                                campo1[posicao_horizontal+(i-2)][posicao_vertical-1] = 2;
                            }
                        }
                       verif = true;
                       printf("\n\n\n");
                        for(int i = 0; i<8;i++){
                            printf("\t");
                            for(int j = 0; j < 8; j++){
                                if(campo1[i][j] == 0){
                                    printf(". ");
                                }
                                if(campo1[i][j] == 1){
                                    printf("W ");
                                }
                                if(campo1[i][j] == 2){
                                    printf("o ");
                                }
                            }
                            printf("\n");
                        }
                        printf("\n\n");
                    }
                }

            }

                //navio de quatro posicoes na vertical

            else if(horizontal_vertical == 2){
                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a coluna da posicao do navio de 4 posicoes:\n");
                    scanf("%d",&posicao_vertical);
                    if(posicao_vertical >= 1 && posicao_vertical <= 8){
                        verif = true;
                    }
                }
                verif = false;
                while(verif == false){
                    printf("\n\nDigite em qual linha da coluna o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 3 proximos espacos serao preenchidos com navio)\n");
                    scanf("%d",&posicao_horizontal);
                    if(posicao_horizontal >= 1 && posicao_horizontal <= 5){
                       for(int i = 0; i<3; i++){
                            if(posicao_horizontal-1 != 0){
                                if(posicao_vertical-1 == 7){
                                    if(i != 2)
                                        campo1[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                }
                                if(posicao_vertical-1 == 0){
                                    if(i != 0)
                                       campo1[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                }
                                else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                    campo1[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                }
                            }
                        }
                        for(int i = 0; i<4; i++){
                            if(posicao_vertical-1 != 7){
                                campo1[posicao_horizontal+(i-1)][posicao_vertical] = 2;
                            }
                        }
                        for(int i = 0; i<4; i++){
                            campo1[posicao_horizontal-1][posicao_vertical-1] = 1;
                            posicao_horizontal++;
                        }
                        posicao_horizontal = posicao_horizontal -4;
                        for(int i = 0; i<4; i++){
                            if(posicao_vertical-1 != 0){
                                campo1[posicao_horizontal+(i-1)][posicao_vertical-2] = 2;
                            }
                        }
                        for(int i = 0; i<3; i++){
                            if(posicao_horizontal != 4){
                                if(posicao_vertical-1 == 7){
                                    if(i != 2)
                                        campo1[posicao_horizontal+3][posicao_vertical+(i-2)] = 2;
                                }
                                if(posicao_vertical-1 == 0){
                                    if(i != 0)
                                        campo1[posicao_horizontal+3][posicao_vertical+(i-2)] = 2;
                                }
                                else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                    campo1[posicao_horizontal+3][posicao_vertical+(i-2)] = 2;
                                }
                            }
                        }
                       verif = true;
                       printf("\n\n\n");
                        for(int i = 0; i<8;i++){
                            printf("\t");
                            for(int j = 0; j < 8; j++){
                                if(campo1[i][j] == 0){
                                    printf(". ");
                                }
                                if(campo1[i][j] == 1){
                                    printf("W ");
                                }
                                if(campo1[i][j] == 2){
                                    printf("o ");
                                }
                            }
                            printf("\n");
                        }
                        printf("\n\n");
                    }
                }
            }
        }
    }
    verif = false;

    //posicionando o navio de 3 posicoes na horizontal ou vertical

    printf("\n\n\nInsira os navios de tres espacos:\n\n");
    while(verif == false){
        printf("\n\nDeseja inserir o navio na vertical ou na horizontal? ('1' para horizontal e '2' para vertical):");
        scanf("%d",&horizontal_vertical);
        if(horizontal_vertical == 1 || horizontal_vertical == 2){

                //navio de tres posicoes na horizontal

            if(horizontal_vertical == 1){
                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a linha da posicao do navio de 3 posicoes:\n");
                    scanf("%d",&posicao_horizontal);
                    if(posicao_horizontal >= 1 && posicao_horizontal <= 8){
                        a = 0;
                        while(verif == false){
                            printf("\n\nDigite em qual coluna da linha o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 2 proximos espacos serao preenchidos com navio)\n");
                            scanf("%d",&posicao_vertical);
                            if(posicao_vertical >= 1 && posicao_vertical <= 6){
                                for(int i = 0; i< 3; i++){
                                    if(campo1[posicao_horizontal-1][posicao_vertical-1] == 1 || campo1[posicao_horizontal-1][posicao_vertical-1] == 2){
                                        printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                        verif = true;
                                        a = 1;
                                        break;
                                    }
                                    else{
                                        posicao_vertical++;
                                        contnavio3++;
                                    }
                                }
                                    posicao_vertical = posicao_vertical - contnavio3;
                                    if(contnavio3 == 3){
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-1 != 0){
                                                campo1[posicao_horizontal+(i-2)][posicao_vertical-2] = 2;
                                            }
                                        }
                                        for(int i = 0; i<3; i++){
                                            campo1[posicao_horizontal-1][posicao_vertical-1] = 1;
                                            campo1[posicao_horizontal][posicao_vertical-1] = 2;
                                            campo1[posicao_horizontal-2][posicao_vertical-1] = 2;
                                            posicao_vertical++;
                                        }
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-3 != 6){
                                                campo1[posicao_horizontal+(i-2)][posicao_vertical-1] = 2;
                                            }
                                        }
                                        verif = true;
                                        printf("\n\n\n");
                                        for(int i = 0; i<8;i++){
                                            printf("\t");
                                            for(int j = 0; j < 8; j++){
                                                if(campo1[i][j] == 0){
                                                    printf(". ");
                                                }
                                                if(campo1[i][j] == 1){
                                                    printf("W ");
                                                }
                                                if(campo1[i][j] == 2){
                                                    printf("o ");
                                                }
                                            }
                                            printf("\n");
                                        }
                                        printf("\n\n");

                                    }
                                }
                            }
                        }
                        contnavio3 = 0;
                        if(a == 1)
                            verif = false;
                    }
                }





                //navio de tres posicoes na vertical

            else if(horizontal_vertical == 2){
                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a coluna da posicao do navio de 3 posicoes:\n");
                    scanf("%d",&posicao_vertical);
                    if(posicao_vertical >= 1 && posicao_vertical <= 8){
                        int contnavio3 = 0;
                        a = 0;
                        while(verif == false){
                        printf("\n\nDigite em qual linha da coluna o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 3 proximos espacos serao preenchidos com navio)\n");
                        scanf("%d",&posicao_horizontal);
                        if(posicao_horizontal >= 1 && posicao_horizontal <= 6){
                            for(int i = 0; i< 3; i++){
                                if(campo1[posicao_horizontal-1][posicao_vertical-1] == 1 || campo1[posicao_horizontal-1][posicao_vertical-1] == 2){
                                    printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                    verif = true;
                                    a = 1;
                                    break;
                                    }
                                else{
                                    posicao_vertical++;
                                    contnavio3++;
                                    }
                                }
                                posicao_vertical = posicao_vertical - contnavio3;
                                if(contnavio3 == 3){
                                    for(int i = 0; i<3; i++){
                                    if(posicao_horizontal-1 != 0){
                                        if(posicao_vertical-1 == 7){
                                            if(i != 2)
                                                campo1[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                        if(posicao_vertical-1 == 0){
                                            if(i != 0)
                                                campo1[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                        else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                            campo1[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                    }
                                }
                            for(int i = 0; i<3; i++){
                                if(posicao_vertical-1 != 7){
                                    campo1[posicao_horizontal+(i-1)][posicao_vertical] = 2;
                                }
                            }
                            for(int i = 0; i<3; i++){
                                campo1[posicao_horizontal-1][posicao_vertical-1] = 1;
                                posicao_horizontal++;
                            }
                            posicao_horizontal = posicao_horizontal -3;
                            for(int i = 0; i<3; i++){
                                if(posicao_vertical-1 != 0){
                                    campo1[posicao_horizontal+(i-1)][posicao_vertical-2] = 2;
                                }
                            }
                            printf("\n\n%d",posicao_horizontal-1);
                            for(int i = 0; i<3; i++){
                                if(posicao_horizontal != 6){
                                    if(posicao_vertical-1 == 7){
                                        if(i != 2)
                                            campo1[posicao_horizontal+2][posicao_vertical+(i-2)] = 2;
                                    }
                                    if(posicao_vertical-1 == 0){
                                        if(i != 0)
                                            campo1[posicao_horizontal+2][posicao_vertical+(i-2)] = 2;
                                    }
                                    else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                        campo1[posicao_horizontal+2][posicao_vertical+(i-2)] = 2;
                                    }
                                }
                            }

                            verif = true;
                            printf("\n\n\n");
                            for(int i = 0; i<8;i++){
                                printf("\t");
                                for(int j = 0; j < 8; j++){
                                    if(campo1[i][j] == 0){
                                        printf(". ");
                                    }
                                    if(campo1[i][j] == 1){
                                        printf("W ");
                                    }
                                    if(campo1[i][j] == 2){
                                        printf("o ");
                                    }
                                }
                                printf("\n");
                            }
                            printf("\n\n");
                                }

                            }

                        }
                    }
                    if(a == 1)
                        verif = false;
                }
            }
        }
    }
    verif = false;

    //posicionando o primeiro navio de 2 posicoes na horizontal ou vertical

    printf("\n\n\nInsira os navios de dois espacos:\n\n");
    while(verif == false){
        printf("\n\nDeseja inserir o navio na vertical ou na horizontal? ('1' para horizontal e '2' para vertical):");
        scanf("%d",&horizontal_vertical);
        if(horizontal_vertical == 1 || horizontal_vertical == 2){

                //navio de duas posicoes na horizontal

            if(horizontal_vertical == 1){
                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a linha da posicao do navio de 2 posicoes:\n");
                    scanf("%d",&posicao_horizontal);
                    if(posicao_horizontal >= 1 && posicao_horizontal <= 8){
                        a = 0;
                        while(verif == false){
                            printf("\n\nDigite em qual coluna da linha o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 2 proximos espacos serao preenchidos com navio)\n");
                            scanf("%d",&posicao_vertical);
                            if(posicao_vertical >= 1 && posicao_vertical <= 7){
                                for(int i = 0; i< 2; i++){
                                    if(campo1[posicao_horizontal-1][posicao_vertical-1] == 1 || campo1[posicao_horizontal-1][posicao_vertical-1] == 2){
                                        printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                        verif = true;
                                        a = 1;
                                        break;
                                    }
                                    else{
                                        posicao_vertical++;
                                        contnavio3++;
                                    }
                                }
                                    posicao_vertical = posicao_vertical - contnavio3;
                                    if(contnavio3 == 2){
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-1 != 0){
                                                campo1[posicao_horizontal+(i-2)][posicao_vertical-2] = 2;
                                            }
                                        }
                                        for(int i = 0; i<2; i++){
                                            campo1[posicao_horizontal-1][posicao_vertical-1] = 1;
                                            campo1[posicao_horizontal][posicao_vertical-1] = 2;
                                            campo1[posicao_horizontal-2][posicao_vertical-1] = 2;
                                            posicao_vertical++;
                                        }
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-3 != 6){
                                                campo1[posicao_horizontal+(i-2)][posicao_vertical-1] = 2;
                                            }
                                        }
                                        verif = true;
                                        printf("\n\n\n");
                                        for(int i = 0; i<8;i++){
                                            printf("\t");
                                            for(int j = 0; j < 8; j++){
                                                if(campo1[i][j] == 0){
                                                    printf(". ");
                                                }
                                                if(campo1[i][j] == 1){
                                                    printf("W ");
                                                }
                                                if(campo1[i][j] == 2){
                                                    printf("o ");
                                                }
                                            }
                                            printf("\n");
                                        }
                                        printf("\n\n");

                                    }
                                }
                            }
                        }
                        contnavio3 = 0;
                        if(a == 1)
                            verif = false;
                    }
                }


                //navio de duas posicoes na vertical

            else if(horizontal_vertical == 2){
                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a coluna da posicao do navio de 2 posicoes:\n");
                    scanf("%d",&posicao_vertical);
                    if(posicao_vertical >= 1 && posicao_vertical <= 8){
                        int contnavio3 = 0;
                        a = 0;
                        while(verif == false){
                        printf("\n\nDigite em qual linha da coluna o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 3 proximos espacos serao preenchidos com navio)\n");
                        scanf("%d",&posicao_horizontal);
                        if(posicao_horizontal >= 1 && posicao_horizontal <= 6){
                            for(int i = 0; i< 2; i++){
                                if(campo1[posicao_horizontal-1][posicao_vertical-1] == 1 || campo1[posicao_horizontal-1][posicao_vertical-1] == 2){
                                    printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                    verif = true;
                                    a = 1;
                                    break;
                                    }
                                else{
                                    posicao_vertical++;
                                    contnavio3++;
                                    }
                                }
                                posicao_vertical = posicao_vertical - contnavio3;
                                printf("\n\n%d",contnavio3);
                                if(contnavio3 == 2){
                                    for(int i = 0; i<3; i++){
                                    if(posicao_horizontal-1 != 0){
                                        if(posicao_vertical-1 == 7){
                                            if(i != 2)
                                                campo1[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                        if(posicao_vertical-1 == 0){
                                            if(i != 0)
                                                campo1[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                        else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                            campo1[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                    }
                                }
                            for(int i = 0; i<2; i++){
                                if(posicao_vertical-1 != 7){
                                    campo1[posicao_horizontal+(i-1)][posicao_vertical] = 2;
                                }
                            }
                            for(int i = 0; i<2; i++){
                                campo1[posicao_horizontal-1][posicao_vertical-1] = 1;
                                posicao_horizontal++;
                            }
                            posicao_horizontal = posicao_horizontal -2;
                            for(int i = 0; i<2; i++){
                                if(posicao_vertical-1 != 0){
                                    campo1[posicao_horizontal+(i-1)][posicao_vertical-2] = 2;
                                }
                            }
                            printf("\n\n%d",posicao_horizontal-1);
                            for(int i = 0; i<3; i++){
                                if(posicao_horizontal != 7){
                                    if(posicao_vertical-1 == 7){
                                        if(i != 2)
                                            campo1[posicao_horizontal+1][posicao_vertical+(i-2)] = 2;
                                    }
                                    if(posicao_vertical-1 == 0){
                                        if(i != 0)
                                            campo1[posicao_horizontal+1][posicao_vertical+(i-2)] = 2;
                                    }
                                    else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                        campo1[posicao_horizontal+1][posicao_vertical+(i-2)] = 2;
                                    }
                                }
                            }
                            verif = true;
                            printf("\n\n\n");
                            for(int i = 0; i<8;i++){
                                printf("\t");
                                for(int j = 0; j < 8; j++){
                                    if(campo1[i][j] == 0){
                                        printf(". ");
                                    }
                                    if(campo1[i][j] == 1){
                                        printf("W ");
                                    }
                                    if(campo1[i][j] == 2){
                                        printf("o ");
                                    }
                                }
                                printf("\n");
                            }
                            printf("\n\n");
                                }

                            }

                        }
                    }
                    if(a == 1)
                        verif = false;
                }
            }
        }
    }
    verif = false;
    //posicionando o segundo navio de 2 posicoes na horizontal ou vertical

    printf("\n\n\nInsira os navios de dois espacos:\n\n");
    while(verif == false){
        printf("\n\nDeseja inserir o navio na vertical ou na horizontal? ('1' para horizontal e '2' para vertical):");
        scanf("%d",&horizontal_vertical);
        if(horizontal_vertical == 1 || horizontal_vertical == 2){

                //navio de duas posicoes na horizontal

            if(horizontal_vertical == 1){
                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a linha da posicao do navio de 2 posicoes:\n");
                    scanf("%d",&posicao_horizontal);
                    if(posicao_horizontal >= 1 && posicao_horizontal <= 8){
                        a = 0;
                        while(verif == false){
                            printf("\n\nDigite em qual coluna da linha o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 2 proximos espacos serao preenchidos com navio)\n");
                            scanf("%d",&posicao_vertical);
                            if(posicao_vertical >= 1 && posicao_vertical <= 7){
                                for(int i = 0; i< 2; i++){
                                    if(campo1[posicao_horizontal-1][posicao_vertical-1] == 1 || campo1[posicao_horizontal-1][posicao_vertical-1] == 2){
                                        printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                        verif = true;
                                        a = 1;
                                        break;
                                    }
                                    else{
                                        posicao_vertical++;
                                        contnavio3++;
                                    }
                                }
                                    posicao_vertical = posicao_vertical - contnavio3;
                                    if(contnavio3 == 2){
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-1 != 0){
                                                campo1[posicao_horizontal+(i-2)][posicao_vertical-2] = 2;
                                            }
                                        }
                                        for(int i = 0; i<2; i++){
                                            campo1[posicao_horizontal-1][posicao_vertical-1] = 1;
                                            campo1[posicao_horizontal][posicao_vertical-1] = 2;
                                            campo1[posicao_horizontal-2][posicao_vertical-1] = 2;
                                            posicao_vertical++;
                                        }
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-3 != 6){
                                                campo1[posicao_horizontal+(i-2)][posicao_vertical-1] = 2;
                                            }
                                        }
                                        verif = true;
                                        printf("\n\n\n");
                                        for(int i = 0; i<8;i++){
                                            printf("\t");
                                            for(int j = 0; j < 8; j++){
                                                if(campo1[i][j] == 0){
                                                    printf(". ");
                                                }
                                                if(campo1[i][j] == 1){
                                                    printf("W ");
                                                }
                                                if(campo1[i][j] == 2){
                                                    printf("o ");
                                                }
                                            }
                                            printf("\n");
                                        }
                                        printf("\n\n");

                                    }
                                }
                            }
                        }
                        contnavio3 = 0;
                        if(a == 1)
                            verif = false;
                    }
                }


                //navio de duas posicoes na vertical

            else if(horizontal_vertical == 2){
                verif = false;
                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a coluna da posicao do navio de 2 posicoes:\n");
                    scanf("%d",&posicao_vertical);
                    if(posicao_vertical >= 1 && posicao_vertical <= 8){
                        int contnavio3 = 0;
                        a = 0;
                        while(verif == false){
                        printf("\n\nDigite em qual linha da coluna o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 3 proximos espacos serao preenchidos com navio)\n");
                        scanf("%d",&posicao_horizontal);
                        if(posicao_horizontal >= 1 && posicao_horizontal <= 6){
                            for(int i = 0; i< 2; i++){
                                if(campo1[posicao_horizontal-1][posicao_vertical-1] == 1 || campo1[posicao_horizontal-1][posicao_vertical-1] == 2){
                                    printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                    verif = true;
                                    a = 1;
                                    break;
                                    }
                                else{
                                    posicao_vertical++;
                                    contnavio3++;
                                    }
                                }
                                posicao_vertical = posicao_vertical - contnavio3;
                                printf("\n\n%d",contnavio3);
                                if(contnavio3 == 2){
                                    for(int i = 0; i<3; i++){
                                    if(posicao_horizontal-1 != 0){
                                        if(posicao_vertical-1 == 7){
                                            if(i != 2)
                                                campo1[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                        if(posicao_vertical-1 == 0){
                                            if(i != 0)
                                                campo1[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                        else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                            campo1[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                    }
                                }
                            for(int i = 0; i<2; i++){
                                if(posicao_vertical-1 != 7){
                                    campo1[posicao_horizontal+(i-1)][posicao_vertical] = 2;
                                }
                            }
                            for(int i = 0; i<2; i++){
                                campo1[posicao_horizontal-1][posicao_vertical-1] = 1;
                                posicao_horizontal++;
                            }
                            posicao_horizontal = posicao_horizontal -2;
                            for(int i = 0; i<2; i++){
                                if(posicao_vertical-1 != 0){
                                    campo1[posicao_horizontal+(i-1)][posicao_vertical-2] = 2;
                                }
                            }
                            printf("\n\n%d",posicao_horizontal-1);
                            for(int i = 0; i<3; i++){
                                if(posicao_horizontal != 7){
                                    if(posicao_vertical-1 == 7){
                                        if(i != 2)
                                            campo1[posicao_horizontal+1][posicao_vertical+(i-2)] = 2;
                                    }
                                    if(posicao_vertical-1 == 0){
                                        if(i != 0)
                                            campo1[posicao_horizontal+1][posicao_vertical+(i-2)] = 2;
                                    }
                                    else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                        campo1[posicao_horizontal+1][posicao_vertical+(i-2)] = 2;
                                    }
                                }
                            }
                            verif = true;
                            printf("\n\n\n");
                            for(int i = 0; i<8;i++){
                                printf("\t");
                                for(int j = 0; j < 8; j++){
                                    if(campo1[i][j] == 0){
                                        printf(". ");
                                    }
                                    if(campo1[i][j] == 1){
                                        printf("W ");
                                    }
                                    if(campo1[i][j] == 2){
                                        printf("o ");
                                    }
                                }
                                printf("\n");
                            }
                            printf("\n\n");
                                }

                            }

                        }
                    }
                    if(a == 1)
                        verif = false;
                }
            }
        }
    }
    //posicionando o primeiro navio de 1 posicoes na horizontal ou vertical
    verif = false;
    printf("\n\n\nInsira os navios de uma espaco:\n\n");
    while(verif == false){

                //navio de uma posicao na horizontal

                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a linha da posicao do primeiro navio de 1 posicao:\n");
                    scanf("%d",&posicao_horizontal);
                    if(posicao_horizontal >= 1 && posicao_horizontal <= 8){
                        a = 0;
                        while(verif == false){
                            printf("\n\nDigite em qual coluna da linha o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 2 proximos espacos serao preenchidos com navio)\n");
                            scanf("%d",&posicao_vertical);
                            if(posicao_vertical >= 1 && posicao_vertical <= 8){
                                for(int i = 0; i< 1; i++){
                                    if(campo1[posicao_horizontal-1][posicao_vertical-1] == 1 || campo1[posicao_horizontal-1][posicao_vertical-1] == 2){
                                        printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                        verif = true;
                                        a = 1;
                                        break;
                                    }
                                    else{
                                        posicao_vertical++;
                                        contnavio3++;
                                    }
                                }
                                    posicao_vertical = posicao_vertical - contnavio3;
                                    if(contnavio3 == 1){
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-1 != 0){
                                                campo1[posicao_horizontal+(i-2)][posicao_vertical-2] = 2;
                                            }
                                        }
                                        for(int i = 0; i<1; i++){
                                            campo1[posicao_horizontal-1][posicao_vertical-1] = 1;
                                            campo1[posicao_horizontal][posicao_vertical-1] = 2;
                                            campo1[posicao_horizontal-2][posicao_vertical-1] = 2;
                                            posicao_vertical++;
                                        }
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-3 != 6){
                                                campo1[posicao_horizontal+(i-2)][posicao_vertical-1] = 2;
                                            }
                                        }
                                        verif = true;
                                        printf("\n\n\n");
                                        for(int i = 0; i<8;i++){
                                            printf("\t");
                                            for(int j = 0; j < 8; j++){
                                                if(campo1[i][j] == 0){
                                                    printf(". ");
                                                }
                                                if(campo1[i][j] == 1){
                                                    printf("W ");
                                                }
                                                if(campo1[i][j] == 2){
                                                    printf("o ");
                                                }
                                            }
                                            printf("\n");
                                        }
                                        printf("\n\n");

                                    }
                                }
                            }
                        }
                        contnavio3 = 0;
                        if(a == 1)
                            verif = false;
                    }
                    verif = false;
                    while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a linha da posicao do primeiro navio de 1 posicao:\n");
                    scanf("%d",&posicao_horizontal);
                    if(posicao_horizontal >= 1 && posicao_horizontal <= 8){
                        a = 0;
                        while(verif == false){
                            printf("\n\nDigite em qual coluna da linha o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 2 proximos espacos serao preenchidos com navio)\n");
                            scanf("%d",&posicao_vertical);
                            if(posicao_vertical >= 1 && posicao_vertical <= 8){
                                for(int i = 0; i< 1; i++){
                                    if(campo1[posicao_horizontal-1][posicao_vertical-1] == 1 || campo1[posicao_horizontal-1][posicao_vertical-1] == 2){
                                        printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                        verif = true;
                                        a = 1;
                                        break;
                                    }
                                    else{
                                        posicao_vertical++;
                                        contnavio3++;
                                    }
                                }
                                    posicao_vertical = posicao_vertical - contnavio3;
                                    if(contnavio3 == 1){
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-1 != 0){
                                                campo1[posicao_horizontal+(i-2)][posicao_vertical-2] = 2;
                                            }
                                        }
                                        for(int i = 0; i<1; i++){
                                            campo1[posicao_horizontal-1][posicao_vertical-1] = 1;
                                            campo1[posicao_horizontal][posicao_vertical-1] = 2;
                                            campo1[posicao_horizontal-2][posicao_vertical-1] = 2;
                                            posicao_vertical++;
                                        }
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-3 != 6){
                                                campo1[posicao_horizontal+(i-2)][posicao_vertical-1] = 2;
                                            }
                                        }
                                        verif = true;
                                        printf("\n\n\n");
                                        for(int i = 0; i<8;i++){
                                            printf("\t");
                                            for(int j = 0; j < 8; j++){
                                                if(campo1[i][j] == 0){
                                                    printf(". ");
                                                }
                                                if(campo1[i][j] == 1){
                                                    printf("W ");
                                                }
                                                if(campo1[i][j] == 2){
                                                    printf("o ");
                                                }
                                            }
                                            printf("\n");
                                        }
                                        printf("\n\n");

                        }
                    }
                }
            }
            contnavio3 = 0;
            if(a == 1)
                verif = false;
        }
    }
   system("cls");
   system("color a");
   printf("Legenda:\n\n. - Espaco vazio que pode ser preenchido\nW - Navio\no - Espaco vazio que nao pode ser preenchido");
   //int campo2[8][8] = {0};

   for(int i = 0; i<8;i++){
        for(int j = 0; j < 8; j++){
            campo2[i][j] = 0;
        }
   }
    //Player 2
    // Posicionando os navios de 4 posicoes na horizontal ou vertical


    printf("Posicione os navios no campo do player 2:");
    //Mostrando matriz do campo
    printf("\n\n\n");
    for(int i = 0; i<8;i++){
        printf("\t");
        for(int j = 0; j < 8; j++){
            if(campo2[i][j] == 0){
                printf(". ");
            }
            if(campo2[i][j] == 1){
                printf("W ");
            }
            if(campo2[i][j] == 2){
                printf("o ");
            }
        }
        printf("\n");
    }
    printf("\n\n");

    //Player 2
    // Posicionando os navios de 4 posicoes na horizontal ou vertical

    printf("Insira os navios de quatro espacos:\n\n");
    printf("\n\nDeseja inserir o navio na vertical ou na horizontal? ('1' para horizontal e '2' para vertical):");
    verif = false;
    while(verif == false){
        scanf("%d",&horizontal_vertical);
        if(horizontal_vertical == 1 || horizontal_vertical == 2){

                //navio de quatro posicoes na horizontal

            if(horizontal_vertical == 1){
                printf("\n\nDigite um numero de 1 a 8 para escolher a linha da posicao do navio de 4 posicoes:\n");
                while(verif == false){
                    scanf("%d",&posicao_horizontal);
                    if(posicao_horizontal >= 1 && posicao_horizontal <= 8){
                        verif = true;
                    }
                }
                verif = false;
                printf("\n\nDigite em qual coluna da linha o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 3 proximos espacos serao preenchidos com navio)\n");
                while(verif == false){
                    scanf("%d",&posicao_vertical);
                    if(posicao_vertical >= 1 && posicao_vertical <= 5){
                       for(int i = 0; i<3; i++){
                            if(posicao_vertical-1 != 0){
                                campo2[posicao_horizontal+(i-2)][posicao_vertical-2] = 2;
                            }
                        }
                        for(int i = 0; i<4; i++){
                            campo2[posicao_horizontal-1][posicao_vertical-1] = 1;
                            campo2[posicao_horizontal][posicao_vertical-1] = 2;
                            campo2[posicao_horizontal-2][posicao_vertical-1] = 2;
                            posicao_vertical++;
                        }
                        for(int i = 0; i<3; i++){
                            if(posicao_vertical-4 != 5){
                                campo2[posicao_horizontal+(i-2)][posicao_vertical-1] = 2;
                            }
                        }
                       verif = true;
                       printf("\n\n\n");
                        for(int i = 0; i<8;i++){
                            printf("\t");
                            for(int j = 0; j < 8; j++){
                                if(campo2[i][j] == 0){
                                    printf(". ");
                                }
                                if(campo2[i][j] == 1){
                                    printf("W ");
                                }
                                if(campo2[i][j] == 2){
                                    printf("o ");
                                }
                            }
                            printf("\n");
                        }
                        printf("\n\n");
                    }
                }

            }

                //navio de quatro posicoes na vertical

            else if(horizontal_vertical == 2){
                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a coluna da posicao do navio de 4 posicoes:\n");
                    scanf("%d",&posicao_vertical);
                    if(posicao_vertical >= 1 && posicao_vertical <= 8){
                        verif = true;
                    }
                }
                verif = false;
                while(verif == false){
                    printf("\n\nDigite em qual linha da coluna o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 3 proximos espacos serao preenchidos com navio)\n");
                    scanf("%d",&posicao_horizontal);
                    if(posicao_horizontal >= 1 && posicao_horizontal <= 5){
                       for(int i = 0; i<3; i++){
                            if(posicao_horizontal-1 != 0){
                                if(posicao_vertical-1 == 7){
                                    if(i != 2)
                                        campo2[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                }
                                if(posicao_vertical-1 == 0){
                                    if(i != 0)
                                       campo2[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                }
                                else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                    campo2[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                }
                            }
                        }
                        for(int i = 0; i<4; i++){
                            if(posicao_vertical-1 != 7){
                                campo2[posicao_horizontal+(i-1)][posicao_vertical] = 2;
                            }
                        }
                        for(int i = 0; i<4; i++){
                            campo2[posicao_horizontal-1][posicao_vertical-1] = 1;
                            posicao_horizontal++;
                        }
                        posicao_horizontal = posicao_horizontal -4;
                        for(int i = 0; i<4; i++){
                            if(posicao_vertical-1 != 0){
                                campo2[posicao_horizontal+(i-1)][posicao_vertical-2] = 2;
                            }
                        }
                        for(int i = 0; i<3; i++){
                            if(posicao_horizontal != 4){
                                if(posicao_vertical-1 == 7){
                                    if(i != 2)
                                        campo2[posicao_horizontal+3][posicao_vertical+(i-2)] = 2;
                                }
                                if(posicao_vertical-1 == 0){
                                    if(i != 0)
                                        campo2[posicao_horizontal+3][posicao_vertical+(i-2)] = 2;
                                }
                                else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                    campo2[posicao_horizontal+3][posicao_vertical+(i-2)] = 2;
                                }
                            }
                        }
                       verif = true;
                       printf("\n\n\n");
                        for(int i = 0; i<8;i++){
                            printf("\t");
                            for(int j = 0; j < 8; j++){
                                if(campo2[i][j] == 0){
                                    printf(". ");
                                }
                                if(campo2[i][j] == 1){
                                    printf("W ");
                                }
                                if(campo2[i][j] == 2){
                                    printf("o ");
                                }
                            }
                            printf("\n");
                        }
                        printf("\n\n");
                    }
                }
            }
        }
    }
    verif = false;

    //posicionando o navio de 3 posicoes na horizontal ou vertical

    printf("\n\n\nInsira os navios de tres espacos:\n\n");
    while(verif == false){
        printf("\n\nDeseja inserir o navio na vertical ou na horizontal? ('1' para horizontal e '2' para vertical):");
        scanf("%d",&horizontal_vertical);
        if(horizontal_vertical == 1 || horizontal_vertical == 2){

                //navio de tres posicoes na horizontal

            if(horizontal_vertical == 1){
                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a linha da posicao do navio de 3 posicoes:\n");
                    scanf("%d",&posicao_horizontal);
                    if(posicao_horizontal >= 1 && posicao_horizontal <= 8){
                        a = 0;
                        while(verif == false){
                            printf("\n\nDigite em qual coluna da linha o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 2 proximos espacos serao preenchidos com navio)\n");
                            scanf("%d",&posicao_vertical);
                            if(posicao_vertical >= 1 && posicao_vertical <= 6){
                                for(int i = 0; i< 3; i++){
                                    if(campo2[posicao_horizontal-1][posicao_vertical-1] == 1 || campo2[posicao_horizontal-1][posicao_vertical-1] == 2){
                                        printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                        verif = true;
                                        a = 1;
                                        break;
                                    }
                                    else{
                                        posicao_vertical++;
                                        contnavio3++;
                                    }
                                }
                                    posicao_vertical = posicao_vertical - contnavio3;
                                    if(contnavio3 == 3){
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-1 != 0){
                                                campo2[posicao_horizontal+(i-2)][posicao_vertical-2] = 2;
                                            }
                                        }
                                        for(int i = 0; i<3; i++){
                                            campo2[posicao_horizontal-1][posicao_vertical-1] = 1;
                                            campo2[posicao_horizontal][posicao_vertical-1] = 2;
                                            campo2[posicao_horizontal-2][posicao_vertical-1] = 2;
                                            posicao_vertical++;
                                        }
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-3 != 6){
                                                campo2[posicao_horizontal+(i-2)][posicao_vertical-1] = 2;
                                            }
                                        }
                                        verif = true;
                                        printf("\n\n\n");
                                        for(int i = 0; i<8;i++){
                                            printf("\t");
                                            for(int j = 0; j < 8; j++){
                                                if(campo2[i][j] == 0){
                                                    printf(". ");
                                                }
                                                if(campo2[i][j] == 1){
                                                    printf("W ");
                                                }
                                                if(campo2[i][j] == 2){
                                                    printf("o ");
                                                }
                                            }
                                            printf("\n");
                                        }
                                        printf("\n\n");

                                    }
                                }
                            }
                        }
                        contnavio3 = 0;
                        if(a == 1)
                            verif = false;
                    }
                }





                //navio de tres posicoes na vertical

            else if(horizontal_vertical == 2){
                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a coluna da posicao do navio de 3 posicoes:\n");
                    scanf("%d",&posicao_vertical);
                    if(posicao_vertical >= 1 && posicao_vertical <= 8){
                        int contnavio3 = 0;
                        a = 0;
                        while(verif == false){
                        printf("\n\nDigite em qual linha da coluna o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 3 proximos espacos serao preenchidos com navio)\n");
                        scanf("%d",&posicao_horizontal);
                        if(posicao_horizontal >= 1 && posicao_horizontal <= 6){
                            for(int i = 0; i< 3; i++){
                                if(campo2[posicao_horizontal-1][posicao_vertical-1] == 1 || campo2[posicao_horizontal-1][posicao_vertical-1] == 2){
                                    printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                    verif = true;
                                    a = 1;
                                    break;
                                    }
                                else{
                                    posicao_vertical++;
                                    contnavio3++;
                                    }
                                }
                                posicao_vertical = posicao_vertical - contnavio3;
                                if(contnavio3 == 3){
                                    for(int i = 0; i<3; i++){
                                    if(posicao_horizontal-1 != 0){
                                        if(posicao_vertical-1 == 7){
                                            if(i != 2)
                                                campo2[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                        if(posicao_vertical-1 == 0){
                                            if(i != 0)
                                                campo2[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                        else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                            campo2[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                    }
                                }
                            for(int i = 0; i<3; i++){
                                if(posicao_vertical-1 != 7){
                                    campo2[posicao_horizontal+(i-1)][posicao_vertical] = 2;
                                }
                            }
                            for(int i = 0; i<3; i++){
                                campo2[posicao_horizontal-1][posicao_vertical-1] = 1;
                                posicao_horizontal++;
                            }
                            posicao_horizontal = posicao_horizontal -3;
                            for(int i = 0; i<3; i++){
                                if(posicao_vertical-1 != 0){
                                    campo2[posicao_horizontal+(i-1)][posicao_vertical-2] = 2;
                                }
                            }
                            printf("\n\n%d",posicao_horizontal-1);
                            for(int i = 0; i<3; i++){
                                if(posicao_horizontal != 6){
                                    if(posicao_vertical-1 == 7){
                                        if(i != 2)
                                            campo2[posicao_horizontal+2][posicao_vertical+(i-2)] = 2;
                                    }
                                    if(posicao_vertical-1 == 0){
                                        if(i != 0)
                                            campo2[posicao_horizontal+2][posicao_vertical+(i-2)] = 2;
                                    }
                                    else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                        campo2[posicao_horizontal+2][posicao_vertical+(i-2)] = 2;
                                    }
                                }
                            }

                            verif = true;
                            printf("\n\n\n");
                            for(int i = 0; i<8;i++){
                                printf("\t");
                                for(int j = 0; j < 8; j++){
                                    if(campo2[i][j] == 0){
                                        printf(". ");
                                    }
                                    if(campo2[i][j] == 1){
                                        printf("W ");
                                    }
                                    if(campo2[i][j] == 2){
                                        printf("o ");
                                    }
                                }
                                printf("\n");
                            }
                            printf("\n\n");
                                }

                            }

                        }
                    }
                    if(a == 1)
                        verif = false;
                }
            }
        }
    }
    verif = false;

    //posicionando o primeiro navio de 2 posicoes na horizontal ou vertical

    printf("\n\n\nInsira os navios de dois espacos:\n\n");
    while(verif == false){
        printf("\n\nDeseja inserir o navio na vertical ou na horizontal? ('1' para horizontal e '2' para vertical):");
        scanf("%d",&horizontal_vertical);
        if(horizontal_vertical == 1 || horizontal_vertical == 2){

                //navio de duas posicoes na horizontal

            if(horizontal_vertical == 1){
                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a linha da posicao do navio de 2 posicoes:\n");
                    scanf("%d",&posicao_horizontal);
                    if(posicao_horizontal >= 1 && posicao_horizontal <= 8){
                        a = 0;
                        while(verif == false){
                            printf("\n\nDigite em qual coluna da linha o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 2 proximos espacos serao preenchidos com navio)\n");
                            scanf("%d",&posicao_vertical);
                            if(posicao_vertical >= 1 && posicao_vertical <= 7){
                                for(int i = 0; i< 2; i++){
                                    if(campo2[posicao_horizontal-1][posicao_vertical-1] == 1 || campo2[posicao_horizontal-1][posicao_vertical-1] == 2){
                                        printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                        verif = true;
                                        a = 1;
                                        break;
                                    }
                                    else{
                                        posicao_vertical++;
                                        contnavio3++;
                                    }
                                }
                                    posicao_vertical = posicao_vertical - contnavio3;
                                    if(contnavio3 == 2){
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-1 != 0){
                                                campo2[posicao_horizontal+(i-2)][posicao_vertical-2] = 2;
                                            }
                                        }
                                        for(int i = 0; i<2; i++){
                                            campo2[posicao_horizontal-1][posicao_vertical-1] = 1;
                                            campo2[posicao_horizontal][posicao_vertical-1] = 2;
                                            campo2[posicao_horizontal-2][posicao_vertical-1] = 2;
                                            posicao_vertical++;
                                        }
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-3 != 6){
                                                campo2[posicao_horizontal+(i-2)][posicao_vertical-1] = 2;
                                            }
                                        }
                                        verif = true;
                                        printf("\n\n\n");
                                        for(int i = 0; i<8;i++){
                                            printf("\t");
                                            for(int j = 0; j < 8; j++){
                                                if(campo2[i][j] == 0){
                                                    printf(". ");
                                                }
                                                if(campo2[i][j] == 1){
                                                    printf("W ");
                                                }
                                                if(campo2[i][j] == 2){
                                                    printf("o ");
                                                }
                                            }
                                            printf("\n");
                                        }
                                        printf("\n\n");

                                    }
                                }
                            }
                        }
                        contnavio3 = 0;
                        if(a == 1)
                            verif = false;
                    }
                }


                //navio de duas posicoes na vertical

            else if(horizontal_vertical == 2){
                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a coluna da posicao do navio de 2 posicoes:\n");
                    scanf("%d",&posicao_vertical);
                    if(posicao_vertical >= 1 && posicao_vertical <= 8){
                        int contnavio3 = 0;
                        a = 0;
                        while(verif == false){
                        printf("\n\nDigite em qual linha da coluna o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 3 proximos espacos serao preenchidos com navio)\n");
                        scanf("%d",&posicao_horizontal);
                        if(posicao_horizontal >= 1 && posicao_horizontal <= 6){
                            for(int i = 0; i< 2; i++){
                                if(campo2[posicao_horizontal-1][posicao_vertical-1] == 1 || campo2[posicao_horizontal-1][posicao_vertical-1] == 2){
                                    printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                    verif = true;
                                    a = 1;
                                    break;
                                    }
                                else{
                                    posicao_vertical++;
                                    contnavio3++;
                                    }
                                }
                                posicao_vertical = posicao_vertical - contnavio3;
                                printf("\n\n%d",contnavio3);
                                if(contnavio3 == 2){
                                    for(int i = 0; i<3; i++){
                                    if(posicao_horizontal-1 != 0){
                                        if(posicao_vertical-1 == 7){
                                            if(i != 2)
                                                campo2[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                        if(posicao_vertical-1 == 0){
                                            if(i != 0)
                                                campo2[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                        else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                            campo2[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                    }
                                }
                            for(int i = 0; i<2; i++){
                                if(posicao_vertical-1 != 7){
                                    campo2[posicao_horizontal+(i-1)][posicao_vertical] = 2;
                                }
                            }
                            for(int i = 0; i<2; i++){
                                campo2[posicao_horizontal-1][posicao_vertical-1] = 1;
                                posicao_horizontal++;
                            }
                            posicao_horizontal = posicao_horizontal -2;
                            for(int i = 0; i<2; i++){
                                if(posicao_vertical-1 != 0){
                                    campo2[posicao_horizontal+(i-1)][posicao_vertical-2] = 2;
                                }
                            }
                            printf("\n\n%d",posicao_horizontal-1);
                            for(int i = 0; i<3; i++){
                                if(posicao_horizontal != 7){
                                    if(posicao_vertical-1 == 7){
                                        if(i != 2)
                                            campo2[posicao_horizontal+1][posicao_vertical+(i-2)] = 2;
                                    }
                                    if(posicao_vertical-1 == 0){
                                        if(i != 0)
                                            campo2[posicao_horizontal+1][posicao_vertical+(i-2)] = 2;
                                    }
                                    else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                        campo2[posicao_horizontal+1][posicao_vertical+(i-2)] = 2;
                                    }
                                }
                            }
                            verif = true;
                            printf("\n\n\n");
                            for(int i = 0; i<8;i++){
                                printf("\t");
                                for(int j = 0; j < 8; j++){
                                    if(campo2[i][j] == 0){
                                        printf(". ");
                                    }
                                    if(campo2[i][j] == 1){
                                        printf("W ");
                                    }
                                    if(campo2[i][j] == 2){
                                        printf("o ");
                                    }
                                }
                                printf("\n");
                            }
                            printf("\n\n");
                                }

                            }

                        }
                    }
                    if(a == 1)
                        verif = false;
                }
            }
        }
    }
    verif = false;
    //posicionando o segundo navio de 2 posicoes na horizontal ou vertical

    printf("\n\n\nInsira os navios de dois espacos:\n\n");
    while(verif == false){
        printf("\n\nDeseja inserir o navio na vertical ou na horizontal? ('1' para horizontal e '2' para vertical):");
        scanf("%d",&horizontal_vertical);
        if(horizontal_vertical == 1 || horizontal_vertical == 2){

                //navio de duas posicoes na horizontal

            if(horizontal_vertical == 1){
                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a linha da posicao do navio de 2 posicoes:\n");
                    scanf("%d",&posicao_horizontal);
                    if(posicao_horizontal >= 1 && posicao_horizontal <= 8){
                        a = 0;
                        while(verif == false){
                            printf("\n\nDigite em qual coluna da linha o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 2 proximos espacos serao preenchidos com navio)\n");
                            scanf("%d",&posicao_vertical);
                            if(posicao_vertical >= 1 && posicao_vertical <= 7){
                                for(int i = 0; i< 2; i++){
                                    if(campo2[posicao_horizontal-1][posicao_vertical-1] == 1 || campo2[posicao_horizontal-1][posicao_vertical-1] == 2){
                                        printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                        verif = true;
                                        a = 1;
                                        break;
                                    }
                                    else{
                                        posicao_vertical++;
                                        contnavio3++;
                                    }
                                }
                                    posicao_vertical = posicao_vertical - contnavio3;
                                    if(contnavio3 == 2){
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-1 != 0){
                                                campo2[posicao_horizontal+(i-2)][posicao_vertical-2] = 2;
                                            }
                                        }
                                        for(int i = 0; i<2; i++){
                                            campo2[posicao_horizontal-1][posicao_vertical-1] = 1;
                                            campo2[posicao_horizontal][posicao_vertical-1] = 2;
                                            campo2[posicao_horizontal-2][posicao_vertical-1] = 2;
                                            posicao_vertical++;
                                        }
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-3 != 6){
                                                campo2[posicao_horizontal+(i-2)][posicao_vertical-1] = 2;
                                            }
                                        }
                                        verif = true;
                                        printf("\n\n\n");
                                        for(int i = 0; i<8;i++){
                                            printf("\t");
                                            for(int j = 0; j < 8; j++){
                                                if(campo2[i][j] == 0){
                                                    printf(". ");
                                                }
                                                if(campo2[i][j] == 1){
                                                    printf("W ");
                                                }
                                                if(campo2[i][j] == 2){
                                                    printf("o ");
                                                }
                                            }
                                            printf("\n");
                                        }
                                        printf("\n\n");

                                    }
                                }
                            }
                        }
                        contnavio3 = 0;
                        if(a == 1)
                            verif = false;
                    }
                }


                //navio de duas posicoes na vertical

            else if(horizontal_vertical == 2){
                verif = false;
                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a coluna da posicao do navio de 2 posicoes:\n");
                    scanf("%d",&posicao_vertical);
                    if(posicao_vertical >= 1 && posicao_vertical <= 8){
                        int contnavio3 = 0;
                        a = 0;
                        while(verif == false){
                        printf("\n\nDigite em qual linha da coluna o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 3 proximos espacos serao preenchidos com navio)\n");
                        scanf("%d",&posicao_horizontal);
                        if(posicao_horizontal >= 1 && posicao_horizontal <= 6){
                            for(int i = 0; i< 2; i++){
                                if(campo2[posicao_horizontal-1][posicao_vertical-1] == 1 || campo2[posicao_horizontal-1][posicao_vertical-1] == 2){
                                    printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                    verif = true;
                                    a = 1;
                                    break;
                                    }
                                else{
                                    posicao_vertical++;
                                    contnavio3++;
                                    }
                                }
                                posicao_vertical = posicao_vertical - contnavio3;
                                printf("\n\n%d",contnavio3);
                                if(contnavio3 == 2){
                                    for(int i = 0; i<3; i++){
                                    if(posicao_horizontal-1 != 0){
                                        if(posicao_vertical-1 == 7){
                                            if(i != 2)
                                                campo2[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                        if(posicao_vertical-1 == 0){
                                            if(i != 0)
                                                campo2[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                        else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                            campo2[posicao_horizontal-2][posicao_vertical+(i-2)] = 2;
                                        }
                                    }
                                }
                            for(int i = 0; i<2; i++){
                                if(posicao_vertical-1 != 7){
                                    campo2[posicao_horizontal+(i-1)][posicao_vertical] = 2;
                                }
                            }
                            for(int i = 0; i<2; i++){
                                campo2[posicao_horizontal-1][posicao_vertical-1] = 1;
                                posicao_horizontal++;
                            }
                            posicao_horizontal = posicao_horizontal -2;
                            for(int i = 0; i<2; i++){
                                if(posicao_vertical-1 != 0){
                                    campo2[posicao_horizontal+(i-1)][posicao_vertical-2] = 2;
                                }
                            }
                            printf("\n\n%d",posicao_horizontal-1);
                            for(int i = 0; i<3; i++){
                                if(posicao_horizontal != 7){
                                    if(posicao_vertical-1 == 7){
                                        if(i != 2)
                                            campo2[posicao_horizontal+1][posicao_vertical+(i-2)] = 2;
                                    }
                                    if(posicao_vertical-1 == 0){
                                        if(i != 0)
                                            campo2[posicao_horizontal+1][posicao_vertical+(i-2)] = 2;
                                    }
                                    else if(posicao_vertical-1 != 7 && posicao_vertical-1 != 0){
                                        campo2[posicao_horizontal+1][posicao_vertical+(i-2)] = 2;
                                    }
                                }
                            }
                            verif = true;
                            printf("\n\n\n");
                            for(int i = 0; i<8;i++){
                                printf("\t");
                                for(int j = 0; j < 8; j++){
                                    if(campo2[i][j] == 0){
                                        printf(". ");
                                    }
                                    if(campo2[i][j] == 1){
                                        printf("W ");
                                    }
                                    if(campo2[i][j] == 2){
                                        printf("o ");
                                    }
                                }
                                printf("\n");
                            }
                            printf("\n\n");
                                }

                            }

                        }
                    }
                    if(a == 1)
                        verif = false;
                }
            }
        }
    }
    //posicionando o primeiro navio de 1 posicoes na horizontal ou vertical
    verif = false;
    printf("\n\n\nInsira os navios de uma espaco:\n\n");
    while(verif == false){

                //primeiro navio de uma posicao

                while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a linha da posicao do primeiro navio de 1 posicao:\n");
                    scanf("%d",&posicao_horizontal);
                    if(posicao_horizontal >= 1 && posicao_horizontal <= 8){
                        a = 0;
                        while(verif == false){
                            printf("\n\nDigite em qual coluna da linha o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 2 proximos espacos serao preenchidos com navio)\n");
                            scanf("%d",&posicao_vertical);
                            if(posicao_vertical >= 1 && posicao_vertical <= 8){
                                for(int i = 0; i< 1; i++){
                                    if(campo2[posicao_horizontal-1][posicao_vertical-1] == 1 || campo2[posicao_horizontal-1][posicao_vertical-1] == 2){
                                        printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                        verif = true;
                                        a = 1;
                                        break;
                                    }
                                    else{
                                        posicao_vertical++;
                                        contnavio3++;
                                    }
                                }
                                    posicao_vertical = posicao_vertical - contnavio3;
                                    if(contnavio3 == 1){
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-1 != 0){
                                                campo2[posicao_horizontal+(i-2)][posicao_vertical-2] = 2;
                                            }
                                        }
                                        for(int i = 0; i<1; i++){
                                            campo2[posicao_horizontal-1][posicao_vertical-1] = 1;
                                            campo2[posicao_horizontal][posicao_vertical-1] = 2;
                                            campo2[posicao_horizontal-2][posicao_vertical-1] = 2;
                                            posicao_vertical++;
                                        }
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-3 != 6){
                                                campo2[posicao_horizontal+(i-2)][posicao_vertical-1] = 2;
                                            }
                                        }
                                        verif = true;
                                        printf("\n\n\n");
                                        for(int i = 0; i<8;i++){
                                            printf("\t");
                                            for(int j = 0; j < 8; j++){
                                                if(campo2[i][j] == 0){
                                                    printf(". ");
                                                }
                                                if(campo2[i][j] == 1){
                                                    printf("W ");
                                                }
                                                if(campo2[i][j] == 2){
                                                    printf("o ");
                                                }
                                            }
                                            printf("\n");
                                        }
                                        printf("\n\n");

                                    }
                                }
                            }
                        }
                        contnavio3 = 0;
                        if(a == 1)
                            verif = false;
                    }
                    verif = false;

                    //segundo navio de uma posicao

                    while(verif == false){
                    printf("\n\nDigite um numero de 1 a 8 para escolher a linha da posicao do primeiro navio de 1 posicao:\n");
                    scanf("%d",&posicao_horizontal);
                    if(posicao_horizontal >= 1 && posicao_horizontal <= 8){
                        a = 0;
                        while(verif == false){
                            printf("\n\nDigite em qual coluna da linha o navio ira ficar:\n(Sabendo que a partir da posicao escolhida, os 2 proximos espacos serao preenchidos com navio)\n");
                            scanf("%d",&posicao_vertical);
                            if(posicao_vertical >= 1 && posicao_vertical <= 8){
                                for(int i = 0; i< 1; i++){
                                    if(campo2[posicao_horizontal-1][posicao_vertical-1] == 1 || campo2[posicao_horizontal-1][posicao_vertical-1] == 2){
                                        printf("\n\nNao foi possivel por o navio aqui!\n\n");
                                        verif = true;
                                        a = 1;
                                        break;
                                    }
                                    else{
                                        posicao_vertical++;
                                        contnavio3++;
                                    }
                                }
                                    posicao_vertical = posicao_vertical - contnavio3;
                                    if(contnavio3 == 1){
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-1 != 0){
                                                campo2[posicao_horizontal+(i-2)][posicao_vertical-2] = 2;
                                            }
                                        }
                                        for(int i = 0; i<1; i++){
                                            campo2[posicao_horizontal-1][posicao_vertical-1] = 1;
                                            campo2[posicao_horizontal][posicao_vertical-1] = 2;
                                            campo2[posicao_horizontal-2][posicao_vertical-1] = 2;
                                            posicao_vertical++;
                                        }
                                        for(int i = 0; i<3; i++){
                                            if(posicao_vertical-3 != 6){
                                                campo2[posicao_horizontal+(i-2)][posicao_vertical-1] = 2;
                                            }
                                        }
                                        verif = true;
                                        printf("\n\n\n");
                                        for(int i = 0; i<8;i++){
                                            printf("\t");
                                            for(int j = 0; j < 8; j++){
                                                if(campo2[i][j] == 0){
                                                    printf(". ");
                                                }
                                                if(campo2[i][j] == 1){
                                                    printf("W ");
                                                }
                                                if(campo2[i][j] == 2){
                                                    printf("o ");
                                                }
                                            }
                                            printf("\n");
                                        }
                                        printf("\n\n");

                        }
                    }
                }
            }
            contnavio3 = 0;
            if(a == 1)
                verif = false;
        }
    }
    system("cls");

    //Começo do jogo
    printf("Legenda:\n\nO - Alvo errado\nX - Alvo encontrado\n\n\n");

    while(true){
        verif = false;
        while(verif == false){
            system("color b");
            printf("Player 1, digite as posicoes horizontais e verticais respectivamente para acertar o navio inimigo:\n(Sabendo que os valores para vertical e horizontal, vao de 1 a 8)\n");
            printf("\n\nHorizontal: ");
            scanf("%d %d",&jogador_horizontal1,&jogador_vertical1);
            if(campo2[jogador_horizontal1-1][jogador_vertical1-1] == 1){
                campo2[jogador_horizontal1-1][jogador_vertical1-1] = 3;
                printf("\nAcertou!");
                jogo();
                ganhou1++;
            }
            else if(campo1[jogador_horizontal1-1][jogador_vertical1-1] == 3 || campo1[jogador_horizontal1-1][jogador_vertical1-1] == 4){
                printf("Nao foi possivel atacar neste lugar\n");
            }
            else{
                campo2[jogador_horizontal1-1][jogador_vertical1-1] = 4;
                printf("\Errou!");
                jogo();
                verif = true;
            }
            if(ganhou1 == 13){
                printf("\nPlayer 1 ganhou!!");
                exit(0);
            }
        }
        verif = false;
        while(verif == false){
            system("color a");
            printf("Player 2, digite as posicoes horizontais e verticais respectivamente para acertar o navio inimigo:\n(Sabendo que os valores para vertical e horizontal, vao de 1 a 8)\n");
            printf("\n\nHorizontal: ");
            scanf("%d %d",&jogador_horizontal2,&jogador_vertical2);
            if(campo1[jogador_horizontal2-1][jogador_vertical2-1] == 1){
                campo1[jogador_horizontal2-1][jogador_vertical2-1] = 3;
                printf("\nAcertou!");
                jogo();
                ganhou2++;
            }
            else if(campo2[jogador_horizontal2-1][jogador_vertical2-1] == 3 || campo2[jogador_horizontal2-1][jogador_vertical2-1] == 4){
                printf("Nao foi possivel atacar neste lugar");
            }
            else{
                campo1[jogador_horizontal2-1][jogador_vertical2-1] = 4;
                printf("\Errou!");
                jogo();
                verif = true;
            }
            if(ganhou2 == 13){
                printf("\nPlayer 2 ganhou!!");
                exit(0);
            }
        }


    }

}
