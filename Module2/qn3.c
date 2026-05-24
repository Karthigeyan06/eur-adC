pid_t pid = fork();

if(pid == 0)
    printf("Child Process\n");
else
    printf("Parent Process\n");
