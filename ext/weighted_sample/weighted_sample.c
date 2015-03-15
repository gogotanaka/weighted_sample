#include "weighted_sample.h"


static VALUE
rb_ary_expand(int argc, VALUE *argv, VALUE ary)
{
    VALUE new_ary = rb_ary_new();
    long i, j, weight;
    VALUE e, tmp_ary;

    for (i=0; i<RARRAY_LEN(ary); i++) {
        e = rb_ary_entry(ary, i);
        weight = FIX2LONG(rb_yield(e));
        tmp_ary = rb_ary_new();
        for (j=0; j<weight; j++) {
            rb_ary_push(tmp_ary, e);
        }
        new_ary = rb_ary_plus(new_ary, tmp_ary);
    }

    return new_ary;
}

void
Init_weighted_sample(void)
{
    rb_define_method(rb_cArray, "expand", rb_ary_expand, -1);
}

