#include "DcsMock.h"
#include <iostream>
#include <cstring>

#include "../../../src/internal/PollingInput.h"

namespace DcsBios {
    PollingInput* PollingInput::firstPollingInput = nullptr;
    
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
