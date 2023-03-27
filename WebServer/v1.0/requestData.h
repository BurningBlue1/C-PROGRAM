#ifndef REQUESTDATA
#define REQUESTDATA
#include <string>
#include <unordered_map>

const int STATE_PARSE_URI = 1;
const int STATE_PARSE_HEADERS =2;
const int STATE_RECV_BODY =3;
const int STATE_ANALYSIS =4;
const int STATE_FINISH =5;

const int MAX_BUFF =4096;

//有请求出现但是读不到数据，可能是Request Aborted，
//或者来自网络的数据没有达到等原因，
//对这样的请求尝试达到一定的次数就抛弃
const int AGAIN_MAX_TIMES =200;

const int PARSE_URI_AGAIN =-1;
const int  PARSE_URI_ERROR =-2;
const int PARSE_URI_SUCCESS =0;

const int PARSE_HEADER_AGAIN =-1;
const int PARSE_HEADER_ERROR =-2;
const int PARSE_HEADER_SUCCESS =0;

const int ANALYSIS_ERROR =-2;
const int ANALYSIS_SUCCESS =0;

const int METHOD_POST =1;
const int METHOD_GET =2;
const int HTTP_10 = 1;
const int HTTP_11= 2;

const int EPOLL_WAIT_TIME =500;

class MimeType{
private:
    static pthread_mutex_t lock;
    static std::unordered_map<std::string,std::string> mine;
    MimeType();
    MimeType(const MimeType &m);
public:
    static std::string getMime(const std::string &suffix);
};

#endif