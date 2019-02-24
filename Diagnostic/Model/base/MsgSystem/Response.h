//
// Created by Fortunato Rosa on 2019-02-04.
//

#ifndef DIAGNOSTICAPP_REPONSE_H
#define DIAGNOSTICAPP_REPONSE_H

#include <string>
#include <map>

using namespace std;
struct Response  {
    std::string time;
    std::map<string, string> information;
public:

 Response(): time("00:01:30") {};

 Response(const string& type, const string& type_val){
     information.insert(std::pair<string, string>(type, type_val));

 }
    const string &getInformation(const string &key) const {
        string info_value;
        if(information.find(key) != information.end())
            info_value = information.at(key);
        return info_value;
    }

    void setInformation(const string &key,const string &info) {
        if(information.find(key) != information.end()){}
            information.insert(std::pair<string, string>(key, info));
    }

};

#endif //DIAGNOSTICAPP_REPONSE_H
