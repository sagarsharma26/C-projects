#include<stdio.h>
#include<stdbool.h>

int main(){

    int luckynum[]={23,45,76,89,93};
    int size = sizeof(luckynum)/sizeof(luckynum[0]);

    int choice;
    printf("choose your lucky number b/w(1 to 100):");
    scanf("%d",&choice);

    if(choice<1 || choice>100){
        printf("Please enter number between 1 to 100.\n");
    }

    bool found = false;
    int list;

    for(int i=0;i<=size;i++){
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