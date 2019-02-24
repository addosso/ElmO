//
// Created by Fortunato Rosa on 2019-02-13.
//

#ifndef DIAGNOSTICAPP_ERRORMESSAGEFACTORY_H
#define DIAGNOSTICAPP_ERRORMESSAGEFACTORY_H


#include "../../../base/MsgSystem/ErrorResponse.h"
#include "ErrorMessageDef.h"

class ErrorMessageFactory {
public:
    static ErrorResponse create_error(Error_type error_type);
};


#endif //DIAGNOSTICAPP_ERRORMESSAGEFACTORY_H
