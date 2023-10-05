#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern mel;
	{
	// Tests wrong name
		try
		{
			/*AForm *bocal = mel.makeForm("RobotomyRequestForm", "bocal");
			std::cout << bocal->getName() << std::endl;
			Bureaucrat tac("Tac", 1);
			bocal->beSigned(tac);
			tac.executeForm(*bocal);
			delete bocal;*/
			AForm *bocal = mel.makeForm("ShrubberyC reationForm", "bocal");
			if (bocal == NULL)
				std::cout << "clean it" << std::endl;
			AForm *boc = mel.makeForm("ShrubberyCreationForm", "bocal");
			std::cout << "the name of boc is : " << boc->getName() << std::endl;
			Bureaucrat tac("Tac", 1);
			boc->beSigned(tac);
			tac.executeForm(*boc);
			delete bocal;
			delete boc;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
