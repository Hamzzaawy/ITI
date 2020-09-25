/*
 * MADC_Private.h
 *
 *  Created on: Jul 7, 2019
 *      Author: Hamza
 */

#ifndef MADC_PRIVATE_H_
#define MADC_PRIVATE_H_

#define MADC_ADMUX  	*((volatile u8*)(0x27))
#define MADC_ADCSRA  	*((volatile u8*)(0x26))
#define MADC_ADC  		*((volatile u16*)(0x24))
#define MADC_SFIOR  	*((volatile u8*)(0x50))
#define MADC_SREG       *((volatile u8*)(0x5F))

// register MADC_ADMUX bits

#define REFS1		7
#define REFS0		6
#define ADLAR		5
#define MUX4		4
#define MUX3		3
#define MUX2		2
#define MUX1		1
#define MUX0		0



// register ADCSRA bits

#define ADEN		7
#define ADSC		6
#define ADATE		5
#define ADIF		4
#define ADIE		3
#define ADPS2		2
#define ADPS1		1
#define ADPS0		0


// register SFIOR bits

#define ADTS2		7
#define ADTS1		6
#define ADTS0		5



#endif /* MADC_PRIVATE_H_ */
