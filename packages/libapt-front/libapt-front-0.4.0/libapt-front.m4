# LIBAPT_FRONT_DEFS([LIBAPT_FRONT_REQS=libapt-front])
# ---------------------------------------
AC_DEFUN([LIBAPT_FRONT_DEFS],
[
	dnl Import libapt-front data
	PKG_CHECK_MODULES(LIBAPT_FRONT,m4_default([$1], libapt-front))
	AC_SUBST(LIBAPT_FRONT_CFLAGS)
	AC_SUBST(LIBAPT_FRONT_LIBS)
])
