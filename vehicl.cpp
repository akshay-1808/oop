#pragma once
#include<string>
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
	bool stoped;
	
	public:

	Vehicle(int wheel, string c, int s, int g):numWheels(wheel), color(c), maxSpeed(s), maxGears(g), curGear(0), curSpeed(0), started(false), stoped(true) {}
	
	static int getWheels(){return numWheels;}
	static int getMaxGears(){return maxGears;}
	static int getMaxSpeed(){return maxSpeed;}
	static int getSpeed(){return curSpeed;}
	
	
	//start
	static void start(){
		if(!started){
			started=true;
			stoped=false;	
			cout<<"Vehicle Started.\n";
		}
		else{
			cout<<"Vehicle is started.\n";
		}
	}
	//stop
	static void stop(){
		if(!stoped){
			started=false;
			stoped=true;
			curSpeed=0;
			curGear=0;	
			cout<<"Vehicle Stoped.\n";
		}
		else{
			cout<<"Vehicle is already stoped.\n";
		}
	}
	
	static void display(){
			cout<<"Shifted gear to "<<curGear<<endl;
			cout<<"Current speed:"<<curSpeed<<"km/h"<<endl;
	}
	
	//next Gear
	static void nextGear(){
		if(started && curGear<maxGears){
			curGear++;
			display();
		}
		else{
			cout<<"Vehicle not started or already in highest gear"<<endl;
		}
	}
	
	//prev Gear
	static void prevGear(){
		if(started && curGear>0){
			curGear--;
			display();
		}
		else{
			cout<<"Vehicle not started or already in lowest gear"<<endl;
		}
	}
	
	// increase speed
	static void incSpeed(){
		if(curGear==1){
			   if(curSpeed>=0&&curSpeed<40){
			   		curSpeed+=10;
			   		display();
			   }
			   else{
					nextGear();
			   }
		}
		else if(curGear==2){
			if(curSpeed>=40&&curSpeed<80){
			   		curSpeed+=10;
			   		display();
			   }
			   else{
			   		nextGear();
			   }
		}
		else if(curGear==3){
			if(curSpeed>=80 && curSpeed<120){
			   		curSpeed+=10;
			   		display();
			   }
			   else{
			   		nextGear();
			   }
		}
		else if(curGear==4){
			if(curSpeed>=120 && curSpeed<160){
			   		curSpeed+=10;
			   		display();
			   }
			   else{
			   		nextGear();
			   }
		}
		else if(curGear==5){
			if(curSpeed>=160&&curSpeed<=200){
			   		curSpeed+=10;
			   		display();
			   }
			   else{
			   		nextGear();
			   }
		}
	}
	
	static void decSpeed(){
		if(curGear==1){
			   if(curSpeed>=0&&curSpeed<40){
			   		curSpeed-=10;
			   		display();		
			   }
			   else{
			   		prevGear();
			   }
		}
		else if(curGear==2){
			if(curSpeed>=40&&curSpeed<80){
			   		curSpeed-=10;
			   		display();
			   }
			   else{
			   		prevGear();
			   }
		}
		else if(curGear==3){
			if(curSpeed>=80&&curSpeed<120){
			   		curSpeed-=10;
			   }
			   else{
			   		prevGear();
			   }
		}
		else if(curGear==4){
			if(curSpeed>=120&&curSpeed<160){
			   		curSpeed-=10;
			   		display();
			   }
			   else{
			   		prevGear();
			   }
		}
		else if(curGear==5){
			if(curSpeed>=160&&curSpeed<200){
			   		curSpeed-=10;
			   		display();
			   }
			   else{
			   		prevGear();
			   }
		}
	}
	
};

#endif
