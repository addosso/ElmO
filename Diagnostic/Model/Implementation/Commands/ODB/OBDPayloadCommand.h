//
// Created by Fortunato Rosa on 2019-02-25.
//

#ifndef DIAGNOSTICAPP_OBDPAYLOADMESSAGE_H
#define DIAGNOSTICAPP_OBDPAYLOADMESSAGE_H

#include <vector>
#include "../../../base/Command.h"
#include "../SimpleCommand.h"

struct OBDPayload{
private:
    const static int PAYLOAD_SIZE = 14;
    char payload[PAYLOAD_SIZE+1] = {
            0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0
    };

public:
    explicit OBDPayload(const char *pay)  {
        size_t str_len = strlen(pay);
        for(int i=0; i<=str_len; i++){
            if(i == PAYLOAD_SIZE) break;
            payload[i] = pay[i];
        }
    }
    std::string to_string() const {
        return  std::string(payload);
    }
};

class OBDPayloadCommand : public SimpleCommand {
    OBDPayload obd_pl;
public:
    explicit OBDPayloadCommand(const OBDPayload& obd_p): obd_pl(obd_p), SimpleCommand{obd_p.to_string()} {};
};


#endif //DIAGNOSTICAPP_OBDPAYLOADMESSAGE_H
