#include "stm32f4xx.h"

int main(void) {
    // 1. Enable the clock for GPIOA (bit 0 in RCC AHB1ENR)
    RCC->AHB1ENR |= (1 << 0);

    // 2. Set pin PA5 as output  (MODER5 = 01)
    GPIOA->MODER &= ~(3 << (5 * 2));   // clear mode bits
    GPIOA->MODER |=  (1 << (5 * 2));   // set as output

    // 3. Infinite loop: toggle LD2 and delay
    while (1) {
        GPIOA->ODR ^= (1 << 5);        // toggle output
        for (volatile int i = 0; i < 500000; i++);  // crude delay
    }
}
