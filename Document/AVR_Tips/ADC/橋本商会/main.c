/***
  ADC0でAD変換した値を文字列に変換してUARTでPCに送る
  ADC0の値が700以上の時、LEDを点灯させる
  
  CPU: ATMEGA168 8MHz(内蔵)
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
#define sbi(BYTE,BIT) BYTE|=_BV(BIT) // BYTEの指定BITに1をセット
#define cbi(BYTE,BIT) BYTE&=~_BV(BIT) // BYTEの指定BITをクリア

/** 動作設定 **/
#define FOSC 8000000 // 8MHz

/** UART設定 **/
#define BAUD 9600 // 9600bps
#define MYUBRR FOSC/16/BAUD-1 // UART分周率
// #define UCSR0A_U2X0 1 // 倍速フラグ 等速ならコメントアウト
#ifdef UCSR0A_U2X0 // 倍速が定義されているならば
 #define MYUBRR FOSC/16/(BAUD/2)-1 // UART分周率(倍速)
#endif
volatile char usart_recvData; // USARTで受信したデータ

#define LED_SET() sbi(PORTB, PB0) // 基盤上の動作確認LED
#define LED_CLR() cbi(PORTB, PB0)


/* PORT設定 */
void port_init(void){
  sbi(DDRB, PB0);
}


/* USART設定 */
void usart_init(unsigned int ubrr){
  UBRR0H = (unsigned char)(ubrr>>8); // ボーレート上位8bit
  UBRR0L = (unsigned char)ubrr; // ボーレート下位8bit
  UCSR0A = (0<<U2X0); // 等速
  UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0); // 送受信許可、受信完了割り込み許可
  UCSR0C = (0<<UMSEL00)|(3<<UCSZ00)|(1<<USBS0)|(0<<UPM00);
  // フレーム設定 非同期通信 8ビット 1ストップビット パリティ無し
}

/* intの桁数を返す */
char getDigit(int n){
  char i;
  i = 0;
  while(n>0){
    n /= 10;
    i++;
  }
  return i;
}

/* int->String変換 */
char *intToStr(int n, char *buf){ // 変換する数、作業領域
  int i, digit;
  digit = getDigit(n); // 桁数
  for(i = digit-1; i >= 0; i--){ // intは最大5桁
    buf[i] = n%10+'0';
    n /= 10;
  }
  buf[digit] = '\0'; // 行末改行
  return buf;
}

/* UARTで文字列送信 */
void usart_sendStr(char *str){
  while(*str != NULL){
    loop_until_bit_is_set(UCSR0A,UDRE0); // 送信データレジスタ空きまで待機
    UDR0 = *str++; // 1文字送信、1文字進む
  }
}

/* ADコンバータ設定 */
void adc_init(void){
  ADMUX = (0<<REFS0); // 外部基準電圧
  ADCSRA =(1<<ADEN)|(1<<ADSC)|(0<<ADPS0);
  // A/D変換許可、1回目変換開始(調整)、分周率2
}

/* ピンを指定してAD変換 return 0-1023 */
int adc_convert(char pin){
  int ad;
  ADMUX = pin; // AD変換入力ピン
  cbi(ADCSRA,ADIF);
  sbi(ADCSRA,ADSC); // 変換開始
  loop_until_bit_is_set(ADCSRA,ADIF); // 変換完了まで待つ
  ad = ADCL; // 下位8bit取得
  return ad += (ADCH<<8); // 上位2bit取得
}

int main(void){
  port_init(); // PORT設定
  usart_init(MYUBRR); // USART設定
  adc_init(); // ADConverter設定
  
  LED_SET(); // 起動確認LED
  
  int ad;
  char buf[6];
  
  for(;;){
    ad = adc_convert(0); // ADC0からAD変換
    if(ad > 700) LED_SET();
    else LED_CLR();
    usart_sendStr(intToStr(ad,buf)); // AD値を文字列にして送信
    usart_sendStr("\r\n"); // 改行
  }
}



