/* $MawkId: regexp.c,v 1.4 2010/07/31 00:15:13 tom Exp $ */
#ifdef LOCAL_REGEXP
#		include "mawk.h"
#		include "rexp.c"
#		include "rexp0.c"
#		include "rexp1.c"
#		include "rexp2.c"
#		include "rexp3.c"
#		include "rexp4.c"
#		include "rexpdb.c"
#else
#		include "rexp4.c"
#		include "regexp_system.c"
#endif

#ifdef NO_LEAKS
void
rexp_leaks(void)
{
    TRACE(("rexp_leaks\n"));
#ifdef LOCAL_REGEXP
    if (bv_base) {
	BV **p = bv_base;
	while (p != bv_next) {
	    RE_free(*p);
	    ++p;
	}
	RE_free(bv_base);
	bv_base = 0;
	bv_limit = 0;
	bv_next = 0;
    }
    if (RE_run_stack_base) {
	RE_free(RE_run_stack_base);
	RE_run_stack_base = 0;
    }
    if (RE_pos_stack_base) {
	RE_free(RE_pos_stack_base);
	RE_pos_stack_base = 0;
    }
#endif
}
#endif
