#include <iostream>
#include <list>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;
typedef int TIME;//
typedef pair<int,TIME> CONSUMER;//id,processing_time
typedef pair<TIME,CONSUMER> WAITING_COMSUMER;//in_time,CONSUMER
typedef tuple<TIME,TIME,WAITING_COMSUMER> PROCESSING_COMSUMER;//in_time,end_time,CONSUMER
typedef queue<WAITING_COMSUMER> WAITTING_LIST;
typedef enum{consumerGeneraterlog,lineUPConmsumerlog,realeaseConsumerlog} LOGCASE;
const int PROCESSING_TIME_PRE_CONSUMER=180;
const int AVERAGE_CONSUMER_PER_HOUR=110;
const int SERVER_PORT=5;
const int START_HOUR=9;
const int END_HOUR=10;
const PROCESSING_COMSUMER NULL_PROCESSING_COMSUMER=make_tuple(-1,-1,make_pair(-1,make_pair(-1,-1)));
void consumerGenerater(WAITTING_LIST &waitting_list,TIME now_time,int &total_consumer_number);
void lineUPConmsumer(WAITTING_LIST &waitting_list,PROCESSING_COMSUMER processing_port[],TIME now_time);
void realeaseConsumer(PROCESSING_COMSUMER processing_port[],TIME now_time);
void log(WAITING_COMSUMER w_con,WAITTING_LIST &waitting_list);
void log(PROCESSING_COMSUMER p_con,int port);
void log(TIME now_time,PROCESSING_COMSUMER p_con,int port);
void showStastics();
void daytime();
