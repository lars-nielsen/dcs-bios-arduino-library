#include "DcsMock.h"
#include <iostream>
#include <cstring>

namespace DcsBios {
    static std::vector<std::pair<std::string, std::string>> messageLog;

    bool tryToSendDcsBiosMessage(const char* msg, const char* arg) {
        messageLog.emplace_back(msg ? msg : "", arg ? arg : "");
        return true;
    }

    void resetMessageLog() {
        messageLog.clear();
    }

    const std::vector<std::pair<std::string, std::string>>& getMessageLog() {
        return messageLog;
    }
}

// Global function for use by PollingInput and other code
bool tryToSendDcsBiosMessage(const char* msg, const char* arg) {
    return DcsBios::tryToSendDcsBiosMessage(msg, arg);
}
