#ifndef FAKENETWORK_H
#define FAKENETWORK_H

#include <string>
#include <map>
#include <vector>

class FakeNetwork
{
    /////////////////////////////////
    // Singleton Pattern
    /////////////////////////////////

    private:
        // Constructor; private so we can have singletons FTW
        FakeNetwork();
    public:
        // Singleton instance
        static FakeNetwork* getInstance();

        // Destructor
        ~FakeNetwork();
    private:
        // Singleton instance
        static FakeNetwork* instance;

    /////////////////////////////////
    // Functionality
    /////////////////////////////////

    private:
        std::map<int, std::vector<std::string>*> stringPackets;

    public:
        void sendString(int channel, std::string packet);
        bool checkString(int channel);
        std::string getString(int channel);
};

#endif // FAKENETWORK_H
