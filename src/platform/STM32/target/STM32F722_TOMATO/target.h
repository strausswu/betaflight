#pragma once

#define TARGET_CONFIG

// LED configuration (for tomato clock indicator)
#define LED0_PIN                 GPIO_PIN_5
#define LED0_PORT                GPIOA
#define LED0_EXTI                5
#define LED0_EXTI_IRQn           EXTI9_5_IRQn

// Beeper configuration
#define BEEPER                   GPIO_PIN_0
#define BEEPER_PORT              GPIOB
#define BEEPER_PWM

// UART configuration
#define USE_UART1
#define USE_UART2
#define USE_UART3

// SPI configuration (for display if needed)
#define USE_SPI
#define USE_SPI_DEVICE_1

// Disable flight-specific features
#define USE_ACC
#define USE_GYRO
#define USE_BARO
#define USE_MAG

// Resource mapping
#define TARGET_IO_PORTA          0xFFFF
#define TARGET_IO_PORTB          0xFFFF
#define TARGET_IO_PORTC          0xFFFF
#define TARGET_IO_PORTD          (BIT(2))
#define TARGET_IO_PORTE          (BIT(2))
