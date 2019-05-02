//
// Created by Fortunato Rosa on 2019-03-01.
//

#include "../../base/Command.h"

#ifndef DIAGNOSTICAPP_SIMPLECOMMAND_H
#define DIAGNOSTICAPP_SIMPLECOMMAND_H

#endif //DIAGNOSTICAPP_SIMPLECOMMAND_H

class SimpleCommand : public Command{
    const std::string END_LINE = "\x0d";
    std::string text;
public:
    SimpleCommand(const std::string text) : text{text}
    {
    }
    std::string get_text_command() override {
        return text + END_LINE;
    }
};