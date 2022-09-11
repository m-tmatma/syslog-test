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
    pid_t pid = getpid();
    pid_t ppid = getppid();
    char work_to_pid[256];
    char work_to_ppid[256];
    char path_to_pid[256];
    char path_to_ppid[256];
    struct {
        int level;
        const char * data;
    } data[] = {
        { LOG_EMERG   , "LOG_EMERG  "},
        { LOG_ALERT   , "LOG_ALERT  "},
        { LOG_CRIT    , "LOG_CRIT   "},
        { LOG_ERR     , "LOG_ERR    "},
        { LOG_WARNING , "LOG_WARNING"},
        { LOG_NOTICE  , "LOG_NOTICE "},
        { LOG_INFO    , "LOG_INFO   "},
        { LOG_DEBUG   , "LOG_DEBUG  "},
    };
    int i;
    snprintf(work_to_pid, sizeof(work_to_pid), "/proc/%d/exe", pid);
    readlink(work_to_pid, path_to_pid, sizeof(path_to_pid));

    snprintf(work_to_ppid, sizeof(work_to_ppid), "/proc/%d/exe", ppid);
    readlink(work_to_ppid, path_to_ppid, sizeof(path_to_ppid));

    printf("%s: %s\n", work_to_pid, path_to_pid);
    printf("%s: %s\n", work_to_ppid, path_to_ppid);

    for (i = 0; i < sizeof(data)/sizeof(data[0]); i++)
    {
        syslog(data[i].level, "[PID=%d:%s] [PPID=%d:%s] %s", (int)getpid(), path_to_pid, (int)getppid(), path_to_ppid, data[i].data);
    }
}
