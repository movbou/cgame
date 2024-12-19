#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int width; // columns in the game grid
    int height; // rows in the game grid
    cin >> width >> height; cin.ignore();

    // game loop
    while (1) {
        int entity_count;
        cin >> entity_count; cin.ignore();
        int myid;
        int ax;
        int ay;
        int myx;
        int myy;

        for (int i = 0; i < entity_count; i++) {
            int x;
            int y; // grid coordinate
            string type; // WALL, ROOT, BASIC, TENTACLE, HARVESTER, SPORER, A, B, C, D
            int owner; // 1 if your organ, 0 if enemy organ, -1 if neither
            int organ_id; // id of this entity if it's an organ, 0 otherwise
            string organ_dir; // N,E,S,W or X if not an organ
            int organ_parent_id;
            int organ_root_id;
            cin >> x >> y >> type >> owner >> organ_id >> organ_dir >> organ_parent_id >> organ_root_id; cin.ignore();
            if(owner == 1){
            myid= organ_id;
            myx = x;
            myy =y;
            }

            if(type == "A" && y<4)
            {
                ax=x;
                ay=y;
            }
        }
        cerr << myid << ", myx" << myx << ", myy"<< myy << ", ax"<<ax << ", ay"<<ay<< endl;
        
        int my_a;
        int my_b;
        int my_c;
        int my_d; // your protein stock
        cin >> my_a >> my_b >> my_c >> my_d; cin.ignore();
        int opp_a;
        int opp_b;
        int opp_c;
        int opp_d; // opponent's protein stock
        cin >> opp_a >> opp_b >> opp_c >> opp_d; cin.ignore();
        int required_actions_count; // your number of organisms, output an action for each one in any order
        cin >> required_actions_count; cin.ignore();
        for (int i = 0; i < required_actions_count; i++) {

            // Write an action using cout. DON'T FORGET THE "<< endl"
            // To debug: cerr << "Debug messages..." << endl;
           if( ay == 2 && myx < ax-2)
                cout << "GROW 1 "<<"16"<<" "<<"2"<<" BASIC" << endl;
           else if( ay != 2 && myx < ax-1)
                cout << "GROW 1 "<<"16"<<" "<<"2"<<" BASIC" << endl;
            if(ay==2 && myx == ax-2)
                cout << "GROW 1 "<<"16"<<" "<<"2"<<" HARVESTER E" << endl;
            else if(ay < 2 && myx == ax-1)
                cout << "GROW 1 "<<"16"<<" "<<"2"<<" HARVESTER N" << endl;
            else if(ay > 2 && myx == ax-1)
                cout << "GROW 1 "<<"16"<<" "<<"2"<<" HARVESTER S" << endl;
            else if(myx >= ax )
            {
                cout << "GROW 1 "<<"16"<<" "<<"7"<<" BASIC" << endl;
            }
        }
    }
}
