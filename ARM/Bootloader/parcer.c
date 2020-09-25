/*
 * parcer.c
 *
 *  Created on: Jul 13, 2019
 *      Author: Hamza
 */
#include "LSTR_Types.h"
#include "parser.h"



void parserFunction(u8* record,Parser* parser)
{
    u16 Check_Sum=0,check=0;
    u8 i=0;
    if(record[0] == ':')
    {
        //extracting the data count from the record
        i++;
        parser->DataCount=(16*Char_HEX_To_DEC(record[i])) + Char_HEX_To_DEC(record[i+1]);



        //extracting the address from the record
        i+=2;
        parser->Address = ((4096) * Char_HEX_To_DEC(record[i])) + ((256) * Char_HEX_To_DEC(record[i+1])) + ((16) * Char_HEX_To_DEC(record[i+2])) + Char_HEX_To_DEC(record[i+3]);



        //extracting The record type
        i+=4;
        parser->RecordType = (16*Char_HEX_To_DEC(record[i])) + Char_HEX_To_DEC(record[i+1]);



        //extracting the Data
        i+=2;

        for (int k=0;k<(parser->DataCount*2);k++)
        {
            parser->Data[k]=Char_HEX_To_DEC(record[i]);

            i++;
        }

        //extracting the Check sum from the data
        parser->CheckSum = (16*Char_HEX_To_DEC(record[i])) + Char_HEX_To_DEC(record[i+1]);
        Check_Sum += check;


    }
    else
    {
        printf("record error");
    }

}


u8 Char_HEX_To_DEC(u8 data)
{
    int out=0;
    if((data>='0')&&(data<='9'))
    {
        out =data-48;
    }
    else
    {
        out =data-55;
    }
    return out;
}








