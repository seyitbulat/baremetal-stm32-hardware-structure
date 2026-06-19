#include <stdint.h>



typedef struct{
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t BRR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t CR3;
    volatile uint32_t GTPR;
} USART_TypeDef;

#define USART1_BASE_ADDRESS 0x40011000
#define USART1 ((USART_TypeDef *) USART1_BASE_ADDRESS)



typedef struct{
    volatile uint32_t CR;
    volatile uint32_t RESERVED[11];
    volatile uint32_t AHB1ENR;
    volatile uint32_t RESERVED2[3];
    volatile uint32_t RCC_APB1ENR;
    volatile uint32_t RCC_APB2ENR;
} RCC_TypeDef;


#define RCC_BASE_ADDRESS 0x40023800
#define RCC ((RCC_TypeDef *) RCC_BASE_ADDRESS)


typedef struct{
    volatile uint32_t MODER;
    volatile uint32_t RESERVED[7];
    volatile uint32_t AFRL;
    volatile uint32_t AFHL;

} GPIO_TypeDef;

#define GPIOA_BASE_ADDRESS 0x40020000
#define GPIOA ((GPIO_TypeDef *) GPIOA_BASE_ADDRESS)


typedef struct{
    volatile uint32_t ISER[8];
} NVIC_TypeDef;

#define NVIC_BASE_ADDRESS 0xE000E100
#define NVIC ((NVIC_TypeDef *) NVIC_BASE_ADDRESS)



typedef struct{
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
} STK_TypeDef;

#define STK_BASE_ADDRESS 0xE000E010
#define STK ((STK_TypeDef *) STK_BASE_ADDRESS)
