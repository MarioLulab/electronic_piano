#include "led.h"

void LED_Init(){
  GPIO_InitTypeDef GPIO_InitStruct;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //使能PA,C端口时钟

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStruct);

  // GPIO_ResetBits(GPIOC, GPIO_Pin_13);   // 初始化亮灯
  GPIO_SetBits(GPIOC, GPIO_Pin_13);   // 初始化灭灯

}