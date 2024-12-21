#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath> 

using namespace std;

struct Entity {
    int x;
    int y; // grid coordinate
    string type; // WALL, ROOT, BASIC, TENTACLE, HARVESTER, SPORER, A, B, C, D
    int owner; // 1 if your organ, 0 if enemy organ, -1 if neither
    int organ_id; // id of this entity if it's an organ, 0 otherwise
    string organ_dir; // N,E,S,W or X if not an organ
    int organ_parent_id;
    int organ_root_id;
};
double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
    int width; // columns in the game grid
    int height; // rows in the game grid
    cin >> width >> height; cin.ignore();

    // game loop
    while (1) {
        int entity_count;
        cin >> entity_count; cin.ignore();
        Entity a;
        int myx,myy,ax,ay;
        int myid = 0;
        double dist = 1000;
        
        vector<Entity> thing;
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
            a = {x,y,type,owner,organ_id,organ_dir,organ_parent_id,organ_root_id};
            thing.push_back(a);
               cerr << myid<< endl; 
            if(owner == 1 && organ_id>myid){
            myid= organ_id;
            myx = x;
            myy =y;
            
            }
            cerr << "00"<<myid<< endl;
        }
                 

        for(int i = 0; i < entity_count; i++){
            if(thing[i].type == "A"){
                if(dist > calculateDistance(thing[i].x, thing[i].y, myx, myy)){
                    dist = calculateDistance(thing[i].x, thing[i].y, myx, myy);
                    ax = thing[i].x;
                    ay = thing[i].y;
                }
            }
        }

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
            if((ax == myx+1 && ay == myy)|| (ax == myx - 1 && ay == myy) || (ax == myx && ay == myy+1) || (ax == myx && ay == myy-1))
             cout << "GROW "<< myid << " "<<ax<<" "<<ay<<" BASIC" << endl;

            else if ((ax == myx+1 && ay == myy+1)||(ax == myx+1 && ay == myy-1)||(ax == myx+2&& ay == myy))
            {
                if ((ax == myx+1 && ay == myy+1))
                cout << "GROW 1 "<<myx+1<<" "<<myy<<" HARVESTER N" << endl;
            else if ()

            }

            else if ((ax == myx-1 && ay == myy+1)||(ax == myx-1 && ay == myy-1)||(ax == myx-2 && ay == myy))
            {

            }

            else if ((ax == myx && ay == myy-2))
            {

            }
            
            else if((ax == myx && ay == myy+2))
            {

            }

              
        

        }
    }
} 





        // if(myx < 11)
        // 
        // else if (myx == 11 && myy<5)
        // cout << "GROW "<< myid << " "<<"11"<<" "<<myy+1<<" BASIC" << endl;
        // else if (myx > 1 && myy==5)
        // cout << "GROW "<< myid << " "<<"1"<<" "<<"5"<<" BASIC" << endl;


           // Write an action using cout. DON'T FORGET THE "<< endl"
            // To debug: cerr << "Debug messages..." << endl;
        //    if( ay == 2 && myx < ax-2)
        //         cout << "GROW 1 "<<"16"<<" "<<"2"<<" BASIC" << endl;
        //    else if( ay != 2 && myx < ax-1)
        //         cout << "GROW 1 "<<"16"<<" "<<"2"<<" BASIC" << endl;
        //     if(ay==2 && myx == ax-2)
        //         cout << "GROW 1 "<<"16"<<" "<<"2"<<" HARVESTER E" << endl;
        //     else if(ay < 2 && myx == ax-1)
        //         cout << "GROW 1 "<<"16"<<" "<<"2"<<" HARVESTER N" << endl;
        //     else if(ay > 2 && myx == ax-1)
        //         cout << "GROW 1 "<<"16"<<" "<<"2"<<" HARVESTER S" << endl;
        //     else if(myx >= ax )
        //     {
        //      
        //     } 
            
