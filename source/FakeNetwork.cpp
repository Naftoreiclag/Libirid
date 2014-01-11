#include "FakeNetwork.h"

/////////////////////////////////
// Singleton pattern
/////////////////////////////////

// Instance getting
FakeNetwork* FakeNetwork::instance;
FakeNetwork* FakeNetwork::getInstance()
{
    if(instance == NULL)
    {
        instance = new FakeNetwork();
    }

    return instance;
}

// Constructor
FakeNetwork::FakeNetwork()
{
}

// Destructor
FakeNetwork::~FakeNetwork()
{
    FakeNetwork::instance = NULL;
}

///////////////////////////////////
//
///////////////////////////////////
void FakeNetwork::sendString(int channel, std::string packet)
{
    // If the list does not exist yet
    if(stringPackets.find(channel) == stringPackets.end())
    {
        // Make it
        stringPackets.insert(
            std::pair<int, std::vector<std::string>*>(channel, new std::vector<std::string>)
            );
    }

    // Find the list of packets
    auto listPtr = stringPackets.find(channel);

    (listPtr*)->push_back(packet);
}

bool FakeNetwork::checkString(int channel)
{

}

std::string FakeNetwork::getString(int channel)
{

}
