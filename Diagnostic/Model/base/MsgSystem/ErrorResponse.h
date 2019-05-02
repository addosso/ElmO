//
// Created by Fortunato Rosa on 2019-02-21.
//

#ifndef DIAGNOSTICAPP_ERRORRESPONSE_H
#define DIAGNOSTICAPP_ERRORRESPONSE_H

#include "Response.h"

class ErrorResponse : public Response {
public:
    ErrorResponse() : Response("resp_type", "Error"){

    }
    void set_error_msg(const string &error_msg){
        Response::set_information("err_msg", error_msg);
    }

};
#endif //DIAGNOSTICAPP_ERRORRESPONSE_H
