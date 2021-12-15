// The MIT License (MIT)

// Copyright (c) YEAR NAME

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

#ifndef Expanded_H
#define Expanded_H

#include <Arduino.h>
#include <Wire.h> // specify use of Wire.h library.

//endereço I2C do MCP23016
#define MCPAddress  0x20
#define GP0  0x00   // DATA PORT REGISTER 0 
#define GP1  0x01   // DATA PORT REGISTER 1 
#define OLAT0  0x02   // OUTPUT LATCH REGISTER 0 
#define OLAT1  0x03   // OUTPUT LATCH REGISTER 1 
#define IPOL0   0x04  // INPUT POLARITY PORT REGISTER 0 
#define IPOL1   0x05  // INPUT POLARITY PORT REGISTER 1 
#define IODIR0  0x06  // I/O DIRECTION REGISTER 0 
#define IODIR1  0x07  // I/O DIRECTION REGISTER 1 
#define INTCAP0 0x08  // INTERRUPT CAPTURE REGISTER 0 
#define INTCAP1 0x09  // INTERRUPT CAPTURE REGISTER 1 
#define IOCON0  0x0A  // I/O EXPANDER CONTROL REGISTER 0 
#define IOCON1  0x0B  // I/O EXPANDER CONTROL REGISTER 1 

#define  W3E_DEBUG

#ifdef W3E_DEBUG
    #define DEBUG_PRINTER Serial
    #define DEBUG_PRINT(...) { DEBUG_PRINTER.print(__VA_ARGS__); }
    #define DEBUG_PRINTLN(...) { DEBUG_PRINTER.println(__VA_ARGS__); }
#else
    #define DEBUG_PRINT(...) { }
    #define DEBUG_PRINTLN(...) { }
#endif

class expanded_io {
    public:
    expanded_io();
    void configurePort(uint8_t port, uint8_t custom);
    void writeBlockData(uint8_t cmd, uint8_t data);
//faz a leitura de um pino específico
//pin: pino desejado (0-7)
//gp: GP0 ou GP1
//retorno: 0 ou 1
uint8_t readPin(uint8_t pin, uint8_t gp);
//retorna o valor do bit na posição desejada
//pin: posição do bit (0-7)
//statusGP: valor lido do GP (0-255)
uint8_t valueFromPin(uint8_t pin, uint8_t statusGP);
}
;
#endif
