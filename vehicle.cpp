#include <iostream>
using namespace std;
class Vehicle
{
    int numWheels;
    string color;
    int maxSpeed;
    int maxGears;
    int curGear;
    int curSpeed;
    bool started;
	public:
    Vehicle()
    {
        numWheels = 4;
        color = "Black";
        maxSpeed = 200;
        maxGears = 5;
        curGear = 0;
        curSpeed = 0;
        started = false;
    }
    int getWheels() { return numWheels; }
    int getMaxGears() { return maxGears; }
    int getMaxSpeed() { return maxSpeed; }
    int getSpeed() { return curSpeed; }
    string getColor() { return color; }
    void start()
    {
        if (!started)
        {
            started = true;
            cout << "Vehicle started.\n";
        }
        else
        {
            cout << "Vehicle is already started.\n";
        }
    }
    void stop()
    {
        if (started)
        {
            started = false;
            curSpeed = 0;
            curGear = 0;
            cout << "Vehicle stopped.\n";
        }
        else
        {
            cout << "Vehicle is already stopped.\n";
        }
    }
    void nextGear()
    {
        if (started && curGear < maxGears)
        {
            curGear++;
            curSpeed += 40;
            cout << "Shifted to gear " << curGear << endl;
        }
        else
        {
            cout << "Vehicle not started or already in the highest gear.\n";
        }
    }
    void previousGear()
    {
        if (started && curGear > 0)
        {
            curGear--;
            cout << "Shifted to gear " << curGear << endl;
        }
        else
        {
            cout << "Vehicle not started or already in the lowest gear.\n";
        }
    }
    void increaseSpeed()
    {
        int s;
        cout << "Enter speed to increase: ";
        cin >> s;
        if (curSpeed + s <= maxSpeed)
        {
            curSpeed += s;
            cout << "Current speed: " << curSpeed << endl;
        }
        else
        {
            curSpeed = maxSpeed;
            cout << "Current speed: " << curSpeed << endl;
        }
    }
    void decreaseSpeed()
    {
        int s;
        cout << "Enter speed to decrease: ";
        cin >> s;
        if (curSpeed - s >= 0)
        {
            curSpeed -= s;
            cout << "Current speed: " << curSpeed << endl;
        }
        else
        {
            curSpeed = 0;
            cout << "Current speed: " << curSpeed << endl;
        }
    }
};
int main()
{
    Vehicle car;
    int choice;
    while (true)
    {
        cout << "1. Start\n";
        cout << "2. Next gear\n";
        cout << "3. Previous gear\n";
        cout << "4. Increase speed\n";
        cout << "5. Decrease speed\n";
        cout << "6. Stop\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            car.start();
            break;
        case 2:
            car.nextGear();
            break;
        case 3:
            car.previousGear();
            break;
        case 4:
            car.increaseSpeed();
            break;
        case 5:
            car.decreaseSpeed();
            break;
        case 6:
            car.stop();
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
