//
// Created by Fortunato Rosa on 2019-02-06.
//

#include "ATCommand.h"

std::string ATCommand::get_text_command() {
    string result_message = COMMAND_PREFIX + " " + specific_command + END_LINE;
    return result_message;
}


