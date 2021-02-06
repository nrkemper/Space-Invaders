//
//  invaderlib.c
//  Space Invaders
//
//  Created by Nicholas Kemp on 2020-09-29.
//  Copyright © 2020 Nicholas Kemp. All rights reserved.
//

#include "invaderlib.h"
#include <stdio.h>

void (*NVDR_memcpy) (void *des, const void *src, size_t length);
boolean (*memory_is_aligned) (uint64_t n);
int     word_size;

void NVDR_memset (void *des, char val, size_t length)
{
        byte    *d = (byte*)des;
        
        while (length)
        {
                *d++ = val;
                length--;
        }
}

void __NVDR_memcpy32bit__ (void *des, const void *src, size_t length)
{
        uint32_t        *d32 = des;
        const uint32_t  *s32 = src;
        byte            *d8;
        const byte      *s8;
        
        if (!((uint32_t)src & 0x1f) && !((uint32_t)des & 0x1f))
        {
                while (1)
                {
                        if (length < word_size)
                                break;
                        
                        *d32++ = *s32++;
                        length -= word_size;
                }
        }
        
        d8 = (byte*)d32;
        s8 = (const byte*)s32;
        
        while (1)
        {
                if (length == 0)
                        break;
                
                *d8++ = *s8++;
                length--;
        }
        
        return;
}

void __NVDR_memcpy64bit__  (void *des, const void *src, size_t length)
{
        uint64_t        *d64 = des;
        const uint64_t  *s64 = src;
        byte            *d8;
        const byte      *s8;
        
        if (!((uint64_t)src & 0x003f) && !((uint64_t)des & 0x003f))
        {
                while (1)
                {
                        if (length < word_size)
                                break;
                        
                        *d64++ = *s64++;
                        length -= word_size;
                }
        }
        
        d8 = (byte*)d64;
        s8 = (const byte*)s64;
        
        while (1)
        {
                if (length == 0)
                        break;
                
                *d8++ = *s8++;
                length--;
        }
}

int NVDR_atoi (char *str)
{
        int     sign=0, val=0;
        
        while (*str)
        {//detect white space and sign
                if (*str == ' ')
                {
                        str++;
                        continue;
                }
                else if (*str == '-')
                {
                        sign = -1;
                        str++;
                        break;
                }
                else if (*str >= '0' && *str <= '9')
                {
                        sign = 1;
                        break;
                }
                else
                        return 0;
        }
        
        while (*str)
        {
                if (*str >= '0' && *str <= '9')
                {
                        val = val * 10 + *str - '0';
                        str++;
                }
                else
                        break;
        }
        
        return val * sign;
}


int NVDR_strlen (char *str)
{
        int i=0;
        
        while (*str++)
                i++;
        
        return i;
}

int NVDR_strcmp (char *str1, char *str2)
{
        while (1)
        {
                if (*str1 > *str2)
                        return 1;
                
                else if (*str1 < *str2)
                        return -1;
                
                if (*str1 == '\0' ||
                    *str2 == '\0')
                        break;
                        
                str1++;
                str2++;
        }
        
        return 0;
}

long NVDR_ntohl (long n)
{
        if (little_endian())
                return LongSwap(n);
        else
                return n;
}

short NVDR_ntohs (short n)
{
        if (little_endian())
                return ShortSwap(n);
        else
                return n;
}

long NVDR_htonl (long n)
{
        if (little_endian())
                return LongSwap(n);
        else
                return n;
}

short NVDR_htons (short n)
{
        if (little_endian())
                return ShortSwap(n);
        else
                return n;
}

long LongSwap (long l)
{
        byte    b1, b2, b3, b4;
        
        b1 = (l & 0xff000000) >> 24;
        b2 = (l & 0x00ff0000) >> 16;
        b3 = (l & 0x0000ff00) >> 8;
        b4 = (l & 0x000000ff);
        
        return (b4 << 24) | (b3 << 16) | (b2 << 8) | b1;
}

short ShortSwap (short s)
{
        byte    b1, b2;
        
        b1 = (s & 0xff00) >> 8;
        b2 = (s & 0xff);
        
        return (b2 << 8) | b1;
}

void set_word_size (void)
{
        word_size = sizeof (void*);
}

boolean little_endian (void)
{
        long    x = 0x0001;
        char    *y = (char*)&x;
        
        if (y)
                return 1;
        else
                return 0;
}

boolean __memory_is_aligned_32bit__ (uint64_t n)
{
        if (n & 31)
                return 0;
        else
                return 1;
}

boolean __memory_is_aligned_64bit__ (uint64_t n)
{
        if (n & 63)
                return 0;
        else
                return 1;
}
            
uint64_t align_memory (uint64_t n)
{
        return 1;
}

//FIXME: This...not good.
void NVDR_Library_Init (void)
{
        set_word_size();
        
        if (word_size == 4)
        {
                NVDR_memcpy = &__NVDR_memcpy32bit__;
                memory_is_aligned = &__memory_is_aligned_32bit__;
        }
        else if (word_size == 8)
        {
                NVDR_memcpy = &__NVDR_memcpy64bit__;
                memory_is_aligned = &__memory_is_aligned_64bit__;
        }
        else
        {
                printf ("ERROR: Unsupported system. Your computer is too old.\n");
        }
}
