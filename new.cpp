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
    int flag = 0;
    // game loop
    while (1) {
        int entity_count;
        cin >> entity_count; cin.ignore();
        Entity a;
        int myx,myy,ax,ay,xr,yr,rid;
        
        int myid = 0;
        string mytype;
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
               
            if(owner == 1 && organ_id>myid){
            myid= organ_id;
            myx = x;
            myy =y;
            mytype = type;
            }
            if(owner == 1 && type == "ROOT"){
                rid = organ_id;
                xr = x;
                yr = y;
            }
           
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
        if ((mytype != "HARVESTER") && flag ==0){
            if(((ax == myx+1 && ay == myy)|| (ax == myx - 1 && ay == myy) || (ax == myx && ay == myy+1) || (ax == myx && ay == myy-1)))
             cout << "GROW "<< myid << " "<<ax<<" "<<ay<<" BASIC" << endl;

            else if ((ax == myx+1 && ay == myy+1)||(ax == myx+1 && ay == myy-1)||(ax == myx+2&& ay == myy))
            {
                if ((ax == myx+1 && ay == myy+1))
                    cout << "GROW "<< myid << " "<<myx+1<<" "<<myy<<" HARVESTER S" << endl;
                else if ((ax == myx+1 && ay == myy-1))
                    cout << "GROW "<< myid << " "<<myx+1<<" "<<myy<<" HARVESTER N" << endl;
                else if ((ax == myx+2&& ay == myy))
                    cout << "GROW "<< myid << " "<<myx+1<<" "<<myy<<" HARVESTER E" << endl;
                flag = 1;

            }

            else if ((ax == myx-1 && ay == myy+1)||(ax == myx-1 && ay == myy-1)||(ax == myx-2 && ay == myy))
            {
                if ((ax == myx-1 && ay == myy+1))
                    cout << "GROW "<< myid << " "<<myx-1<<" "<<myy<<" HARVESTER S" << endl;
                else if ((ax == myx-1 && ay == myy-1))
                    cout << "GROW "<< myid << " "<<myx-1<<" "<<myy<<" HARVESTER N" << endl;
                else if ((ax == myx-2 && ay == myy))
                    cout << "GROW "<< myid << " "<<myx-1<<" "<<myy<<" HARVESTER W" << endl;
                flag = 1; 

            }

            else if ((ax == myx && ay == myy-2)){
                cout << "GROW "<< myid << " "<<myx<<" "<<myy-1<<" HARVESTER N" << endl;
                flag = 1;
            }
            else if((ax == myx && ay == myy+2)){
                cout << "GROW "<< myid << " "<<myx<<" "<<myy+1<<" HARVESTER S" << endl;
                flag = 1;
            }
            else
                cout << "GROW "<< myid << " "<<ax<<" "<<ay<<" BASIC" << endl;
            }
        else
            {
                if(xr<width/2)
                cout << "GROW "<< rid  << " "<<width -1<<" "<<height-1<<" BASIC" << endl;
                else
                cout << "GROW "<< rid  << " 0 0 BASIC" << endl;
            }
            
 
              
        

        }
    }
} 
