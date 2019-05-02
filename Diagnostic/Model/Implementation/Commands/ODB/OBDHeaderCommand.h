//
// Created by Fortunato Rosa on 2019-02-25.
//

#ifndef DIAGNOSTICAPP_OBDHEADERCOMMAND_H
#define DIAGNOSTICAPP_OBDHEADERCOMMAND_H

#include "../../../base/Command.h"
#include "../AT/ATCommand.h"

struct OBDHeader{
    char priority_0;
    char priority_1;
    char receiver_0;
    char receiver_1;    //TA
    char transmitter_0; //SA
    char transmitter_1;

    OBDHeader(char priority_0, char priority_1, char receiver_0, char receiver_1, char transmitter_0, char transmitter_1)
    : priority_0(priority_0), priority_1(priority_1),
      receiver_0(receiver_0),receiver_1(receiver_1),
      transmitter_0(transmitter_0),transmitter_1(transmitter_1)
      {
      }

      string to_string() const {
        char header[] =  {priority_0, priority_1,
                          receiver_0, receiver_1,
                          transmitter_0, transmitter_1, 0};
        string hd(header);
        return hd;
    }
};


class OBDHeaderCommand : public ATCommand {
    OBDHeader obd_header;
public:
    OBDHeaderCommand(const OBDHeader &obd_h);

};


#endif //DIAGNOSTICAPP_OBDHEADERCOMMAND_H
