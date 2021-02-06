//
//  invaderlib.h
//  Space Invaders
//
//  Created by Nicholas Kemp on 2020-09-29.
//  Copyright © 2020 Nicholas Kemp. All rights reserved.
//

#ifndef __INVADERLIB_H__
#define __INVADERLIB_H__

#include <stdint.h>

typedef         uint8_t         boolean;
typedef         uint8_t         byte;
extern int      word_size;

void NVDR_memset (void *des, char val, size_t length);
extern void (*NVDR_memcpy) (void *des, const void *src, size_t length);
int NVDR_atoi (char *str);
int NVDR_strlen (char *str);
int NVDR_strcmp (char *str1, char *str2);

long NVDR_ntohl (long n);
short NVDR_ntohs (short n);
long NVDR_htonl (long n);
short NVDR_htons (short n);

long LongSwap (long l);
short ShortSwap (short s);

void set_word_size (void);
boolean little_endian (void);
extern boolean (*memory_is_aligned) (uint64_t n);
uint64_t align_memory (uint64_t n);

//FIXME: This... not good
void NVDR_Library_Init (void);

#endif /* __INVADERLIB_H__ */
