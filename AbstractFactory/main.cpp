//
// Created by pxy on 2025/10/21.
//

#include <iostream>

using std::cout;
using std::endl;

class AbstractProductA
{
public:
	explicit AbstractProductA(std::string name) : Name(std::move(name))
	{
		cout << "Create AbstractProductA: " << Name << endl;
	}
	virtual ~AbstractProductA() = default;
	virtual void Show() const
	{
		cout << "AbstractProductA: " << Name << endl;
	}
protected:
	std::string Name;
};

class AbstractProductB
{
public:
	explicit AbstractProductB(std::string name) : Name(std::move(name))
	{
		cout << "Create AbstractProductB: " << Name << endl;
	}
	virtual ~AbstractProductB() = default;
	virtual void Show() const
	{
		cout << "AbstractProductB: " << Name << endl;
	}
protected:
	std::string Name;
};

class ProductA1 final : public AbstractProductA
{
public:
	explicit ProductA1(std::string name) : AbstractProductA(std::move(name))
	{
		cout << "Create ProductA1: " << Name << endl;
	}
};

class ProductA2 final : public AbstractProductA
{
public:
	explicit ProductA2(std::string name) : AbstractProductA(std::move(name))
	{
		cout << "Create ProductA2: " << Name << endl;
	}
};

class ProductB1 final : public AbstractProductB
{
public:
	explicit ProductB1(std::string name) : AbstractProductB(std::move(name))
	{
		cout << "Create ProductB1: " << Name << endl;
	}
};

class ProductB2 final : public AbstractProductB
{
public:
	explicit ProductB2(std::string name) : AbstractProductB(std::move(name))
	{
		cout << "Create ProductB2: " << Name << endl;
	}
};

class AbstractFactory
{
public:
	AbstractFactory() = default;
	virtual ~AbstractFactory() = default;

	virtual AbstractProductA* CreateProductA(std::string name) = 0;
	virtual AbstractProductB* CreateProductB(std::string name) = 0;
};

class ConcreteFactory1 final : public AbstractFactory
{
public:
	ConcreteFactory1()
	{
		cout << "Create ConcreteFactory1" << endl;
	}

	AbstractProductA* CreateProductA(const std::string name) override
	{
		return new ProductA1(name);
	}
	AbstractProductB* CreateProductB(const std::string name) override
	{
		return new ProductB1(name);
	}
};

class ConcreteFactory2 final : public AbstractFactory
{
public:
	ConcreteFactory2()
	{
		cout << "Create ConcreteFactory2" << endl;
	}

	AbstractProductA* CreateProductA(const std::string name) override
	{
		return new ProductA2(name);
	}
	AbstractProductB* CreateProductB(const std::string name) override
	{
		return new ProductB2(name);
	}
};

int main()
{
	AbstractFactory* factory1 = new ConcreteFactory1();
	const AbstractProductA* productA1 = factory1->CreateProductA("PA1");
	const AbstractProductB* productB1 = factory1->CreateProductB("PB1");
	productA1->Show();
	productB1->Show();

	AbstractFactory* factory2 = new ConcreteFactory2();
	const AbstractProductA* productA2 = factory2->CreateProductA("PA2");
	const AbstractProductB* productB2 = factory2->CreateProductB("PB2");
	productA2->Show();
	productB2->Show();

	delete productA1;
	delete productA2;
	delete productB1;
	delete productB2;
	delete factory1;
	delete factory2;

	return 0;
}