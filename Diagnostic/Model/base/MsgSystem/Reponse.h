//
// Created by Fortunato Rosa on 2019-02-04.
//

#ifndef DIAGNOSTICAPP_REPONSE_H
#define DIAGNOSTICAPP_REPONSE_H

#include <string>

using namespace std;
struct Response  {

    std::string time;
    std::string information;
public:

 Response(): time("00:01:30") {};

    const string &getInformation() const {
        return information;
    }

    void setInformation(const string &information) {
        Response::information = information;
    }

};

#endif //DIAGNOSTICAPP_REPONSE_H
