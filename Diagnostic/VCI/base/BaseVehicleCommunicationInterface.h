//
// Created by Fortunato Rosa on 2019-02-03.
//

#ifndef DIAGNOSTICAPP_BASEVEHICLECOMMUNICATIONINTERFACE_H
#define DIAGNOSTICAPP_BASEVEHICLECOMMUNICATIONINTERFACE_H

#include "WLAN/Status.h"
#include "../../Model/base/MsgSystem/Message.h"
#include "../../Model/base/MsgSystem/Request.h"
#include "../../Model/base/MsgSystem/Reponse.h"

class BaseVehicleCommunicationInterface {

protected:
    Status status;
public:
    BaseVehicleCommunicationInterface(): status{Status::IDLE}
    {
    }
    virtual bool connect() = 0;
    virtual bool disconnect() = 0;
    virtual Status get_status() { return status; };
    virtual Response transmit_message(Request req) = 0;

};


#endif //DIAGNOSTICAPP_BASEVEHICLECOMMUNICATIONINTERFACE_H
