#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int money = 0;


int main()
{

    struct quests {
        vector<string> easy = { "Drop a parcel", "Fly for 3 minutes", "-", "-", "-" };
    }kur;

    int num;
    srand(time(0));
    for (int i = 0; i < 3; i++)
    {
        num = (rand() % 5) + 1;
        if (num >= 0 && num <= 4)
        {
            cout << kur.easy[num] << " ";

            money += 10;//Due to this being an easy task
        }
        else
            num = 0;
    }
    cout << money;
}
