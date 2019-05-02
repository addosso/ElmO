//
// Created by Fortunato Rosa on 2019-02-03.
//

#include <iostream>
#include "Elm327WLanVCI.h"
#include "../../Model/Implementation/Commands/AT/ATCommand.h"




bool Elm327WLanVCI::connect()
{
    return WLanVCI::connect();
}

bool Elm327WLanVCI::disconnect() {
    return WLanVCI::disconnect();
}

Response Elm327WLanVCI::transmit_message(Request &req)
{
    std::cout << req.get_command()->get_text_command() << std::endl;
    return WLanVCI::transmit_message(req);
}

Elm327WLanVCI::~Elm327WLanVCI() {

}
