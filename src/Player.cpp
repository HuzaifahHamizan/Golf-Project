#include "Player.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <locale>
#include <cstdlib>
#include <algorithm>

using namespace std;

Player::Player()
{
    surname = "bb";
    forename = "";
    handicap = 0;
    fullname = " ";
    tscore = 0;

    //ctor
}

Player::Player(string s, string f){

    string forename, surname, fname, temp2;
    forename = f;
    surname = s;

    locale loc;

    for (string::size_type i=0; i<forename.length(); ++i){
        if (i == 0){
            temp2 = toupper(forename[i],loc);
            fname.append(temp2);
        }
        else if (i > 0) {
            temp2 = tolower(forename[i],loc);
            fname.append(temp2);
        }
    }
    fname.append(" ");

    for (string::size_type i=0; i<surname.length(); ++i){
        if (i == 0){
            temp2 = toupper(surname[i],loc);
            fname.append(temp2);
        }
        else if (i > 0) {
            temp2 = tolower(surname[i],loc);
            fname.append(temp2);
        }
    }
    fullname = fname;
    cout << fname;
    //ctor
}

void Player::cal(){
    int parScore = 0;
    int globalHandicap = 0;
    int scoreTotal = 0;
    int netScore[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //initialise variables
    int score[18];
    int par[18];

    int handicap = 0;
    cout << "What is your handicap? [0 to 54] "; //Handicap input
    cin >> handicap;
    srand(handicap); //Handicap sets the seed for the randomness in this case, replace with integer to remove randomness

    int holeWeight[18] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18}; //Randomly designate hole difficulties to the different holes
    random_shuffle(holeWeight, holeWeight + 18);

    cout << "Hole Weights: ";
    for(int i=0; i<18;)
    {
        cout <<holeWeight[i]<<", ";                         //Hole difficulty index readout


        par[i] = rand() % 3 + 3;

        i++;
    }
    cout<<endl<<endl;

    if(handicap <= 54 && handicap >=0) //Check if handicap is a valid number
    {
        for(int HCDummy = handicap; HCDummy>=18;)
        {                                        //This part adds +1 to every hole for every multiple of 18 using a 'global handicap'
            handicap = handicap - 18;             //There is no specified 'local handicap', rather just an if statement that adds a +1 (see below)
            HCDummy = HCDummy - 18;
            globalHandicap++;
        }

        //cout<<"Your handicap is "<<globalHandicap+1<<" between holes weighted 18 and "<<19-handicap<<" and "<<globalHandicap<<" between "<<18-handicap<<" and 1."<<endl<<endl;


        for(int i = 0; i<18;)
        {
            cout<<"Hole "<<i+1<<":\nPar is: "<<par[i]<<"\nHow many shots did you take? [1 to 12] ";//UI part 1
            cin>>score[i];

            if(score[i] == 12)                   //This Section of code checks if the amount of shots taken is valid
            {
                cout<<"You ran out of strokes! [14]\n"; //Too many shots
                score[i] = 14;
            }
            else if(score[i] > 12)
            {
                cout<<"How did you take so many strokes ?! [14]\n";
                score[i] = 14;
            }
            else if(score[i] < 1)                       //Not enough shots
            {
                cout<<"Impossible Score.\nI'm giving you 1 over par instead for lying. ["<<par[i] +1<<"]\n";
                score[i] = par[i] +1;
            }

            if(holeWeight[i]>18-handicap)                   //This If/Else statement determines if the handicap gets added to this hole using the
            {                                               //Hole weights from earlier (1 = Hardest hole, 18 = Easiest hole)
                if((par[i]-score[i])+globalHandicap<-2)
                    {parScore = -3;}
                else
                    {parScore = par[i]-score[i]+globalHandicap+1;}//This +1 is the 'local handicap'

                netScore[i]= parScore +3;
                cout <<"Your handicap for this hole was: "<<globalHandicap+1<<"\nYour overall score for the hole was: ";//UI part 2
                cout << netScore[i]<<endl<<endl;
            }
            else                                            //Else of the If/Else statement (aka. when there is no 'local handicap')
            {
                if((par[i]-score[i])+globalHandicap<-2)
                    {parScore = -2;}
                else
                    {parScore = par[i]-score[i]+globalHandicap;}

                netScore[i]= parScore +2;
                cout <<"Your handicap for this hole was: "<<globalHandicap<<"\nYour overall score for the hole was: ";//UI part 2 (as well)
                cout << netScore[i]<<endl<<endl;
            }

            scoreTotal = scoreTotal + netScore[i]; //This calculates the net score for the whole game
            i++;
        }
        cout<<"\nYour total score for the game was "<<scoreTotal;//This is the readout for the final score


    }else
    {
        cout << "Handicap is not valid.\n"; //Handicap must be between 0 and 54, otherwise print this
    }
    tscore = scoreTotal;
}

Player::~Player()
{
    //dtor
}
