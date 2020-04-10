#ifndef __SPB_H
#define	__SPB_H	   
#include "spblcd.h"   
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//ALIENTEK STM32F103������
//SPBЧ��ʵ�� ����	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2015/3/6
//�汾��V1.2
//��Ȩ���У�����ؾ���
//Copyright(C) �������������ӿƼ����޹�˾ 2014-2024
//All rights reserved
//*******************************************************************************
//V1.1 20150322
//����gui_draw_bline����
//�޸����4.3/7��������ͼ����ʾ��ʽ,ֱ��ȫ������DMA,������ٶ�.
//V1.2 20150325
//1,����SPB_ICOS_NUM,�����޶�������ͼ������
//2,�޸��Դ�洢����ΪSPI FLASH
//3,�޸�spb_init����
////////////////////////////////////////////////////////////////////////////////// 	




#define SPB_MOVE_WIN 		2 		//SPB������ⴰ��ֵ
#define SPB_MOVE_MIN		8		//SPB��Ϊ�ǻ�������Сֵ,��������Ϊ�ǻ���,���ǲ�һ���ᷭҳ	   
#define SPB_MOVE_ACT 		50 		//SPB����������ֵ,�������ֵ������з�ҳ
#define SPB_ICOS_NUM 		11 		//SPB������ͼ�����(����3����ͼ��)

#define SPB_ALPHA_VAL 		18 		//SPBѡ��͸��������
#define SPB_ALPHA_COLOR		WHITE	//SPB͸��ɫ
#define SPB_FONT_COLOR 		BLUE 	//SPB������ɫ
#define SPB_MICO_BKCOLOR	0XA5BB	//micoͼ�걳��ɫ

extern u8*const spb_bkpic_path_tbl[3][2];
extern u8*const spb_icos_path_tbl[3][2][8];
extern u8*const spb_micos_path_tbl[3][3];

//SPB ͼ����ƽṹ��
__packed typedef struct _m_spb_icos
{										    
	u16 x;			//ͼ�����꼰�ߴ�
	u16 y;
	u8 width;
	u8 height; 
	u8 * path;		//ͼ��·��ָ��
	u8 * name;		//ͼ������ָ��
}m_spb_icos;


//SPB ������
typedef struct _m_spb_dev
{										    
	u16 oldxpos;     			//��һ��TP��x����λ��
 	u16 curxpos;     			//��ǰtp���µ�x����
	u16 curypos;     			//��ǰtp���µ�y����
	u16	spbsta;					//spb״̬
								//[15]:��һ�ΰ��±�־
								//[14]:������־;					 
								//[13~0]:��������
	
	u16 pos;                    //��ǰ֡��λ��(x����)
	u8 frame;				 	//��ǰ֡(0/1)
	
	u8 stabarheight;			//״̬���߶�
	u16 spbheight;				//SPB��������߶�
	u16 spbwidth;				//SPB�����������,һ�����LCD�ֱ��ʿ���
	 
	u8 selico;					//��ǰѡ�е�ͼ��.
								//0~8,��ѡ�е�ͼ����	 
								//����,û���κ�ͼ�걻ѡ��	  
	m_spb_icos icos[2][8];		//2ҳ,ÿҳ8��ͼ�� 
	m_spb_icos micos[3];		//3����ͼ��
}m_spb_dev;
extern m_spb_dev spbdev;




u8 spb_init(u8 mode);
void spb_clock_set(u8 PLL);
u8 spb_load_icos(u8 frame);
u8 spb_load_micos(void);
void spb_gsm_signal_show(u16 x,u16 y,u8 signal);
void spb_stabar_msg_show(u8 clr);
u8 spb_load_mui(void);
void spb_frame_move(u8 dir,u8 skips,u16 pos);
void spb_unsel_micos(u8 selx);
void spb_set_sel(u8 sel);
u8 spb_move_chk(void);
#endif
























