AC_INIT([cpp], [0.00.00], [ukarthickrajkumar@gmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([-Wall foreign subdir-objects dist-xz])
AM_SILENT_RULES([yes])

m4_ifdef([AM_PROG_AR],[AM_PROG_AM])
AC_PROG_CC
AC_PROG_CXX
AC_PROG_LIBTOOL

CFLAGS="$CFLAGS -Wall -Wextra"
CPPFLAGS="$CPPFLAGS -Wall -Wextra"

AC_CONFIG_HEADERS([source/config.h])

AC_CONFIG_FILES([
        Makefile
        source/Makefile
    ])

AC_OUTPUT