#include <iostream>
#include <string>

using namespace std;

class Mode {
public:
	virtual ~Mode() = default;
	virtual void Attack() = 0;
	virtual void Move(int x, int y) = 0;
};

class SiegeMode : public Mode {
public:
	void Attack() override {
		cout << "attack 70" << endl;
	};
	void Move(int x, int y) override {
		cout << "Move 0" << endl;
	};
};

class TankMode : public Mode {
public:
	void Attack() override {
		cout << "attack 30" << endl;
	};
	void Move(int x, int y) override {
		cout << "Move "<<x<<"," << y << endl;
	};
};

class Tank {
public:
	Tank(Mode* initialState) : pState(initialState) {}

	void Attack() { pState->Attack(); }
	void Move(int x, int y) { pState->Move(x, y); }

	void SwitchingMode(Mode* mode) {
		pState = mode;
	}
private:
	Mode* pState = NULL;
};

int main() {

	TankMode  tankMode;
	SiegeMode siegeMode;
	Tank tank(&tankMode);

	tank.Move(3, 4);
	tank.Attack();

	tank.SwitchingMode(&siegeMode);
	tank.Move(10, 20);
	tank.Attack();
}