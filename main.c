
#include<reg51.h>
sbit rs =P2^6;
sbit en=P2^7;
sbit ldr=P2^0;
sbit consen=P2^1;
#define ldata P1
sbit light1=P2^2;
sbit light2=P2^3;
sbit light3=P2^4;
void delay(unsigned int time);void lcdcmd(unsigned char);
void lcdstr(unsigned char temp[]);
void lcddata(unsigned char);
void transmit(char temp[]);
main()
lcdcmd(0X01);
lcdcmd(0X0E);
lcdcmd(0X38);
lcdcmd(0X80);
lcdcmd(0XC0);
lcdstr(“STREET LIGHT MONTRNG”);
lcdcmd(0XC0);
lcdstr(“SYSTEM BY ECE BATCH”);
delay(900);
lcdcmd(0X01);
transmit(“Intensity Based Street Light Control System by ECE 01\r\n”);
while(1)
{
if((ldr==0) && (consen==1))
{
light1=light2=light3=1;
lcdcmd(0X80);
lcdstr(“STREET LIGHT STATUS”);
lcdcmd(0XC0);
lcdstr(“ DURING NIGHT ”);
}
elseif((ldr==1) && (consen==1))
{
light1=light2=light3=0;
lcdcmd(0X80);lcdstr(“STREET LIGHT STATUS”);
lcdcmd(0XC0);
lcdstr(“ DURING MORNING ”);
}
elseif((ldr==1) && (consen==0))
{
light1=light2=light3=0;
lcdcmd(0X80);
lcdstr(“STREET LIGHT STATUS”);
lcdcmd(0XC0);
lcdstr(“ CONTINUITY PROBLEM ”);
}
else
{
light1=light2=light3=0;
lcdcmd(0X80);
lcdstr(“STREET LIGHT STATUS”);
lcdcmd(0XC0);
lcdstr(“ CONTINUITY PROBLEM ”);
}
void delay(unsigned int time)
{
int i,j;
for(i=0;i<time;i++)
for(j=0;j<1275;j++);
}
void lcdcmd(unsigned char ch);
{
ldata=ch;rs=1;
en=1;
delay(2);
en=0;
}
void lcddata(unsigned char ch);
{
ldata=ch;
rs=0;
en=1;
delay(2);
en=0;
}
void lcdstr(unsigned chat temp[])
{
char k;
for(k=0;temp[k]!=’\0’;k++)
{
lcddata(temp[k]);
}
}
Void transmit(char temp[])
{
unsigned int s;
TMOD=0X20;
SCON=0X50;
TH1=-3;
TR1=1;
for(s=0;temp[s]!=’\0’;s++)
SBUF=temp[s];while(TI==0)
TI=0;
delay(10);
}
}
