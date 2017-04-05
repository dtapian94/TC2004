// A01022285
//  main.cpp
//  cadenaDeResponsabilidad
//
//  Created by Daniel Esteban Tapia Nava on 05/04/17.
//  Copyright © 2017 Daniel Esteban Tapia Nava. All rights reserved.
//


#include <iostream>
#include "DNSServer.h"

using namespace std;

void prtReq(DNSServer & dnsServer, std::string domain){
    cout << dnsServer.processRequest(domain) << endl; }

int main(int argc, const char * argv[])
    {
    
    cout << "TEST del funcionamiento del programa:" << endl;
    cout <<""<<endl;
    
    DNSServer dns1("DNS1");
    DNSServer dns2("DNS2", dns1);
    DNSServer dns3("DNS3", dns2);
    DNSServer dns4("DNS4", dns3);
    DNSServer dns5("DNS5", dns4);
    
    dns1.addDomain("google.com", "201.151.207.57");
    dns1.addDomain("kickstarter.com", "54.230.7.4");
    dns1.addDomain("microsoft.com", "191.239.213.197");
    dns1.addDomain("9gag.com", "54.67.73.213");
    
    
    dns2.addDomain("facebook.com", "31.13.66.36");
    dns2.addDomain("instagram.com", "52.1.180.175");
    dns2.addDomain("udemy.com", "104.20.64.82");
    
    
    dns3.addDomain("snapchat.com", "54.230.7.5");
    dns3.addDomain("wikipedia.org", "208.80.153.224");
    dns3.addDomain("pelispedia.tv", "104.20.72.45");
    
    dns4.addDomain("tec.mx", "104.210.149.110");
    dns4.addDomain("youtube.com", "201.151.207.57");
    dns4.addDomain("desmos.com", "174.129.194.81");
    
    
    dns5.addDomain("amazon.com", "54.239.25.192");
    dns5.addDomain("netflix.com", "107.21.48.181");
    dns5.addDomain("ebay.com", "66.211.181.123");
    
    
    
    prtReq(dns5, "google.com");
    prtReq(dns5, "kickstarter.com");
    prtReq(dns5, "instagram.com");
    prtReq(dns5, "microsoft.com");
    prtReq(dns5, "gmail.com");
    prtReq(dns5, "netflix.com");
    prtReq(dns5, "wikipedia.org");
    prtReq(dns4, "ebay.com");
    prtReq(dns3, "youtube.com");
        
    cout<<""<<endl;
    
    return 0;
    
}
