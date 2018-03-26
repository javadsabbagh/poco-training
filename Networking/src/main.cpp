#include <iostream>
#include <Poco/Net/DNS.h>

using Poco::Net::DNS;
using Poco::Net::IPAddress;
using Poco::Net::HostEntry;
int main(int argc, char** argv)
{
    const HostEntry& entry = DNS::hostByName("www.appinf.com");
    std::cout << "Canonical Name: " << entry.name() << std::endl;

    const HostEntry::AliasList& aliases = entry.aliases();
    HostEntry::AliasList::const_iterator aliasIter = aliases.begin();
    for (; aliasIter != aliases.end(); ++aliasIter)
        std::cout << "Alias: " << *aliasIter << std::endl;

    const HostEntry::AddressList& addrs = entry.addresses();
    HostEntry::AddressList::const_iterator addrIter = addrs.begin();
    for (; addrIter != addrs.end(); ++addrIter)
        std::cout << "Address: " << addrIter->toString() << std::endl;

    return 0;
}
