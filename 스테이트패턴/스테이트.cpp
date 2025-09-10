#include <iostream>
#include <string>

using namespace std;

class Tank {
public:
	void Attack();
	void Move(int x, int y);
	void SwitchingMode(Mode* mode);
private:
	Mode* pState = NULL;
};

class Mode {
public:
	void Attack();
	void Move(int x, int y);
};

class SiegeMode : Mode {
public:
	void Attack() {
		cout << "attack 70" << endl;
	};
	void Move(int x, int y) {
		cout << "Move 0" << endl;
	};
};

class TankMode : Mode {
public:
	void Attack() {
		cout << "attack 30" << endl;
	};
	void Move(int x, int y) {
		cout << "Move "<<x<<y << endl;
	};
};

int main() {

	Tank tank;


	return 0;
}