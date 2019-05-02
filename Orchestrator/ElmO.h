//
// Created by Fortunato Rosa on 2019-02-20.
//

#ifndef DIAGNOSTICAPP_ELMO_H
#define DIAGNOSTICAPP_ELMO_H


#include "../Diagnostic/Model/base/Ecu.h"
#include "../Diagnostic/VCI/Implementation/Elm327WLanVCI.h"

class ElmO {
private:
    Elm327WLanVCI elm327WLanVCI;
   // ResponseParser resp_parser;

public:
    ElmO(const Elm327WLanVCI& wlan);
    ElmO(IPUtils::IP_ADDRESS ip_address);
    void diagnose_ecu(const Ecu &ecu, const string mode, const string payload);
    void send_silent_command(Command* cmd);
    Response send_command(Command cmd);

};


#endif //DIAGNOSTICAPP_ELMO_H
