//
// Created by Fortunato Rosa on 2019-02-11.
//

#include "OBDCommand.h"

std::string OBDCommand::get_text_command() {
    string odb_header_string = odb_header.priority_0 + odb_header.priority_1 + odb_header.receiver_0 + " ";
    return odb_header_string;
}

OBDCommand::OBDCommand(const ODBHeader &header) : odb_header(header) {}

