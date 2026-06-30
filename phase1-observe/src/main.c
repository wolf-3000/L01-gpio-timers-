#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect)
{
    PIND = (1 << PIND4);
}

int main(void)
{
    DDRD |= (1 << PD4);
    PORTD &= ~(1 << PD4);

    //TIMER1 CTC
    TCCR1A = 0X00;
    TCCR1B = (1 << WGM12) | (1 << CS12);
    OCR1A = 31249;
    TIMSK1 = (1 << OCIE1A);
    sei();

    while (1) 
    {

    }
}