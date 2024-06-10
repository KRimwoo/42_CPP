#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
        std::cout << "=====BureaucratA working with FormA, FormB=====" << std::endl;
        Bureaucrat bureaucratA("BureaucratA", 44);
        Form formA("FormA", 45, 40);
		Form formB("FormB", 160, 120);

        std::cout << bureaucratA;
        std::cout << formA;
        std::cout << formB;

        bureaucratA.signForm(formA);
        bureaucratA.signForm(formB);
        std::cout << formA << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	try {
        std::cout << "\n=====BureaucratB working with FormC=====" << std::endl;
        Bureaucrat bureaucratB("BureaucratB", 121);
        Form formC("FormC", 120, 100);

        std::cout << bureaucratB;

        std::cout << "=====Before signing FormC=====\n";
        std::cout << formC;

        bureaucratB.signForm(formC);

		bureaucratB.increaseGrade();
        std::cout << bureaucratB;
		bureaucratB.signForm(formC);
	}
	catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	return 0;
}