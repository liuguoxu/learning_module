#include <stdio.h>

//布控相关
#define CONTROL_ID_LEN          64
#define CONTROL_PHONE_NUM_MAX   10 //一个布控实例上报的最大手机号数量
#define CONTROL_INST_NUM_MAX    10 //一个身份ID对应的实例最大个数

////布控实例
typedef struct{
    char id[CONTROL_ID_LEN + 1];
    time_t start_time;
    time_t end_time;
    int alarm_interval;
    char proposer_phone[PHONE_NUMBER_LEN + 1][CONTROL_PHONE_NUM_MAX];
}control_inst;

typedef struct{
    int num;
    control_inst list[CONTROL_INST_NUM_MAX];
}control_hash_value;

void main()
{
	control_hash_value v[10];

}
