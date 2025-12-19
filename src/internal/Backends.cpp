#include <cstdint>

namespace DcsBios {
    struct AnalogBackend
    {
        using AnalogReadFn = uint16_t (*)(uint8_t);
        using PinModeFn = void (*)(uint8_t);

        AnalogReadFn analogRead;
        PinModeFn pinMode;
    };

    struct DigitalBackend
    {
        using DigitalReadFn = int (*)(uint8_t);
        using PinModeFn = void (*)(uint8_t);

        DigitalReadFn digitalRead;
        PinModeFn pinMode;
    };
}
