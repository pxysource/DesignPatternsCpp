//
// Created by pxy on 2025/10/17.
//

#include <iostream>
#include <utility>

using std::cout;
using std::endl;

class Product
{
protected:
	std::string Name;

public:
	explicit Product(std::string name) : Name(std::move(name))
	{
	}
	virtual ~Product() = default;

	virtual void show() const
	{
		cout << "Product: " << Name << endl;
	}
};

class ConcreteProductA final : public Product
{
public:
	explicit ConcreteProductA(std::string name) : Product(std::move(name))
	{
		cout << "Create ConcreteProductA: " << Name << endl;
	}
};

class ConcreteProductB final : public Product
{
public:
	explicit ConcreteProductB(std::string name) : Product(std::move(name))
	{
		cout << "Create ConcreteProductB: " << Name << endl;
	}
};

class Factory
{
public:
	Factory() = default;
	virtual ~Factory() = default;
	virtual Product* CreateProduct() = 0;
};

class ConcreteFactoryA final : public Factory
{
public:
	Product* CreateProduct() override
	{
		return new ConcreteProductA("PA");
	}
};

class ConcreteFactoryB final : public Factory
{
public:
	Product* CreateProduct() override
	{
		return new ConcreteProductB("PB");
	}
};

int main()
{
	Factory* factoryA = new ConcreteFactoryA();
	Factory* factoryB = new ConcreteFactoryB();
	const Product* productA = factoryA->CreateProduct();
	const Product* productB = factoryB->CreateProduct();
	productA->show();
	productB->show();

	delete productA;
	delete productB;
	delete factoryA;
	delete factoryB;

	return 0;
}
