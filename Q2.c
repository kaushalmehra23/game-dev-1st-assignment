#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include<limits.h>
int Max(int a ,int b){
    return (a>b)? a:b;
}
int Min(int a ,int b){
    return (a<b)? a:b;
}
 int minimax (int depth, int nodeindex, bool player,int evals[]){
    if(depth == 0 || nodeindex <0){
        return evals[nodeindex];
    }
    if (player)
    {
        int min = INT_MIN;
        for (int i = 1; i <= 2; i++)
        {
            int child = minimax(depth-1,nodeindex*2+i,!player,evals);
            min = Max(min,child);
        }
        return min;
    }
    else{
        int max = INT_MAX;
        for (int i = 1; i <= 2; i++)
        {
            int child = minimax(depth-1,nodeindex*2+i,!player,evals);
            max = Min(max,child);
        }
        return max;
    }
 }
int main(){
    int evals[] = {3, 5, 2, 9, 12, 5, 23, 23};
	int res = minimax(4, 0, true, evals);
	printf("The optimal value is :%d\n",res);
    return 0;
}