#include <stdint.h>

#include "stm32_regs.h"

void USART1_IRQHandler(void) {
  if (((USART1->SR >> 5) & 0x01) == 1) {
    char data = (char)(USART1->DR);

    while (((USART1->SR >> 7) & 0x01) != 1) {
    }

    USART1->DR = data;
  }
}


void USART_SendString(char* str){
  char* addr = str;

  while(*addr != '\0'){
    while(((USART1->SR >> 7) & 0x01) != 1){}
    USART1->DR = *addr;
    addr++;
  }
}


int main(void) {
  // set gpio a pin enabled
  RCC->AHB1ENR |= (1 << 0);

  // set usart2 clock enabled
  // *RCC_APB1ENR |= (1 << 17);
  RCC->RCC_APB2ENR |= (1 << 5);

  // set gpio a pin to alternate mode
  // *GPIOA_MODER &= ~(0xF0);
  // *GPIOA_MODER |= (0b1010 << 4);

  GPIOA->MODER &= ~(0xF << 18);
  GPIOA->MODER |= (0b1010 << 18);

  // set AF7 for gpioa to usart2
  // *GPIOx_AFRL &= ~(0xFF00);
  // *GPIOx_AFRL |= (0x77 << 8);

  // set AF7 for gpioa to usart 1 pins 8 and 9
  GPIOA->AFHL &= ~(0xFF << 4);
  GPIOA->AFHL |= (0x77 << 4);

  // set baud rate
  USART1->BRR = (0x8 << 4) | (0xB);

  // RE, TX, UE

  USART1->CR1 |= (1 << 3) | (1 << 2) | (1 << 13);

  // usart interrupt RXNEIE
  USART1->CR1 |= (1 << 5);

  NVIC->ISER[1] |= (1 << 5);

  // message
  char* message = "HELLO BAREMETAL\n";

  USART_SendString(message);

  while (1) {
  }
}


void delay_ms(uint32_t ms){
  STK->LOAD = (ms * (16000 - 1))/100;

  STK->CTRL |= (1 << 0) | (1 << 2);

  while(((STK->CTRL >> 16) & 0x01) != 1){}

  STK->CTRL &= ~(1 << 0);
}