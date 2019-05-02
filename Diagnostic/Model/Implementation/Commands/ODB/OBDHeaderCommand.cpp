//
// Created by Fortunato Rosa on 2019-02-25.
//

#include "OBDHeaderCommand.h"


OBDHeaderCommand::OBDHeaderCommand(const OBDHeader &obd_h)
    :ATCommand{"SH",obd_h.to_string()}, obd_header(obd_h)
{
}
