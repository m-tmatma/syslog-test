/*!
    @file

    install developer tools.
        $ sudo  apt install -y build-essential

    compile
        $ gcc -o syslog-test syslog-test.c

    run
        $ ./syslog-test

    check syslog
        $ hostname
        ubuntu2204-01

        $ cat /var/log/syslog
        Sep 11 08:36:33 ubuntu2204-01 systemd[1592]: Started Application launched by gnome-session-binary.
        Sep 11 08:36:56 ubuntu2204-01 syslog-test: [PID=3506] [PPID=2342] LOG_EMERG
        Sep 11 08:36:56 ubuntu2204-01 syslog-test: [PID=3506] [PPID=2342] LOG_ALERT
        Sep 11 08:36:56 ubuntu2204-01 syslog-test: [PID=3506] [PPID=2342] LOG_CRIT
        Sep 11 08:36:56 ubuntu2204-01 syslog-test: [PID=3506] [PPID=2342] LOG_ERR
        Sep 11 08:36:56 ubuntu2204-01 syslog-test: [PID=3506] [PPID=2342] LOG_WARNING
        Sep 11 08:36:56 ubuntu2204-01 syslog-test: [PID=3506] [PPID=2342] LOG_NOTICE
        Sep 11 08:36:56 ubuntu2204-01 syslog-test: [PID=3506] [PPID=2342] LOG_INFO
        Sep 11 08:36:56 ubuntu2204-01 syslog-test: [PID=3506] [PPID=2342] LOG_DEBUG

    If you received "Broadcast message from systemd-journald" on console running this program,
    See https://github.com/boltgolt/howdy/issues/385#issuecomment-653710695
*/
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
