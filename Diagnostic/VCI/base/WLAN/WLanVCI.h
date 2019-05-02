//
// Created by Fortunato Rosa on 2019-02-03.
//

#ifndef DIAGNOSTICAPP_WLANVCI_H
#define DIAGNOSTICAPP_WLANVCI_H


#include "../BaseVehicleCommunicationInterface.h"
#include "IPUtils.h"
#include <boost/asio.hpp>


using namespace boost::asio;
using ip::tcp;

class WLanVCI : public BaseVehicleCommunicationInterface {
private:
    IPUtils::IP_ADDRESS ip_addr;
    tcp::socket* socket;
public:
    WLanVCI(IPUtils::IP_ADDRESS ip_add) : ip_addr{std::move(ip_add)}, BaseVehicleCommunicationInterface()
    {
    }


    Response transmit_message(Request req) override
    {
        switch(get_status()){
            case Status::DISCONNECTED:  return Response{"msg","Disconnected Device: Impossible to transmit messages"}; break;
            case Status::ERR_CONN: return Response{"msg","Error Connection: Impossible to transmit messages"}; break;
        }
        Response respo;
        boost::asio::streambuf receive_buffer;
        boost::system::error_code error;
        std::string command_text = req.get_command()->get_text_command();
        boost::asio::write( *socket, boost::asio::buffer(command_text), error );
        if( !error ) {
#if defined ELM_DEBUG
            std::cout << "Sending message.." << std::endl;
#endif
        }
        else {
#if defined ELM_DEBUG
            std::cout << "send failed: " << error.message() << std::endl;
#endif
            return Response{"msg","Communication Error: Impossible to transmit message"};
        }

            boost::asio::read(*socket, receive_buffer, boost::asio::transfer_all(), error);
            if (error && error != boost::asio::error::eof) {
#if defined ELM_DEBUG
                std::cout << "receive failed: " << error.message() << std::endl;
#endif
                return Response{"msg", "Communication Error: Impossible to read the message"};
            } else {
                const char *data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
                respo.set_information("msg", string(data));
#if defined ELM_DEBUG
                std::cout << data << std::endl;
#endif

        }
        return respo;
    }


    bool connect() override {

        boost::asio::io_service io_service;
        socket = new tcp::socket(io_service);
        try{
            socket->connect( tcp::endpoint( boost::asio::ip::address::from_string(getIp_addr().ip_address), getIp_addr().port ));
        }catch(...){
#if defined ELM_DEBUG
            std::cout << "Connection failed" << std::endl;
#endif
            status = Status::ERR_CONN;
            return false;
        }
        status = Status::CONNECTED;
        return true;
    }

    bool disconnect() override {
        status = Status::DISCONNECTED;
        return true;
    }

    const IPUtils::IP_ADDRESS &getIp_addr() const {
        return ip_addr;
    }
    void setIp_addr(const IPUtils:: IP_ADDRESS &ip_addr) {
        WLanVCI::ip_addr = ip_addr;
    }


};


#endif //DIAGNOSTICAPP_WLANVCI_H
