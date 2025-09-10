#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Unit {
public:
    virtual ~Unit() {
        cout << "¼Ò¸êÀÚ È£Ãâ" << endl;
    };
    virtual void Move(int x, int y) = 0;
};

class Marin : public Unit {
public:
    void Move(int x, int y) override {
        cout <<x <<"," << y << "Attack" << endl;
    }
};

class Medic : public Unit {
    void Move(int x, int y) override {
        cout <<x << "," << y << "Move" << endl;
    }
};

class Commander {
private:
    vector<Unit*> selected;

public:
    void SelectUnit(Unit* u) {
        if (u == NULL) return;
        selected.emplace_back(u);
    }

    void DeselectUnit(Unit* u) {
        if (u == NULL) return;
        selected.erase(remove(selected.begin(), selected.end(), u ), selected.end());

    }

    void Move(int x, int y) {
        for (Unit* u : selected) {
            if (u) u->Move(x, y);
        }
    }
};

int main() {
    Commander commander;
    Marin marin; Medic medic;

    commander.SelectUnit(&marin);
    commander.SelectUnit(&medic);

    commander.Move(10, 20);

    commander.DeselectUnit(&marin);
    commander.Move(0, 0);

    return 0;
}