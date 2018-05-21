#include <cstdio>
#include <memory>
#include "SandBlox.hpp"
#include "globalVars.hpp"

int main()
{
	//temp logging until we get Pawlib's loggers working
	printf("Starting SandBlox Client.\n");
	
	g_Client = std::unique_ptr<SandBlox>(new SandBlox());
	
	g_Client->run();
	
	printf("Exiting SandBlox Client.\n");
	return 0;
}
