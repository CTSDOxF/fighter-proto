#include <iostream>

#include <random>

#include <string.h>

using namespace std;

long long int PHP,PMHP,PEXP,PL,PEXPL,MHP,MMHP,ML;

long long int gold, cost;

long long int PATK,PDEF,MATK,MDEF,PXP;

char CHOICE;

int Upgrade ()
{
    cout << "How much gold will you spend? ";
    cin >> cost;
    if (gold >= cost)
    {
        gold -= cost;
        PATK += cost / 2;
        PDEF += cost / 2;
    } else
    {
        PATK += gold / 2;
        PDEF += gold / 2;
        gold = 0;
    }
    return 0;
}

int Display ()
{
    cout << "Player Level: " << PL << endl;
    cout << '[';
    int i;
    for (i=0;i<50;i++)
    {
        if (PHP > (PMHP * i) / 50)
        {
            cout << '|';
        } else
        {
            cout << ' ';
        }
    }
    cout << ']' << PHP << '/' << PMHP << endl;
    cout << '[';
    for (i = 0; i < 30; i++)
    {
        if (PEXP > (PEXPL * i) / 30)
        {
            cout << '|';
        } else
        {
            cout << ' ';
        }
    }
    cout << ']' << PEXP << '/' << PEXPL << endl;
    cout << "Gold: " << gold <<endl;
    cout << "Monster Level: " << ML << endl;
    cout << '[';
    for (i = 0; i < 50; i++)
    {
        if (MHP > (MMHP * i) / 50)
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
        gold += 5 * ML;
        while (PEXP > PEXPL)
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
        MHP = MMHP;
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
    
    cout << " Monster Fighter Text. \n Version 0.3 \n Author: CTSD0xF \n";
    
    while (PHP > 0 && CHOICE != 'q')
    {
        cout << "Please select \"a\" for attack, \"h\" for heal, \"u\" to upgrade your character,\n\"v\" for view, or \"q\" for quit." << endl;
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
        } else if (CHOICE == 'u')
        {
            Upgrade ();
            Display ();
        } else if (CHOICE == 'd')
        {
            string debug_text;
            cin >> debug_text;
            if (debug_text == "exp")
            {
                long long int exp_boost;
                cin >> exp_boost;
                PEXP += exp_boost;
            }
            if (debug_text == "stat")
            {
                cout << "PATK: " << PATK << endl;
                cout << "PDEF: " << PDEF << endl;
                cout << "MHP: " << MHP << endl;
                cout << "MMHP: " << MMHP << endl;
                cout << "MATK: " << MATK << endl;
                cout << "MDEF: " << MDEF << endl;
            }
            if (debug_text == "gold")
            {
                long long int gold_boost;
                cin >> gold_boost;
                gold += gold_boost;
            }
            if (debug_text == "mod stat")
            {
                cin >> debug_text;
                long long int buff;
                if (debug_text == "PATK")
                {
                    cin >> buff;
                    PATK += buff;
                }
                if (debug_text == "PDEF")
                {
                    cin >> buff;
                    PDEF += buff;
                }
                if (debug_text == "MHP")
                {
                    cin >> buff;
                    MHP += buff;
                }
                if (debug_text == "MMHP")
                {
                    cin >> buff;
                    MMHP += buff;
                }
                if (debug_text == "MATK")
                {
                    cin >> buff;
                    MATK += buff;
                }
                if (debug_text == "MDEF")
                {
                    cin >> buff;
                    MDEF += buff;
                }
            }
        } else
        {
            cout << "not a valid option." << endl;
        }
    }
    cout << " Well Played. \n You achieved " << PXP + 0.1 * gold << " Points!\nNow just input a character to leave" << endl;
    cin >> CHOICE;
    return 0;
}
