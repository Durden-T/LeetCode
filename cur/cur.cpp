signed __int64 __fastcall fun7(__int64 n1, __int64 s)
{
    signed __int64 result; // rax

    if (!n1)
        return 0xFFFFFFFFLL;
    if (*(_DWORD *)n1 > (signed int)s)
        return 2 * (unsigned int)fun7(*(_QWORD *)(n1 + 8), s);
    result = 0LL;
    if (*(_DWORD *)n1 != (_DWORD)s)
        result = 2 * (unsigned int)fun7(*(_QWORD *)(n1 + 16), s) + 1;
    return result;
}