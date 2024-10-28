#include "App.h"
#include "Route.h";
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	App run;
	run.runApp();
	return 0;
}