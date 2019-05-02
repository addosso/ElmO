//
// Created by Fortunato Rosa on 2019-02-03.
//

#ifndef DIAGNOSTICAPP_ECU_H
#define DIAGNOSTICAPP_ECU_H

#include <string>
#include <vector>

using namespace std;

class Ecu {
    string name;
    string phisical_address;
    vector<string> available_modes;
    string priority;
public:
    Ecu(const string &name, const string& address, const string& priority)
    : name(name), phisical_address(address), priority(priority)
    {
    }

    bool insert_mode(const string mode) {
        if(find(available_modes.begin(),available_modes.end(), mode) != available_modes.end())
        {
            available_modes.push_back(mode);
            return true;
        }
        return false;
    }

    const string &getPriority() const {
        return priority;
    }

    const string &getName() const {
        return name;
    }

    const string &getPhisical_address() const {
        return phisical_address;
    }

    const vector<string> &getAvailable_modes() const {
        return available_modes;
    }


};
#endif //DIAGNOSTICAPP_ECU_H
