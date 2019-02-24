//
// Created by Fortunato Rosa on 2019-02-13.
//

#include "ErrorMessageFactory.h"

ErrorResponse ErrorMessageFactory::create_error(Error_type error_type) {

        ErrorResponse resp;
        switch(error_type){
            case Error_type::BUFFER_FULL      : resp.set_error_msg(Error::Descriptions::BUFFER_FULL); break;
            case Error_type::BUS_BUSY         : resp.set_error_msg(Error::Descriptions::BUS_BUSY); break;
            case Error_type::BUS_ERROR        : resp.set_error_msg(Error::Descriptions::BUS_ERROR); break;
            case Error_type::CAN_ERROR        : resp.set_error_msg(Error::Descriptions::CAN_ERROR); break;
            case Error_type::DATA_ERROR       : resp.set_error_msg(Error::Descriptions::DATA_ERROR); break;
            case Error_type::MINOR_DATA_ERROR : resp.set_error_msg(Error::Descriptions::MINOR_DATA_ERROR); break;
            case Error_type::ERRxx            : resp.set_error_msg(Error::Descriptions::ERRxx); break;
            case Error_type::FB_ERROR         : resp.set_error_msg(Error::Descriptions::FB_ERROR); break;
            case Error_type::LV_RESET         : resp.set_error_msg(Error::Descriptions::LV_RESET); break;
            case Error_type::NO_DATA          : resp.set_error_msg(Error::Descriptions::NO_DATA); break;
            case Error_type::MINOR_RX_ERROR   : resp.set_error_msg(Error::Descriptions::MINOR_RX_ERROR); break;
            case Error_type::STOPPED          : resp.set_error_msg(Error::Descriptions::STOPPED); break;
            case Error_type::UNABLE_TO_CONNECT: resp.set_error_msg(Error::Descriptions::UNABLE_TO_CONNECT); break;
            default                           : resp.set_error_msg(""); break;
        }
        return resp;

}

