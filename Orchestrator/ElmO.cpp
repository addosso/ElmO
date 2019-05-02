//
// Created by Fortunato Rosa on 2019-02-20.
//

#include "ElmO.h"
#include "../Diagnostic/Model/Implementation/Commands/ODB/OBDHeaderCommand.h"
#include "../Diagnostic/Model/Implementation/Commands/ODB/OBDPayloadCommand.h"

void ElmO::diagnose_ecu(const Ecu &ecu, const string mode, const string payload) {
    OBDHeader obd_h{ecu.getPriority()[0],ecu.getPriority()[1],
                    ecu.getPhisical_address()[0], ecu.getPhisical_address()[1],
                    elm327WLanVCI.DEVICE_ADDRESS[0], elm327WLanVCI.DEVICE_ADDRESS[1]};
    OBDHeaderCommand odb_h_cmd{obd_h};
    Request set_header_req{&odb_h_cmd};
    elm327WLanVCI.transmit_message(set_header_req);

    std::string payl = std::string(mode+payload);
    OBDPayload obd_p{payl.c_str()};
    OBDPayloadCommand odb_p_cmd{obd_p};
    Request payload_msg{&odb_p_cmd};
    elm327WLanVCI.transmit_message(payload_msg);
}

ElmO::ElmO(const Elm327WLanVCI &wlan) : elm327WLanVCI{wlan}
{
    elm327WLanVCI.connect();
}

ElmO::ElmO(const IPUtils::IP_ADDRESS ip_address): elm327WLanVCI{ip_address}
{
    elm327WLanVCI.connect();
}

void ElmO::send_silent_command(Command* cmd) {
    Request req{cmd};
    elm327WLanVCI.transmit_message(req);
}

