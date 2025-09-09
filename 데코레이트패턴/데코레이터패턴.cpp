#include <iostream>
#include <memory>

class Context {
public:
	Context() = default;
	virtual ~Context() = default;
	virtual int Status() = 0;
};

class ConcreteContext : public Context
{
	int value;
public:
	explicit ConcreteContext(int v) : value(v) {}
	int Status() override { return value; }
};

class Decorator : public Context {
protected:
	std::unique_ptr<Context> context;
public:
	explicit Decorator(std::unique_ptr<Context> c)
		: context(std::move(c)) {}

	int Status() override {
		if (!context) return 0;
		return context->Status();
	}
};

class ConcreateDecoratorA : public Decorator {
	int added;
public:
	ConcreateDecoratorA(std::unique_ptr<Context> c, int add)
		: Decorator(std::move(c)), added(add) {}

	int Status() override {
		return Decorator::Status() + added;
	}
};

class ConcreateDecoratorB : public Decorator {
public:
	using Decorator::Decorator;

	void AddBehavior() const {
		std::cout << "AddBehavior\n";
	}

	int Status() override {
		AddBehavior(); 
		return Decorator::Status();
	}
};

int main() {
	std::unique_ptr<Context> c = std::make_unique<ConcreteContext>(10);
	c = std::make_unique<ConcreateDecoratorA>(std::move(c), 5);
	c = std::make_unique<ConcreateDecoratorB>(std::move(c));

	std::cout << "Status = " << c->Status() << "\n";
}