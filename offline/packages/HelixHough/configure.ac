AC_INIT([HelixHough], [1.00])
AC_CONFIG_SRCDIR([configure.ac])

AM_INIT_AUTOMAKE(HelixHough, 1.00)

AC_PROG_CXX(CC g++)
AC_ENABLE_STATIC(no)

LT_INIT([disable-static])

dnl   no point in suppressing warnings people should 
dnl   at least see them, so here we go for g++: -Wall
dnl if test $ac_cv_prog_gxx = yes; then
dnl    CXXFLAGS="$CXXFLAGS -Wall -Werror"
dnl fi

ROOTLIBS=`$ROOTSYS/bin/root-config --libs`
AC_SUBST(ROOTLIBS)

AC_CONFIG_FILES([
	Makefile
	FitNewton/Makefile
	FitNewton/fitnewton.pc
	Seamstress/Makefile
	Seamstress/seamstress.pc
	helix_hough/Makefile
	helix_hough/helix_hough.pc
	helix_hough/circlegen/Makefile
	helix_hough/test/Makefile
])
AC_OUTPUT
