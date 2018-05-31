#include "SandBlox.hpp"
#include "globalVars.hpp"

#define BOLD_GREEN pawlib::ta_bold << pawlib::fg_green

int main()
{
	//temp logging until we get Pawlib's loggers working
	pawlib::ioc << BOLD_GREEN << "Starting SandBlox Client." << pawlib::io_end;

	g_Client = std::unique_ptr<SandBlox>( new SandBlox() );

	g_Client->run();

	pawlib::ioc << BOLD_GREEN << "Exiting SandBlox Client." << pawlib::io_end;
	return 0;
}
