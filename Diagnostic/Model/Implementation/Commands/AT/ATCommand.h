//
// Created by Fortunato Rosa on 2019-02-06.
//

#ifndef DIAGNOSTICAPP_ATCOMMAND_H
#define DIAGNOSTICAPP_ATCOMMAND_H


#include "../../../base/Command.h"

using namespace std;

class ATCommand : public Command{
protected:
    const std::string END_LINE = "\x0d";
private:
    const std::string COMMAND_PREFIX = "AT";
    std::string specific_command = "";
public:
    ATCommand(const string command) : specific_command(command) {};
    ATCommand(const string command, const string body): specific_command{command+" "+body} {};
    std::string get_text_command() override;
};


#endif //DIAGNOSTICAPP_ATCOMMAND_H
