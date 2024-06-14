#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
private:
    int numWheels;
    std::string color;
    int maxSpeed;
    int maxGears;
    int curGear;
    int curSpeed;
    bool started;
    bool stopped;

public:
    // Constructor
    Vehicle(int maxGears, int maxSpeed, int numWheels, std::string color);

    int getWheels();
    int getMaxGears();
    int getMaxSpeed();
    int getSpeed();
    std::string getColor();

    void display();

    // Start
    void start();

    // Stop
    void stop();

    // Next gear
    void nextGear();

    // Previous gear
    void previousGear();

    void incSpeed();

    void decSpeed();
};
Vehicle::Vehicle(int maxGears, int maxSpeed, int numWheels, string color)
{
    this->numWheels = numWheels;
    this->color = color;
    this->maxSpeed = maxSpeed;
    this->maxGears = maxGears;
    this->curGear = 0;
    this->curSpeed = 0;
    this->started = false;
    this->stopped = true;
}

int Vehicle::getWheels() { return numWheels; }
int Vehicle::getMaxGears() { return maxGears; }
int Vehicle::getMaxSpeed() { return maxSpeed; }
int Vehicle::getSpeed() { return curSpeed; }
string Vehicle::getColor() { return color; }

void Vehicle::display()
{
    cout << "Vehicle current gear is " << curGear << "and current speed is " << curSpeed << "km/h" << endl;
}

// Start
void Vehicle::start()
{
    if (!started)
    {
        started = true;
        stopped = false;
        cout << "Vehicle started.\n";
    }
    else
    {
        cout << "Vehicle is already started.\n";
    }
}

// Stop
void Vehicle::stop()
{
    if (!stopped)
    {
        started = false;
        stopped = true;
        curSpeed = 0;
        curGear = 0;
        cout << "Vehicle stopped.\n";
    }
    else
    {
        cout << "Vehicle is already stopped.\n";
    }
}

// Next gear
void Vehicle::nextGear()
{
    if (started && curGear < maxGears)
    {
        curGear++;
        display();
    }
}

// Previous gear
void Vehicle::previousGear()
{
    if (started && curGear > 0)
    {
        curGear--;
        display();
    }
}

void Vehicle::incSpeed()
{
    if (curGear == 1)
    {
        if (curSpeed >= 0 && curSpeed < 40)
        {
            curSpeed += 10;
            display();
        }
        else
        {
            nextGear();
        }
    }
    else if (curGear == 2)
    {
        if (curSpeed >= 40 && curSpeed < 80)
        {
            curSpeed += 10;
            display();
        }
        else
        {
            nextGear();
        }
    }
    else if (curGear == 3)
    {
        if (curSpeed >= 80 && curSpeed < 120)
        {
            curSpeed += 10;
            display();
        }
        else
        {
            nextGear();
        }
    }
    else if (curGear == 4)
    {
        if (curSpeed >= 120 && curSpeed < 160)
        {
            curSpeed += 10;
            display();
        }
        else
        {
            nextGear();
        }
    }
    else if (curGear == 5)
    {
        if (curSpeed >= 160 && curSpeed <= 200)
        {
            curSpeed += 10;
            display();
        }
        else
        {
            nextGear();
        }
    }
}

void Vehicle::decSpeed()
{
    if (curGear == 1)
    {
        if (curSpeed >= 0 && curSpeed < 40)
        {
            curSpeed -= 10;
            display();
        }
        else
        {
            previousGear();
        }
    }
    else if (curGear == 2)
    {
        if (curSpeed >= 40 && curSpeed < 80)
        {
            curSpeed -= 10;
            display();
        }
        else
        {
            previousGear();
        }
    }
    else if (curGear == 3)
    {
        if (curSpeed >= 80 && curSpeed < 120)
        {
            curSpeed -= 10;
            display();
        }
        else
        {
            previousGear();
        }
    }
    else if (curGear == 4)
    {
        if (curSpeed >= 120 && curSpeed < 160)
        {
            curSpeed -= 10;
            display();
        }
        else
        {
            previousGear();
        }
    }
    else if (curGear == 5)
    {
        if (curSpeed >= 160 && curSpeed <= 200)
        {
            curSpeed -= 10;
            display();
        }
        else
        {
            previousGear();
        }
    }
}
int main()
{
    int maxGears, maxSpeed, numWheels;
    string color;
    cout<<"ENter the number of wheels:";
    cin >> numWheels;
    cout<<"Enter the Max Speed of Vehicle:";
    cin>> maxSpeed; 
    cout<<"Enter the Max Gears of Vehicle:";
    cin>> maxGears; 
    cout<<"Enter the Colour of Vehicle:";
    cin>> color;
    Vehicle car(maxGears, maxSpeed, numWheels, color);

    int choice;
    do
    {
        cout << "\nEnter your choice:\n";
        cout << "1. Start vehicle\n";
        cout << "2. Increase Speed\n";
        cout << "3. Decrease Speed\n";
        cout << "4. Stop\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            car.start();
            car.display();
            break;
        case 2:
            car.incSpeed();
            car.display();
            break;
        case 3:
            car.decSpeed();
            car.display();
            break;
        case 4:
            car.stop();
            car.display();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}