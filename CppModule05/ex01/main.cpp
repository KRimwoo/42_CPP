#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
        Bureaucrat bureaucratA("BureaucratA", 44);
        Form formA("FormA", 45, 40);
		Form formB("FormB", 160, 120);

        std::cout << bureaucratA;
        std::cout << formA;

        bureaucratA.signForm(formA);
        std::cout << formA << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	try {
        Bureaucrat bureaucratB("BureaucratB", 121);
        Form formC("FormC", 120, 100);
        bureaucratB.signForm(formC);
		bureaucratB.increaseGrade();
		bureaucratB.signForm(formC);
	}
	catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	return 0;
}