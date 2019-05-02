#define ELM_DEBUG 1

#include <iostream>
#include "Diagnostic/VCI/Implementation/Elm327WLanVCI.h"
#include "Diagnostic/Model/Implementation/Commands/ODB/OBDPayloadCommand.h"
#include "Diagnostic/Model/Implementation/Commands/ODB/OBDHeaderCommand.h"
#include "Orchestrator/ElmO.h"

int main() {

    std::string ip = "192.168.0.10";
    unsigned short port = 35000;
    IPUtils::IP_ADDRESS my_ip{ip, IPUtils::IP_V4, port};
    Elm327WLanVCI my_vci{my_ip};
    ElmO elm{my_vci};
    ATCommand read_voltage("MA");

    char fluid_temperature[14] = { '0', '1', '0','0'};
    OBDHeader header('A','8','4','8','F','1');
    OBDPayload payload(fluid_temperature);

    OBDHeaderCommand obd_h_cmd{header};
    OBDPayloadCommand obd_pl_cmd{payload};

    elm.send_silent_command(&read_voltage);
 //   elm.send_silent_command(&obd_h_cmd);
    elm.send_silent_command(&obd_pl_cmd);

    return 0;
}