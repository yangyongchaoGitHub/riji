#include <iostream>
#include "module_interface.h"

using namespace std;
int main() {
	ModuleInterface module;
	module.init();
	module.run();
	module.stop();
	return 0;
}
