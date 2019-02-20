//
// Created by Fortunato Rosa on 2019-02-11.
//

#ifndef DIAGNOSTICAPP_OBDCOMMAND_H
#define DIAGNOSTICAPP_OBDCOMMAND_H


#include "../AT/ATCommand.h"

struct ODBHeader{
    char priority_0;
    char priority_1;
    char receiver_0;
    char receiver_1;    //TA
    char transmitter_0; //SA
    char transmitter_1;

    ODBHeader(char priority_0, char priority_1, char receiver_0, char receiver_1, char transmitter_0,
                         char transmitter_1) : priority_0(priority_0), priority_1(priority_1), receiver_0(receiver_0),
                                               receiver_1(receiver_1), transmitter_0(transmitter_0),
                                               transmitter_1(transmitter_1) {}
};



class OBDCommand : public ATCommand{
private:
    ODBHeader odb_header;
public:
    OBDCommand(const ODBHeader &header);

    std::string get_text_command() override;

};


#endif //DIAGNOSTICAPP_OBDCOMMAND_H
