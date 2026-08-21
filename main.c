#include <REGX52.H>

typedef unsigned char uchar;
typedef unsigned int uint;

sbit RS = P2^6;
sbit RW = P2^5;
sbit EN = P2^7;
#define DATA_PORT P0

void delay_ms(uint t)
{
    uint i,j;
    for(i=t;i>0;i--)
        for(j=110;j>0;j--);
}

void Lcd_Cmd(uchar cmd)
{
    RS = 0;
    RW = 0;
    DATA_PORT = cmd;
    delay_ms(1);
    EN = 1;
    delay_ms(1);
    EN = 0;
}

void Lcd_Data(uchar dat)
{
    RS = 1;
    RW = 0;
    DATA_PORT = dat;
    delay_ms(1);
    EN = 1;
    delay_ms(1);
    EN = 0;
}

void Lcd_Init(void)
{
    Lcd_Cmd(0x38);
    Lcd_Cmd(0x0c);
    Lcd_Cmd(0x06);
    Lcd_Cmd(0x01);
    delay_ms(5);
}

void main(void)
{
    Lcd_Init();
    Lcd_Cmd(0x80);   //???
    Lcd_Data('F');
    Lcd_Data('o');
    Lcd_Data('r');
    Lcd_Data(':');
    Lcd_Data(' ');
    Lcd_Data('J');
    Lcd_Data('i');
    Lcd_Data('a');
    Lcd_Data('n');
    Lcd_Data('g');

    Lcd_Cmd(0xC0);   //???
    Lcd_Data('I');
    Lcd_Data(' ');
    Lcd_Data('L');
    Lcd_Data('O');
    Lcd_Data('V');
    Lcd_Data('E');
    Lcd_Data(' ');
    Lcd_Data('Y');
    Lcd_Data('O');
    Lcd_Data('U');

    while(1);
}
