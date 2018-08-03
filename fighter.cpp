#include <iostream>

#include <random>

using namespace std;

int PHP,PMHP,PEXP,PL,PEXPL,MHP,MMHP,ML;

int PATK,PDEF,MATK,MDEF,PXP;

char CHOICE;

int Display ()
{
    cout << "Player Level: " << PL << endl;
    cout << '[';
    int i;
    for (i=0;i<20;i++)
    {
        if (PHP > (PMHP * i) / 20)
        {
            cout << '|';
        } else
        {
            cout << ' ';
        }
    }
    cout << ']' << PHP << '/' << PMHP << endl;
    cout << '[';
    for (i = 0; i < 10; i++)
    {
        if (PEXP > (PEXPL * i) / 10)
        {
            cout << '|';
        } else
        {
            cout << ' ';
        }
    }
    cout << ']' << PEXP << '/' << PEXPL << endl;
    cout << endl;
    cout << "Monster Level: " << ML << endl;
    cout << '[';
    for (i = 0; i < 20; i++)
    {
        if (MHP > (MMHP * i) / 20)
        {
            cout << '|';
        } else
        {
            cout << ' ';
        }
    }
    cout << ']' << endl;
    cout << endl;
    return 0;
}

int Attack ()
{
    if (random() < 0.7)
    {
        MHP -= (PATK / MDEF) + (2 * PL);
        //cout << "CRITICAL" << endl;
    } else
    {
        MHP -= 2 * ((PATK / MDEF) + (2 * PL));
        //cout << "CRITICAL" << endl;
    }
    if (MHP <= 0)
    {
        cout << "Killed a monster. Gained " << int(ML * ML) << " experience points." << endl;
        PEXP += int(ML * ML);
        PXP += int(ML * ML);
        if (PEXP > PEXPL)
        {            
            PEXP -= PEXPL;
            int inc = PL * 20 + 50;
            PHP += inc;
            PMHP += inc;
            PL++;
            PEXPL += PL * 30 + 30;
            PATK += 20;
            PDEF += 30;
            cout << "Well done. You have advanced to level " << PL << endl;
        }
        MMHP += 10 * PL;
        MHP += MMHP;
        ML = int(MMHP / 200) + 1;
        MATK = 20 + 10 * ML;
        MDEF = 10 + 5 * ML;        
    } else
    {
        PHP -= (MATK / PDEF) + (2 * ML);
    }
    Display();
    return 0;
}

int Heal ()
{
    if (PHP >= (PMHP * 9) / 10)
    {
        PHP = PMHP;
    } else
    {
        PHP += PMHP * 0.1;
    }
    Display();
    return 0;
}

int main ()
{
    PHP = 250;
    PMHP = 250;
    PEXP = 0;
    PEXPL = 10;
    PL = 1;
    PATK = 50;
    PDEF = 60;
    
    MHP = 10;
    MMHP = 10;
    ML = 1;
    MATK = 30;
    MDEF = 15;
    
    cout << " Monster Fighter Text. \n Version 0.1 \n Author: CTSD0xF \n";
    
    while (PHP > 0 && CHOICE != 'q')
    {
        cout << "Please select \"a\" for attack, \"h\" for heal, \"v\" for view, or \"q\" for quit." << endl;
        cin >> CHOICE;
        int i;
        for (i=0;i<20;i++)
        {
            cout << endl;
        }
        if (CHOICE == 'a')
        {
            Attack();
        } else if (CHOICE == 'v')
        {
            Display();
        } else if (CHOICE == 'h')
        {
            Heal();
        } else
        {
            cout << "not a valid option." << endl;
        }
    }
    cout << " Well Played. \n You achieved " << PXP << " Points!\nNow just input a character to leave";
    cin >> CHOICE;
    return 0;
}
