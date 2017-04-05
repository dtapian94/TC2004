
#include <map>
#include <iostream>
using namespace std;

class DNSServer {
protected:
    
    DNSServer * server;
    string name;
    map<string, string> dnsList;

public:
    DNSServer(string name){
        this->name = name;
    }
    DNSServer(string name, DNSServer & next){
        this->name = name;
        server = &next;
    }

    void setServer(DNSServer & next){
        server = &next;
    }

    void addDomain(string domain,string ip){
        dnsList[domain] = ip;
    }

    string processRequest(string domain){
        string response;
        try {
            return name + ": " + domain + "\n Direccion IP:  -> " + dnsList.at(domain);
            
            }
        catch (out_of_range)
            {
            if(server != nullptr){
                return server->processRequest(domain);
            }
            else
            {
                return name + ": NO DNS RECORD FOUND";
            
            }
        }
    }

};
