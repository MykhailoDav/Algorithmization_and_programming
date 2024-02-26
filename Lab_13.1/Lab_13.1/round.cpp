#include "var.h"
#include <math.h>
#include "round.h"
using namespace std;
using namespace nsVar;
double nsRoundToNDigits::roundToNDigits()
{
	double factor = pow(10, 2);
	return round(x * factor) / factor;
}
