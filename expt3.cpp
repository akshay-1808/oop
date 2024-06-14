#include<iostream>

using namespace std;

class Vehicle{
    private:
        int numWheels;
        string color;
        int maxSpeed;
        int maxGears;
        int curGear;
        int curSpeed;
        bool started;
        bool stopped;
    public:
        Vehicle(){
            numWheels = 0;
            color = "";
            curGear = 0;
            curSpeed = 0;
            started = false;
            stopped = true;
        }
        Vehicle(int nw,string c,int cs,int cg){
            numWheels = nw;
            color = c;
            curSpeed = cs;
            curGear = cg;
            maxSpeed = 150;
            maxGears = 5;
        }
        void isStart(bool s){
            started = true;
            stopped = false;
        }
        void isStop(bool s){
            stopped = true;
            started = false;
            curGear = 0;
            curSpeed = 0;
        }
        bool Start(){
            return started;
        }
        void setGear(){
            curGear += 1;
        }
        void decGear(){
            curGear -= 1;
        }
        int getGear(){
            return curGear;
        }
        void setSpeed(){
            curSpeed += 10;
        }
        int getSpeed(){ 
            return curSpeed;
        }
        void decSpeed(){
            curSpeed -= 10;
        }
        void showStatus(){
            cout<<endl<<"Current Gear is "<<curGear<<endl;
            cout<<"Current Speed is "<<curSpeed<<endl;
        }
        int getWheels(){
            return numWheels;
        }
        string getColour(){
            return color;
        }
        int getmaxSpeed(){
            return maxSpeed;
        }
        int getmaxGears(){
            return maxGears;
        }
};

int main(){
    Vehicle v1(4,"Black",0,0);
    cout<<endl<<"Current feature of car is "
        <<endl<<"Maximum Wheels are "<<v1.getWheels()
        <<endl<<"Colour of car is "<<v1.getColour()
        <<endl<<"Maximum speed of car is "<<v1.getmaxSpeed()
        <<endl<<"Maximum Gears are "<<v1.getmaxGears();

    int choice;
    while(1){
        cout<<endl<<"1] Start"
            <<endl<<"2] Stop"
            <<endl<<"3] Increase Gear"
            <<endl<<"4] Decrease Gear"
            <<endl<<"5] Increase Speed"
            <<endl<<"6] Decrease Speed"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                v1.isStart(true);
                v1.showStatus();
                break;
            case 2:
                v1.isStop(true);
                v1.showStatus();
                break;
            case 3:
                if(v1.Start()&&v1.getGear()<5){
                    v1.setGear();
                }
                v1.showStatus();
                break;
            case 4:
                if(v1.Start()&&v1.getGear()<=5){
                    v1.decGear();
                }
                v1.showStatus();
                break;
            case 5:
                if(v1.Start()&&v1.getSpeed()<150){
                    v1.setSpeed();
                }
                v1.showStatus();
                break;
            case 6:
                if(v1.Start()&&v1.getSpeed()<=150){
                    v1.decSpeed();
                }
                v1.showStatus();
                break;
            default:
                cout<<endl<<"Wrong Choice!"<<endl;
                v1.showStatus();
                break;
        }
    }
    return 0;
}