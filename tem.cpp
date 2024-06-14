#include <bits/stdc++.h>
using namespace std;
class Vehicle
{
    int numWheel;
    string color;
    int maxSpeed;
    int maxGear;
    int curGear;
    int curSpeed;
    bool started;
    bool stopped;

public:
    Vehicle()
    {
        this->numWheel = 0;
        this->color = "";
        this->curGear = 0;
        this->curSpeed = 0;
        this->started = false;
        this->stopped = true;
    }
    Vehicle(int numWheel, string color, int curGear, int curSpeed)
    {
        this->numWheel = numWheel;
        this->color = color;
        this->maxSpeed = 150;
        this->maxGear = 5;
        this->curGear = curGear;
        this->curSpeed = curSpeed;
    }
    void isStart(bool s)
    {
        started = true;
        stopped = false;
    }
    void isStopped(bool s)
    {
        started = false;
        stopped = true;
        curGear = 0;
        curSpeed = 0;
    }
    bool start()
    {
        return started;
    }
    void steGear()
    {
        curGear += 1;
    }
    void decGear()
    {
        curGear -= 1;
    }
    int getGear()
    {
        return curGear;
    }
    void setSpeed()
    {
        curSpeed += 10;
    }
    int getSpeed()
    {
        return curSpeed;
    }
    void decSpeed()
    {
        curSpeed -= 10;
    }
    void showStatus()
    {
        cout << "The current Gear is:" << getGear
             << endl
             << "Current Speed is:" << getSpeed << endl;
    }

    int getWheel()
    {
        return numWheel;
    }
    string getColour()
    {
        return color;
    }
    int getmaxSpeed()
    {
        return maxSpeed;
    }
    int getmaxGear()
    {
        return maxGear;
    }
};

int main()
{
    Vehicle v1(4, "Black", 0, 0);
    cout << "The featuers of car is:"
         << endl<< "The Wheels of car:" << v1.getWheel()
         <<endl<<"The color is:"<<v1.getColour()
         <<endl<<"Maximun Speed of Car:"<<v1.getmaxSpeed()
        <<endl<<"Maximum Gear of car:"<<v1.getmaxGear()<<endl;
    int ch;
    while (1)
    {
        cout << "1.Start:"
             << endl
             << "2.Increase Gear:"
             << endl
             << "3.Decrease Gear:"
             << endl
             << "4.Increase Speed:"
             << endl
             << "5.Decrease Speed:"
             << endl
             << "6.Stop:" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        v1.getGear();
        v1.showStatus();
        }
    }
    return 0;
}