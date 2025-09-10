#include <iostream>
#include <string>

using namespace std;

class Tank {
public:
	virtual void Attack();
	virtual void Move(int x, int y);
	virtual void SwitchingMode();
private:
	string Mode = NULL;
};

class SiegeMode : Tank {
	
};

class TankMode : Tank {

};