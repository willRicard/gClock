#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(gClock, 1.0, guillaume.ricard@mail.com)
AM_INIT_AUTOMAKE([foreign dist-bzip2])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([wiringPi], [digitalWrite], [], [
	echo "Error: The wiringPi library is required to build this program."
	echo "You can download it from http://wiringpi.com (LGPL3 license)"
	exit -1
])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h stdio.h unistd.h pthread.h wiringPi.h sys/types.h sys/stat.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_OUTPUT
