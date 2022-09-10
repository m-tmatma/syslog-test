#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <syslog.h>

void main()
{
    syslog(LOG_EMERG, "[PID=%d] [PPID=%d] %s", (int)getpid(), (int)getppid(), "LOG_EMERG");
    syslog(LOG_ALERT, "[PID=%d] [PPID=%d] %s", (int)getpid(), (int)getppid(), "LOG_ALERT");
    syslog(LOG_CRIT, "[PID=%d] [PPID=%d] %s", (int)getpid(), (int)getppid(), "LOG_CRIT");
    syslog(LOG_ERR, "[PID=%d] [PPID=%d] %s", (int)getpid(), (int)getppid(), "LOG_ERR");
    syslog(LOG_WARNING, "[PID=%d] [PPID=%d] %s", (int)getpid(), (int)getppid(), "LOG_WARNING");
    syslog(LOG_NOTICE, "[PID=%d] [PPID=%d] %s", (int)getpid(), (int)getppid(), "LOG_NOTICE");
    syslog(LOG_INFO, "[PID=%d] [PPID=%d] %s", (int)getpid(), (int)getppid(), "LOG_INFO");
    syslog(LOG_DEBUG, "[PID=%d] [PPID=%d] %s", (int)getpid(), (int)getppid(), "LOG_DEBUG");
}
