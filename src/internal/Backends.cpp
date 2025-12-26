#include <cstdint>

namespace DcsBios {

    struct DigitalBackend
    {
        using DigitalReadFn = int (*)(uint8_t);
        using DigitalWriteFn = void (*)(uint8_t, uint8_t);

        using PinModeFn = void (*)(uint8_t, uint8_t);      
        
        DigitalReadFn digitalRead;
        DigitalWriteFn digitalWrite;

        PinModeFn pinMode;
    };

    struct AnalogBackend
    {
        using AnalogReadFn = uint16_t (*)(uint8_t);
        using AnalogWriteFn = void (*)(uint8_t, uint16_t);

        using PinModeFn = void (*)(uint8_t, uint8_t);      

        AnalogReadFn analogRead;
        AnalogWriteFn analogWrite;

        PinModeFn pinMode;
    };
}
