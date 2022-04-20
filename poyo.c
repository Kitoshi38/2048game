#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    {srand((unsigned int)time(NULL));
    int s = rand() % 2 + 1;
    int t = rand() % s;
    
    printf("%d,%d\n",s,t);
    }
    {
    int t = 16;
    int mat[5][5] =  {
    {0,2,2,2,0},
    {0,0,0,2,2},
    {0,2,0,2,0},
    {0,0,2,0,0},
    {0,2,0,2,0},
    };
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(mat[i][j] == 0){
                t  -= 1;
            }
        }
    }
    printf("%d\n",t);
    }
}
