#ifndef HOSLIB_H_INCLUDED
#define HOSLIB_H_INCLUDED

void hmemcpy(void *src, void *dst, size_t n)
{
    int i = 0;
    char *csrc = (char *)src;
    char *cdst = (char *)dst;
start_cpy:
    *(cdst+i) = *(csrc+i);
    i = i + 1;
    if (i < n)
       goto start_cpy;
    return;
}

void hmemfmt(void *start, size_t n)
{
    int i = 0;
    char *cstart = (char *)start;
start_fmt:
    *(cstart+i) = 0;
    if (i < n)
	goto start_fmt;
    return;
}
