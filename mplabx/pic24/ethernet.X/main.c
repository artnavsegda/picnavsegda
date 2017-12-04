#define THIS_IS_STACK_APPLICATION
#include "TCPIP Stack/TCPIP.h"
#include "main.h"

APP_CONFIG AppConfig;
BYTE AN0String[8];

int main(void)
{
    StackInit();
    
    while(1)
    {
        StackTask();
        StackApplications();
        
        #if defined(STACK_USE_GENERIC_TCP_CLIENT_EXAMPLE)
        GenericTCPClient();
        #endif

        #if defined(STACK_USE_GENERIC_TCP_SERVER_EXAMPLE)
        GenericTCPServer();
        #endif

        #if defined(STACK_USE_MODBUS_TCP_SERVER)
		MODBUSTCPServer();
		#endif

        #if defined(STACK_USE_BERKELEY_API)
        BerkeleyTCPClientDemo();
        BerkeleyTCPServerDemo();
        BerkeleyUDPClientDemo();
        #endif
    }
    
    return 0;
}
