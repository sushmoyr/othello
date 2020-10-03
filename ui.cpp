//
// Created by ExMachina on 9/21/2020.
//

#include "ui.h"
#include <iostream>
using namespace  std;

void ui::show_menu() {
    printf("|----------------------------------|\n");
    printf("|                                  |\n");
    printf("|        Welcome To Othello        |\n");
    printf("|                                  |\n");
    printf("|     >Please choose an option     |\n");
    printf("|                                  |\n");
    printf("|           1.Start Game           |\n");
    printf("|                                  |\n");
    printf("|           2.Exit Game            |\n");
    printf("|                                  |\n");
    printf("|----------------------------------|\n");
}

int ui::getChoice() {
    cin>>this->choices;
    return choices;
}

void ui::game_over(int black, int white) {
    printf("\n");
    printf("  ____  ____ ___  ___   ___   \n");
    printf(" / _  |/ _  |  _ ` _ \\ / _ \\  \n");
    printf("| (_| | (_| | | | | | |  __/  \n");
    printf(" \\__, |\\__,_|_| |_| |_|\\___|  \n");
    printf(" |___/                        \n");
    printf("   ___ __   __ ___   _____    \n");
    printf("  / _ \\\\ \\ / // _ \\ / ___ \\   \n");
    printf(" | (_) |\\ V /|  __/ | | / /   \n");
    printf("  \\___/  \\_/  \\___| |_| \\_\\   \n\n\n");

    if(black>white)
        printf("Black won the game. Total pieces earned %d\n",black);
    else
        printf("White won the game. Total pieces earned %d\n",white);
}

void ui::loading(int n) {

    int sum=0, limit = 50/n;
    printf("|------------------------------------------------|\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                  LOADING GAME                  |\n");
    printf("|                                                |\n");
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<limit; i++)
        {
            printf("|");
        }
        delay(1);
    }
    sum = limit*n;
    if(sum<50)
    {
        while(++sum<=50)
            printf("|");
    }
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|------------------------------------------------|\n\n\n");

}
