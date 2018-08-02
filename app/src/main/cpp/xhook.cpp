//
// Created by wurongqiu on 2018/7/16.
//



#include "xhcore.h"
#include "xhook.h"

int xhook_register(const char *pathname_regex_str, const char *symbol,
                   void *new_func, void **old_func)
{
    return xh_core_register(pathname_regex_str, symbol, new_func, old_func);
}

int xhook_ignore(const char *pathname_regex_str, const char *symbol)
{
    return xh_core_ignore(pathname_regex_str, symbol);
}

int xhook_refresh(int async)
{
    return xh_core_refresh(async);
}

void xhook_clear()
{
    return xh_core_clear();
}

void xhook_enable_debug(int flag)
{
    return xh_core_enable_debug(flag);
}

void xhook_enable_sigsegv_protection(int flag)
{
    return xh_core_enable_sigsegv_protection(flag);
}
