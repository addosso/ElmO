#include <iostream>
#include "Diagnostic/VCI/Implementation/Elm327WLanVCI.h"

int main() {

    std::string ip = "192.168.0.10";
    unsigned short port = 35000;

    IPUtils::IP_ADDRESS my_ip{ip, IPUtils::IP_V4, port};

    Elm327WLanVCI my_vci{my_ip};
    my_vci.connect();

    return 0;
}