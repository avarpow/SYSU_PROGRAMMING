#include "order.h"
#include "RANDOM.H"
Random r(false);

void consumerGenerater(WAITTING_LIST &waitting_list,TIME now_time,int &total_consumer_number){
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
void lineUPConmsumer(WAITTING_LIST &waitting_list,PROCESSING_COMSUMER processing_port[],TIME now_time){
    for(int i=0;i<SERVER_PORT;i++){
        if(get<0>(processing_port[i])==-1 && !waitting_list.empty()){
                WAITING_COMSUMER top_consumer= waitting_list.front(); 
                waitting_list.pop();
                PROCESSING_COMSUMER temp_p_con=make_tuple(now_time,now_time + get<1>(top_consumer.second),top_consumer);
                processing_port[i]=temp_p_con;
            log(temp_p_con,i);
        }
    }
}
void realeaseConsumer(PROCESSING_COMSUMER processing_port[],TIME now_time){
    for(int i=0;i<SERVER_PORT;i++){
        if(get<1>(processing_port[i])==now_time){
            log(now_time,processing_port[i],i);
            processing_port[i]=NULL_PROCESSING_COMSUMER;
        }
    }
}
//consumerGeneraterlog
void log(WAITING_COMSUMER w_con,WAITTING_LIST& waitting_list){
    //to do file
    cout<<"["<<w_con.first<<"]: "<<" WAIT  "
    <<"consumer id:"<< get<0>(w_con.second) <<" in queue"
    <<" processing time: "<<get<1>(w_con.second)<<"s"
    <<" queue length:"<< waitting_list.size()<<endl;
}
//lineUPConmsumerlog
void log(PROCESSING_COMSUMER p_con,int port){
    //to do file
    cout<<"["<<get<0>(p_con)<<"]: "<<" SERVE "
    <<"at server_port "<<port<<" "
    <<" exit time "<<get<1>(p_con);
    WAITING_COMSUMER w_con=get<2>(p_con);
        cout <<" consumer id:"<< get<0>(w_con.second) <<" is servering "
    <<" processing time: "<<get<1>(w_con.second)<<"s"<<endl;
}
//realeaseConsumerlog
void log(TIME now_time,PROCESSING_COMSUMER p_con,int port){
    cout<<"["<<now_time<<"]: "<<" EXIT  "
    <<"at server_port "<<port<<" ";
    WAITING_COMSUMER w_con=get<2>(p_con);
        cout <<" consumer id:"<< get<0>(w_con.second) <<" is exiting "
    <<" processing time: "<<get<1>(w_con.second)<<"s"<<endl;
}
void showStastics(){

}
void processingPortInit(PROCESSING_COMSUMER processing_port[],int SERVER_PORT){
    for(int i=0;i<SERVER_PORT;i++){
        processing_port[i]=NULL_PROCESSING_COMSUMER;
    }
}

void daytime(){
    WAITTING_LIST waitting_list;
    PROCESSING_COMSUMER processing_port[SERVER_PORT];
    TIME start_time=START_HOUR*60*60;
    TIME now_time=start_time;
    TIME end_time=END_HOUR*60*60;
    int total_consumer_number=0;
    processingPortInit(processing_port,SERVER_PORT);
    while(now_time<=end_time){
        consumerGenerater(waitting_list,now_time,total_consumer_number);
        realeaseConsumer(processing_port,now_time);
        lineUPConmsumer(waitting_list,processing_port,now_time);
        now_time++;
    }
    showStastics();
}
int main(){
    daytime();
    return 0;
}