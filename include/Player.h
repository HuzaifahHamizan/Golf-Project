#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

class Player
{
    public:
        Player();
        Player (string s, string f);
        virtual ~Player();

        string Getforename() { return forename; }
        void Setforename(string val) { forename = val; }
        string Getsurname() { return surname; }
        void Setsurname(string val) { surname = val; }
        string Getfullname() { return fullname; }
        void Setfullname(string val) { fullname = val; }
        int Gettscore() { return tscore; }
        void Settscore(int val) { tscore = val; }
        void cal();



    protected:

    private:

        string forename;
        string surname;
        string fullname;
        int tscore;
        int handicap;
};

#endif // PLAYER_H
