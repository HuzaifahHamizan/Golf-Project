#ifndef MANAGER_H
#define MANAGER_H
#include "Player.h"

const int NUM2 = 3;

class Manager
{
    public:
        Manager();
        virtual ~Manager();

        string Getbing() { return bing; }
        void Setbing(string val) { bing = val; }
        int Getbong() { return bong; }
        void Setbong(int val) { bong = val; }
        void addPlayers(Player p);
    protected:

    private:
        string bing;
        int bong;
        Player IDs [NUM2];
        int cnt2 = 0;
};

#endif // MANAGER_H
