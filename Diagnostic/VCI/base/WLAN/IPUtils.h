//
// Created by Fortunato Rosa on 2019-02-03.
//

#ifndef DIAGNOSTICAPP_IPUTILS_H
#define DIAGNOSTICAPP_IPUTILS_H

#include <string>

using namespace std;

namespace IPUtils {
    enum ip_addr_type {
        IP_V4,
        IP_V6
    };

    struct IP_ADDRESS {
        string ip_address;
        ip_addr_type ip_address_type;
        unsigned short port;
        IP_ADDRESS(const string &ip_address, ip_addr_type ip_address_type, unsigned short port) : ip_address(ip_address),
                                                                             ip_address_type(ip_address_type), port(port) {}
    };

}

#endif //DIAGNOSTICAPP_IPUTILS_H
