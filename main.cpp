#include <iostream>
#include "Diagnostic/VCI/Implementation/Elm327WLanVCI.h"
#include "Diagnostic/Model/Implementation/Commands/ODB/OBDCommand.h"
int main() {

    std::string ip = "192.168.0.10";
    unsigned short port = 35000;

    IPUtils::IP_ADDRESS my_ip{ip, IPUtils::IP_V4, port};

    Elm327WLanVCI my_vci{my_ip};
    my_vci.connect();
    //ElmO::GetInstance()->init_connection_layer()
    //ElmO::GetInstance()->getConnectionPool(0);


    char fluid_temperature[14] = {'1','0'};
    OBDHeader header('A','8','4','8','F','1');
    OBDPayload payload(fluid_temperature);

    OBDCommand command(header, payload);


    Request fluid_temperature_request(&command);

    Response fluid_temp_resp = my_vci.transmit_message(fluid_temperature_request);

    cout << fluid_temp_resp.getInformation() << endl;
    return 0;
}