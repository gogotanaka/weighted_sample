#include "weighted_sample.h"

static VALUE
rb_ary_weighted_sample(int argc, VALUE *argv, VALUE ary)
{

    // return LONG2FIX(rb_yield(2));
    // return LONG2FIX(RARRAY_LEN(ary));
    VALUE new_ary = rb_ary_new();
    long j;

    for (long i=0; i<RARRAY_LEN(ary); i++) {
        VALUE e = rb_ary_entry(ary, i);
        long weight = FIX2LONG(rb_yield(e));
        VALUE new_ary2 = rb_ary_new();
        for (j=0; j<weight; j++) {
            rb_ary_push(new_ary2, LONG2FIX(weight));
        }
        new_ary = rb_ary_plus(new_ary, new_ary2);
    }

    return new_ary;
}

void
Init_weighted_sample(void)
{
  rb_define_method(rb_cArray, "sample", rb_ary_weighted_sample, -1);
}

