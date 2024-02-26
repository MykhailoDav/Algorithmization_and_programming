#include "dod.h"
#include "var.h" // підключили зовнішні оголошення змінних
using namespace nsVar;
void nsDod::dod() 
{
	a *= -(2.0 * n - 1) * x * x / (2.0 * n + 1); // доданок домножується на 
}				// коефіцієнт рекурентності