//
// Created by Fortunato Rosa on 2019-02-06.
//

#ifndef DIAGNOSTICAPP_ATCOMMAND_H
#define DIAGNOSTICAPP_ATCOMMAND_H


#include "../../../base/Command.h"

using namespace std;

class ATCommand : public Command{
    ATCommand* next;
private:
    const std::string COMMAND_PREFIX = "AT";
    std::string specific_command = "";
public:
    void add_command(ATCommand* cmd);

    ATCommand(const string command) : specific_command(command) {};
    std::string get_text_command() override;
};


#endif //DIAGNOSTICAPP_ATCOMMAND_H
