#ifndef DCS_MOCK_H
#define DCS_MOCK_H

#include <string>
#include <vector>

// DCS-BIOS mock
namespace DcsBios {

    bool tryToSendDcsBiosMessage(const char* msg, const char* arg);

    void resetMessageLog();
    const std::vector<std::pair<std::string, std::string>>& getMessageLog();

    inline void assertMessageLogEmpty() {
        resetMessageLog();
    }
}

#endif // DCS_MOCK_H
