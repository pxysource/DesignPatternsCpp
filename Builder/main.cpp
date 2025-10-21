//
// Created by pxy on 2025/10/21.
//

#include <iostream>
#include <utility>

using std::cout;
using std::endl;

class ProductPart1
{
public:
	explicit ProductPart1(std::string  name) : _name(std::move(name))
	{

	}
	std::string GetName() const
	{
		return _name;
	}
private:
	std::string _name;
};

class ProductPart2
{
public:
	explicit ProductPart2(std::string  name) : _name(std::move(name))
	{

	}
	std::string GetName() const
	{
		return _name;
	}
private:
	std::string _name;
};

class ProductPart3
{
public:
	explicit ProductPart3(std::string name) : _name(std::move(name))
	{

	}
	std::string GetName() const
	{
		return _name;
	}
private:
	std::string _name;
};

class Product
{
public:
	Product() : _part1(nullptr), _part2(nullptr), _part3(nullptr)
	{

	}
	~Product()
	{
		delete _part1;
		delete _part2;
		delete _part3;
	}
	void SetPart1(ProductPart1* part1)
	{
		_part1 = part1;
	}
	void SetPart2(ProductPart2* part2)
	{
		_part2 = part2;
	}
	void SetPart3(ProductPart3* part3)
	{
		_part3 = part3;
	}
	void Show() const
	{
		cout << "Product: ";
		if (_part1)
		{
			cout << _part1->GetName() << " ";
		}
		if (_part2)
		{
			cout << _part2->GetName() << " ";
		}
		if (_part3)
		{
			cout << _part3->GetName() << endl;
		}
	}
private:
	ProductPart1* _part1;
	ProductPart2* _part2;
	ProductPart3* _part3;
};

class Builder
{
public:
	Builder() : _product(new Product())
	{

	}
	virtual ~Builder() = default;

	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
	virtual void BuildPart3() = 0;

	virtual Product* GetResult()
	{
		return _product;
	}
protected:
	Product* _product;
};

class ConcreteBuilder final : public Builder
{
public:
	void BuildPart1() override
	{
		_product->SetPart1(new ProductPart1("Part1"));
	}
	void BuildPart2() override
	{
		_product->SetPart2(new ProductPart2("Part2"));
	}
	void BuildPart3() override
	{
		_product->SetPart3(new ProductPart3("Part3"));
	}
};

class Director
{
public:
	Director() : _builder(nullptr)
	{

	}
	void SetBuilder(Builder* builder)
	{
		_builder = builder;
	}
	Product* Construct() const
	{
		if (!_builder)
		{
			return nullptr;
		}

		_builder->BuildPart1();
		_builder->BuildPart2();
		_builder->BuildPart3();
		return _builder->GetResult();
	}
private:
	Builder* _builder;
};

int main()
{
	Builder* builder = new ConcreteBuilder();
	Director director;
	director.SetBuilder(builder);
	const Product* product = director.Construct();
	product->Show();

	delete product;
	delete builder;

	return 0;
}