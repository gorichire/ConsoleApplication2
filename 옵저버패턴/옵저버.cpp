#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Unit {
public:
	virtual ~Unit() {};
	virtual void Move(int x, int y) = 0;
	virtual void SelectUnit() = 0;
	virtual void DeselectUnit() = 0;
};

class Commander {

};

class Marin : public Unit {

};

class Medic : public Unit {

};