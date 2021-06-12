/*
*********************************************************************************************************
*                                              EXAMPLE CODE
*
*                          (c) Copyright 2003-2007; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                           MASTER INCLUDES
*
*                                     ST Microelectronics STM32
*                                              with the
*                                   IAR STM32-SK Evaluation Board
*
* Filename      : includes.h
* Version       : v1.00
* Programmer(s) : FT
*********************************************************************************************************
*/

#ifndef  __INCLUDES_H__
#define  __INCLUDES_H__

#include    <stdio.h>
#include    <string.h>
#include    <ctype.h>
#include    <stdlib.h>
#include    <stdarg.h>

#include    <ucos_ii.h>

#include    <cpu.h>
#include    <lib_def.h>
#include    <lib_mem.h>
#include    <lib_str.h>
#include    <lib_ascii.h>

#include    <stm32f10x_conf.h>
// #include    <stm32f10x_lib.h>

#include    <app_cfg.h>
#include    <bsp.h>


#include "led.h"
#include "digits.h"
#include "sound.h"
#include "adc.h"
#include "timer.h"
#include "usart.h"


// #include "delay.h"


// 定义音高
#define LOW  0
#define MID  1
#define HIGH 2


// 定义按键ADC1的通道号
#define KEY_0 5
#define KEY_1 4
#define KEY_2 3
#define KEY_3 1

// Function_Tag的标号
#define FREE 0
#define SELF_CHECK 1
#define PLAY 2
#define RECORD 3





typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

static unsigned int key_list[] = {KEY_0, KEY_1, KEY_2, KEY_3};

struct pitch{
    int level;
    int step;
    unsigned int period;    // 单位us
    unsigned int arr;
    unsigned int psc;
};

struct real_pitch{
    float delay_time;     // 单位节拍，比例系数待定
    int pitch_index;
};


// static struct pitch pitch_table[] = {
//     {LOW,3,3034,491,443}, {LOW,4,2864,536,383}, {LOW,5,2551,431,424},
//     {LOW,6,2272,425,383}, {LOW,7,2024,395,367}, {MID,1,1911,377,363}, {MID,2,1703,392,311}, {MID,3,1517,332,327}, {MID,4,1432,357,287}, {MID,5,1275,305,299},   // 低音6La -> 中音5So
//     {MID,6,1136,287,283}, {MID,7,1012,275,263}, {HIGH,1,955,359,190},  {HIGH,2,851,275,221}                       // 中音6La -> 高音2Re
// };


static struct pitch pitch_table[] = {
    {LOW,6,2272,425,383}, {LOW,7,2024,395,367}, {MID,1,1911,377,363}, {MID,2,1703,392,311}, {MID,3,1517,332,327}, {MID,4,1432,357,287}, {MID,5,1275,305,299},   // 低音6La -> 中音5So
    {MID,6,1136,287,283}, {MID,7,1012,275,263}, {HIGH,1,955,359,190},  {HIGH,2,851,275,221}                       // 中音6La -> 高音2Re
};




typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;


#define SYSTEM_SUPPORT_OS 1


void Delay_ms(int times);
void Delay_us(int times);

#if (APP_CFG_LCD_EN > 0)
// #include    <arm_comm.h>
// #include    <drv_glcd_cnfg.h>
// #include    <drv_glcd.h>
// #include    <glcd_ll.h>
// #include    <drv_spi1.h>
#endif

#if (APP_CFG_PROBE_COM_EN == DEF_ENABLED)
#include    <probe_com.h>

#if (APP_CFG_KSD_EN == DEF_ENABLED)
#include    <ksd.h>
#endif

#if (PROBE_COM_CFG_RS232_EN == DEF_ENABLED)
#include    <probe_rs232.h>
#endif

#if (APP_CFG_PROBE_OS_PLUGIN_EN == DEF_ENABLED)
#include    <os_probe.h>
#endif
#endif



#endif
