#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat bureaucratA("bureaucratA", 1);
	Bureaucrat bureaucratB("bureaucratB", 150);
	Form form("form", false, 70, 150);

	try
	{
		std::cout << bureaucratA;
		std::cout << bureaucratB;
		std::cout << form;
		bureaucratA.signForm(form);
		std::cout << form;
		bureaucratB.signForm(form);
		std::cout << form;
		bureaucratA.signForm(form);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	return 0;
}