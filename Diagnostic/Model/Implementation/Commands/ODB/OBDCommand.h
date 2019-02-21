//
// Created by Fortunato Rosa on 2019-02-11.
//

#ifndef DIAGNOSTICAPP_OBDCOMMAND_H
#define DIAGNOSTICAPP_OBDCOMMAND_H


#include <vector>
#include "../AT/ATCommand.h"

struct OBDHeader{
    char priority_0;
    char priority_1;
    char receiver_0;
    char receiver_1;    //TA
    char transmitter_0; //SA
    char transmitter_1;

    OBDHeader(char priority_0, char priority_1, char receiver_0, char receiver_1, char transmitter_0,
                         char transmitter_1) : priority_0(priority_0), priority_1(priority_1), receiver_0(receiver_0),
                                               receiver_1(receiver_1), transmitter_0(transmitter_0),
                                               transmitter_1(transmitter_1) {}
};

struct OBDPayload{
    const static int PAYLOAD_SIZE = 14;
    char payload[PAYLOAD_SIZE] = {
            0,0,0,0,0,0,0,
            0,0,0,0,0,0,0
    };

    OBDPayload(char *pay)  {
        size_t str_len = strlen(pay);
        for(int i=0; i<=str_len; i++){
            if(i == PAYLOAD_SIZE) break ;
            payload[i] = pay[i];
        }
    }


};

class OBDCommand : public ATCommand{
private:
    OBDHeader obd_header;
    OBDPayload obd_payload;
public:
    OBDCommand(const OBDHeader &header, const OBDPayload &payload);

    std::string get_text_command() override;

};


#endif //DIAGNOSTICAPP_OBDCOMMAND_H
