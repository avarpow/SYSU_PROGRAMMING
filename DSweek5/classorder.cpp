#include "RANDOM.H"
#include <iostream>
#include <list>
#include <utility>
#include <queue>
#include <tuple>
#include<iomanip>
using namespace std;
typedef int TIME;                                                //
typedef pair<int, TIME> CONSUMER;                                //id,processing_time
typedef pair<TIME, CONSUMER> WAITING_COMSUMER;                   //in_time,CONSUMER
typedef tuple<TIME, TIME, WAITING_COMSUMER> PROCESSING_COMSUMER; //inpro_time,end_time,CONSUMER
typedef queue<WAITING_COMSUMER> WAITTING_LIST;
typedef enum
{
    consumerGeneraterlog,
    lineUPConmsumerlog,
    realeaseConsumerlog
} LOGCASE;
class order
{
private:
    static const PROCESSING_COMSUMER NULL_PROCESSING_COMSUMER;
    static Random r;
    int PROCESSING_TIME_PRE_CONSUMER;//平均顾客处理时间
    int AVERAGE_CONSUMER_PER_HOUR;//每小时平均产出的顾客
    int SERVER_PORT;//开启的服务窗口数量
    int START_HOUR;//开始营业的时间
    int END_HOUR;//设置营业结束时间
    int total_consumer_number;//储存总共生成的顾客数目
    int now_time;//当前时间
    int servered_count;//总共处理的顾客数目
    int total_waiting_time;//全部顾客的等待时间
    bool stastics_ready=false;//是否已经执行过daytime，是否可以展示数据
    WAITTING_LIST waitting_list;//正在等待的顾客队列
    PROCESSING_COMSUMER *processing_port;//每个处理窗口
    vector<PROCESSING_COMSUMER> result_list;//经过处理的顾客
    //随机生成前来排队的顾客，服从泊松分布
    void consumerGenerater(WAITTING_LIST &waitting_list, TIME now_time, int &total_consumer_number);
    //将排队的顾客分配到服务窗口上
    void lineUPConmsumer(WAITTING_LIST &waitting_list, PROCESSING_COMSUMER processing_port[], TIME now_time);
    //将处理结束的顾客离开处理窗口
    void realeaseConsumer(PROCESSING_COMSUMER processing_port[], TIME now_time);
    //输出进入排队的顾客信息
    void log(WAITING_COMSUMER w_con, WAITTING_LIST &waitting_list);
    //输出当前进入窗口处理阶段的顾客
    void log(PROCESSING_COMSUMER p_con, int port);
    //输出结束处理的顾客
    void log(TIME now_time, PROCESSING_COMSUMER p_con, int port);
    //初始化窗口
    void processingPortInit(PROCESSING_COMSUMER processing_port[],int SERVER_PORT);
    //输出根据60进制输出时间
    string outTime(TIME time);

public:
    order();
    ~order();
    void daytime();
    void showStastics();
    void setProcessingTimePreConsumer(int ProcessingTimePreConsumer);
    void setAvargeConsumerPerHour(int AvargeConsumerPerHour);
    void setServerPort(int ServerPort);
    void setStartHour(TIME StartHour);
    void setEndHour(TIME EndHour);
};
Random order::r=Random(false);
const PROCESSING_COMSUMER order::NULL_PROCESSING_COMSUMER=make_tuple(-1,-1,make_pair(-1,make_pair(-1,-1)));
void order::processingPortInit(PROCESSING_COMSUMER processing_port[],int SERVER_PORT){
    for(int i=0;i<SERVER_PORT;i++){
        processing_port[i]=NULL_PROCESSING_COMSUMER;
    }
}

void order::daytime(){
    cout<<"start"<<endl;
    total_consumer_number=0;
    total_waiting_time=0;
    servered_count=0;
    result_list.clear();
    processing_port = new PROCESSING_COMSUMER[SERVER_PORT];
    processingPortInit(processing_port,SERVER_PORT);
    TIME start_time=START_HOUR*60*60;
    TIME now_time=start_time;
    TIME end_time=END_HOUR*60*60;
    while(now_time<=end_time){
        consumerGenerater(waitting_list,now_time,total_consumer_number);
        realeaseConsumer(processing_port,now_time);
        lineUPConmsumer(waitting_list,processing_port,now_time);
        now_time++;
    }
    stastics_ready=true;
    delete[] processing_port;
}
void order::setProcessingTimePreConsumer(int ProcessingTimePreConsumer)
{
    if(ProcessingTimePreConsumer<0)
        return;
    PROCESSING_TIME_PRE_CONSUMER = ProcessingTimePreConsumer;
}
void order::setAvargeConsumerPerHour(int AvargeConsumerPerHour)
{
    if(AvargeConsumerPerHour<0)
        return;
    AVERAGE_CONSUMER_PER_HOUR = AvargeConsumerPerHour;
}
void order::setServerPort(int ServerPort)
{
    if(ServerPort<0)
        return;
    SERVER_PORT = ServerPort;
}
void order::setStartHour(TIME StartHour)
{
    if(StartHour<0 || StartHour>24)
        return;
    START_HOUR = StartHour;
}
void order::setEndHour(TIME EndHour)
{
    if(EndHour<0 || EndHour>24)
        return;
    END_HOUR = EndHour;
}
string order::outTime(TIME time){
    cout<< time/60/60 <<":"<<setw(2)<<setfill('0')<< time%60 ;
    return "";
}
void order::consumerGenerater(WAITTING_LIST &waitting_list,TIME now_time,int &total_consumer_number){//随机生成顾客前来排队，服从泊松分布
    double probability_per_second=(double)AVERAGE_CONSUMER_PER_HOUR/3600;
    //cout<<probability_per_second<<endl;
    double k=r.random_real();
    //cout<<"possion "<<r.poisson(PROCESSING_TIME_PRE_CONSUMER)<<endl;
    int processing_time=r.random_integer(AVERAGE_CONSUMER_PER_HOUR/3,AVERAGE_CONSUMER_PER_HOUR*3);
    //cout<<processing_time<<endl;
    
    if(k<probability_per_second){
        CONSUMER temp=make_pair(total_consumer_number+1,processing_time);
        total_consumer_number++;
        WAITING_COMSUMER temp_w_con=make_pair(now_time,temp);
        waitting_list.push(temp_w_con);
        log(temp_w_con,waitting_list);
    }
}
void order::lineUPConmsumer(WAITTING_LIST &waitting_list,PROCESSING_COMSUMER processing_port[],TIME now_time){//将排队的顾客分配到窗口
    for(int i=0;i<SERVER_PORT;i++){
        if(get<0>(processing_port[i])==-1 && !waitting_list.empty()){
                WAITING_COMSUMER top_consumer= waitting_list.front(); 
                waitting_list.pop();
                PROCESSING_COMSUMER temp_p_con=make_tuple(now_time,now_time + get<1>(top_consumer.second),top_consumer);
                processing_port[i]=temp_p_con;
                total_waiting_time+=now_time-top_consumer.first;
                servered_count++; 
                log(temp_p_con,i);
        }
    }
}
void order::realeaseConsumer(PROCESSING_COMSUMER processing_port[],TIME now_time){//查询是否有顾客处理结束
    for(int i=0;i<SERVER_PORT;i++){
        if(get<1>(processing_port[i])==now_time){
            log(now_time,processing_port[i],i);
            result_list.push_back(processing_port[i]);
            processing_port[i]=NULL_PROCESSING_COMSUMER;
        }
    }
}
void order::showStastics(){
    /*for(int i=0;i<SERVER_PORT;i++){
        cout<<" port "<<i+1<<" "
        <<"serveing consumer id "<<get<0>(get<2>(processing_port[i]).second)<<endl;
    }*/
    if(!stastics_ready){
        cout<<"please run daytime() first"<<endl;
        return;
    }
    for(auto &i:result_list){
        WAITING_COMSUMER &w_con=get<2>(i);
        CONSUMER &con=w_con.second;
        cout<<"consumer id: "<<setw(3)<<con.first
        <<" start lineup time " << outTime(w_con.first)
        <<" start processing time "<<outTime(get<0>(i)) << endl
        <<" waitting time "<< outTime(get<0>(i)-w_con.first)
        <<" end processing time " << outTime(get<1>(i)) <<endl;
    }
    cout<<"total served consumer "<<servered_count<<" "
    <<"avarge waitting time "<<setprecision(6)<<(double)total_waiting_time/servered_count
    <<" s";
}
//consumerGeneraterlog
void order::log(WAITING_COMSUMER w_con,WAITTING_LIST& waitting_list){
    cout<<"["<<w_con.first<<"]: "<<" WAIT  "
    <<"consumer id:"<< get<0>(w_con.second) <<" in queue"
    <<" processing time: "<<outTime(get<1>(w_con.second))<<"s"
    <<" queue length:"<< waitting_list.size()<<endl;
}
//lineUPConmsumerlog
void order::log(PROCESSING_COMSUMER p_con,int port){
    cout<<"["<<get<0>(p_con)<<"]: "<<" SERVE "
    <<"at server_port "<<port<<" "
    <<" exit time "<<outTime(get<1>(p_con))
    <<" wait time "<<outTime(get<0>(p_con)-get<2>(p_con).first);
    WAITING_COMSUMER w_con=get<2>(p_con);
    cout <<" consumer id:"<< get<0>(w_con.second) <<" is servering "
    <<" processing time: "<<outTime(get<1>(w_con.second))<<"s"<<endl;
}
//realeaseConsumerlog
void order::log(TIME now_time,PROCESSING_COMSUMER p_con,int port){
    cout<<"["<<now_time<<"]: "<<" EXIT  "
    <<"at server_port "<<port<<" ";
    WAITING_COMSUMER w_con=get<2>(p_con);
    cout <<" consumer id:"<< get<0>(w_con.second) <<" is exiting "
    <<" processing time: "<<outTime(get<1>(w_con.second))<<"s"<<endl;
}
order::order(/* args */){}

order::~order(){   }

int main(){
    order test1;
    test1.setAvargeConsumerPerHour(100);
    test1.setStartHour(9);//设置开始营业的时间
    test1.setEndHour(10);//设置停止营业的时间
    test1.setServerPort(5);//设置服务的窗口数量
    test1.setProcessingTimePreConsumer(180);//设置平均处理每个顾客需求的时间，服从泊松分布
    test1.daytime();//开始执行队列模拟
    test1.showStastics();//在队列模拟之后展示每个执行顾客的编号，到来时间，排队时间， 结束时间。并最终输出顾客总数和 平均等待时间
}
