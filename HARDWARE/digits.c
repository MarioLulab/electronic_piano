#include "digits.h"

/*

新分配
                    数码管
    PA15            DP(2)
    PB3             A(3)
    PB4             B(9)
    PB5             C(8)
    PB6             D(6)
    PB7             E(7)
    PB8             F(4)
    PB9             G(1)

    PA8             D1(10)
    PA11            D2(5)
----------------------------------
新新分配
                    数码管
    -PB13            B(9)   
    -PB14            C(8)
    -PB15            E(7)
    PB5             D(6)
    PB6             F(4)
    PB7             A(3)
    PB8             DP(2)
    PB9             G(1)

    PA8             D1(10)
    -PB12            D2(5)


*/
void DISPLAY_Init(void){
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |RCC_APB2Periph_GPIOC, ENABLE);	 //使能PA端口时钟
	
 	// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 \
    //                                 | GPIO_Pin_4 \
    //                                 | GPIO_Pin_5 \
    //                                 | GPIO_Pin_6 \
    //                                 | GPIO_Pin_7 \
    //                                 | GPIO_Pin_8 \
    //                                 | GPIO_Pin_9;

 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 \
                                    | GPIO_Pin_14 \
                                    | GPIO_Pin_15 \
                                    | GPIO_Pin_5 \
                                    | GPIO_Pin_6 \
                                    | GPIO_Pin_7 \
                                    | GPIO_Pin_8 \
                                    | GPIO_Pin_9 \
                                    | GPIO_Pin_12;


 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);				 //初始化B口

    // GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15 \
    //                             | GPIO_Pin_8 \
    //                             | GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);				 //初始化A口


     
    // GPIO_WriteBit(GPIOB, GPIO_Pin_8, Bit_RESET);    // DP
    // GPIO_WriteBit(GPIOB, GPIO_Pin_7, Bit_RESET);     // A
    // GPIO_WriteBit(GPIOA, GPIO_Pin_15, Bit_RESET);     // B
    // GPIO_WriteBit(GPIOB, GPIO_Pin_3, Bit_RESET);     // C
    // GPIO_WriteBit(GPIOB, GPIO_Pin_5, Bit_RESET);     // D
    // GPIO_WriteBit(GPIOB, GPIO_Pin_4, Bit_RESET);     // E
    // GPIO_WriteBit(GPIOB, GPIO_Pin_6, Bit_RESET);     // F
    // GPIO_WriteBit(GPIOB, GPIO_Pin_9, Bit_RESET);     // G


}


//选择显示数据位，2位输出数据只有一个置位，其为选择显示的位(digit selected)
void digit_select(int index)
{
    BitAction v[2];
    int i;

    for (i=0; i<2; i++){

        //根据index选择显示位
        if (index == i){
            v[i] = Bit_SET;
        }else{
            v[i] = Bit_RESET;
        }
    }

    GPIO_WriteBit(GPIOA, GPIO_Pin_8,  v[1]);
    GPIO_WriteBit(GPIOB, GPIO_Pin_12, v[0]);
}

//根据输入数字点亮对应led，共8位，包括小数点以及7段数码管
// input : digit 要显示的数据
//         index 要显示在数码管的第几位（0说明显示音高，1说明显示音级）
void digit_show(int digit, int index)
{

    int segment, i, base;

    /*
    v[8] = {dp,g,f,e,d,c,b,a}
    */
    BitAction v[8];

    if (index == 1){
        // 如果显示的是音级
        switch (digit){
            case    0   :  segment = 0xc0; break;
            case    1   :  segment = 0xf9; break;
            case    2   :  segment = 0xa4; break;
            case    3   :  segment = 0xb0; break;
            case    4   :  segment = 0x99; break;
            case    5   :  segment = 0x92; break;
            case    6   :  segment = 0x82; break;
            case    7   :  segment = 0xf8; break;
            case    8   :  segment = 0x80; break;
            case    9   :  segment = 0x90; break;
            default     :  segment = 0x86; break;
        }
    }
    else{
        // 如果显示的是音高
        switch (digit){
            case    LOW     :   segment = 0xe7;break;
            case    MID     :   segment = 0x8f;break;
            case    HIGH    :   segment = 0xde;break;
            default         :   segment = 0x86;break;
                                // 0x86 = 0b10000110
        }
    }

    base = 1 << 8;

    // 由于数码管为共阳极，所以此处置位为不显示。

    for (i=0; i<8; i++){
        base >>= 1;

        if ((segment & base )== 0){
            v[i] = Bit_RESET;
        }else{
            v[i] = Bit_SET;
        }

    }

    /*
    v[8] = {dp,g,f,e,d,c,b,a}
    */

    // GPIO_WriteBit(GPIOA, GPIO_Pin_15, v[0]);    // DP
    // GPIO_WriteBit(GPIOB, GPIO_Pin_3, v[7]);     // A
    // GPIO_WriteBit(GPIOB, GPIO_Pin_4, v[6]);     // B
    // GPIO_WriteBit(GPIOB, GPIO_Pin_5, v[5]);     // C
    // GPIO_WriteBit(GPIOB, GPIO_Pin_6, v[4]);     // D
    // GPIO_WriteBit(GPIOB, GPIO_Pin_7, v[3]);     // E
    // GPIO_WriteBit(GPIOB, GPIO_Pin_8, v[2]);     // F
    // GPIO_WriteBit(GPIOB, GPIO_Pin_9, v[1]);     // G

    // v[0] = Bit_RESET;

    //     v[1] = Bit_RESET;
    //     v[2] = Bit_RESET;
    //     v[3] = Bit_RESET;
    //     v[4] = Bit_RESET;
    //     v[5] = Bit_RESET;
    //     v[6] = Bit_RESET;
    //     v[7] = Bit_RESET;



    GPIO_WriteBit(GPIOB, GPIO_Pin_8, v[0]);    // DP
    GPIO_WriteBit(GPIOB, GPIO_Pin_7, v[7]);     // A
    GPIO_WriteBit(GPIOB, GPIO_Pin_13, v[6]);     // B
    GPIO_WriteBit(GPIOB, GPIO_Pin_14, v[5]);     // C
    GPIO_WriteBit(GPIOB, GPIO_Pin_5, v[4]);     // D
    GPIO_WriteBit(GPIOB, GPIO_Pin_15, v[3]);     // E
    GPIO_WriteBit(GPIOB, GPIO_Pin_6, v[2]);     // F
    GPIO_WriteBit(GPIOB, GPIO_Pin_9, v[1]);     // G


}

//控制时分复用，每调用一次显示对应的一位，使用静态变量控制选择位
// input : step 音级
//        level 音高 
void display(int step, int level){
    static int index = -1;
    int i;

    // index 0 -> 1, 
    //    left -> right 
    index = (index + 1) % 2;

    if (index == 0){
        // display level
        digit_select(index);
        digit_show(level, index);
        // digit_show(step, index);

    }
    else{
        // display step
        digit_select(index);
        digit_show(step, index);
    }

}


void showFree(void)
{

    static int free_index = -1;
    free_index = (free_index + 1) % 2;
    // 显示"--"的数码管段
    BitAction v[8];
    // int segment = 0b10111111
    int segment = 0xbf;
    int base = 1 << 8;
    int i;


    /*******************************
        写位选
    *******************************/
    digit_select(free_index);



    /*******************************
        写段选
    *******************************/
    // 由于数码管为共阳极，所以此处置位为不显示。
    for (i=0; i<8; i++){
        base >>= 1;

        if ((segment & base )== 0){
            v[i] = Bit_RESET;
        }else{
            v[i] = Bit_SET;
        }

    }

    /*
    v[8] = {dp,g,f,e,d,c,b,a}
    */

    // GPIO_WriteBit(GPIOA, GPIO_Pin_15, v[0]);    // DP
    // GPIO_WriteBit(GPIOB, GPIO_Pin_3, v[7]);     // A
    // GPIO_WriteBit(GPIOB, GPIO_Pin_4, v[6]);     // B
    // GPIO_WriteBit(GPIOB, GPIO_Pin_5, v[5]);     // C
    // GPIO_WriteBit(GPIOB, GPIO_Pin_6, v[4]);     // D
    // GPIO_WriteBit(GPIOB, GPIO_Pin_7, v[3]);     // E
    // GPIO_WriteBit(GPIOB, GPIO_Pin_8, v[2]);     // F
    // GPIO_WriteBit(GPIOB, GPIO_Pin_9, v[1]);     // G

    GPIO_WriteBit(GPIOB, GPIO_Pin_8, v[0]);    // DP
    GPIO_WriteBit(GPIOB, GPIO_Pin_7, v[7]);     // A
    GPIO_WriteBit(GPIOB, GPIO_Pin_13, v[6]);     // B
    GPIO_WriteBit(GPIOB, GPIO_Pin_14, v[5]);     // C
    GPIO_WriteBit(GPIOB, GPIO_Pin_5, v[4]);     // D
    GPIO_WriteBit(GPIOB, GPIO_Pin_15, v[3]);     // E
    GPIO_WriteBit(GPIOB, GPIO_Pin_6, v[2]);     // F
    GPIO_WriteBit(GPIOB, GPIO_Pin_9, v[1]);     // G


}