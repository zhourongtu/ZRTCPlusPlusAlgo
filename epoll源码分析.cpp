// epoll函数
int epoll_create(int size);
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
int epoll_wait(int epfd, struct epoll_event * events, int maxevents, int timeout);

struct epoll_event
{
    __uint32_t events;
    epoll_data_t data;
};
