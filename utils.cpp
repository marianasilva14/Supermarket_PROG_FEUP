#include "utils.h"
#include <stdlib.h>

void clearScreen()
{

	if (system("CLS"))
		system("clear");
}

