#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maximum)
{
    srand(std::time(0));
    short randomValue = (rand() % maximum) + 1;
    short userValue;
    bool stayInLoop = true;
    short count = 0;


    while(stayInLoop)
    {
        cout << "Arvaa luku valilta 1-" << maximum << endl;
        cin >> userValue;
        count++;

        if(userValue == randomValue)
        {
            cout << "Arvasit oikein luku = " << userValue << endl;
            stayInLoop = false;
        }
        else if(userValue < randomValue)
        {
            cout << "Lukusi on liian pieni" << endl;
        }
        else
        {
            cout << "Lukusi on liian suuri" << endl;
        }
    }
    return count;
}

int main()
{
    cout << "Lahdetaan pelaamaan...!" << endl;
    short range = 0;
    cout << "Anna maksimiluku" << endl;
    cin >> range;
    cout << "Tulos = " << game(range) << endl;
    return 0;
}
