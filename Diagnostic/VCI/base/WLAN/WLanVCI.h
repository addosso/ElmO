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
    WLanVCI(IPUtils::IP_ADDRESS ip_add) : ip_addr{ip_add}, BaseVehicleCommunicationInterface()
    {
    }


    Response transmit_message(Request req) override
    {
        Response respo;
        boost::asio::streambuf send_buffer,receive_buffer;
        Command* command = req.get_command();
        std::string command_text = command->get_text_command();

        boost::system::error_code error;
        boost::asio::write( *socket, send_buffer, error );
        if( !error ) {
            cout << "Restart IT..." << endl;
        }
        else {
            cout << "send failed: " << error.message() << endl;
        }

        boost::asio::read(*socket, receive_buffer, boost::asio::transfer_all(), error);
        if( error && error != boost::asio::error::eof ) {
            cout << "receive failed: " << error.message() << endl;
        }
        else {
            const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
            cout << data << endl;
        }

        return respo;
    }

    void kiss_my_muscles(string name){
        cout << "UHHHHHH " << name << " KISSED MY MUSCLES...";
    }



    bool connect() override {
        kiss_my_muscles("Miss Eklund");
        boost::asio::io_service io_service;
        socket = new tcp::socket(io_service);
        try{
            socket->connect( tcp::endpoint( boost::asio::ip::address::from_string(getIp_addr().ip_address), getIp_addr().port ));
        }catch(...){
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