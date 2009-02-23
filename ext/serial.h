#ifndef _SERIAL_H
#define _SERIAL_H

#include  <windows.h>
#include  <stdio.h>

#define VERSION 0.3

/*
DWORD baudrate
Represents the baud rate for communication supported by an external device. For
example, you can give this parameter as 9600 or CBR_9600 for a baud rate of
9600. The available standard baud rates supported by the PC are CBR_110,
CBR_300, CBR_600, CBR_1200, CBR_2400, CBR_4800, CBR_9600, CBR_14400, CBR_19200,
CBR_38400, CBR_56000, CBR_57600, CBR_115200, CBR_128000, and CBR_256000.

BYTE bytesize
Represents the number of bits in the bytes transmitted and received. Standard
values are 8 or 4.

DWORD fparity
Specifies whether parity checking is enabled. If this member is TRUE, parity
checking is performed and errors are reported. If FALSE, no parity checking is
performed.

BYTE parity
Specifies the parity scheme to be used. This member can be one of the following values:
Value          Meaning
EVENPARITY     Even
MARKPARITY     Mark
NOPARITY       No parity
ODDPARITY      Odd
SPACEPARITY    Space

BYTE stopbits
Specifies the number of stop bits to be used. This member can be one of the
following values:
Value          Meaning
ONESTOPBIT     1 stop bit
ONE5STOPBITS   1.5 stop bits
TWOSTOPBITS    2 stop bits

*/

int openport (char *comport, HANDLE *cfd);
int configure (DWORD baudrate, BYTE bytesize, DWORD fparity, BYTE parity, BYTE stopbits, HANDLE *cfd);
int timeouts (DWORD readinterval, DWORD readmult, DWORD readconst, DWORD writemult, DWORD writeconst, HANDLE *cfd);
int readport (int b2read, char *buffer, HANDLE *cfd);
int writeport(int b2write, char *buffer, HANDLE * cfd);
int cleanup (HANDLE *cfd);
void print_error(int line);

#endif /* serial.h */
