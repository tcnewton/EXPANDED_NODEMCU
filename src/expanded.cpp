#include "expanded.h"

void expanded_io::configurePort(uint8_t port, uint8_t custom)
{
    if (custom == INPUT)
    {
        writeBlockData(port, 0xFF);
    }
    else if (custom == OUTPUT)
    {
        writeBlockData(port, 0x00);
    }
    else
    {
        writeBlockData(port, custom);
    }
}

void expanded_io::writeBlockData(uint8_t cmd, uint8_t data)
{
    Wire.beginTransmission(MCPAddress);
    Wire.write(cmd);
    Wire.write(data);
    Wire.endTransmission();
    delay(10);
}

uint8_t expanded_io::readPin(uint8_t pin, uint8_t gp)
{
    uint8_t statusGP = 0;
    Wire.beginTransmission(MCPAddress);
    Wire.write(gp); 
    Wire.endTransmission();
    Wire.requestFrom(MCPAddress, 1); // ler do chip  1 byte
    statusGP = Wire.read(); 
    return valueFromPin(pin, statusGP);
}

uint8_t expanded_io::valueFromPin(uint8_t pin, uint8_t statusGP)
{
  return (statusGP &( 0x0001 << pin)) == 0 ? 0 : 1;
}

