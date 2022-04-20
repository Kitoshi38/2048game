#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 

void print_board(int N1, int N2, int mat[][N2]){
    // 縦N1 x 横N2の大きさの行列matの中身を表示する
    for(int j = 0; j < N1; j++){
        for(int i = 0; i < N2; i++){
            printf("\x1b[31m%5d\033[m ", mat[j][i]);
            if(i == N2 - 1){
                printf("\r\n");
            }
        }
    }
}

int number_0(int mat[5][5]){
    int a = 0;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            if(mat[i][j] == 0){
                a += 1;
            }
        }
    }
    return a;
}

int main (int argc, char *argv[]) {
    int mat_2048[5][5] = {
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    };

    printf("Press any key to conitnue\n");
    int c;

    system("/bin/stty raw onlcr");  // enterを押さなくてもキー入力を受け付けるようになる

    while((c = getchar()) != '.') {
        if(c == 'A'){
            for(int i = 0; i < 5; ++i){
                for(int j = 0; j < 5; ++j){
                    if(mat_2048[i][j] >= 2){
                        for(int p = i - 1; p >= 0; --p){
                            if(mat_2048[p][j] != 0 && mat_2048[i][j] != mat_2048[p][j]){
                                break;
                            }
                            else if(mat_2048[i][j] == mat_2048[p][j]){
                                mat_2048[i][j] = 1;
                                mat_2048[p][j] = 2 * mat_2048[p][j];
                                break;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < 5; ++i){
                for(int j = 0; j < 5; ++j){
                    if(mat_2048[i][j] >= 2){
                        for(int k = 0; k < i; ++k){
                            if(mat_2048[k][j] == 0 || mat_2048[k][j] == 1){
                                mat_2048[k][j] = mat_2048[i][j];
                                mat_2048[i][j] = 0;
                                break;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < 5; ++i){
                for(int j = 0; j < 5; ++j){
                    if(mat_2048[i][j] == 1){
                        mat_2048[i][j] = 0;
                    }
                }
            }
        }

        else if(c == 'B'){
            for(int i = 4; i >= 0; --i){
                for(int j = 0; j < 5; ++j){
                    if(mat_2048[i][j] >= 2){
                        for(int p = i + 1; p < 5; ++p){
                            if(mat_2048[p][j] != 0 && mat_2048[i][j] != mat_2048[p][j]){
                                break;
                            }
                            else if(mat_2048[i][j] == mat_2048[p][j]){
                                mat_2048[i][j] = 1;
                                mat_2048[p][j] = 2 * mat_2048[p][j];
                                break;
                            }
                        }
                    }
                }
            }
            for(int i = 4; i >= 0; --i){
                for(int j = 0; j < 5; ++j){
                    if(mat_2048[i][j] >= 2){
                        for(int k = 4; k > i; --k){
                            if(mat_2048[k][j] == 0 || mat_2048[k][j] == 1){
                                mat_2048[k][j] = mat_2048[i][j];
                                mat_2048[i][j] = 0;
                                break;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < 5; ++i){
                for(int j = 0; j < 5; ++j){
                    if(mat_2048[i][j] == 1){
                        mat_2048[i][j] = 0;
                    }
                }
            }
        }
        
        else if(c == 'C'){
            for(int i = 0; i < 5; ++i){
                for(int j = 4; j >= 0; --j){
                    if(mat_2048[i][j] >= 2){
                        for(int p = j + 1; p < 5; ++p){
                            if(mat_2048[i][p] != 0 && mat_2048[i][j] != mat_2048[i][p]){
                                break;
                            }
                            else if(mat_2048[i][j] == mat_2048[i][p]){
                                mat_2048[i][j] = 1;
                                mat_2048[i][p] = 2 * mat_2048[i][p];
                                break;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < 5; ++i){
                for(int j = 4; j >= 0; --j){
                    if(mat_2048[i][j] >= 2){
                        for(int k = 4; k > j; --k){
                            if(mat_2048[i][k] == 0 || mat_2048[i][k] == 1){
                                mat_2048[i][k] = mat_2048[i][j];
                                mat_2048[i][j] = 0;
                                break;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < 5; ++i){
                for(int j = 0; j < 5; ++j){
                    if(mat_2048[i][j] == 1){
                        mat_2048[i][j] = 0;
                    }
                }
            }
        }

        else if(c == 'D'){
            for(int i = 0; i < 5; ++i){
                for(int j = 0; j < 5; ++j){
                    if(mat_2048[i][j] >= 2){
                        for(int p = j - 1; p >= 0; --p){
                            if(mat_2048[i][p] != 0 && mat_2048[i][j] != mat_2048[i][p]){
                                break;
                            }
                            else if(mat_2048[i][j] == mat_2048[i][p]){
                                mat_2048[i][j] = 1;
                                mat_2048[i][p] = 2 * mat_2048[i][p];
                                break;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < 5; ++i){
                for(int j = 0; j < 5; ++j){
                    if(mat_2048[i][j] >= 2){
                        for(int k = 0; k < j; ++k){
                            if(mat_2048[i][k] == 0 || mat_2048[i][k] == 1){
                                mat_2048[i][k] = mat_2048[i][j];
                                mat_2048[i][j] = 0;
                                break;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < 5; ++i){
                for(int j = 0; j < 5; ++j){
                    if(mat_2048[i][j] == 1){
                        mat_2048[i][j] = 0;
                    }
                }
            }
        }
       
        srand((unsigned int)time(NULL));

        int s = number_0(mat_2048);
        int t = rand() % s;
        int r = rand() % 2 + 1;
     
        if(c == 'A' || c == 'B' || c == 'C' || c == 'D'){
            for(int i = 0; i < 5; ++i){
                for(int j = 0; j < 5; ++j){
                    if(t > 0 && mat_2048[i][j] == 0){
                        t -= 1;
                    }
                    else if(t == 0 && mat_2048[i][j] == 0){
                        mat_2048[i][j] = 2 * r;
                        t -= 1;
                    }
                }
            }
        }

    
        system("clear");
        printf("Press '.' to close\r\n");
        printf("You pressed '%c'\r\n", c);
        print_board(5, 5, mat_2048);
    }

    system("/bin/stty cooked");  // 後始末

    return 0;
}
//上下左右動かせない時の挙動おかしい
//GAME OVER変更
//number_0が0の時の場合分け