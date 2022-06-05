#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


bool checkSelectionsAreCollides(int UserNumber, int *UserSelection)
{
    bool ret = false;

    for(int i=0; i<UserNumber; i++)
    {
        for(int k=0; k<UserNumber; k++)
        {
            if((UserSelection[i] == UserSelection[k]) && (i != k))
                return true;
        }
    }

    return ret;
}

bool selectSlot(int UserNumber, int SlotSize, bool PreviusCon)
{
    int *user_selection = new int[UserNumber];

    if(PreviusCon)
    {
        SlotSize = SlotSize * 2;
    }

    for(int k = 0; k<UserNumber; k++)
    {
        user_selection[k] = rand() % SlotSize;
    }

    bool ret = checkSelectionsAreCollides(UserNumber, user_selection);

    delete [] user_selection;

    return ret;
}

int main(int argc, char *argv[])
{

    int user_number;
    int slot_size;
    srand((unsigned)time(0));

    cout << "Enter slot size: " << endl;
    cin >> slot_size;

    cout << "Enter user number: " << endl;
    cin >> user_number;


    int step;
    cout << "Enter Step Number:" << endl;
    cin >> step;

    bool col_en;
    cout << "Enter collision prob change enable:" << endl;
    cin >> col_en;

    int collision_count = 0;
    bool ret = false;

    for(int i=0; i<step; i++)
    {

        if(col_en)
            ret = selectSlot(user_number, slot_size, ret);
        else
            ret = selectSlot(user_number, slot_size, false);

        if(ret)
        {
            collision_count++;
        }

    }

    cout << "step: " << to_string(step) << endl;
    cout << "collision number: " << to_string(collision_count) << endl;
    cout << "collition prob: " << to_string((double) collision_count / step);

}
