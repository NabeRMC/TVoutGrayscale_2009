

								/*	Arduino AREF-OPEN,AVCC=VCC			*/
#define	INI_ADMUX	0x75		/*	AVCC, left move, ADC5	011-_0101B	*/
#define	INI_ADCSRA	0xF0		/*	enable, start, auto, clear, disable, CK/2	1111_0000B	*/
#define	INI_ADCSRB	0x40		/*	MPX enable continous conv.	-1--_000B	*/

/*--- high speed PWM ---
	WGM02-0 = 111
	BOTTOM - TOP/[OCR0A](周期)

*/

/*--- PWM1 CTC mode ---
	WGM02-0 = 010
	TCNT0 == OCR0AでTCNT0 <- 0
	COM0A1-0 = 01,DDR_OC0A = 1
	交互動作
	focnx = fclk_I/O/( 2*N*(1+OCR0x) )
	
	
	fclk_IO = 16MHz
	focnx = 16MHz/(2N+2OCR0x)
	2N+2OCR0x = 16MHz/focnx
	2OCR0 = 16MHz/focnx - 2N
	OCR0 = 8MHz/focnx -N
	N=1なら
	OCR0 = 8MHz/focnx -1
	440Hz時
	OCR0 = 8000000Hz/440Hz -1 = 18181.81...
	前置分周= 1では成立せず。
	
	
--- PWM2 CTCモード ---

	WGM22-0 = 010
	TCNT2 == OCR2AでTCNT2 <- 0
	COM2A1-0 = 01,DDR_OC2A = 1
	交互動作
	focnx = fclk_I/O/( 2*N*(1+OCR2x) )
	
	
	fclk_IO = 16MHz
	focnx = 16MHz/(2N+2OCR2x)
	2N+2OCR2x = 16MHz/focnx
	2OCR2 = 16MHz/focnx - 2N
	OCR2 = 8MHz/focnx -N
	N=1なら
	OCR0 = 8MHz/focnx -1
	261Hz時
	OCR0 = 8000000Hz/261Hz -1 = 30651
	Nは1,8,32,64,128,256,1024から選択できる
	30651/256=119
	N=128とする。
	OCR2 = 8MHz/focnx -N
	OCR2 = 8MHz/focnx -128
	
	
	16MHz/256 = 62500Hz
	62500Hz/523Hz = 119.5
	
	focnx = fclk_I/O/( 2*N*(1+OCR2x) )
	N=128とする
	
	focnx = fclkIO/( 256+256*OCR2x )
	256+256*OCR2x = fclkIO/focnx
	OCR2x 	= (fclkIO/focnx - 256) /256
			= (16MHZ/focnx -256)/256
	
	523Hz : (16MHz/523Hz -256)/256 = 118
	261Hz : (16MHz/261Hz -256)/256 = 238
	
ド　ハ　Ｃ　　16.352　32.703　65.406　130.81　261.63　523.25　1046.5　2093.0　4186.0
　　　　Ｃ♯　17.324　34.648　69.296　138.59　277.18　554.37　1108.7　2217.5　4434.9
レ　ニ　Ｄ　　18.354　36.708　73.416　146.83　293.66　587.33　1174.7　2349.3　4698.6
　　　　Ｄ♯　19.445　38.891　77.782　155.56　311.13　622.25　1244.5　2489.0　4978.0
ミ　ホ　Ｅ　　20.602　41.203　82.407　164.81　329.63　659.26　1318.5　2637.0　5274.0
ﾌｧ　ヘ　Ｆ　　21.827　43.654　87.307　174.61　349.23　698.46　1396.9　2793.8　5587.7
　　　　Ｆ♯　23.125　46.249　92.499　185.00　369.99　739.99　1480.0　2960.0　5919.9
ソ　ト　Ｇ　　24.500　48.999　97.999　196.00　392.00　783.99　1568.0　3136.0　6271.9
　　　　Ｇ♯　25.957　51.913　103.83　207.65　415.30　830.61　1661.2　3322.4　6644.9
ラ　イ　Ａ　　27.500　55.000　110.00　220.00　440.00　880.00　1760.0　3520.0　7040.0
　　　　Ａ♯　29.135　58.270　116.54　233.08　466.16　932.33　1864.7　3729.3　7458.6
シ　ロ　Ｈ　　30.868　61.735　123.47　246.94　493.88　987.77　1975.5　3951.1　7902.1


	
	
*/


