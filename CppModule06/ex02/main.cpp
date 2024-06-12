#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base	*generate(void)
{
	Base *basePtr;
	int randNum = rand() % 3;

	if (randNum == 0)
		basePtr = new A;
	else if (randNum == 1)
		basePtr = new B;
	else
		basePtr = new C;
	
	return basePtr;
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer's type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer's type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer's type is C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Reference's type is A" << std::endl;
	}
	catch(const std::exception &e)
	{}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Reference's type is B" << std::endl;
	}
	catch(const std::exception &e)
	{}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Reference's type is C" << std::endl;
	}
	catch(const std::exception &e)
	{}
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base *basePtr = generate();
		identify(basePtr);
		identify(*basePtr);
		delete basePtr;
		std::cout << std::endl;
	}
	return 0;
}