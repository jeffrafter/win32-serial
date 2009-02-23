#include "serial.h"
#include <string.h>

int openport(char *comport, HANDLE * cfd)
{
    *cfd =
	CreateFile(comport, GENERIC_READ | GENERIC_WRITE, 0, NULL,
		   OPEN_EXISTING, 0, NULL);
    if (*cfd == INVALID_HANDLE_VALUE || *cfd == NULL) {
#ifdef DEBUG
	print_error(__LINE__);
#endif
	return -1;
    }

    if (!SetupComm(*cfd, 1024, 1024) != 0) {
#ifdef DEBUG
	print_error(__LINE__);
#endif
	return -1;
    }
    return 1;
}

int configure(DWORD baudrate, BYTE bytesize, DWORD fparity, BYTE parity,
	      BYTE stopbits, HANDLE * cfd)
{
    DCB dcb;
    if (!GetCommState(*cfd, &dcb)) {
#ifdef DEBUG
	print_error(__LINE__);
#endif
	return -1;
    }
    // See serial.h for an in-depth description of these params
    dcb.BaudRate = baudrate;
    dcb.StopBits = stopbits;
    dcb.Parity = parity;
    dcb.fParity = fparity;
    dcb.ByteSize = bytesize;

    if (!SetCommState(*cfd, &dcb)) {
#ifdef DEBUG
	print_error(__LINE__);
#endif
	return -1;
    }
    return 1;
}

int timeouts (DWORD readinterval, DWORD readmult, DWORD readconst, DWORD writemult, DWORD writeconst, HANDLE *cfd)
{
    COMMTIMEOUTS ctout;
    if (!GetCommTimeouts(*cfd, &ctout)) {
#ifdef DEBUG
        print_error(__LINE__);
#endif
        return -1;
    }
    ctout.ReadIntervalTimeout = readinterval;
    ctout.ReadTotalTimeoutMultiplier = readmult;
    ctout.ReadTotalTimeoutConstant = readconst;
    ctout.WriteTotalTimeoutMultiplier = writemult;
    ctout.WriteTotalTimeoutConstant = writeconst;
    if (!SetCommTimeouts(*cfd, &ctout)) {
#ifdef DEBUG
        print_error(__LINE__);
#endif
        return -1;
    }
    return 1;
}

int readport(int b2read, char *buffer, HANDLE * cfd)
{
    int bytesread;

    bytesread = 0;
    if (!ReadFile(*cfd, buffer, b2read, &bytesread, NULL)) {
#ifdef DEBUG
	print_error(__LINE__);
#endif
	return -1;
    }
    buffer[bytesread] = '\0';
    return bytesread;
}

int writeport(int b2write, char *buffer, HANDLE * cfd)
{
    int byteswritten;
    int retval;

    byteswritten = 0;
    if (!WriteFile(*cfd, buffer, b2write, &byteswritten, NULL)) {
#ifdef DEBUG
	print_error(__LINE__);
#endif
	return -1;
    }
    return byteswritten;
}

int cleanup(HANDLE * cfd)
{
    if (CloseHandle(*cfd))
	return 1;
    else {
#ifdef DEBUG
	print_error(__LINE__);
#endif
	return -1;
    }
    return 1;
}

void print_error(int line)
{
    LPVOID msgbuf;
    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
		  FORMAT_MESSAGE_IGNORE_INSERTS |
		  FORMAT_MESSAGE_FROM_SYSTEM,
		  NULL,
		  GetLastError(),
		  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		  (LPTSTR) & msgbuf, 0, NULL);
    fprintf(stderr, "(serial.c) Err Line #%i: %s\n", line, msgbuf);
}
