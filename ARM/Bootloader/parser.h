/*
 * parser.h
 *
 *  Created on: Aug 19, 2019
 *      Author: Hamza
 */

#ifndef PARSER_H_
#define PARSER_H_

typedef struct
{
    u16    DataCount;
    u32    Address;
    u8     RecordType;
    u8     Data[30];
    u16    CheckSum;
}Parser;



u8 Char_HEX_To_DEC(u8 data);

void parserFunction(u8* record,Parser* parser);


#endif /* PARSER_H_ */
