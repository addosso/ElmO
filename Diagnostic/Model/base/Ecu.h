//
// Created by Fortunato Rosa on 2019-02-03.
//

#ifndef DIAGNOSTICAPP_ECU_H
#define DIAGNOSTICAPP_ECU_H

#include <string>

using namespace std;

class Ecu {
    string name;
    string phisical_address;
public:
    Ecu(const string &name, const string& address)
    : name(name), phisical_address(address)
    {
    }



};
#endif //DIAGNOSTICAPP_ECU_H
