//
// Created by Fortunato Rosa on 2019-02-04.
//

#ifndef DIAGNOSTICAPP_REQUEST_H
#define DIAGNOSTICAPP_REQUEST_H

#include <string>
#include "../Command.h"

struct Request {

private:
    std::string time;
    std::string request_type;
    Command* command;
public:
    Request(Command* command) : command(command) {};

    ~Request()
    {
    }

    Command* get_command(){
        return command;
    }

};

#endif //DIAGNOSTICAPP_REQUEST_H
