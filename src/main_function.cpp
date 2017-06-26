#include "main_function.h"
#include <iostream>
#include "PcapLiveDeviceList.h"

int main_function(int argc, char** argv)
{
    // IPv4 address of the interface we want to sniff
    std::string interfaceIPAddr = (argc > 1)? argv[1] : "0.0.0.0";

    // find the interface by IP address
    pcpp::PcapLiveDevice* dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(interfaceIPAddr.c_str());
    if (dev == nullptr)
    {
        std::cerr << "Cannot find interface with IPv4 address of " << interfaceIPAddr << "\n";
        return 1;
    }

    // before capturing packets let's print some info about this interface
    std::cout << "Interface info:\n";
    // get interface name
    std::cout << "   Interface name:        " << dev->getName() << "\n";
    // get interface description
    std::cout << "   Interface description: " << dev->getDesc() << "\n";
    // get interface MAC address
    std::cout << "   MAC address:           " << dev->getMacAddress().toString() << "\n";
    // get default gateway for interface
    std::cout << "   Default gateway:       " << dev->getDefaultGateway().toString() << "\n";
    // get interface MTU
    std::cout << "   Interface MTU:         " << dev->getMtu() << "\n";
    // get DNS server if defined for this interface
    if (dev->getDnsServers().size() > 0) {
        std::cout << "   DNS server:            " << dev->getDnsServers().at(0).toString() << "\n";
    }

    return 0;
}
