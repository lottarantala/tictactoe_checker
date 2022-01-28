#include <stdio.h>
#include <inttypes.h>

int8_t tictactoe_check(int8_t * gameboard, int win_len);

int8_t tictactoe_check(int8_t * gameboard, int win_len){
    int samat = 0, voittaja = 0;
    int voittajat_lkm[2] = {0, 0};

    //kaydaan lapi jokainen listan alkio
    for(int i = 0; i < 100; i++){
        samat = 0;
        //jos alkio ei nolla
        if(gameboard[i] != 0){
            //tarkistetaan vaakarivi
            for(int j = i; j < i + win_len; j++){
                //jos menee yli rivin
                if(j > 9 + ((i / 10) * 10))
                    break;
                else{
                    if(gameboard[j] == gameboard[i])
                        samat++;
                }
            }
            if(samat == win_len){
                voittaja = gameboard[i];
                voittajat_lkm[voittaja-1] = 1;
            }
            samat = 0;
            //tarkistetaan pystyrivi
            for(int k = i; k <= i+((win_len-1)*10); k += 10){
                if(k >= 100)
                    break;
                else{
                    if(gameboard[k] == gameboard[i])
                        samat++;
                }
            }
            if(samat == win_len){
                voittaja = gameboard[i];
                voittajat_lkm[voittaja-1] = 1;
            }
            samat = 0;
            //tarkistetaan vino rivi oikealle
            for(int l = i; l <= i+((win_len-1)*11); l += 11){
                if(l >= 100 || (l%10==0 && l != i))
                    break;
                else{
                    if(gameboard[l] == gameboard[i])
                        samat++;
                }
            }
            if(samat == win_len){
                voittaja = gameboard[i];
                voittajat_lkm[voittaja-1] = 1;
            }
            samat = 0;
            //vino rivi vasemmalle
            for(int m = i; m <= i+((win_len-1)*9); m += 9){
                if(m >= 100 || ((m-9)%10==0 && m != i))
                    break;
                else{
                    if(gameboard[m] == gameboard[i])
                        samat++;
                }
            }
            if(samat == win_len){
                voittaja = gameboard[i];
                voittajat_lkm[voittaja-1] = 1;
            }
            samat = 0;
        }
    }
    if(voittajat_lkm[0] == voittajat_lkm[1])
        voittaja = 0;
    return voittaja;
}
