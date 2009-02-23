#include "ruby.h"
#include "serial.h"

VALUE cWin32Serial;
HANDLE cfd;

static VALUE my_open(VALUE self, VALUE comport)
{
    int retval;
    retval = openport(STR2CSTR(rb_str_concat(rb_str_new2("\\\\.\\"), comport)), &cfd);
    return (retval == -1) ? Qnil : Qtrue;
}

static VALUE
my_timeouts(VALUE self, VALUE readinterval, VALUE readmult, VALUE readconst, VALUE writemult, VALUE writeconst)
{
    int retval;
    retval = timeouts(FIX2INT(readinterval), FIX2INT(readmult), FIX2INT(readconst), FIX2INT(writemult), FIX2INT(writeconst), &cfd);
    return (retval == -1) ? Qnil : Qtrue;
}

static VALUE
my_config(VALUE self, VALUE baudrate, VALUE bytesize, VALUE parity,
	  VALUE stopbits)
{
    int retval;
    DWORD fparity;
    fparity = (FIX2INT(parity) == NOPARITY) ? FALSE : TRUE;
    retval =
	configure(FIX2INT(baudrate), FIX2INT(bytesize), fparity,
		  FIX2INT(parity), FIX2INT(stopbits), &cfd);
    return (retval == -1) ? Qnil : Qtrue;
}

static VALUE my_read(VALUE self, VALUE b2read)
{
    int retval;
    int bytes = (NUM2INT(b2read) > 1024) ? 1024 : NUM2INT(b2read);
    char buffer[1025];

    retval = readport(bytes, buffer, &cfd);
    return (retval == -1) ? Qnil : rb_str_new(buffer, retval);
}

static VALUE my_write(VALUE self, VALUE data)
{
    int retval;
    retval = writeport(RSTRING(data)->len, STR2CSTR(data), &cfd);
    return (retval == -1) ? Qnil : rb_int_new(retval);
}

static VALUE my_close(VALUE self)
{
    int retval;
    retval = cleanup(&cfd);
    return (retval == -1) ? Qnil : Qtrue;
}

void Init_Win32Serial()
{
    cWin32Serial = rb_define_class("Win32Serial", rb_cObject);
    rb_define_method(cWin32Serial, "open", my_open, 1);
    rb_define_method(cWin32Serial, "config", my_config, 4);
    rb_define_method(cWin32Serial, "timeouts", my_timeouts, 5);
    rb_define_method(cWin32Serial, "read", my_read, 1);
    rb_define_method(cWin32Serial, "write", my_write, 1);
    rb_define_method(cWin32Serial, "close", my_close, 0);
    rb_define_const(cWin32Serial, "CBR_110", INT2FIX(CBR_110));
    rb_define_const(cWin32Serial, "CBR_300", INT2FIX(CBR_300));
    rb_define_const(cWin32Serial, "CBR_600", INT2FIX(CBR_600));
    rb_define_const(cWin32Serial, "CBR_1200", INT2FIX(CBR_1200));
    rb_define_const(cWin32Serial, "CBR_2400", INT2FIX(CBR_2400));
    rb_define_const(cWin32Serial, "CBR_4800", INT2FIX(CBR_4800));
    rb_define_const(cWin32Serial, "CBR_9600", INT2FIX(CBR_9600));
    rb_define_const(cWin32Serial, "CBR_14400", INT2FIX(CBR_14400));
    rb_define_const(cWin32Serial, "CBR_19200", INT2FIX(CBR_19200));
    rb_define_const(cWin32Serial, "CBR_38400", INT2FIX(CBR_38400));
    rb_define_const(cWin32Serial, "CBR_56000", INT2FIX(CBR_56000));
    rb_define_const(cWin32Serial, "CBR_57600", INT2FIX(CBR_57600));
    rb_define_const(cWin32Serial, "CBR_115200", INT2FIX(CBR_115200));
    rb_define_const(cWin32Serial, "CBR_128000", INT2FIX(CBR_128000));
    rb_define_const(cWin32Serial, "CBR_256000", INT2FIX(CBR_256000));
    rb_define_const(cWin32Serial, "NOPARITY", INT2FIX(NOPARITY));
    rb_define_const(cWin32Serial, "ODDPARITY", INT2FIX(ODDPARITY));
    rb_define_const(cWin32Serial, "EVENPARITY", INT2FIX(EVENPARITY));
    rb_define_const(cWin32Serial, "MARKPARITY", INT2FIX(MARKPARITY));
    rb_define_const(cWin32Serial, "SPACEPARITY", INT2FIX(SPACEPARITY));
    rb_define_const(cWin32Serial, "ONESTOPBIT", INT2FIX(ONESTOPBIT));
    rb_define_const(cWin32Serial, "ONE5STOPBITS", INT2FIX(ONE5STOPBITS));
    rb_define_const(cWin32Serial, "TWOSTOPBITS", INT2FIX(TWOSTOPBITS));
}
