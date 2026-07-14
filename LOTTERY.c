#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(NULL));

    int luckynum[5];
    int size = sizeof(luckynum)/sizeof(luckynum[0]);

    for(int i=0;i<size;i++){
        luckynum[i]=rand()%100+1;
    }

    int choice;
    printf("choose your lucky number(1-100):");
    scanf("%d",&choice);

    if(choice<1 || choice>100){
        printf("Please enter number between 1 to 100.\n");
        return 0;
    }

    bool found = false;

    for(int i=0;i<size;i++){
        if(choice == luckynum[i]){
            found = true;
            break;
        }
    }
    if (found) {
        printf("CONGRATULATIONS!You won the prize");
    }else{
        printf("Better luck next time.");
    }

    return 0;
    
}