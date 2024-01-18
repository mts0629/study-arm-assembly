#include <stdint.h>

// Serial settings
#define UART0       ((volatile unsigned int*)0x101f1000)
#define UARTFR      0x06
#define UARTFR_TXFF 0x20

// Timer settings
#define TIMER0          ((volatile unsigned int*)0x101e2000)
#define TIMER1          ((volatile unsigned int*)0x101e2020)
#define TIMER2          ((volatile unsigned int*)0x101e3000)
#define TIMER3          ((volatile unsigned int*)0x101e3020)
#define TIMER_VALUE     0x1 // 0x04 bytes
#define TIMER_CONTROL   0x2 // 0x08 bytes
#define TIMER_INTCLR    0x3 // 0x0c bytes
#define TIMER_MIS       0x5 // 0x14 bytes

#define TIMER_EN        0x80
#define TIMER_PERIODIC  0x40
#define TIMER_INTEN     0x20
#define TIMER_32BIT     0x02
#define TIMER_ONESHOT   0x01

// PIC (Primary Interrupt Controller)
#define PIC             ((volatile unsigned int*)0x10140000)
#define PIC_TIMER01     0x10
#define VIC_INTENABLE   0x4 // 0x10 bytes

extern void enable_irq(void);

// Serial output
void uart_puts(char *s) {
    while (*s) {
        while (*(UART0 + UARTFR) & UARTFR_TXFF);
        *UART0 = *s;
        s++;
    }
}

// IRQ handler
void c_irq_handler(void) {
    if (*(TIMER0 + TIMER_MIS)) {
        // Output a string to the serial interface
        uart_puts("timer0 interrupt!\n");
        // Clear interrupts
        *(TIMER0 + TIMER_INTCLR) = 1;
    }
}

// Entry point
void boot_main(void) {
    // Enable interrupts from the Timer0 and Timer1
    *(PIC + VIC_INTENABLE) = PIC_TIMER01;

    // Set an interval of the interrupt from the Timer0
    *TIMER0 = 1000000;

    // Config the Timer0
    *(TIMER0 + TIMER_CONTROL) =
        (TIMER_EN | TIMER_PERIODIC | TIMER_32BIT | TIMER_INTEN);

    // Enable IRQ
    enable_irq();

    for (;;);
}
