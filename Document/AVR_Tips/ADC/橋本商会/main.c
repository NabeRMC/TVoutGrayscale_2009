/***
  ADC0��AD�ϊ������l�𕶎���ɕϊ�����UART��PC�ɑ���
  ADC0�̒l��700�ȏ�̎��ALED��_��������
  
  CPU: ATMEGA168 8MHz(����)
  Compiler: WinAVR20060421(AVR-GCC3.4.6)
  Date: 2006/12/24
  Author: Sho Hashimoto
  WebSite: http://shokai.org
  ***/

#include <avr/io.h>
#include <avr/interrupt.h>

#define TRUE 1
#define FALSE 0
#define NULL '\0'
#define sbi(BYTE,BIT) BYTE|=_BV(BIT) // BYTE�̎w��BIT��1���Z�b�g
#define cbi(BYTE,BIT) BYTE&=~_BV(BIT) // BYTE�̎w��BIT���N���A

/** ����ݒ� **/
#define FOSC 8000000 // 8MHz

/** UART�ݒ� **/
#define BAUD 9600 // 9600bps
#define MYUBRR FOSC/16/BAUD-1 // UART������
// #define UCSR0A_U2X0 1 // �{���t���O �����Ȃ�R�����g�A�E�g
#ifdef UCSR0A_U2X0 // �{������`����Ă���Ȃ��
 #define MYUBRR FOSC/16/(BAUD/2)-1 // UART������(�{��)
#endif
volatile char usart_recvData; // USART�Ŏ�M�����f�[�^

#define LED_SET() sbi(PORTB, PB0) // ��Տ�̓���m�FLED
#define LED_CLR() cbi(PORTB, PB0)


/* PORT�ݒ� */
void port_init(void){
  sbi(DDRB, PB0);
}


/* USART�ݒ� */
void usart_init(unsigned int ubrr){
  UBRR0H = (unsigned char)(ubrr>>8); // �{�[���[�g���8bit
  UBRR0L = (unsigned char)ubrr; // �{�[���[�g����8bit
  UCSR0A = (0<<U2X0); // ����
  UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0); // ����M���A��M�������荞�݋���
  UCSR0C = (0<<UMSEL00)|(3<<UCSZ00)|(1<<USBS0)|(0<<UPM00);
  // �t���[���ݒ� �񓯊��ʐM 8�r�b�g 1�X�g�b�v�r�b�g �p���e�B����
}

/* int�̌�����Ԃ� */
char getDigit(int n){
  char i;
  i = 0;
  while(n>0){
    n /= 10;
    i++;
  }
  return i;
}

/* int->String�ϊ� */
char *intToStr(int n, char *buf){ // �ϊ����鐔�A��Ɨ̈�
  int i, digit;
  digit = getDigit(n); // ����
  for(i = digit-1; i >= 0; i--){ // int�͍ő�5��
    buf[i] = n%10+'0';
    n /= 10;
  }
  buf[digit] = '\0'; // �s�����s
  return buf;
}

/* UART�ŕ����񑗐M */
void usart_sendStr(char *str){
  while(*str != NULL){
    loop_until_bit_is_set(UCSR0A,UDRE0); // ���M�f�[�^���W�X�^�󂫂܂őҋ@
    UDR0 = *str++; // 1�������M�A1�����i��
  }
}

/* AD�R���o�[�^�ݒ� */
void adc_init(void){
  ADMUX = (0<<REFS0); // �O����d��
  ADCSRA =(1<<ADEN)|(1<<ADSC)|(0<<ADPS0);
  // A/D�ϊ����A1��ڕϊ��J�n(����)�A������2
}

/* �s�����w�肵��AD�ϊ� return 0-1023 */
int adc_convert(char pin){
  int ad;
  ADMUX = pin; // AD�ϊ����̓s��
  cbi(ADCSRA,ADIF);
  sbi(ADCSRA,ADSC); // �ϊ��J�n
  loop_until_bit_is_set(ADCSRA,ADIF); // �ϊ������܂ő҂�
  ad = ADCL; // ����8bit�擾
  return ad += (ADCH<<8); // ���2bit�擾
}

int main(void){
  port_init(); // PORT�ݒ�
  usart_init(MYUBRR); // USART�ݒ�
  adc_init(); // ADConverter�ݒ�
  
  LED_SET(); // �N���m�FLED
  
  int ad;
  char buf[6];
  
  for(;;){
    ad = adc_convert(0); // ADC0����AD�ϊ�
    if(ad > 700) LED_SET();
    else LED_CLR();
    usart_sendStr(intToStr(ad,buf)); // AD�l�𕶎���ɂ��đ��M
    usart_sendStr("\r\n"); // ���s
  }
}



