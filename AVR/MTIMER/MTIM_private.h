#ifndef MTIMER_PRIVATE_H
#define MTIMER_PRIVATE_H

// TIM0 Timer/Counter Control Register
#define MTIM0_TCCR0    		  	*((volatile u8*)(0x53))

//TIM0 Timer/Counter Register
#define MTIM0_TCNT0     		*((volatile u8*)(0x52))

//TIM0 Output Compare Register
#define MTIM0_OCR0  	  		*((volatile u8*)(0x5c))

//Timer/Counter interrupt mask
#define MTIM_IMSK  	   			*((volatile u8*)(0x59))

//Timer/Counter interrupt Flag
#define MTIM_TIFR     			*((volatile u8*)(0x58))

//global interupt enable pin in sreg
#define MTIM_SREG      			*((volatile u8*)(0x5F))

//timer 0 macros

#define CS00      0
#define CS01      1
#define CS02      2
#define WGM01     3
#define COM00     4
#define COM01     5
#define WGM00     6
#define FOC0      7


#define TOIE0 	  0
#define OCIE0 	  1



//timer 1 macros

//TCCR1A macros
#define WGM10      0
#define WGM11      1
#define FOC1B      2
#define FOC1A      3
#define COM1B0     4
#define COM1B1     5
#define COM1A0     6
#define COM1A1     7

//TCCR1B macros
#define CS10       0
#define CS11       1
#define CS12       2
#define WGM12      3
#define WGM13      4

#define ICES1      6
#define ICNC1      7


//TIMSK's timer1 macros
#define TOIE1       2
#define OCIE1B      3
#define OCIE1A      4
#define TICIE1      5

//TIFR's timer1 macros
#define TOV1       2
#define OCF1B      3
#define OCF1A      4
#define ICF1       5


//timer1 registers addreses

#define MTIM1_TCCR1A      *((volatile u8*)(0x4F))

#define MTIM1_TCCR1B      *((volatile u8*)(0x4E))


#define MTIM1_TCNT1		 *((volatile u16*)(0x4C))

#define MTIM1_OCR1A		 *((volatile u16*)(0x4A))

#define MTIM1_OCR1B		 *((volatile u16*)(0x48))

#define MTIM1_ICR1		 *((volatile u16*)(0x46))






#endif
