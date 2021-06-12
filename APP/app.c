#include "includes.h"

#define transfer_music(level, step) (level == 0 ? step-6 : \
                                     level == 1 ? step+1 : \
                                     step + 8)

static struct real_pitch YUEDING[] = {
    {0.5, 2},
    {0.5, 5},
    {0.5, 6},
    {0.5, 7},
    {0.5,6},
    {0.5,5},
    {0.5,7},
    {1.5,6},
    {0.5,2},
    {1,2},

    {0.5,-1},
    {0.5,0},
    {0.5,3},
    {0.5,4},
    {0.5,5},
    {0.5,4},
    {1,3},
    {1,5},
    {1.5,4},
    {0.5,0},
    {1,2},

    {1,-1},
    {0.5,3},
    {0.5,2},
    {0.5,2},
    {0.5,0},
    {1.5,2},
    {0.25,5},

    {0.5,-1},
    {0.5,0},
    {1,0},
    {0.5,6},
    {1.5,5},

    {0.25,6},
    {0.25,7},
    {0.5,8},
    {0.5,7},
    {0.5,6},
    {0.5,5},
    {1,5},
    {0.5,3},
    {2.5,6},

    {1.5,-1},
    {0.5, 2},
    {0.5, 5},
    {0.5, 6},
    {0.5, 7},
    {0.5,6},
    {0.5,5},
    {0.5,7},
    {1.5,6},
    {0.5,transfer_music(LOW,7)},
    {1,transfer_music(LOW,5)},

    {0.5,-1},
    {0.5,0},
    {0.5,3},
    {0.5,4},
    {0.5,5},
    {0.5,4},
    {1,3},
    {1,5},
    {1.5,4},
    {0.5,0},
    {1,2},

    {1,-1},
    {0.5,transfer_music(LOW,6)},
    {0.5,transfer_music(LOW,5)},
    {0.5,transfer_music(LOW,5)},
    {0.5,transfer_music(LOW,3)},
    {0.75,transfer_music(LOW,5)},
    {1.25,transfer_music(MID,1)},
    {1.5,transfer_music(MID,2)},
    {0.5,transfer_music(LOW,3)},
    {1,transfer_music(MID,1)},

    {0.5,-1},
    {0.25,transfer_music(LOW,6)},
    {0.25,transfer_music(LOW,7)},
    {1,transfer_music(MID,1)},
    {1,transfer_music(LOW,6)},
    {1.25,transfer_music(MID,1)},
    {0.75,transfer_music(MID,6)},
    {1.25,transfer_music(MID,5)},
    {1.25,transfer_music(MID,5)}

};


static struct real_pitch XITIEJIE[] = {
    {0.5,transfer_music(LOW,5)},
    {0.5,transfer_music(MID,1)},
    {0.5,transfer_music(MID,2)},
    {0.25,transfer_music(MID,2)},
    {0.5,transfer_music(MID,3)},
    {0.25,transfer_music(MID,3)},
    {0.5,-1},

    {0.25,transfer_music(LOW,5)},
    {0.5,transfer_music(MID,4)},
    {0.5,transfer_music(MID,3)},
    {0.5,transfer_music(MID,2)},
    {0.75,transfer_music(MID,1)},
    {0.5,transfer_music(MID,2)},
    {0.25,transfer_music(MID,2)},
    {0.5,transfer_music(MID,2)},
    {0.5,transfer_music(MID,3)},
    {1.25,transfer_music(LOW,6)},
    {1,-1},

    {0.5,transfer_music(MID,4)},
    {0.25,transfer_music(MID,4)},
    {0.75,transfer_music(MID,4)},
    {0.25,transfer_music(LOW,6)},
    {0.5,transfer_music(MID,4)},
    {0.5,transfer_music(MID,3)},
    {0.5,transfer_music(MID,2)},
    {0.5,transfer_music(MID,1)},
    {0.25,transfer_music(MID,1)},
    {0.5,transfer_music(MID,1)},
    {0.25,transfer_music(LOW,6)},
    {0.5,transfer_music(MID,1)},
    {0.5,transfer_music(MID,2)},
    {1.25,transfer_music(MID,2)},
    {1,-1},

    {0.5,transfer_music(MID,5)},
    {0.25,transfer_music(MID,5)},
    {1.25,transfer_music(MID,5)},
    {0.25,transfer_music(LOW,6)},
    {0.75,transfer_music(MID,6)},
    {0.5,transfer_music(MID,5)},
    {0.5,transfer_music(MID,4)},
    {0.75,transfer_music(MID,3)},
    {0.5,transfer_music(MID,5)},
    {0.25,transfer_music(MID,4)},
    {0.5,transfer_music(MID,3)},
    {0.5,transfer_music(MID,4)},
    {1.25,transfer_music(LOW,6)},
    {0.5,-1},

    {0.25,transfer_music(MID,2)},
    {0.25,transfer_music(MID,3)},
    {0.5,transfer_music(MID,3)},
    {0.25,transfer_music(MID,4)},
    {0.5,transfer_music(MID,4)},
    {0.5,transfer_music(MID,3)},
    {0.5,transfer_music(MID,3)},
    {0.5,transfer_music(MID,2)},
    {0.5,transfer_music(MID,1)},
    {0.75,transfer_music(LOW,6)},

    {0.5,transfer_music(MID,1)},
    {0.25,transfer_music(MID,1)},
    {0.5,transfer_music(MID,1)},
    {0.5,transfer_music(MID,2)},
    {1.25,transfer_music(MID,2)}

};


static struct real_pitch SONGBIE[] = {

    {1,transfer_music(MID,5)},
    {0.5,transfer_music(MID,3)},
    {0.5,transfer_music(MID,5)},
    {2,transfer_music(HIGH,1)},
    {1,transfer_music(MID,6)},
    {1,transfer_music(HIGH,1)},
    {2,transfer_music(MID,5)},
    {0.5,transfer_music(MID,5)},
    {0.5,transfer_music(MID,1)},
    {0.5,transfer_music(MID,2)},
    {1,transfer_music(MID,3)},
    {0.5,transfer_music(MID,2)},
    {0.5,transfer_music(MID,1)},
    {2,transfer_music(MID,2)},
    {2,-1},

    {1,transfer_music(MID,5)},
    {0.5,transfer_music(MID,3)},
    {0.5,transfer_music(MID,5)},
    {1.5,transfer_music(HIGH,1)},
    {0.5,transfer_music(MID,7)},
    {1,transfer_music(MID,6)},
    {1,transfer_music(HIGH,1)},
    {2,transfer_music(MID,5)},
    {1,transfer_music(MID,5)},
    {0.5,transfer_music(MID,2)},
    {0.5,transfer_music(MID,3)},
    {1.5,transfer_music(MID,4)},
    {0.5,transfer_music(LOW,7)},
    {2,transfer_music(MID,1)},
    {2,-1},

    {1,transfer_music(MID,6)},
    {1,transfer_music(HIGH,1)},
    {2,transfer_music(HIGH,1)},
    {1,transfer_music(MID,7)},
    {0.5,transfer_music(MID,6)},
    {0.5,transfer_music(MID,7)},
    {2,transfer_music(HIGH,1)},
    {0.5,transfer_music(MID,6)},
    {0.5,transfer_music(MID,7)},
    {0.5,transfer_music(HIGH,1)},
    {0.5,transfer_music(MID,6)},
    {0.5,transfer_music(MID,6)},
    {0.5,transfer_music(MID,5)},
    {0.5,transfer_music(MID,3)},
    {0.5,transfer_music(MID,1)},
    {2,transfer_music(MID,2)},
    {2,-1},

    {1,transfer_music(MID,5)},
    {0.5,transfer_music(MID,3)},
    {0.5,transfer_music(MID,5)},
    {1.5,transfer_music(HIGH,1)},
    {0.5,transfer_music(MID,7)},
    {1,transfer_music(MID,6)},
    {1,transfer_music(HIGH,1)},
    {2,transfer_music(MID,5)},
    {1,transfer_music(MID,5)},
    {0.5,transfer_music(MID,2)},
    {0.5,transfer_music(MID,3)},
    {1.5,transfer_music(MID,4)},
    {0.5,transfer_music(LOW,7)},
    {2,transfer_music(MID,1)},
    {2,-1},

};

static struct real_pitch HUANLESONG[] = {

    {1,transfer_music(MID,3)},
    {1,transfer_music(MID,3)},
    {1,transfer_music(MID,4)},
    {1,transfer_music(MID,5)},
    {1,transfer_music(MID,5)},
    {1,transfer_music(MID,4)},
    {1,transfer_music(MID,3)},
    {1,transfer_music(MID,2)},
    {1,transfer_music(MID,1)},
    {1,transfer_music(MID,1)},
    {1,transfer_music(MID,2)},
    {1,transfer_music(MID,3)},
    {1.5,transfer_music(MID,3)},
    {0.5,transfer_music(MID,2)},
    {2,transfer_music(MID,2)},

    {1,transfer_music(MID,3)},
    {1,transfer_music(MID,3)},
    {1,transfer_music(MID,4)},
    {1,transfer_music(MID,5)},
    {1,transfer_music(MID,5)},
    {1,transfer_music(MID,4)},
    {1,transfer_music(MID,3)},
    {1,transfer_music(MID,2)},
    {1,transfer_music(MID,1)},
    {1,transfer_music(MID,1)},
    {1,transfer_music(MID,2)},
    {1,transfer_music(MID,3)},
    {1.5,transfer_music(MID,2)},
    {0.5,transfer_music(MID,1)},
    {2,transfer_music(MID,1)},

    {1,transfer_music(MID,2)},
    {1,transfer_music(MID,2)},
    {1,transfer_music(MID,3)},
    {1,transfer_music(MID,1)},
    {1,transfer_music(MID,2)},
    {0.5,transfer_music(MID,3)},
    {0.5,transfer_music(MID,4)},
    {1,transfer_music(MID,3)},
    {1,transfer_music(MID,1)},

    {1,transfer_music(MID,2)},
    {0.5,transfer_music(MID,3)},
    {0.5,transfer_music(MID,4)},
    {1,transfer_music(MID,3)},
    {1,transfer_music(MID,2)},
    {1,transfer_music(MID,1)},
    {1,transfer_music(MID,2)},
    {1,transfer_music(LOW,6)},
    {2,transfer_music(MID,3)},
    {1,transfer_music(MID,3)},
    {1,transfer_music(MID,4)},
    {1,transfer_music(MID,5)},
    {1,transfer_music(MID,5)},
    {1,transfer_music(MID,4)},
    {1,transfer_music(MID,3)},
    {1,transfer_music(MID,2)},
    {1,transfer_music(MID,1)},
    {1,transfer_music(MID,1)},
    {1,transfer_music(MID,2)},
    {1,transfer_music(MID,3)},
    {1.5,transfer_music(MID,2)},
    {0.5,transfer_music(MID,1)},
    {2,transfer_music(MID,1)},

};



/*
    引脚设置：
    STM32			器 件

----------------------------------
新新分配
                    数码管
    PB13            B(9)   
    PB14            C(8)
    PB15            E(7)
    PB5             D(6)
    PB6             F(4)
    PB7             A(3)
    PB8             DP(2)
    PB9             G(1)

    PA8             D1(10)
    PB12            D2(5)


                    测试LED
    PC13 ->         LED
    

                      蜂鸣器
    PB0(TIM3_CH3) -> PWM输出


                        光敏电阻
    PA1(ADC1/2_IN1) -> 电阻3
    PA3(ADC1/2_IN3) -> 电阻2
    PA4(ADC1/2_IN4) -> 电阻1
    PA5(ADC1/2_IN5) -> 电阻0

                      USB-TTL模块
    PA9(TX)             RX
    PA10(RX)            TX

    TIM2


*/


/*
按键对照表
(x : 遮挡; o : 未遮挡)
从左往右：电阻3 电阻2 电阻1 电阻0   数值            功能
          o     o     o    o       0             不响
          x     o     o    o       1             低音La
          o     x     o    o       2             低音Xi
          x     x     o    o       3             中音Do
          o     o     x    o       4             中音Re
          x     o     x    o       5             中音Me
          o     x     x    o       6             中音Fa
          x     x     x    o       7             中音So
          o     o     o    x       8             中音La
          x     o     o    x       9             中音Xi
          o     x     o    x      10             高音Do
          x     x     o    x      11             高音Re
          o     o     x    x      12             放歌或切到下一首歌
          x     o     x    x      13             录音开始/录音结束并自动播放
          o     x     x    x      14             自检(1,2,3,...)
          x     x     x    x      15             退出功能模式，停止当前所有音






*/

static int led_ctl = -1;


// 设置任务优先级
#define START_TASK_PRIO     10

// 设置任务堆栈
#define START_STK_SIZE      64
OS_STK START_TASK_STK[START_STK_SIZE];

// 任务函数接口
void start_task(void *pdata);

//读按键数据的任务
//设置任务优先级
#define KEY_TASK_PRIO       			1 
//设置任务堆栈大小
#define KEY_STK_SIZE  		    		64
//任务堆栈	
OS_STK KEY_TASK_STK[KEY_STK_SIZE];
//任务函数
void KEY_task(void *pdata);

//数码管动态扫描的任务
//设置任务优先级
#define DISPLAY_TASK_PRIO       		3 
//设置任务堆栈大小
#define DISPLAY_STK_SIZE  		    		64
//任务堆栈	
OS_STK DISPLAY_TASK_STK[DISPLAY_STK_SIZE];
//任务函数
void DISPLAY_task(void *pdata);


//开启拓展功能的任务
//设置任务优先级
#define FUNCTION_TASK_PRIO       		6 
//设置任务堆栈大小
#define FUNCTION_STK_SIZE  		    		64
//任务堆栈	
OS_STK FUNCTION_TASK_STK[FUNCTION_STK_SIZE];
//任务函数
void FUNCTION_task(void *pdata);

// 标记现在要实现什么功能
int Function_Tag = FREE;
// 额外功能退出标志
int Exit_Flag = 1;

// 开启录音功能的标志
int Record_Flag = 0;

// 记录用户的谱子
#define MAX_BUFFER 100
int User_puzi[MAX_BUFFER] = {-1};
int User_puzi_index = 0;    // 记录用户输入的音符的长度






void LED_task(void *pdata);
void test_DISPLAY_task(void *pdata);
void KEY_scan(float threshold_voltage);

void do_self_check(void);
void do_play(void);
void do_record(void);

// OS_EVENT * msg_data;

// 1 -> 有遮挡
// 0 -> 无遮挡
int KEY_value[4] = {0,0,0,0};   // 0->3(MSB->LSB) : 从右到左

// 数码管显示功能
int beep_key_value = -1;

// 按键读取功能
int read_ready_flag = 0;    // 可以开始读按键值的标志
int last_key_value = -1;
int current_key_value = -1;



void SysTick_Handler(void){
    OS_CPU_SR   cpu_sr;
    OS_ENTER_CRITICAL();
    OSIntNesting++;
    OS_EXIT_CRITICAL();
    OSTimeTick();
    OSIntExit();
}
void Delay_ms(int times);
void Delay_us(int times);
void start_2Seconds_Int(void);
void start_ready_Int(void);
void play_song(struct real_pitch* puzi, int length);


// 数码管扫描的空闲标志
int free_flag = 1;  // free_flag == 1 -> 显示'--'
                    // free_flag == 0 -> 显示正常


int main(){

    // 硬件初始化
    LED_Init();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
    DISPLAY_Init();
    Adc_Init();


    uart_init(115200);

    //  初始时蜂鸣器不响
    // uint16_t arr = 391;
    // uint16_t psc = 350;
    // SOUND_Init(arr, psc);   //注意填写arr和psc值


    // 两秒中断定时器初始化
    TIM2_Int_Init(19999, 7199);
    // 0.2s定时器初始化
    TIM4_Int_Init(1999, 7199);


    OSInit();
    OS_CPU_SysTickInit();




    // 创建起始任务
 	OSTaskCreate(start_task,(void *)0,(OS_STK *)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO );

    OSStart();

    return 0;
}


//开始任务
void start_task(void *pdata)
{
    OS_CPU_SR cpu_sr=0;
	pdata = pdata; 

  	OS_ENTER_CRITICAL();			//进入临界区(无法被中断打断)    
 	
    // 创建数码管动态扫描任务
    OSTaskCreate(DISPLAY_task,(void *)0,(OS_STK*)&DISPLAY_TASK_STK[DISPLAY_STK_SIZE-1],DISPLAY_TASK_PRIO);						   

    // 创建按键扫描任务
    OSTaskCreate(KEY_task,(void *)0,(OS_STK*)&KEY_TASK_STK[KEY_STK_SIZE-1],KEY_TASK_PRIO);

    // 创建功能任务
    OSTaskCreate(FUNCTION_task,(void *)0,(OS_STK*)&FUNCTION_TASK_STK[FUNCTION_STK_SIZE-1],FUNCTION_TASK_PRIO);


	OSTaskSuspend(START_TASK_PRIO);	//挂起起始任务.
	OS_EXIT_CRITICAL();				//退出临界区(可以被中断打断)
}


void Delay_ms(int times){
    OSTimeDly(OS_TICKS_PER_SEC / 1000 * times);
}

void Delay_us(int times){
    int i;
    for(i=0;i<times;i++);
}

// 点灯测试程序
void LED_task(void* pdata){

    while(1){

        GPIO_SetBits(GPIOC, GPIO_Pin_13);   // 灭灯
        Delay_ms(1000);
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);   // 点灯
        Delay_ms(1000);

    }

}



void FUNCTION_task(void *pdata){

    while(1){

        if(Exit_Flag == 0){
            // 如果还未退出功能
            switch (Function_Tag)
            {
            case FREE:
                break;
            case SELF_CHECK:
                /* 循环播放Do,Re,Mi... */
                do_self_check();
                break;

            case PLAY:
                /* 播放歌曲或切到下一首歌 */
                /* 实现连续切歌 */
                do_play();
                break;

            case RECORD:
                /* 录音模式。第一次按下此按钮时，进入录音；第二次按下此按钮式，播放录音 */
                do_record();
                break;

            default:
                break;
            }
        }

        Delay_ms(100);
    }


}



void KEY_task(void *pdata){
    
    float threshold = 1.7;

    unsigned int current_arr = pitch_table[0].arr;
    unsigned int current_psc = pitch_table[0].psc;


    while(1){
        // 依次扫描按键
        KEY_scan(threshold);

        if (last_key_value != current_key_value){
            // 如果本次扫描得到的按键值不同于上一次
            start_ready_Int();
        }


        if (read_ready_flag == 1){
            read_ready_flag = 0;
            if (current_key_value == -1 ){
                // TIM_Cmd(TIM3, DISABLE);  //停止TIM3，停止输出PWM波
                // free_flag = 1;
                // last_key_value = current_key_value;
                continue;
            }
            else if (current_key_value >=0 && current_key_value <= 10)            
            {
                // 改变音调
                free_flag = 0;
                SOUND_Init(pitch_table[current_key_value].arr, pitch_table[current_key_value].psc);
                last_key_value = current_key_value;

                if (Exit_Flag == 1){
                    beep_key_value = current_key_value;
                    start_2Seconds_Int();
                }

                if (Record_Flag){
                    // User_puzi[User_puzi_index++] = beep_key_value;
                    beep_key_value = current_key_value;
                    User_puzi[User_puzi_index++] = current_key_value;
                    start_2Seconds_Int();

                }

                if (Function_Tag == FREE){
                    beep_key_value = current_key_value;
                    // start_2Seconds_Int();
                }

            }
            else if (current_key_value == 11){
                // play_song(YUEDING, 83);
                // play_song(XITIEJIE,62);
                Function_Tag = PLAY;
                Exit_Flag = 0;
            }
            else if(current_key_value == 12){
                Function_Tag = RECORD;
                Exit_Flag = 0;
            }
            else if(current_key_value == 13){
                Function_Tag = SELF_CHECK;
                Exit_Flag = 0;
            }
            else if(current_key_value == 14){
                // 如果按下退出
                free_flag = 1;  // 显示Free
                Function_Tag = FREE;    // function task 进入FREE
                Exit_Flag = 1;          // 退出特殊特殊功能标志位置位
                memset(User_puzi, -1, MAX_BUFFER);  // 清空用户自定义输入
            }

            // 按键值发生了变化
            printf("%d\n\r",current_key_value);



            if (Exit_Flag == 0){
                // 如果进入了特殊功能模式
                GPIO_ResetBits(GPIOC, GPIO_Pin_13);
            }
            else {
                // 如果退出了特殊功能模式
                GPIO_SetBits(GPIOC, GPIO_Pin_13);
            }        

        }
    
        Delay_ms(50);
    }

}


void DISPLAY_task(void *pdata){
	  
    int step = 1,level = MID;

    while(1){

        if (free_flag == 1){
            // 没有遮挡
            showFree();
        }
        // else if (beep_key_value >= 0 && beep_key_value <= 10){
        else{
            step = pitch_table[beep_key_value].step;
            level = pitch_table[beep_key_value].level;
            display(step, level);
        }

        Delay_ms(10);
    }

}



// 输入: puzi 谱子指针
//       length 谱子的长度
void play_song(struct real_pitch* puzi, int length){
    int i = 0;
    int k_time = 750;  // 与节拍相关的系数，单位ms
    
    uint16_t arr = 0;
    uint16_t psc = 0;
    int index = 0;
    printf("Play song!\n\r");

    
        for (i=0;i<length;i++){

            if (Exit_Flag || Function_Tag == PLAY){
                // 如果拓展功能标志置位
                free_flag = 1;
                TIM_Cmd(TIM3, DISABLE);  //停止TIM3
                return;
            }


            index = puzi[i].pitch_index;

            if (index == -1){
                TIM_Cmd(TIM3, DISABLE);  //停止TIM3
                Delay_ms(k_time*puzi[i].delay_time);
            }
            else{
                beep_key_value = index;
                SOUND_Init(pitch_table[index].arr,pitch_table[index].psc);
                Delay_ms(k_time * puzi[i].delay_time);
            }

        }

    TIM_Cmd(TIM3, DISABLE);  //停止TIM3
}

void do_self_check(void){

    Function_Tag == FREE;
    printf("Self Check!\n\r");


    int pitch_length = 11;
    int i;
    for(i=0;i<pitch_length;i++){

        if (Exit_Flag){
            // Exit_Flag = 0;
            free_flag = 1;
            TIM_Cmd(TIM3, DISABLE);  //停止TIM3
            return;
        }

        SOUND_Init(pitch_table[i].arr, pitch_table[i].psc);
        beep_key_value = i;
        Delay_ms(500);

    }

}


void do_play(void){

    Function_Tag = FREE;    // 重新设Tag为FREE


    static int do_play_count = -1; // 统计进入do_play()函数的次数

    do_play_count = (do_play_count + 1) % 4;

    if(do_play_count == 0){
        play_song(YUEDING,83);
    }
    else if (do_play_count == 1){
        play_song(XITIEJIE,62);
    }
    else if(do_play_count == 2){
        play_song(SONGBIE,61);
    }
    else if(do_play_count == 3){
        play_song(HUANLESONG,62);
    }


}

void play_record_song(int* puzi, int length){

    Function_Tag = FREE;    // 重新设Tag为FREE

    int i = 0;
    int k_time = 750;  // 与节拍相关的系数，单位ms
    
    uint16_t arr = 0;
    uint16_t psc = 0;
    int index = 0;

    printf("play record song!\n\r");

    
    for (i=0;i<length;i++){

            if (Exit_Flag){
                // 如果拓展功能标志置位
                free_flag = 1;
                TIM_Cmd(TIM3, DISABLE);  //停止TIM3
                return;
            }


            index = puzi[i];

            if (index == -1){
                TIM_Cmd(TIM3, DISABLE);  //停止TIM3
                Delay_ms(k_time);
            }
            else{
                beep_key_value = index;
                SOUND_Init(pitch_table[index].arr,pitch_table[index].psc);
                Delay_ms(k_time);
            }

        }

    TIM_Cmd(TIM3, DISABLE);  //停止TIM3
}

void do_record(void){

    Function_Tag = FREE;

    static int do_record_count = -1; // 统计进入do_record()函数的次数
    
    do_record_count = (do_record_count + 1) % 2;

    if(do_record_count == 0){
        // 录音模式开启
        printf("do record!\n\r");

        User_puzi_index = 0;
        memset(User_puzi, -1, MAX_BUFFER);
        Record_Flag = 1;
    }
    else if (do_record_count == 1){
        // 回放模式开启
        Record_Flag = 0;
        play_record_song(User_puzi, User_puzi_index);
        // 自动开启录音模式
        Function_Tag = RECORD;
        free_flag = 1;
    }

}





// ----------测试按键函数-------------
void test_DISPLAY_task(void *pdata){

    float threshold = 1.7;

    // unsigned int current_arr = pitch_table[0].arr;
    // unsigned int current_psc = pitch_table[1].psc;
    int current_key_value = 0;
    int i;

    while(1){

        // uint16_t arr = 391;
        // uint16_t psc = 350;
        // SOUND_Init(arr, psc);   //注意填写arr和psc值

        // printf("Hello!\n\r");
        Delay_ms(1000);
    }

    // while(1){
    //     // 依次扫描按键
    //     KEY_scan(threshold);

    //     printf("*****************\n\r");
    //     for(i=3;i>=0;i--){
    //         printf("%d\n\r",KEY_value[i]);
    //     }

    //     Delay_ms(500);

    // }

        // ------------------

    // float voltage_1 = 0;
    // float voltage_2 = 0;
    // float voltage_3 = 0;
    // float voltage_4 = 0;

    // while(1){

    //     voltage_1 = Get_Adc_Average(KEY_3, 5);
    //     voltage_2 = Get_Adc_Average(KEY_2, 5);
    //     voltage_3 = Get_Adc_Average(KEY_1, 5);
    //     voltage_4 = Get_Adc_Average(KEY_0, 5);

    //     printf("voltage_1 = %f\n\r", voltage_1);
    //     printf("voltage_2 = %f\n\r", voltage_2);
    //     printf("voltage_3 = %f\n\r", voltage_3);
    //     printf("voltage_4 = %f\n\r", voltage_4);
    //     printf("*****************\n\r");

    //     Delay_ms(2500);
    // }



        // -----------------


        // post 按键值
        // OSMboxPost(msg_data, (void*)&(KEY_value));


        // if (current_key_value != KEY_value[0] << 3 + KEY_value[1] << 2 + KEY_value[2] << 1 + KEY_value[3]){

        //     printf("%d",current_key_value);

        // }


        // // 查询按键与音调的对应关系
        // current_key_value = KEY_value[0] << 3 + KEY_value[1] << 2 + KEY_value[2] << 1 + KEY_value[3];

        // current_key_value --;


        // if (current_key_value == -1){
        //     TIM_Cmd(TIM3, DISABLE);  //停止TIM3，停止输出PWM波
        // }
        // else{
        //     // 改变音调
        //     SOUND_Init(pitch_table[current_key_value].arr, pitch_table[current_key_value].psc);
        // }
    

}



// 按键扫描函数
// 如果adc采样得到电压值 < threshold，则认为有遮挡
// threshold 一般取1.8V
/*
输入：threshold_voltage 检测按键遮挡的阈值电压
影响参数：全局变量KEY_value[4],如果有按键被按下，则置为1


*/
void KEY_scan(float threshold_voltage){

    int i;
    int channel;
    float tmp_voltage;
    float threshold = threshold_voltage; 

    last_key_value = current_key_value; // 存入上次的按键值

    // 循环扫描每个按键
    for(i=0;i<4;i++){

        channel = key_list[i];
        tmp_voltage = Get_Adc_Average(channel, 3);
        if (tmp_voltage < threshold){
            Delay_ms(1);   // 去抖动
            tmp_voltage = Get_Adc_Average(channel, 3);
            if(tmp_voltage < threshold){
                KEY_value[i] = 1;
                continue ;
            }
        }

        KEY_value[i] = 0;

    }

    // 存入本次扫描得到的按键值
    current_key_value = KEY_value[0] * 8 + KEY_value[1] * 4 + KEY_value[2] * 2 + KEY_value[3];

    current_key_value --;

}




//定时器2中断服务程序
void TIM2_IRQHandler(void)   //TIM2中断
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)  //检查TIM2更新中断发生与否
		{
            TIM_ClearITPendingBit(TIM2, TIM_IT_Update  );  //清除TIMx更新中断标志 
            
            /* 中断服务 */
            /*
            1. 2s 中断到，停止声响
            2. 2s 中断到，看是否还是没有遮挡，如果没有遮挡，则showFree()
            */


            TIM_Cmd(TIM2, DISABLE);   // 停止2s中断
            TIM_Cmd(TIM3, DISABLE);  //停止声响

            // printf("*****************\n\r");
            // printf("In 2s Interrupt : current_key_value = %d\n\r",current_key_value);

            // printf("In 2s Interrupt : beep_key_value = %d\n\r",beep_key_value);

            // printf("*****************\n\r");

            if ((KEY_value[0] || KEY_value[1] || KEY_value[2] || KEY_value[3] == 0)){
                // 此时没有手遮挡
                free_flag = 1;   
            }
            else{
                free_flag = 0;
            }

            led_ctl = (led_ctl + 1) % 2;
            // if (led_ctl == 0){
            //     GPIO_SetBits(GPIOC, GPIO_Pin_13);
            // }
            // else{
            //     GPIO_ResetBits(GPIOC, GPIO_Pin_13);
            // }

		}
}



//定时器4中断服务程序
void TIM4_IRQHandler(void)   //TIM4中断
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)  //检查TIM4更新中断发生与否
		{
            TIM_ClearITPendingBit(TIM4, TIM_IT_Update  );  //清除TIMx更新中断标志 
            
            /* 中断服务 */
            /*
            1. 0.2s 中断到，可以接受用户最终的按键输入
            */

            TIM_Cmd(TIM4, DISABLE);   // 停止确认中断
            read_ready_flag = 1;


		}
}



void start_2Seconds_Int(void){

	TIM_SetCounter(TIM2, 0);
	TIM_Cmd(TIM2, ENABLE);  //使能TIM2					

}


void start_ready_Int(void){

	TIM_SetCounter(TIM4, 0);
	TIM_Cmd(TIM4, ENABLE);  //使能TIM2					

}

