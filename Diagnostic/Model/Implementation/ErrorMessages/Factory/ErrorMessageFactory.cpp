//
// Created by Fortunato Rosa on 2019-02-13.
//

#include "ErrorMessageFactory.h"

Response ErrorMessageFactory::create_error(Error_type error_type) {

        Response resp;
        switch(error_type){
            case Error_type::BUFFER_FULL      : resp.setInformation(Error::Descriptions::BUFFER_FULL); break;
            case Error_type::BUS_BUSY         : resp.setInformation(Error::Descriptions::BUS_BUSY); break;
            case Error_type::BUS_ERROR        : resp.setInformation(Error::Descriptions::BUS_ERROR); break;
            case Error_type::CAN_ERROR        : resp.setInformation(Error::Descriptions::CAN_ERROR); break;
            case Error_type::DATA_ERROR       : resp.setInformation(Error::Descriptions::DATA_ERROR); break;
            case Error_type::MINOR_DATA_ERROR : resp.setInformation(Error::Descriptions::MINOR_DATA_ERROR); break;
            case Error_type::ERRxx            : resp.setInformation(Error::Descriptions::ERRxx); break;
            case Error_type::FB_ERROR         : resp.setInformation(Error::Descriptions::FB_ERROR); break;
            case Error_type::LV_RESET         : resp.setInformation(Error::Descriptions::LV_RESET); break;
            case Error_type::NO_DATA          : resp.setInformation(Error::Descriptions::NO_DATA); break;
            case Error_type::MINOR_RX_ERROR   : resp.setInformation(Error::Descriptions::MINOR_RX_ERROR); break;
            case Error_type::STOPPED          : resp.setInformation(Error::Descriptions::STOPPED); break;
            case Error_type::UNABLE_TO_CONNECT: resp.setInformation(Error::Descriptions::UNABLE_TO_CONNECT); break;
            default                           : resp.setInformation(""); break;
        }
        return resp;

}
