#pragma once

#ifdef MYLIB_EXPORTS
#define MYLIBAPI extern "C" __declspec(dllexport)

#else

#define MYLIBAPI extern "C" __declspec(dllimport)

#endif

MYLIBAPI int add(int n_op1, int n_op2);
MYLIBAPI int sub(int n_op1, int n_op2);
MYLIBAPI int mul(int n_op1, int n_op2);

MYLIBAPI float divide(int n_op1, int n_op2);