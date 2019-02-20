//
// Created by Fortunato Rosa on 2019-02-03.
//

#ifndef DIAGNOSTICAPP_ELM327WLANVCI_H
#define DIAGNOSTICAPP_ELM327WLANVCI_H

#include "../base/WLAN/WLanVCI.h"




class Elm327WLanVCI : public WLanVCI {
private:

public:

    Elm327WLanVCI(IPUtils::IP_ADDRESS ip_add):  WLanVCI{ip_add}
    {
    }

    virtual ~Elm327WLanVCI();

    bool connect() override;

    bool disconnect() override;

    Response transmit_message(Request &req);


};


#endif //DIAGNOSTICAPP_ELM327WLANVCI_H
