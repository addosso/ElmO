//
// Created by Fortunato Rosa on 2019-02-13.
//

#ifndef DIAGNOSTICAPP_ERRORMESSAGEDEF_H
#define DIAGNOSTICAPP_ERRORMESSAGEDEF_H
#include <string>

enum class Error_type{
    BUFFER_FULL,
    BUS_BUSY,
    BUS_ERROR,
    CAN_ERROR,
    DATA_ERROR,
    MINOR_DATA_ERROR,
    ERRxx,
    FB_ERROR,
    LV_RESET,
    NO_DATA,
    MINOR_RX_ERROR,
    STOPPED,
    UNABLE_TO_CONNECT
};

using namespace std;

namespace Error {

    namespace Descriptions {

       const string BUFFER_FULL = "";
       const string BUS_BUSY = "";
        const string BUS_ERROR = "";
        const string CAN_ERROR = "";
        const string DATA_ERROR = "";
        const string MINOR_DATA_ERROR = "";
        const string ERRxx = "";
        const string FB_ERROR = "";
        const string LV_RESET = "";
        const string NO_DATA = "";
        const string MINOR_RX_ERROR = "";
        const string STOPPED = "";
        const string UNABLE_TO_CONNECT = "";

    }
}
#endif //DIAGNOSTICAPP_ERRORMESSAGEDEF_H
