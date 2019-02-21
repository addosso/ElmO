//
// Created by Fortunato Rosa on 2019-02-11.
//

#include "OBDCommand.h"

std::string OBDCommand::get_text_command()
{
    char header[] =  {obd_header.priority_0, obd_header.priority_1,
                   obd_header.receiver_0, obd_header.receiver_1,
                   obd_header.transmitter_0, obd_header.transmitter_1, 0};
    string hd(header);
    string odb_pay(obd_payload.payload);

    return ATCommand::get_text_command() + " " + hd + " " + odb_pay + "\x0d";
}

OBDCommand::OBDCommand(const OBDHeader &header,  const OBDPayload &payload)
            : ATCommand("SH"), obd_header(header), obd_payload(payload)
    {

    }


