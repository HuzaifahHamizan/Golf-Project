#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <locale>
#include "Player.h"
#include "Manager.h"
#include <algorithm>
#include <cstdlib>
#include<stdio.h>


using namespace std;

int main()
{
    int loop = 1;
    do{
    locale loc;
    int start, manager;
    string name, temps, tempf, temp2, score, ID;
    char q1, q2;

        cout << setfill('*') << setw(69) << '\n';
        cout << setfill(' ') << setw(69) << '\n';
        cout << setfill(' ') << setw(50);
        cout << "Hello! Welcome to our Golf Course!" << endl;
        cout << setfill(' ') << setw(69) << '\n';
        cout << setfill('*') << setw(69) << '\n';


        cout << "What is your surname? ";
        cin >> temps;
        cout << "What is your forename? ";
        cin >> tempf;
        cout << setfill(' ') << setw(69) << '\n';
        cout << setfill('*') << setw(69) << '\n';
        cout << setfill(' ') << setw(69) << '\n';
        cout << setfill(' ') << setw(26);

        cout << "Welcome ";
        Player myPlayer(temps, tempf);
        cout << endl;
        cout << setfill(' ') << setw(69) << '\n';
        cout << setfill('*') << setw(69) << '\n';
        cout << "Please enter a user ID(CXXXX): ";
        cin >> ID;
        if (ID != "C0000"){
            ofstream savefile;
            savefile.open ((ID+".txt").c_str());
            savefile << "Player's name = " << myPlayer.Getfullname() << endl << "Player's ID = " << ID << endl;
        }
        cout << setfill('*') << setw(69) << '\n';
        cout << setfill(' ') << setw(69) << '\n';
        cout << setfill('*') << setw(69) << '\n';

        ofstream savefile;
        savefile.open ((ID+".txt").c_str());
        savefile << "Player's name = " << myPlayer.Getfullname() << endl << "Player's ID = " << ID << endl;


    do {
            if (ID == "C0000")
            {cout << "Option 0. Manage \n";}

            cout << "Option 1. Create a new scorecard \n";
            cout << "Option 2. View Score card \n";
            cout << "Option 3. Quit \n";
            cout << "Option 99. Log Out \n";
            cout << setfill(' ') << setw(69) << '\n';

            if (ID == "C0000"){
            {cout << "What would you like to do? (0,1,2,3,99) \n";}
            }else{
            cout << "What would you like to do? (1,2,3,99) \n";
            }
            cin >> start;
            system("CLS");



switch(start)
               {case 1:
                    {
                        cout << setfill('*') << setw(69) << '\n';
                        cout << setfill(' ') << setw(69) << '\n';
                        cout << "A new scorecard for player named ";
                        Player myPlayer(temps, tempf);
                        cout <<" has been created!" << endl;
                        cout << setfill(' ') << setw(69) << '\n';
                        cout << setfill('*') << setw(69) << '\n';
                        myPlayer.cal();
                        cout << endl;
                        cout << setfill(' ') << setw(69) << '\n';
                        cout << setfill('*') << setw(69) << '\n';
                        savefile << "Player's score = " << myPlayer.Gettscore() << endl;
                        break;
                    }

                case 0:
                    {
                        cout << "1. See scorecard.\n ";
                        cout << "2. Remove player.\n ";
                        cout << "What would you like to do?( 1,2) ";
                        cin >> manager;
                        switch(manager){
                            case 1:{
                                string myTextM;

                                // Read from the text file
                                ifstream MyReadFileM((ID+".txt").c_str());

                                // Use a while loop together with the getline() function to read the file line by line
                                while (getline (MyReadFileM, myTextM)) {
                                  // Output the text from the file
                                  cout << myTextM << endl;
                                }
                                cout << endl;

                                // Close the file
                                MyReadFileM.close();
                                break;
                            }
                            case 2:{

                                  ///Player removal does not function

//                                int status:
//                                string fileName;
//                                cout<<"Enter the Player ID: ";
//                                cin >> fileName;
//                                remove(fileName); //Remove player
//                                cout<<endi wol;
//                                break;

                            }
                        }
                        break;
                    }
                case 2:
                    {


//                        cout << "Please Enter your ID: ";
//                        cin >> ID;
                        string myText;

                        // Read from the text file
                        ifstream MyReadFile((ID+".txt").c_str());

                        // Use a while loop together with the getline() function to read the file line by line
                        while (getline (MyReadFile, myText)) {
                          // Output the text from the file
                          cout << myText << endl;
                        }
                        cout << endl;

                        // Close the file
                        MyReadFile.close();


                        while (q1 != 'y' && q1 != 'Y'){
                            cout << "Go back to the main menu?(y) ";
                            cin >> q1;
                        }
                        break;
                    }
                case 3:
                    {
                        cout << "You have quit" << endl;
                        loop = 0;
                        start = 100;
                        }
                        break;
                case 99:
                {
                    cout << "User " << ID << " has logged out\n";
                    savefile.close();
                    do {
                            cout << "Go back to the main menu?(y) ";
                            cin >> q2;
                       } while (q2 != 'y' && q2 != 'Y' );
                    start = 100;
                    break;
                        break;
                }

                default :
                    {
                        cout << "Error ; Please enter valid option.";
                        return 0;
                    }
                }

            }while (start != 100);
            }while (loop != 0);
        }










