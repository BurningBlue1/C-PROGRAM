chmod +x ./*
touch screen.log

按照ETCD-RC-MC-FS的顺序排列每个例子中的ERROR级别日志
ETCD:首先创建screen.log文件，写入例子名称，而后将ERROR级别日志写入该文件中
RC:读取screen文件目前有多少