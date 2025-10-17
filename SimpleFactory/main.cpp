#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

class Product
{
public:
	explicit Product(const std::string& name)
	{
		Name = name;
	}
	void Show() const
	{
		cout << "Product name: " << Name << endl;
	}
protected:
	std::string Name;
};

class ConcreteProductA : public Product
{
public:
	explicit ConcreteProductA(const std::string& name) : Product(name)
	{
		cout << "Create ConcreteProductA" << endl;
	}
};

class ConcreteProductB : public Product
{
public:
	explicit ConcreteProductB(const std::string& name) : Product(name)
	{
		cout << "Create ConcreteProductB" << endl;
	}
};

class Factory
{
public:
	static Product* CreateProduct(const std::string& name)
	{
		if (!name.compare("PA"))
		{
			return new ConcreteProductA(name);
		}
		else if (!name.compare("PB"))
		{
			return new ConcreteProductB(name);
		}
		else
		{
			cerr << "Unsupported product, name=" << name << "!" << endl;
			return nullptr;
		}
	}
};

int main()
{
	const auto pa = Factory::CreateProduct("PA");
	const auto pb = Factory::CreateProduct("PB");

	if (pa)
	{
		pa->Show();
	}
	if (pb)
	{
		pb->Show();
	}

	delete pa;
	delete pb;

	return 0;
}