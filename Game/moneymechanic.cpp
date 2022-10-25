/*This is the very basic way I think I want to make the quest/money/point system. Needs improvement.*/

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
//global variables are such due to them being stored in other files(header, main.cpp and such)
int money = 0;


int main()
{
    struct quests {
        vector<string> easy = { "Drop a parcel", "Fly for 3 minutes", "-", "-", "-" }; //vector of quests
    }kur;

    int num;
    srand(time(0));
    for (int i = 0; i < 3; i++) //main loop for random number picking and quest choice by same rand num
    {
        num = (rand()%5) + 1;
        if (num >=0 && num <= 4)
        {
            cout << kur.easy[num] << " ";

            money += 10;//Due to this being an easy task
        }
        num = 0;
    }
    cout << money;
}
