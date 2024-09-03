#include "freertos_demo.h"

/*freertos 相关的头文件*/
#include "FreeRTOS.h"
#include "task.h"
/*任务用到 */


/*启动任务的参数*/
#define START_STACK_DEPTH 128
#define START_TASK_PRIORITY 1
TaskHandle_t start_task_handler;

/*任务1的参数*/
#define TASK1_STACK_DEPTH 128
#define TASK1_TASK_PRIORITY 2
TaskHandle_t task1_handler;

/*任务2的参数*/
#define TASK2_STACK_DEPTH 128
#define TASK2_TASK_PRIORITY 3
TaskHandle_t task2_handler;

/*任务3的参数*/
#define TASK3_STACK_DEPTH 128
#define TASK3_TASK_PRIORITY 4
TaskHandle_t task3_handler;

/*创建入口函数*/
void FreeRTOS_Start()
{
    /*1、创建启动任务*/
    xTaskCreate(
                (TaskFunction_t) Start_Task,//启动任务函数名
                (char *) "Start_Task",//定义任务名
                (configSTACK_DEPTH_TYPE) START_STACK_DEPTH,
                (void *) NULL,
                (UBaseType_t) START_TASK_PRIORITY,//任务优先级
                (TaskHandle_t *) &start_task_handler );//任务距离
    
    /*2、启动调度器*/
    xPortPendSVHandler();
}


/*启动任务，创建其他任务*/
void Start_Task()
{
    //进入临界区
    vPortEnterCritical();


    /*创建任务1*/
    xTaskCreate(
                (TaskFunction_t) Task1, 
                (char *) "Task1",
                (configSTACK_DEPTH_TYPE) TASK1_STACK_DEPTH,
                (void *) NULL,
                (UBaseType_t) TASK1_TASK_PRIORITY,
                (TaskHandle_t *) &task1_handler );
    /*创建任务2*/
    xTaskCreate(
                (TaskFunction_t) Task2,
                (char *) "Task2",
                (configSTACK_DEPTH_TYPE) TASK2_STACK_DEPTH,
                (void *) NULL,
                (UBaseType_t) TASK2_TASK_PRIORITY,
                (TaskHandle_t *) &task2_handler );
    /*创建任务3*/
    xTaskCreate(
                (TaskFunction_t) Task3,
                (char *) "Task3",
                (configSTACK_DEPTH_TYPE) TASK3_STACK_DEPTH,
                (void *) NULL,
                (UBaseType_t) TASK3_TASK_PRIORITY,
                (TaskHandle_t *) &task3_handler );

    /*启动任务只需要执行一次，用完就删*/
    vTaskDelete(NULL);

    //退出临界区
    vPortExitCritical();
}


/*任务1*/
void Task1()
{

}

void Task2()
{
    
}

void Task3()
{
    
}
