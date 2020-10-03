//
// Created by ExMachina on 9/21/2020.
//

#ifndef OTHELLOCLION_UI_H
#define OTHELLOCLION_UI_H
#include <chrono>
#include <conio.h>
#include <bits/stdc++.h>

class ui {
public:
    int choices;
    void show_menu();
    int getChoice();
    void game_over(int black, int white);
    void loading(int time);

private:
    void delay(int n)
    {
        using namespace std::this_thread; // sleep_for, sleep_until
        using namespace std::chrono; // nanoseconds, system_clock, seconds

        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + seconds(n));
    }
};


#endif //OTHELLOCLION_UI_H
