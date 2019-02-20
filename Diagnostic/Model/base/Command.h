//
// Created by Fortunato Rosa on 2019-02-06.
//

#ifndef DIAGNOSTICAPP_COMMAND_H
#define DIAGNOSTICAPP_COMMAND_H

#include <string>

struct Command {
private:
    std::string command_string;
public:



    virtual std::string get_text_command() = 0;
};
#endif //DIAGNOSTICAPP_COMMAND_H
